
# Klassen {#classes}

Die grundlegende Idee der Objektorientierung ist, dass Daten und zugehörige
Operationen in einer Einheit gruppiert werden. Dazu steht als Hilfsmittel das
bekannte Konzept der *Klasse* zur Verfügung, das den Aufbau und das Verhalten
gleichartiger Objekte beschreibt.

\cpp bietet vielfältige Möglichkeiten, um Klassen zu beschreiben.

## Deklaration und Definiton einer Klasse {#classdeclaration}

In diesem Abschnitt werden wir uns mit den grundlegenden Möglichkeiten
beschäftigen, wie man in \cpp Klassen deklarieren und definieren kann.

Wir haben schon gesehen, dass mittels `struct` eine Klasse definiert wird,
deren Attribute und Methoden alle öffentlich zur Verfügung stehen.

Ein Attribut wird in \cpp als *data member* (dt. so viel wie Datenmitglied) und
eine Methode wird als *member function* (dt. so viel wie Mitgliedsfunktion)
bezeichnet.

Schauen wir uns zuerst ein Beispiel an, das eine Person definiert, die vorerst
nur über zwei Attribute verfügt:

~~~{.cpp}
// class.cpp
#include <iostream>

using namespace std;

struct Person {
    string name;
    double weight;
};

int main() {
    Person p;
    p.name = "Max";
    p.weight = 79.5;
    Person q;
    cout << "Name: " << p.name << ", Gewicht: "
         << p.weight << endl;
    cout << "Name: " << q.name << ", Gewicht: "
         << q.weight << endl;
}
~~~

Die Ausgabe dieses Programmes könnte folgendermaßen aussehen:

~~~{.sh}
Name: Max, Gewicht: 79.5
Name: , Gewicht: 2.18846e-314
~~~

Aus diesem Quelltext und der Ausgabe lässt sich einiges ablesen:

- Wie schon gesagt, stehen alle Attribute eines `struct`s öffentlich zur
    Verfügung. Das bedeutet, dass von außerhalb der Klasse darauf zugegriffen
    werden kann, wie dies beim Zugriff auf die Attribute `name` und `weight`
    in der Funktion `main` zu sehen ist.

- Da es sich bei `p` und `q` um Objekte des Typs `Person` handelt, haben beide
    unterschiedliche, eigene Werte für die Attribute.

- Weiters erkennen wir, dass weder `name` noch `weight` beim Anlegen
    initialisiert werden. Lediglich im Fall von `p` werden den beiden Attribute
    nachträglich Werte zugewiesen. Bei der Ausgabe der uninitialisierten
    Attribute von `q` sehen wir, dass bei der Ausgabe von `name` ein Leerstring
    ausgegeben wird, während bei der Ausgabe der Größe ein anscheinend
    beliebiger Wert aufscheint.

    Daraus können wir ablesen, dass Attribute eines benutzerdefinierten Typs
    initialisiert werden, Attribute eines eingebauten Typs jedoch nicht!

Man kann allerdings auch direkt in der Deklaration der Klasse die Attribute
initialisieren. Ändere dazu die Deklaration des Attributs `weight` wie
folgt ab, sodass das Gewicht mit `0.0` initialisiert wird:

~~~{.cpp}
double weight{};
~~~

Danach wird die Ausgabe folgendermaßen aussehen:

~~~{.cpp}
Name: Max, Gewicht: 79.5
Name: , Gewicht: 0
~~~

Will man die den Namen und das Gewicht beim Anlegen der Person angeben und
somit die nachträgliche Zuweisung vermeiden, dann benötigt man einen
Konstruktor:

~~~{.cpp}
struct Person {
    Person(string name, double weight) {
        this->name = name;
        this->weight = weight;
    }
    string name;
    double weight{};
};
~~~

Das Anlegen der Instanzen soll jetzt folgendermaßen aussehen:

~~~{.cpp}
Person p{"Max", 79.5};
Person q("", 0);
~~~

Damit funktioniert das Programm jetzt wieder wie gewohnt und wir können uns
den Details zuwenden:

- In \cpp ist ein Konstruktor also eine Methode, die den Namen der Klasse trägt
    und keinen Rückgabetyp aufweist. Dieser Konstruktor wird ausgeführt, wenn
    ein Objekt dieser Klasse angelegt wird. Daher wird ein Konstruktor zum
    Initializieren des Objektes verwendet.

- Der Rumpf des Konstruktors wurde direkt innerhalb der Klassendeklaration
    angeführt. Das hat die gleiche Bedeutung als wenn wir eine Funktion mit dem
    Spezifizierungssymbol `inline` markiert hätten. Wir weisen den Compiler
    an, den Rumpf dieses Konstruktors wenn möglich direkt in den Code
    einzufügen.

- Innerhalb des Rumpfes sehen wir, dass wir einen Zeiger `this` verwenden. Jede
    Methode eines Objektes verfügt implizit über so einen Zeiger, der direkt
    auf das Objekt selber verweist. In diesem konkreten Fall wurde diese
    Konstruktion verwendet, um die Namen der Parameter gleich benennen zu
    können wie die Namen der Instanzvariablen.

    Innerhalb des Rumpfes wurde mit der Angabe der Parameter, die Bezeichner
    dieser Parameter in den Gültigkeitsbereich des Rumpfes des Konstruktors
    übernommen. Mittels `this->` steht eine Möglichkeit zur Verfügung, auf die
    Instanzvariablen zuzugreifen.

    Ohne Verwendung von `this` funktioniert unser Beispiel nicht wie wir uns
    dies erwarten:

    ~~~{.cpp}
    Person(string name, double weight) {
        name = name;
        weight = weight;
    }
    ~~~

    Der Compiler wird das Beispiel ohne Fehler übersetzen, aber es wird
    verständlicherweise nicht wie erwartet funktionieren, da die
    Parameterdeklaration die Deklaration der Instanzvariablen überschattet.
    So erhält man in diesem Fall lediglich, dass die Parameter sich selbst die
    eigenen Werte zuweisen. Die Instanzvariablen werden nicht gesetzt.

    Alternativ hätten wir den auch Konstruktor folgendermaßen definieren
    können:

    ~~~{.cpp}
    Person(string name_, double weight_) {
        name = name_;
        weight = weight_;
    }
    ~~~

    Damit lauten die Bezeichner der Parameter anders als die Bezeichner der
    Instanzvariable. Aus diesem Grund können die Bezeichner der
    Instanzvariablen ohne `this->` verwendet werden. Das hat allerdings rein
    syntaxtische Auswirkungen, da der Compiler -- von der Bedeutung her --
    immer ein `this->` voranstellt:

    ~~~{.cpp}
    Person(string name_, double weight_) {
        this->name = name_;
        this->weight = weight_;
    }
    ~~~

- Die angegebenen Parameter werden beim Anlegen eines Objektes mitgegeben. Wir
    sehen, dass wir die Initialisierung sowohl in der Form der
    vereinheitlichten Initialisierung als auch in der Form eines
    Funktionsaufrufes vornehmen können.

    Wie schon besprochen haben, ist es sinnvoller die vereinheitlichte Form
    zu wählen.

- Weiters sehen wir, dass wir jetzt auch die Variable `q` mit Hilfe dieses
    Konstruktors initialisieren müssen. Das lässt sich leicht verifizieren,
    indem die ursprüngliche Deklaration in der Form von `Person q;` wieder
    eingesetzt wird. Der Compiler wird dies zurückweisen, da kein Konstruktor
    zur Verfügung steht, der keine Parameter erwartet.

    Jetzt stellt sich die Frage, wie dies ohne Konstruktor funktionieren konnte.
    Das liegt daran, dass der Compiler einen Default-Konstruktor
    generiert, wenn es keinen anderen Konstruktor gibt.

    Ein generierter Default-Konstruktor hat keine Parameter und initialisiert
    die Instanzvariablen gemäß den Regeln, die wir schon in diesem Abschnitt
    kennengelernt haben.

    Natürlich steht es uns frei einen Default-Konstruktor selber zu schreiben
    und damit `Person q` wieder wie gewohnt verwenden zu können:

    ~~~{.cpp}
    Person() {}
    ~~~

    In unserem konkreten Fall geht dies in dieser einfachen Art und Weise, da
    wir direkt bei der Deklaration der Instanzvariablen die gewünschte
    Initialisierung vorgenommen haben.

    Alternativ könnte man Default-Parameter zu dem Konstruktor mit den
    Parametern hinzufügen, wodurch ebenfalls ein Default-Konstruktor entsteht,
    da dieser Konstruktor jetzt

    ~~~{.cpp}
    Person(string name="", double weight=0) {
        this->name = name;
        this->weight = weight;
    }
    ~~~

    Damit besteht die Möglichkeit, die Initialisierungen direkt bei der
    Instanzvariable `weight` zu entfernen:

    ~~~{.cpp}
    double weight;
    ~~~

    Allerdings behebt dies nicht das Problem, dass die Variable `name` zuerst
    mit einem Leerstring initialisiert wird und danach mit dem übergebenen
    Parameter im Konstruktor überschrieben wird (durch eine Zuweisung).
    Diesen Umstand kann mit folgender Syntax zu Leibe gerückt werden:

    ~~~{.cpp}
    Person(string name="", double weight=0) : name{name},
      weight{weight} { }
    ~~~

    Damit wird die Instanzvariable `name` mit dem Parameter `name`
    und die Instanzvariable `weight` mit dem Parameter `weight`
    initialisiert. Eine weitere Initialisierung `name` beziehungsweise 
    `weight` findet nicht statt.

Eine Objekt kann auch default-mäßig mittels einer Kopie eines Objektes gleichen
Typs initialisiert werden. Dazu stellt der Compiler diese Funktionalität
selbständig in der Art zur Verfügung, dass jede Instanzvariable kopiert wird:

~~~{.cpp}
Person r{p};
cout << "Name: " << r.name << ", Gewicht: " << r.weight << endl;
~~~

Die Ausgabe wird wie erwartet wie die Ausgabe von `p` sein.

Auf die gleiche Art und Weise besteht default-mäßig die Möglichkeit ein
Objekt einem anderen Objekt zuzuweisen. Auch hierfür stellt der Compiler
die Funktionalität zur Verfügung, sodass jede Instanzvariable kopiert wird:

~~~{.cpp}
r = q;
cout << "Name: " << r.name << ", Gewicht: " << r.weight << endl;
~~~

Damit ergibt sich die Ausgabe wie bei der Ausgabe von `q`.

Im Sinne der Datenkapselung (engl. *encapsulation*) macht es keinen Sinn, alle
Attribute und Methoden öffentlich verfügbar zu machen.

Ändere deshalb das `struct` wie folgt ab:

~~~{.cpp}
struct Person {
    Person(string name="", double weight=0) : name{name},
      weight{weight} { }
  private:
    string name;
    double weight;
};
~~~

In dieser Form lässt sich das Programm jedoch nicht mehr übersetzen! Das
Hinzufügen von `private:` bedeutet, dass die folgenden Bezeichner nicht mehr
von außerhalb der Klasse aus zugreifbar sind. Damit kann `p.name` nicht
mehr funktionieren.

Wie ist vorzugehen? Jetzt ist es Zeit, Methoden einzuführen, die öffentlich
zugreifbar sind und die jeweilige Instanzvariable zurückliefern. Solche
Methoden werden oft als "getter method" bezeichnet:

~~~{.cpp}
struct Person {
    Person(string name="", double weight=0) : name{name},
      weight{weight} { }
    string get_name() { return name; }
    double get_weight() { return weight; }
  private:
    string name;
    double weight;
};
~~~

Natürlich muss jetzt auch noch der Zugriff der Instanzvariablen in `main` auf
den Aufruf der Methode abgeändert werden:

~~~{.cpp}
cout << "Name: " << p.get_name() << ", Gewicht: "
     << p.get_weight() << endl;
cout << "Name: " << q.get_name() << ", Gewicht: "
     << q.get_weight() << endl;
~~~

Da wir die Instanzvariablen mittels `private` verborgen haben, müssen
wir den Zugriff über die Methoden erfolgen lassen.

Jetzt macht es Sinn, das Schlüsselwort `struct` in `class`
umzuändern. Im Unterschied zu `struct`, ist die Bedeutung von `class`, dass
die Standardsichtbarkeit `private` ist. Das zieht allerdings nach sich, dass
die Sichtbarkeit der Methoden mittels `public` sichergestellt werden muss,
damit von `main` aus, diese zugegriffen werden kann:

~~~{.cpp}
class Person {
    string name;
    double weight;
  public:
    Person(string name="", double weight=0) : name{name},
      weight{weight} { }
    string get_name() { return name; }
    double get_weight() { return weight; }
};
~~~

Da die Standardsichtbarkeit von `class` eben `private` ist, wurde die
Deklaration der Instanzvariablen nach vor geschoben. Allerdings ist es
übersichtlicher, die alte Reihenfolge wieder herzustellen, sodass die
öffentliche Schnittstelle der Klasse wieder in den Vordergrund rückt:

~~~{.cpp}
class Person {
  public:
    Person(string name="", double weight=0) : name{name},
      weight{weight} { }
    string get_name() { return name; }
    double get_weight() { return weight; }
  private:
    string name;
    double weight;
};
~~~

Wir sehen hier, dass der öffentliche Teil der Klasse mit den Methoden am Anfang
steht und die Daten, die im Sinne der Kapselung von außen nicht sichtbar und
zugreifbar sein sollten, im privaten Teil am Ende angeordnet sind. Damit muss
zwar ein zusätzliches `private:` angeführt werden, aber die Übersichtlichkeit
konnte gesteigert werden.

Will man die Instanzvariablen verändern, dann werden Methoden notwendig, die
die Veränderung vornehmen. So eine Methode wird meist als "setter method"
bezeichnet:

~~~{.cpp}
void set_name(string name) { this->name = name; }
void set_weight(double weight) { if (weight > 0) this->weight = weight; }
~~~

Als Alternative für diese Notation mittels `set_` und `get_` bietet es sich
auch an, auf überladene Methoden zurückzugreifen:

~~~{.cpp}
#include <iostream>

using namespace std;

class Person {
  public:
    Person(string name="", double weight=0) : name_{name}, weight_{weight} { }
    string name(string name="") { if (name != "") name_ = name; return name_; }
    double weight(double weight=0) { if (weight > 0) weight_ = weight; return weight_;}
  private:
    string name_;
    double weight_;
};

int main() {
    Person p{"Max", 79.5};
    Person q;
    cout << "Name: " << p.name() << ", Gewicht: " << p.weight() << endl;
    q.name("Mini");
    q.weight(60);
    cout << "Name: " << q.name() << ", Gewicht: " << q.weight() << endl;
}
~~~

Als Vorteil lässt sich anführen, dass die Anzahl der Methoden reduziert werden
konnte und damit, aus einer gewissen Sichtweise, die Bedienung der Klasse
übersichtlicher wurde. Der Nachteil ergibt sich durch die notwendige Abfrage im
Rumpf der Methode.

## Methoden {#memberfunctions}

In diesem Abschnitt werden wir näher auf die verschiedenen Möglichkeiten im
Zusammenhang mit der Deklaration von Methoden eingehen. Methoden werden in
\cpp, wie schon erwähnt,  als "member function" bezeichnet.

### Methoden in einer `.cpp` Datei

Methoden können entweder direkt in einer Headerdatei definiert werden
(siehe Abschnitt \at[inlinemethods]) oder außerhalb in einer `.cpp` Datei.

Hier betrachten wir den Fall, dass wir die Definition in einer `.cpp` Datei
vornehmen. In der Headerdatei befindet sich in der Klasse lediglich die
Deklaration der Methode:

~~~{.cpp}
// car.h
#ifndef CAR_H
#define CAR_H

#include <iostream>

class Car {
  public:
    void drive();
};
#endif
~~~

Die Definition erfolgt in der zugehörigen Headerdatei:

~~~{.cpp}
// car.cpp
#include "car.h"

void Car::drive() {
    std::cout << "now driving..." << std::endl;
}
~~~

Beachte, dass der Klassenname gemeinsam mit dem `::` Operator vor den
Methodennamen gesetzt wird, um dem Compiler mitzuteilen zu welcher Klasse die
Methode gehört.

Die Verwendung dieser Klasse findet typischerweise in einer anderen Datei
statt:

~~~{.cpp}
// methods.cpp
#include <iostream>

#include "car.h"

using namespace std;

int main() {
    Car car;
    car.drive();
}
~~~

Bei der Übersetzung muss natürlich beachtet werden, dass das Modul `car.cpp`
zuerst übersetzt werden muss und danach entsprechend gelinkt wird.

Im Abschnitt \at[classdeclaration] haben wir schon gesehen, dass `this` einen
Zeiger auf das aktuelle Objekt darstellt, der implizit immer vorhanden ist,
um auf die Instanzvariablen zuzugreifen, wenn sich diese mit den Parametern
überschneiden.

`this` kann allerdings auch als Rückgabewert verwendet werden:

~~~{.cpp}
// methodchaining.cpp
#include <iostream>

using namespace std;

class Adder {
  public:
    Adder& add(int val) { amount += val; return *this; }
    int value() { return amount; }
  private:
    int amount{};
};

int main() {
    Adder a;
    a.add(1).add(2).add(3);
    cout << a.value() << endl;
}
~~~

Diese Art der Verarbeitung wird als Methodenverkettung (engl. *method
chaining*) zeichnet.


### `const`-Methoden {#constmethods}

Methoden können auch als `const` markiert werden, wobei die Bedeutung darin
liegt, dass auf konstante Objekte nur `const`-Methoden, nicht jedoch
nicht-`const`-Methoden, aufgerufen werden können. Schauen wir uns das an Hand
eines Beispiels an, sodass die Anwendung einsichtig wird.

Ändere bitte die Definition von `value()` so ab, dass `const` hinzugefügt wird:

~~~{.cpp}
int value() const { return amount; }
~~~

Damit wird der Compiler die Datei wie gewohnt übersetzen und das Ergebnis der
Ausführung dieses Programmes wie vorher sein. Als nächsten Schritt werden wir
eine konstante Variable vom Typ `Adder` anlegen und sonst wie vorher verfahren:

~~~{.cpp}
const Adder b;
b.add(1).add(2).add(3);
cout << b.value() << endl;
~~~

Der Compiler wird diesen Programmtext jetzt mit einer Fehlermeldung
zurückweisen, da die Methode `add` nicht als `const` Methode deklariert ist
und hiermit es zu einer Veränderung einer als `const` deklarierten Variable
kommen würde.

Das Programm übersetzt nur, wenn die Methode `add()` für das Objekt `b`
entfernt wird, womit lediglich der Wert 0 ausgegeben wird. Damit dieses
Beispiel Sinn macht, muss man natürlich einen Konstruktor hinzufügen:

~~~{.cpp}
Adder(int val=0) : amount{val} {}
~~~

Mit einer Initialisierung der Variablen erhält man eine Konstante, die
in bestimmten Situationen sehr praktisch sein kann:

~~~{.cpp}
const Adder b{3};
cout << b.value() << endl;
~~~

Es gibt Situationen in denen es angebracht ist, ein Objekt als `const` zu
markieren, aber gewisse Instanzvariablen sehr wohl verändert werden sollen. Das
werden wir im Abschnitt \at[mutablemember] betrachten.

Die Vorteile solcher mit `const` markierten Methoden sind:

- Der Compiler kann eine entsprechende Überprüfung vornehmen und damit sind
    unabsichtliche Veränderungen eines Objektes nicht mehr möglich.
- Außerdem dient diese Markierung auch als Dokumentation gegenüber dem Benutzer
    der Klasse.

Beachte bitte, dass eine `const`-Methode, die außerhalb einer Klasse definiert
ist, unbedingt mit `const` definiert werden muss. Das heißt, dass `const` zum
Typ der Methode gehört und es sowohl eine `const`-Version als auch eine
nicht-`const`-Version einer Methode mit der gleichen Signatur geben kann.

### `inline`-Methoden {#inlinemethods}

Wir haben schon gesehen, dass Methoden, die in der Klasse direkt definiert
werden, vom Compiler so betrachtet werden, als wenn man diese mit `inline`
gekennzeichnet hätte.

Wie auch normale Funktionen können Methoden explizit mit `inline`
gekennzeichnet werden. In diesem Fall muss die Definition der Methode natürlich
in der Headerdatei stehen und nicht in der `.cpp` Datei:

~~~{.cpp}
// inline_car.h
#ifndef INLINE_CAR_H
#define INLINE_CAR_H

#include <iostream>

class Car {
  public:
    void drive();
};

inline void Car::drive() {
    std::cout << "now driving..." << std::endl;
}

#endif
~~~

Die Verwendung unterscheidet sich klarerweise nicht von der nicht-`inline`
Variante. Lediglich das zusätzliche Binden entfällt.


### `static`-Methoden {#staticmethods}

`static`-Methoden (engl. *static method* oder *static member function*) sind
Methoden, die unabhängig von einer konkreten Instanz einer Klasse aufgerufen
werden können. Daher werden diese Methoden auch Klassenmethoden genannt.

Das Entwurfsmuster "Factory method" behandelt das Anlegen eines Objektes,
dessen Typ im vorhinein nicht bekannt ist. Die Idee ist, eine Methode zu
schreiben, die aufgrund eines Parameters die richtige Instanz anlegt
und zurückliefert.

Nehmen wir an, dass wir eine Klasse `Car` schreiben wollen, die eine allgemeine
Beschreibung eines Autos darstellen soll. An sich sollte es nicht möglich
sein, eine Instanz dieser Klasse anzulegen. Wie man sicherstellt, dass
dies nicht möglich ist, werden wir im Abschnitt \at[abstractclass] betrachten.

An konkreten Automarken soll es "Andi" und "Zitrone" geben und in Abhängigkeit
einer Benutzereingabe ein Auto der entsprechenden Automarke erzeugt werden:

~~~{.cpp}
// staticmembermethod.cpp
#include <iostream>

using namespace std;

class Car {
  public:
    static Car* make_car(string type);
};

class Andi : public Car {
};

class  : public Car {
};
~~~

In diesem Beispiel sehen wir bis jetzt schon einige interessante Aspekte:

- In der Klasse `Car` gibt es eine statische Methode (*static member
    function*), die als Parameter den Autotypnamen erhält und einen
    Zeiger auf ein konkretes Autoobjekt zurückliefert.

- Weiters gibt es die Klasse `Andi`, die von `Car` abgeleitet ist und keine
    weiteren Attribute oder Methoden definiert. Abgeleitete Klassen, also
    Vererbung, werden wir uns im Abschnitt \at[classinheritance] ansehen.

Als nächstes werden wir die statische Methode `make_car` implementieren:

~~~{.cpp}
Car* Car::make_car(string type) {
    if (type == "Audi")
        return new Audi();
    else if (type == "Skode")
        return new Skoda();
    else
        return nullptr;
}
~~~

Diese Funktion ist von der Funktionsweise einfach und trotzdem sind wiederum
zwei Aspekte interessant:

- Beachte, dass kein `static` in der Definition dieser Methode vorkommt.

- Es wird das neue konkrete Auto am Heap angelegt. Wer die Verantwortung über
    dieses neu angelegte Objekt übernimmt, muss in der Dokumentation genau
    festgelegt werden.

Die eigentliche Verwendung dieser Methode ist einfach:

~~~{.cpp}
int main() {
    string type;
    cout << "Autotype: ";
    cin >> type;
    Car* car{Car::make_car(type)};
}
~~~

Hier siehst du, dass es kein Objekt der Klasse `Car` gibt und trotzdem die
Methode `make_car` aufgerufen werden kann, da diese `static` deklariert ist.
Beachte weiter, dass mittels des Bereichsauflösungsoperators auf die Methode
zugegriffen wird.

## Datenmember

### `static`-Klassenvariablen {#staticmembervar}

Analog zu statischen Methoden ist es statische Variablen, die unabhängig von
bereits angelegten Objekten immer zur Verfügung stehen. Damit kann sich die
Klasse selbst einen Zustand abspeichern, der unabhängig von einzelnen Instanzen
ist. Solche Variablen werden auch als Klassenvariablen bezeichnet.

Betrachten wir das nachfolgende Beispiel einer Klasse, die für jedes neue
Objekt eine neue fortlaufende Nummer, also so etwas wie eine Seriennummer,
vergibt:

~~~{.cpp}
#include <iostream>

using namespace std;

class Car {
  public:
    Car() : sernr_{maxsernr} { maxsernr++; }
    int sernr() { return sernr_; }
  private:
    static int maxsernr;
    int sernr_;
};

int Car::maxsernr{1};

int main() {
    Car c1;
    Car c2;
    Car c3;
    cout << "c1: " << c1.sernr() << endl;
    cout << "c2: " << c2.sernr() << endl;
    cout << "c3: " << c3.sernr() << endl;
}
~~~

Die Ausgabe wird erwartungsgemäß folgendermaßen aussehen:

~~~{.sh}
c1: 1
c2: 2
c3: 3
~~~

Wichtig ist, dass \cpp es nicht erlaubt Klassenvariablen innerhalb der
Deklaration der Klasse vorzunehmen. Aus diesem Grund wurde diese, in dem
Beispiel, nach der Klassendeklaration vorgenommen.


### `mutable`-Instanzvariablen {#mutablemember}

Im Abschnitt \at[constmethods] haben wir schon konstante Methoden als
Hilfsmittel zur Sicherstellung der Unveränderbarkeit der Instanz
kennengelernt. Allerdings ist es manchmal sinnvoll, dass einzelne
Instanzvariablen von dieser Unveränderlichkeit ausgenommen sind.

Es gibt prinzipiell zwei Möglichkeiten wie diese Anforderung erfüllt werden
kann. Zuerst schauen wir uns eine Technik an, die sich "Memoization" (das an das man
sich erinnert) nennt. Verwendung findet diese Technik überall wo aufwändige
Berechnungen durchzuführen sind oder bei dem Zugriff auf externe Ressourcen
(Netzwerk, Dateien, Datenbanken,...).

Der Einfachheit halber betrachten wir eine Klasse `Polyline`, die einen
Polygonzug darstellen soll. Diese Klasse soll es ermöglichen eine Folge von
Punkten des zweidimensionalen Raumes als Polygonzug zu interpretieren. An
Operationen sind das Hinzufügen eines weiteren Punktes und die Ermittlung
der Länge interessant. Schauen wir uns dazu einmal nur die Schnittstelle
an:

~~~{.cpp}
// polyline.cpp
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

class Polyline {
  public:
    Polyline(initializer_list<pair<double, double>> points);
    void add(double x, double y);
    double length() const;
};
~~~

Wir sehen, dass vorerst alle implementierungsspezifischen Einzelheiten
weggelassen wurden.

Die Verwendung soll in weiterer Folge so funktionieren:

~~~{.cpp}
int main() {
    Polyline poly1{{}};
    cout << poly1.length() << endl;
    poly1.add(0, 0);
    cout << poly1.length() << endl;
    poly1.add(1, 1);
    cout << poly1.length() << endl;
    poly1.add(2, 0);
    cout << poly1.length() << endl;

    const Polyline poly2{{0, 0}, {1, 1}, {2, 0}};
    // poly2.add(3, 3);
    cout << poly2.length() << endl;
}
~~~

Hier können wir schon sehen wie die Schnittstelle verwendet werden soll:

- Man kann einen neuen Polygonzug mit einer Liste von Punkten anlegen.
- Weiters man kann einen neuen Punkt hinten an den Polygonzug anhängen.
- Außerdem kann man die Länge des Polygonzuges bestimmen.
- Weiters kann ein Polygon konstant sein oder nicht. Wenn ein Polygonzug
    konstant ist, dann kann kein weiterer Punkt hinzugefügt werden.
- Man kann dies zwar hieraus nicht ablesen, aber als Randbedingung soll gelten,
    dass die Länge eines Polygonzuges nur berechnet wird, wenn diese benötigt
    wird.

Jetzt werden wir schrittweise auf die Implementierung eingehen. Starten wir mit
den nötigen Instanzvariablen:

~~~{.cpp}
private:
  vector<pair<double, double>> points;
  mutable double distance{-1};
~~~

Offensichtlich wird die Liste der Punkte in einem Vektor gespeichert, der Paare
von `double`-Werten beinhaltet.

Weiters gibt es eine Instanzvariable `distance`, die die Länge beinhaltet. Da
die Länge nur berechnet werden soll, wenn diese benötigt wird, wird in der
Distanz ein ungültiger Wert eingetragen.  Da eine Distanz nie negativ sein
kann, ist damit gekennzeichnet, dass der Wert noch nicht ermittelt worden ist.
Die Wirkungsweise von `mutable` werden wir uns später noch ansehen.

Als nächstes werden wir uns die Implementierung des Konstruktors als auch der
Methode `add` ansehen:

~~~{.cpp}
Polyline(initializer_list<pair<double, double>> points) : points{points} {}
void add(double x, double y) { points.emplace_back(x, y); distance = -1; }
~~~

Der Konstruktor ist wiederum sehr einfach, da lediglich der Vektor mit den
Punkten initialisiert wird. Auch die Implementierung der `add`-Methode
ist einfach. Neu ist lediglich die `emplace_back` Methode, die ein neues
Paar ohne Zwischenobjekt zum Vektor hinzufügt. Damit wird markiert, dass
die Distanz nicht mehr gültig, wird der Wert auf einen ungültigen Wert
zurückgesetzt.

Jetzt zur Implementierung der Methode `length`:

~~~{.cpp}
double length() const {
    if (distance >= 0)
        return distance;
    else {
        const pair<double, double>* p_prev{};
        for (auto& p : points) {
            if (!p_prev) {
                p_prev = &p;
                distance = 0;
                continue;
            }
            distance += sqrt(pow(p.first - p_prev->first, 2) +
                        pow(p.second - p_prev->second, 2));
            p_prev = &p;
        }
        return distance;
    }
}
~~~

Wie funktioniert diese Methode:

- Wenn ein gültiger Wert der Länge schon vorhanden ist, wird dieser
    zurückgeliefert. 
- Anderenfalls muss dieser berechnet werden. Dazu wird über alle Punkte
    iteriert und jeweils der Abstand zum Vorgänger ermittelt und zur Länge
    addiert. Dazu wird der Satz von Pythagoras angewandt.
- Lediglich beim ersten Punkt ist kein vorheriger Punkt vorhanden, daher
    muss dieser Fall extra behandelt werden.

Jetzt sollte das Beispiel wie gefordert funktionieren!

Als Alternative kann zur Verwendung des Schlüsselwort `mutable`, kann man
auch das pimpl-Idiom (pointer to implementation) eingesetzt werden. Die Idee
ist, die veränderlichen oder besser die gesamte Implementierung der Klasse
in ein eigenes Modul auszulagern und in der eigentlichen Klasse nur einen
Pointer auf ein Objekt dieser Implementierung zu speichern. Damit benötigt
man einerseits kein `mutable` mehr (zumindest in der ursprünglichen Klasse)
und andererseits ist in der Schnittstellenklasse keine Implementierung mehr
sichtbar!

Das könnte folgendermaßen aussehen:

~~~{.cpp}
// pimpl_polyline.cpp
// all necessary includes go here

class Polyline {
  public:
    Polyline(initializer_list<pair<double, double>> points) : impl{new PolylineImpl{points}} {}
    void add(double x, double y) { impl->add(x, y); }
    double length() const { return impl->length(); }
    ~Polyline() { delete impl; }
  private:
    PolylineImpl* impl;
};
~~~

Die Klasse `PolylineImpl` wird jetzt in einem eigenem Modul implementiert, das
lediglich in kompilierter Form dem API mitgegeben wird.

## Verschachtelte Typen {#typemember}

~~~{.cpp}
class BST {
    class Node {
        Node* right;
        Node* left;
        int key;
    };
  public:
    void traverse();
};

BST::Node::...
~~~

## Konstruktor und Destruktor {#constructor}

~~~{.cpp}
// specialfuncs.cpp
~~~

Several functions:

- constructor initializing
- copy constructor
- move constructor: return -> indent(s1)
- move assignment: indent(s1) -> s1
- copy assignment: s2 -> s1
- destructor

XXX

vorgeben und verbieten

Default-Konstruktor, allgemeine Konstruktoren, Typumwandlungskonstruktor
Destruktor, delegierender Konstruktor

By default, a constructor invoked by a single argument acts as an implicit
conversion from its argument type to its type. For example: ...

explicit: Initialisierung mit und ohne `=`

- Initialisierungslisten: Wie schon gesehen: `vector<int> nums(10)`
    vs. `vector<int> nums{10}`: Die Form mit den geschwungenen Klammern erzeugt
    eine Initialisierungsliste.

    - Hat der Typ einen Konstruktor mit Initialisierungsliste des
        entsprechenden Typs, dann wird dieser verwendet.
    
        Der eingebaute Typ Array wird so betrachtet als hätte dieser einen
        Konstruktor mit Initialisierungsliste.
        
    - Wenn der Typ einen Konstruktor mit entsprechender Anzahl und Typ von
        Parametern hat, dann wird dieser genommen. Unter Umständen werden
        noch implizite Konvertierungen durchgeführt.

        Auch bei eingebeuten Datentypen wird diese Syntax verwendet. Beachte,
        dass nur werterhaltende Konvertierungen vorgenommen werden (also keine
        narrowing Konverterierungen).

    - Hat der Typ keinen Konstruktor, aber öffentlich zugängige
        Instanzvariable, dann werden diese in der Reihenfolge der Deklaration
        initialisiert.


Ressourcen mittels RAII (siehe \in[raii]).

## Aufzählungen

enum und enum class

## Forward-Deklarationen

gegenseitige Abhängigkeit von Klassen

If you make use of inheritance, it's likely that you need to provide a virtual
destructor for your classes. Modern compilers will warn if you do not, but this
is a pretty recent development.

