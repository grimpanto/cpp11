
# Pointer, Array, Referenz

<div class="drawer">
In diesem Kapitel werden die einzelnen Deklaratoroperatoren beschrieben, mit
denen neue Typen deklariert werden können:

- Pointer
- Array
- Referenzen

Außerdem werden wir Möglichkeiten der Standardbibliothek kennenlernen, die den
Umgang mit Pointern und Arrays erleichtern.
</div>

Die Inhalte dieses Kapitels, die die Pointer und die Arrays betreffen, sind für
das Verständnis extrem wichtig. Trotzdem sind die sogenannten Smart-Pointer den
normalen Pointern vorzuziehen und Referenzen können für viele Anwendungen
verwendet werden, für die früher Pointer eingesetzt wurden.

Arrays sollte man eigentlich in der normalen Anwendungsentwicklung wenn
möglich gar nicht verwenden. Statt Arrays bietet die Standardbibliothek die
Typen \type{vector} und \type{array} an.


## Pointer {#pointer}

Wie schon erwähnt, handelt es sich bei einem Pointer um ein Speicherobjekt, das
eine Speicheradresse enthält. Allerdings gibt es einen wichtigen Unterschied zu
einer reinen Adresse, nämlich, dass ein Pointer einen Typ hat. Dieser Typ legt
fest, wie der Speicherinhalt zu interpretieren ist, auf den dieser Pointer
zeigt. Damit kann \cpp auch dafür sorgen, dass keine Zugriffe mittels
inkompatibler Typen erfolgen.

In \cpp wird solch ein Pointer auf ein Objekt des Typs `T` als `T*`
angeschrieben und, in Abgrenzung zu den Smart-Pointern, auch als roher
Pointer (engl. *raw pointer*) bezeichnet.

Im Zusammenhang mit Pointern gibt es zwei wichtige Operatoren:

- Der Operator `&` ermittelt die Adresse eines Objektes. Diese Operation wird
    auch als Referenzieren (engl. *reference*) bezeichnet.
- Der Operator `*` ermittelt den Wert eines Zeigers. Diese Operation wird als
    Dereferenzieren (engl. *dereference*) bezeichnet.

Diese beiden Zeichen `&` und `*` werden in Ausdrücken verwendet. Innerhalb von
Deklarationen haben diese Zeichen `&` und `*` die Bedeutung der Deklaration
einer Referenz (siehe Abschnitt \in[reference] auf der Seite \at[reference])
beziehungsweise die Bedeutung eines Pointers.

Betrachte den nachfolgenden Quellcode und teste:

~~~{.cpp}
// pointer.cpp
#include <iostream>

using namespace std;

int main() {
    int i{1};
    int* p{&i};

    cout << "p == " << p << ", *p == " << *p
         << ", i == " << i << endl;
}
~~~

Die Ausgabe sieht bei mir folgendermaßen aus, wobei der Wert von `p` bei dir
sehr wahrscheinlich unterschiedlich sein wird:

~~~{.sh}
p == 0xbf88eea4, *p == 1, i == 1
~~~

Was ist passiert?

- Zuerst wird eine `int` Variable angelegt und mit `1` initialisiert. Danach wird
    ein Pointer `p` vom Typ `int*` (Pointer auf `int`) angelegt und mit der
    Adresse von `i` initialisiert.
    
- Danach wird die Adresse von `p`, der Wert der Speicherzelle auf den `p` zeigt
    und der Wert von `i` ausgegeben. Die Adresse wird offensichtlich in
    hexadezimaler Form ausgegeben. Da `p` auf `i` zeigt, sind die beiden
    letzten Werte natürlich identisch.

Füge jetzt die folgenden Zeilen anschließend an:

~~~{.cpp}
*p = 2;
cout << "*p = 2;" << endl;
cout << "p == " << p << ", *p == " << *p
     << ", i == " << i << endl;
~~~

Starte das Programm nochmals. Bei mir kommt es zu folgender Ausgabe:

~~~{.sh}
p == 0xbfc8e728, *p == 1, i == 1
*p = 2;
p == 0xbfc8e728, *p == 2, i == 2
~~~

Wir können folgendes bemerken:

- Die Adressen der Variable sind je Programmlauf unterschiedlich.
- Ändere ich den Wert der Speicherzelle, auf die `p` zeigt, dann ändert sich
    klarerweise in unserem Fall auch der Wert von `i`, da `p` die Adresse von
    `i` enthält.

Klar soweit? Gut, dann hänge die folgenden Zeilen wiederum hinten an:

~~~{.cpp}
int j{};
p = &j;
cout << "p = &j;" << endl;
cout << "p == " << p << ", *p == " << *p << ", i == "
     << i << ", j == " << j << endl;
~~~

Starte das Programm und schaue dir die Ausgabe an.

~~~{.sh}
p == 0xbfb65988, *p == 1, i == 1
*p = 2;
p == 0xbfb65988, *p == 2, i == 2
p = &j;
p == 0xbfb65984, *p == 0, i == 2, j == 0
~~~

Interpretieren wir jetzt einmal die Ausgabe:

- Der erste Teil wurde schon besprochen. Wir können in der letzten Ausgabe
    erkennen, dass die gespeicherte Adresse jetzt unterschiedlich ist. Das ist
    klar, da die Variablen `i` und `j` sicher nicht an derselben Adresse
    liegen werden.

- Weiters sehen wir, dass der Wert der Speicherzelle, auf die `p` zeigt, jetzt
    gleich dem Wert von `j` ist.

Schließen wir das Beispiel jetzt noch ab, indem wir zeigen, dass die Typen der
Pointer von \cpp auf Kompatibilität geprüft werden. Hänge dazu folgende Zeilen
an und übersetze das Programm:

~~~{.cpp}
char c;
p = &c;
~~~

Ok, das lässt sich natürlich nicht übersetzen. Da der Typ von `p` eben `int*`
ist und der Typ von `&c` eben `char*` ist. Das sind inkompatible Typen und
deshalb wird dies vom Compiler zurückgewiesen. Beachte, dass ein `char`
implizit in ein `int` konvertiert werden würde, aber dies trifft
sinnvollerweise nicht auf Pointer zu: Ein Pointer auf ein `char` wird eben
nicht implizit auf einen Pointer auf ein `int` konvertiert.

Ersetze diese beiden Zeilen, die sich nicht übersetzen lassen, durch folgende
Zeilen:

~~~{.cpp}
p = nullptr;
cout << "p == " << p << endl;
cout << "*p == " << *p << endl;
~~~

Nach erfolgreicher Übersetzung kommt es beim Programmlauf zu folgender Ausgabe:

~~~{.sh}
p == 0
Speicherzugriffsfehler
~~~

- Zuerst sehen wir, dass der Wert von `p` mit `0` ausgegeben wird. Das
    Schlüsselwort `nullptr` bezeichnet einen Pointer, der die Adresse 0
    gespeichert hat.

- Danach erfolgt bei mir die Ausgabe "Speicherzugriffsfehler". Diese Ausgabe
    kann bei dir anders aussehen, aber eine Fehlermeldung kommt auf jedem Fall,
    da kein Objekt an der Adresse 0 liegen kann. Erfolgt ein Zugriff auf die
    Adresse 0 wird vom Prozessor der Zugriff erkannt und der Prozess wird
    abgebrochen.

Jetzt stellt sich vielleicht die Frage, ob man direkt den Wert `0` in eine
Pointer-Variable speichern kann. Ja, das geht aus Kompatibilitätsgründen zu
älteren Versionen von \cpp. Ich empfehle es aber nicht zu tun, da `nullptr`
leichter zu lesen ist und der Compiler in anderen Fällen (überladenen
Funktionen) keine Typfehler feststellen kann, wenn `0` verwendet wird.

Meist werden Pointer in Zusammenhang mit dynamisch angeforderten
Speicherobjekten verwendet. Dynamisch angeforderte Speicherobjekte werden
am Heap mittels `new` angelegt und mittels `delete` wieder freigegeben.
Solche Speicherobjekte haben die Lebenszeit "free store".

~~~{.cpp}
p = new int{3};
cout << "p = new int{3};" << endl;
cout << "p == " << p << ", *p == " << *p << endl;
delete p;
~~~

Teste wieder. Bei mir kommt es zu folgender Ausgabe:

~~~{.sh}
p = new int{3};
p == 0x9f32008, *p == 3
~~~

Wie funktionieren diese Anweisungen?

- Mit `p = new int{3};` wird ein neues `int` von der Speicherverwaltung am Heap
    angefordert und die Adresse davon zurückgegeben. Diese Adresse wird dann in
    `p` gespeichert.

- Mittels `*p` kann wiederum auf den Inhalt zugegriffen werden.

- Mit `delete p` wird der angeforderte Speicher wieder freigegeben.

### Pointer und Strukturen

Meist wird nicht ein kleines Objekt eines fundamentalen Datentyps am Heap
abgelegt, sondern benutzerdefinierte Objekte. Wir haben mit `struct` schon eine
Möglichkeit kennengelernt, einen benutzerdefinierten Typ zu definieren.

Wollen wir als bekanntes Beispiel eine Person am Heap anlegen und über den
Pointer auf ein Attribut der Klasse \type{Person} zugreifen, dann könnte
das folgendermaßen aussehen:

~~~{.cpp}
// pointer_struct.cpp
#include <iostream>
#include <memory>

using namespace std;

struct Person {
    string first_name;
    string last_name;
    int year_of_birth;
};

int main() {
    Person* p{new Person{"Max", "Mustermann", 1990}};

    cout << *p.first_name << endl;
}
~~~

Es war zwar gut gemeint, allerdings lässt sich das Programm nicht übersetzen.
Das liegt an den Operatorprioritäten! Der Punktoperator hat höhere Priorität
als der Sternoperator. Deshalb ist die Ausgabezeile folgendermaßen abzuändern:

~~~{.cpp}
cout << (*p).first_name << endl;
~~~

Es ist offensichtlich, dass dies keine übersichtliche Lösung ist. Andererseits
wird diese Art des Zugriffes häufig benötigt. Deshalb gibt es dafür den
Operator `->`, der genau das erledigt:

~~~{.cpp}
cout << p->first_name << endl;
~~~

### Pointer und Konstanten

Im Zusammenhang mit Pointern wollen wir uns auch noch die Verwendung des
Schlüsselwortes `const` ansehen. Wir kennen die Verwendung von `const` schon in
der Verwendung als "normale" Variablen, wie zum Beispiel in `const double
pi{3.1415};`, wodurch festgelegt wird, dass die Variable `pi` nicht mehr
verändert werden kann und daher als Konstante funktioniert.

Erstelle folgendes kleines Programm und versuche es zu übersetzen:

~~~{.cpp}
// const.cpp
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const double pi{atan(1)*4};
    const double e{exp(1)};

    double* p;
    p = &pi;
}
~~~

Das wird nicht funktionieren, da `p` ein Pointer auf ein `double` ist und wir
hier `p` einen Pointer auf ein `const double` zuweisen wollen. Das lässt der
Compiler jedoch nicht zu, da es sonst möglich wäre, über `p` den Wert von `pi`
-- zum Beispiel mittels `*p = 1;` -- zu verändern. `pi` ist jedoch als `const`
deklariert und darf daher seinen Wert nicht ändern, womit klar ist,
dass dies nicht erlaubt ist und vom Compiler zurückgewiesen wird.

Also müssen wir die Definition von `p` abändern:

~~~{.cpp}
const double* p;
~~~

Damit lässt sich das Programm auch problemlos übersetzen, da `p` ein Pointer
auf ein `const double` und dieser Pointer mit der Adresse von `pi` initialisiert
worden ist. Eine Änderung von `pi` über `p` ist daher nicht möglich.

Da der Pointer selber nicht konstant ist und wir in unserem Programm zwei
Konstanten definiert haben, können wir auch `p` ändern:

~~~{.cpp}
p = &e;
~~~

Manchmal will man jedoch, dass der Pointer `p` selbst nicht veränderbar
ist. Füge deshalb folgende Zeilen hinzu und versuche wieder zu übersetzen:

~~~{.cpp}
double d1{1};
double d2{2};
double* const q;
q = &d1;
~~~

Das wird sich nicht übersetzen lassen, da `q` ein konstanter Pointer ist
und eine Konstante initialisiert werden muss.

So, damit unser Programm funktioniert, sind die letzten beiden Zeilen
folgendermaßen abzuändern:

~~~{.cpp}
double* const q{&d1};
~~~

<div class="annotation" title="Tipp">
Am besten liest man die Deklarationen von rechts nach links!

- Bezüglich der Deklaration von `q` bedeutet dies, dass `q` ein konstanter
    Pointer auf ein `double` ist.

- Für die Variable `p` bedeutet das, dass `p` ein Pointer auf ein `double` ist,
  dass konstant ist.
</div>

Eine Änderung von `q` auf `d2` ist damit natürlich nicht möglich, aber der Wert
der Variable `d1` kann geändert werden:

~~~{.cpp}
*q = 2;
cout << d1 << endl;
~~~

Beide Varianten können auch kombiniert werden:

~~~{.cpp}
const double* const r{&e};
~~~

Noch eine letzte Bemerkung zu der Platzierung der Symbole `*` oder `&`:
Leerraum wird auch hier ignoriert, damit könnte man auch
`const double * const r{& e};` schreiben, aber das ist aus meiner Sicht nicht
so gut zu lesen.

### Probleme im Umgang mit rohen Pointern

Mehrere Probleme können im Zusammenhang mit Pointern auftreten:

- Das Verhalten von mehrmaligem Freigeben ist nicht definiert und führt in
    der Regel zu einem Programmabsturz. Du kannst es selber ausprobieren,
    indem du die Anweisung `delete p;` ein zweites Mal in dein Programm
    einfügst. Das Programm bricht mit einer Fehlermeldung ab!

    Fügst du allerdings vor dem zweiten `delete p;` eine Anweisung zum Setzen
    des Pointers auf `nullptr` ein: `p = nullptr`, dann wird das Programm nicht
    mehr abstürzen, da ein `delete` auf einen Nullzeiger keine Wirkung hat. Das
    bedeutet, dass es sinnvoll ist, nach dem Freigeben des Speichers den
    Pointer auf "Null" zu setzen.

- Wird auf ein `delete` vergessen kommt es in der Regel zu einem Speicherleck
    (engl. *memory leak*), da das Speicherobjekt noch nicht zurückgegeben
    worden ist, aber auch nicht mehr darauf zugegriffen werden kann.

    Schreibe dazu folgende Anweisungen in dein Programm:

    ~~~{.cpp}
    {
        int* q{new int{}};
    }
    ~~~

    Es kommt zwar zu keiner zusätzlichen Ausgabe, aber es wird demonstriert,
    wie ein Speicherleck zustande kommen kann. Die Variable `q` ist eine lokale
    Variable in einem Block, da die Definition von dieser innerhalb von
    geschwungenen Klammern stehen. Der Speicher wird angefordert, aber nicht
    mehr freigegeben. Nach der geschlossenen geschwungenen Klammer steht die
    Variable `q` nicht mehr zur Verfügung, da sie den Geltungsbereich
    verlässt. Gleichzeitig wird `q` auch automatisch wieder gelöscht, jedoch
    nicht der Speicherbereich auf den `q` verweist. Damit kann auf diesen
    Speicherbereich nicht mehr zugegriffen werden.

    Damit kommt es in der Regel bei lang laufenden Programmen wie z.B. bei
    Serveranwendungen zu Problemen, weil der verfügbare Speicher immer weniger
    wird.

- Es kann zu sogenannten hängenden Zeigern (engl. *dangling pointer*) kommen,
    das sind Zeiger, die auf ein nicht mehr gültiges Speicherobjekt verweisen.
    Das Verhalten ist in so einem Fall nicht definiert, sondern
    implementierungsabhängig.

    Schauen wir uns das an, indem wir folgenden Codeteil hinten an unser
    Programm anhängen:

    ~~~{.cpp}
    p = new int{1};
    int* r{p};
    cout << "*r == " << *r << endl;
    delete p;
    cout << "*r == " << *r << endl;
    *r = 2;
    cout << "*r == " << *r << endl;
    ~~~

    Die Ausgabe sieht bei mir folgendermaßen aus:

    ~~~{.sh}
    *r == 1
    *r == 0
    *r == 2
    ~~~

    Es ist zu sehen, dass `r` auf den schon freigegebenen Speicherbereich
    verweist! Es gibt absolut keine Garantie, dass dieses Programm in
    irgendeiner Weise funktioniert. Es kann sein, dass es kurzzeitig so
    aussieht, als ob es fehlerfrei ist, aber das ist ein schwerer Fehler, der
    entweder in weiterer Folge zum Absturz oder zu falschen Ergebnissen führt!

Wir sehen, dass es hier zu Problemen kommen kann. Eigentlich ist es so, dass es
auf diese Art und Weise auch ganz sicher zu Problemen kommen wird! Daher biete
ich einige Lösungen für diese Probleme an:

a. Einfach Pointer nicht verwenden: zumindest nicht auf diese Weise.
b. In \cppXI gibt es in der Standardbibliothek sogenannte Smart-Pointer
    (eingedeutscht von *smart pointer*). Diese kümmern sich um die
    Speicherverwaltung. Wir werden diese im Abschnitt \in[smartpointer]
    auf der Seite \at[smartpointer] besprechen.
c. Ersatz der Pointer durch Referenzen, wenn dies möglich ist.
d. Muss oder will man Pointer unbedingt verwenden, dann sollte man auf das
    sogenannte RAII Prinzip zurückgreifen, dass später noch beschrieben wird.

## Array {#array}

Ein Array (eingedeutscht von engl. *array*, deutsch *Feld*) hat einen bestimmten
Typ und eine feste Größe. Es handelt sich bei diesem eingebauten Datentyp
um ein low-level Werkzeug, das eigentlich nur zur Implementierung von
Spezialdatenstrukturen verwendet werden sollte!

Arrays werden mit der folgenden Syntax definiert:

~~~{.cpp}
char firstname[10];
int results[100];
~~~

Bei der Variable `firstname` handelt es sich um ein Array von 10 `char`
Elementen und bei `results` um ein Array von 100 `int` Elementen.

Initialisieren kann man Arrays ebenfalls mit der vereinheitlichten
Initialisierung:

~~~{.cpp}
char firstname[]{'M', 'a', 'x', 0};
~~~

In diesem Fall ist eine Längenangabe innerhalb der eckigen Klammern nicht
notwendig, da der Compiler die Anzahl der Elemente selbstständig
bestimmt. Beachte in diesem Beispiel bitte, dass ein abschließendes Nullzeichen
angegeben wurde, da es sich sonst nicht um einen korrekten C-String
handelt. Denke daran, dass dieses Nullzeichen das Ende eines C-Strings markiert.

Allerdings geht es für ein Array von `char` auch einfacher:

~~~{.cpp}
char firstname[]{"Max"};
~~~

Man kann auch die Längenangabe bei einem Array mitgeben, obwohl man eine
Initialisierung vornimmt:

~~~{.cpp}
int coords[3]{1};
~~~

Hier wird die Längenangabe mitgegeben, aber nur ein Element initialisiert. Die
restlichen Elemente werden mit Nullelementen initialisiert.

Hat man ein Array statisch angelegt wie gerade gezeigt, dann kann man über
die Elemente eines solchen Arrays wie folgt iterieren:

~~~{.cpp}
// iterate_array.cpp

#include <iostream>

using namespace std;

int main() {
    int coords[3]{1};

    for (int i{0}; i < sizeof(coords) / sizeof(int); ++i) {
        cout << coords[i] << endl;
    }
}
~~~

Einfacher geht es natürlich mit der "foreach"-Variante von `for`:

~~~{.cpp}
cout << endl;

for (auto i : coords) {
    cout << i << endl;
}
~~~

Solche Arrays liegen am Stack. Will man Arrays am Heap dynamisch anfordern,
dann ist zum Anlegen der Operator `new[]` und zum Freigeben der Operator
`delete[]` zu verwenden:

~~~{.cpp}
// array.cpp
#include <iostream>

using namespace std;

int main() {
    int* points{new int[10]};

    for (int i{0}; i < 10; ++i) {
        points[i] = i;
    }

    for (int i{0}; i < 10; ++i) {
        cout << points[i] << ' ';
    }

    cout << endl;

    delete[] points;
}
~~~

Damit kann man allerdings nicht mehr die Bestimmung der Anzahl der Elemente
mittels des `sizeof` Operators verwenden und auch die "foreach"-Variante von
`for` funktioniert nicht mehr!

Dazu muss man Folgendes wissen: Ein Array wird von \cpp prinzipiell wie ein
Pointer auf das erste Element behandelt. Damit ergeben sich etliche
Fallstricke, über die man ganz nett stolpern kann:

- Wird ein Array an eine Funktion übergeben, dann wird in Wirklichkeit nur der
    Pointer an die erste Stelle übergeben. Innerhalb der Funktion kennt \cpp nur
    den Pointer! Wir haben dies schon bei der Funktion `main` bei den
    Kommandozeilenargumenten gesehen, dass zusätzlich die Anzahl der
    Arrayelemente übergeben wird.

- Eine Zuweisung von Arrays bewirkt nur die Zuweisung des einen Pointers auf
    den anderen Pointer! Das bedeutet, dass Arrays so nicht
    kopiert werden können.

- Vergleicht man zwei Arrays, dann werden nur die Pointer verglichen. Arrays
    können nur so verglichen werden, dass man selbst über alle Elemente
    iteriert und diese Elemente miteinander vergleicht.

Das bedeutet allerdings nicht, dass ein Array und ein Pointer das gleiche sind.
Schauen wir uns das an dem folgenden Beispiel an:

~~~{.cpp}
char firstname[]{"Max"};
cout << firstname << endl;
char* lastname{"Mustermann"};
cout << lastname << endl;
~~~

Die Definition mittels eines Pointers wird der Compiler unter Umständen mit
einer Warnung versehen, die besagt, dass es sich um eine veraltete
Konvertierung handelt. Abgesehen davon werden diese Anweisungen soweit
erwartungsgemäß funktionieren.

Hängt man allerdings die folgenden Zeilen an, dann wird der Unterschied
deutlich:

~~~{.cpp}
firstname[0] = 'm';
lastname[0] = 'm';
~~~

Das Programm wird sich mit sich einem Zugriffsfehler beenden. Der Grund liegt daran,
dass der Pointer `lastname` bei der Definition mit der Adresse auf den Beginn des
C-String-Literals initialisiert wurde. Wie wir später noch genauer betrachten
werden, handelt es sich bei einem C-String-Literal um ein nicht veränderbares
Array von Zeichen. Daher wäre es vernünftiger gewesen `lastname` folgendermaßen
zu definieren:

~~~{.cpp}
const char* lastname{"Mustermann"};
~~~

Damit wäre einerseits die Warnung verschwunden und andererseits hätte der
Compiler eine Fehlermeldung bei dem schreibenden Zugriff auf das Element mit
dem Index 0 erzeugt (`lastname[0] = 'm'`).

Schauen wir uns in diesem Zusammenhang die sogenannte Zeigerarithmetik *kurz*
an. Tausche in deinem Programm die gesamte zweite `for` Schleife durch folgende
Schleife aus:

~~~{.cpp}
for (int i{0}; i < 10; ++i) {
    cout << *(points + i) << ' ';
}
~~~

Was passiert hier?

- `points` wird also als Zeiger auf das erste Element betrachtet. Zu diesem
    Zeiger wird die ganze Zahl `i` hinzugezählt. Es werden aber zu der Adresse
    `points` nicht `i` Bytes hinzugezählt, sondern in unserem Fall
    `sizeof(int)` Bytes, da wir einen `int*` Pointer haben. Damit verweist
    `points + 2` auf die ganze Zahl mit dem Index 2.

- Danach wird mit dem Dereferenzierungsoperator `*` der Wert dieser Adresse
    genommen und ausgegeben. Damit funktioniert diese Schleife wie die
    vorhergehende Variante.

An sich kann man auch die Differenz von Pointern nehmen, wie z.B. `p2 - p1` und
man bekommt die Anzahl der Elemente zurück, die zwischen diesen beiden Adressen
liegen. Dazu müssen beide Pointer den gleichen Typ haben und `p2` größer als
`p1` sein.

Auf alle Zeichen von `firstname` könnten wir auch folgendermaßen zugreifen:

~~~{.cpp}
for (char* p{firstname}; *p != 0; ++p)
    cout << *p;
~~~

Hier nützen wir aus, dass ein C-String mit einem Nullzeichen abgeschlossen
wird. Ansonsten funktioniert `++p` wie vorhin besprochen.

Als Benutzer greift man **immer** auf die Datentypen `std::vector` oder
`std::array` zurück. Allerdings ist es wichtig das Konzept des Arrays
verstanden zu haben, da viele Datentypen der Standardbibliothek mit Arrays
arbeiten und Funktionen der Programmiersprache `C` nur mit solchen Arrays
arbeiten. Solche Funktionen der Programmiersprache `C` können in \cpp ohne
Probleme verwendet werden. Sie stehen in Headerdateien zur
Verfügung, die in der Regel mit einem "c" beginnen wie bei der Headerdatei
`cmath`.

Eine offensichtliche Verwendung von Arrays haben wir schon bei der Verwendung
von Kommandozeilenargumenten gesehen. Die Kommandozeilenparameter werden als
Array von Pointern auf `char` an die Funktion `main` übergeben. Zusätzlich
wird die Anzahl der Argumente als Parameter übergeben.

### String-Literale

Dazu müssen wir uns außerdem ansehen welchen Typ C-String-Literale in \cpp
haben. Der C-String-Literal `"C++"` hat den Typ `const char[4]`. Das bedeutet,
dass es sich um ein Array mit 4 Elementen vom Typ `char` handelt, die nicht
verändert werden können. 4 Elemente deshalb, weil zu den drei vorhandenen
Zeichen noch das abschließende Nullzeichen `'\0'` als Endekennung angehängt
wird. So eine Endekennung ist notwendig, da keine explizite Längeninformation
gespeichert wird.

In einem String-Literal können die gleichen Escape-Sequenzen verwendet werden
wie bei den Zeichenliteralen (im Abschnitt \in[characterliterals] beschrieben).

String-Literale, die nur durch Whitespace getrennt sind, werden vom Compiler
aneinandergehängt. Betrachte folgendes Beispiel:

~~~{.cpp}
// stringliterals.cpp
#include <iostream>

using namespace std;

int main() {
    const char* alphabet;
    alphabet = "abcdefghijklmnopqrstuvwxyz\n"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << alphabet << endl;
}
~~~

Dieses Beispiel zeigt auch, dass natürlich ein Zeilenumbruch direkt in ein
C-String-Literal mittels `\n` eingefügt werden kann. Bei der Ausgabe wirkt sich
dieser Zeilenumbruch natürlich entsprechend aus.

Weiters sieht man in diesem Beispiel, dass aufeinanderfolgende
C-String-Literale vom Compiler zu einem C-String verkettet werden.

Trotzdem gibt es eine einfachere, elegantere Möglichkeit, nämlich die rohen
C-String-Literale (engl. *raw character strings*). Diese sehen so aus, dass dem
C-String-Literal der Präfix `R` vorangestellt wird und der eigentliche Inhalt
der Zeichenkette in ein rundes Klammernpaar eingeschlossen wird. Zur
Veranschaulichung probiere es aus, indem du den folgenden Quelltext hinten an das
Programm anhängst:

~~~{.cpp}
    alphabet = R"(abcdefghijklmnopqrstuvwxyz"\n
ABCDEFGHIJKLMNOPQRSTUVWXYZ)";
    cout << endl << alphabet << endl;
~~~

Du siehst hier mehrere interessante Eigenheiten dieser rohen C-String-Literale:

- Es kommt ein doppeltes Hochkomma im String-Literal vor.
- Das String-Literal erstreckt sich über zwei Zeilen.
- Und es kommt das Escape-Zeichen im String vor, das keine Auswirkung hat.

Nicht schlecht, aber vielleicht stellst du dir jetzt die Frage, wie man in
einen solchen String die Zeichenfolge `)"` packt, da diese ja das Ende des
C-String-Literals kennzeichnet?

Dafür gibt es eine erweiterte Syntax, sodass man die Begrenzungszeichen
verändern kann, indem man der offenen runden Klammer eine Zeichenkette
voranstellt, die der schließenden runden Klammer hinten ebenfalls angehängt
wird. Schauen wir uns das praktisch an, indem du die folgenden Zeilen an dein
Programm anhängst:

~~~{.cpp}
    alphabet = R"=(abcdefghijklmnopqrstuvwxyz)"\n
ABCDEFGHIJKLMNOPQRSTUVWXYZ)=";
    cout << endl << alphabet << endl;
~~~

Es gibt allerdings auch noch andere Präfixe, die ähnlich den Zeichenliteralen
funktionieren:

- `u8` bezeichnet einen UTF-8 String, wie z.B. `u8"Müßiggang"`, wobei davon
    ausgegangen wird, dass die Umlaute in UTF-8 kodiert sind. Alternativ kann
    auch UTF-8 kodierte Zeichen mittels Escape-Zeichen einfügen:

    ~~~{.cpp}
    cout << u8"Müßiggang" << endl;
    cout << u8"M\xc3\xbcßiggang" << endl;
    ~~~

- `u` bezeichnet einen UTF-16 String und funktioniert analog zu `u8`

- `U` bezeichnet einen UTF-32 String mit analoger Funktionsweise zu `u8` und
    `u`.

- `L` bezeichnet einen `wchar_t` string.

Jeder dieser Präfixe kann mit dem Präfix `R` kombiniert werden: `u8R`, `uR`,
`UR` und `LR`.


### Initialisierung

Wir haben schon die Faustregel kennengelernt, dass immer initialisiert werden
soll. Als Ausnahme kann das Anlegen eines großen Speicherobjektes angesehen werden,
das *zuerst* befüllt wird und erst *danach* wieder gelesen wird. Es macht daher
keinen Sinn, das Speicherobjekt zuerst zu initialisieren und danach zu
befüllen:

~~~{.cpp}
// large_buffer.cpp
#include <iostream>
#include <chrono>

using namespace std;

int main() {
    constexpr size_t max{100000};

    auto start = chrono::system_clock::now();

    for (int i{0}; i < max; ++i) {
        long long buffer[max];
    }

    auto end = chrono::system_clock::now();
    auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << elapsed.count() << "ms" << endl;
}
~~~

Als Ausgabe erhalte ich:

~~~{.sh}
0ms
~~~

Hier verwende ich Möglichkeiten der Zeitmessung aus der Standardbibliothek. Wir
werden uns dies in weiterer Folge später ansehen.

Ändere jetzt den Quelltext so um, dass der Puffer *initialisiert* wird:

~~~{.cpp}
long long buffer[max]{};
~~~

Die Ausgabe auf meinem Rechner sieht zum Beispiel so aus:

~~~{.sh}
2593ms
~~~

Man sieht, dass die zeitliche Differenz in Spezialfällen durchaus beachtlich
ausfallen kann!

## Referenz {#reference}

Wie schon erwähnt, ist eine Referenz nichts anderes als ein anderer Namen für
eine Speicherstelle.

Schauen wir uns dazu noch einmal ein einfaches Beispiel an:

~~~{.cpp}
// lreference.cpp
using namespace std;

int main() {
    int x{1};
    int& r{x};

    r = 2;
    cout << "x = " << x << endl;
}
~~~

Da es sich bei `r` um eine Referenz also einen anderen Namen für die
Speicherstelle von `x` handelt, wird bei einer Veränderung mittels `r` in
Wirklichkeit der Wert von `x` verändert.

Wir erkennen also, dass wir das Beispiel auch mit Hilfe von Zeigern
programmieren hätten können:

~~~{.cpp}
int* p{nullptr};
p = &x;
*p = 3;
cout << "x = " << x << endl;
~~~

Es gibt allerdings ein paar nicht unbedeutende Unterschiede zwischen der
Verwendung von Zeigern und Referenzen:

- Offensichtlich ist die Syntax verschieden: `r = 2;` im Vergleich zu `*p = 3`!

    Hier sieht man schön, dass die Syntax eines Pointers anders ist und auch,
    dass Pointer umständlicher zu verwenden sind.

- Ein Pointer kann zu verschiedenen Objekten zu verschiedenen Zeitpunkten
    zeigen, während eine Referenz bei der Definition initialisiert werden muss
    und in weiterer Folge nicht mehr verändert werden kann.

    Besteht also die Notwendigkeit, dass zu verschiedenen Zeiten auf
    verschiedene Objekte zugegriffen werden muss, dann muss man sich für
    Pointer entscheiden.

- Ein Pointer kann den Nullwert haben, während eine Referenz immer
    initialisiert werden muss. Damit muss man sich bei einer Referenz keine
    Gedanken machen, ob diese initialisiert wurde oder nicht.

    Aus diesem Gesichtspunkt betrachtet ist es sicherer, eine Referenz zu
    verwenden.

- Ein Zugriff über eine Referenz kann in bestimmten Fällen ohne Indirektion
    erfolgen, da die Referenz nichts anderes als ein anderer Name ist.

    Die Indirektion über einen Pointer funktioniert folgendermaßen: Bei einem
    Pointer muss zuerst auf den Wert des Pointers zugegriffen werden, dann muss
    dieser Wert als Adresse interpretiert werden und danach kann auf die
    Speicherstelle zugegriffen werden, die diese Adresse hat und der Wert der
    Speicherstelle ausgelesen oder verändert werden.

    Ist die Performance das vorrangige Ziel, dann spricht das für die
    Verwendung von Referenzen.

    Bei Verwendung von Referenzen respektive Pointern bei der Parameterübergabe
    an Funktionen gibt es diesbezüglich keinen Unterschied!

- Da es sich bei einer Referenz nicht um ein Objekt im Sinne einer "normalen"
    Variablendefinition handelt, kann man keinen Pointer auf eine Referenz
    haben und auch kein Array von Referenzen anlegen!

    Ist daher der Bedarf gegeben, dass man den Zugriff über eine doppelte
    Indirektion herstellen muss oder muss man ein Array verwenden, dann ist die
    Verwendung von Pointern obligatorisch.

Es gibt prinzipiell zwei Arten von Referenzen:

- lvalue Referenz (engl. *lvalue reference*) ist eine Referenz auf einen
    lvalue. Das haben wir uns gerade angesehen.

- rvalue Referenz (engl. *rvalue reference*) ist eben eine Referenz auf einen
    rvalue.

### lvalue Referenz {#lvalueref}

Eine lvalue Referenz kann entweder ohne `const` oder mit `const` auftreten.

Wird die lvalue Referenz ohne `const` verwendet, d.h. so wie wir das bis jetzt
betrachtet haben, dann muss diese Referenz mit einem lvalue des entsprechenden
Typs initialisiert werden. Das bedeutet, dass der Compiler die folgende
Deklaration beanstanden wird:

~~~{.cpp}
int* q{nullptr};
int& r1{0};
int& r2{q};
~~~

Bei `r1` wird nicht mit einem lvalue initialisiert und bei `r2` stimmt der Typ
der Referenz von `r2` (`int`) nicht mit dem Typ des lvalue (`int*`) überein!

Bei einer lvalue Referenz mit `const` muss der Initialisierer nicht ein lvalue
sein und nicht einmal mit dem Typ übereinstimmen. In solchen Fällen wird
vom Compiler folgendermaßen vorgegangen:

a. Zuerst wird eine implizite Konvertierung durchgeführt, sodass die Typen
    übereinstimmen.
b. Dann wird der erhaltene Wert in einer temporären Variable abgelegt.
c. Diese temporäre Variable wird zur Initialisierung der Referenz
    verwendet. Die Lebenszeit solch einer temporären Variable endet, wenn die
    Referenz den Geltungsbereich verlässt.

Schauen wir uns dazu die folgenden Codezeilen an:

~~~{.cpp}
{
    const int& r{1};
    cout << r << endl;
}
~~~

Die temporäre Variable, die intern angelegt wird, wird bei der geschlossenen
geschwungenen Klammer des Blockes wieder entfernt.

lvalue Referenzen werden oft im Zuge von "foreach" Schleifen verwendet. Hänge
den folgenden Code hinten an die Datei an:

~~~{.cpp}
string long_names[]{"maxi", "mini", "otto"};

for (const auto& name : long_names) {
    cout << name << endl;
}
~~~

- Zuerst wird ein Array von `string` Objekt angelegt, wobei jedes einzelne
    `string` Objekt aus einem C-String-Literal erzeugt wird.

- Der interessante Teil betrifft die Laufvariable. Prinzipiell teilen wir dem
    Compiler mit, dass er den Typ selbst eruieren soll, aber wir wollen den
    Wert der Laufvariable nicht ändern (`const`) und außerdem wollen wir, dass
    eine lvalue Referenz verwendet wird.

    Das bewirkt, dass die Strings nicht kopiert werden, sondern lediglich das
    `string` Objekt aus dem Array direkt verwendet wird. Bei wirklich
    langen Namen erspart man sich sehr viel an Speicher, der zuerst
    angefordert, dann kopiert und am Ende des Schleifendurchganges wieder
    freigegeben werden muss. Das wird sich in der Regel auch in der Laufzeit
    entsprechend auswirken.


### rvalue Referenz {#rvalueref}

Eine rvalue Referenz referenziert einen rvalue, der entsteht, wenn ein
temporäres Objekt im Zuge der Auswertung eines Ausdrucks entsteht. Auch eine
rvalue Referenz muss bei der Definition initialisiert werden, nämlich mit einem
rvalue!

Schauen wir uns dazu einmal folgendes Programm an, das vorerst
ohne Referenz auskommt:

~~~{.cpp}
// rreference.cpp
#include <iostream>

using namespace std;

string f() {
    return "f()"; 
}

int main() {
    string res{f()};
    cout << res << endl;
}
~~~

Das Interessante ist, welche Objekte beim Aufruf der Funktion `f` erzeugt
werden:

a. Zuerst wird bei der `return`-Anweisung aus dem C-String-Literal ein
    temporäres Objekt vom Typ `string` angelegt.

b. Dann wird dieses Objekt an den Aufrufer zurückgegeben. Dazu muss eine Kopie
    erstellt werden, die in der Funktion `main` auf der rechten Seite der
    Zuweisung `res = f()` zur Verfügung steht.

c. Beim Ausführen der Initialisierung muss das zurückgegebene temporäre Objekt
    wiederum in das Zielobjekt `res` kopiert werden.

Es steht dem Compiler frei mittels Optimierungen temporäre Objekte zu
vermeiden, aber ohne temporäre Objekte geht es in diesem Fall nicht. Besonders den
letzten Schritt wird ein Compiler wegoptimieren, wodurch faktisch nur mehr zwei
Kopieraktionen über bleiben. Wir werden uns das im Zuge der Behandlung des
Kopierkonstruktors im Abschnitt \in[copyandmove] noch genauer ansehen.

Ändere jetzt den Typ von `res` auf `string&` um:

~~~{.cpp}
string& res{f()};
~~~

Der Compiler wird das Programm nicht mehr übersetzen, da es sich bei dem
Wert des Ausdruckes von `f()` nicht um einen lvalue sondern um eine
lvalue-Referenz handelt!

Ändere das Programm so ab, dass eine rvalue-Referenz als Typ von `res`
verwendet, also `string&&` wird:

~~~{.cpp}
string&& res{f()};
~~~

Das Programm funktioniert wieder wie zuvor! Warum also rvalue-Referenzen
verwenden und nicht einfach `string res{f()};`? Wir haben schon gesehen, dass
bis zu drei Mal kopiert werden muss. Handelt es sich um ein großes Objekt, dann
können diese Kopieraktionen durchaus ins Gewicht fallen. Verwendet man eine
rvalue-Referenz, dann kann der Compiler in diesem Fall eine Kopieraktion durch eine
Verschiebeaktion austauschen. Bei einer Verschiebeaktion wird der Inhalt des
Objektes nicht kopiert, sondern in das neue Objekt verschoben. Wir werden uns
das noch genauer im Abschnitt \in[copyandmove] ansehen.

Damit erkennen wir, dass es für \cpp Sinn macht sowohl lvalue-Referenzen
als auch rvalue-Referenzen im Repertoire zu haben:

- Eine nicht-konstante lvalue-Referenz bezieht sich auf ein Objekt, das vom
    Benutzer beschrieben werden kann.

- Eine konstante lvalue-Referenz verweist auf eine Konstante, die aus Sicht
    des Benutzers der Referenz nicht veränderbar ist.

- Eine rvalue-Referenz bezieht sich auf ein temporäres Objekt, das verändert
    werden kann, da es nicht mehr benützt wird. Ein temporäres Objekt kann
    nicht mehr benützt werden, da es keine Möglichkeit gibt auf dieses Objekt
    in weiterer Folge zuzugreifen. Damit können die Daten, die in diesem Objekt
    gespeichert sind, verschoben werden und müssen nicht kopiert werden.

Verwenden wir explizit rvalue-Referenzen, dann kann der Compiler
Verschiebeaktionen durchführen, wenn diese möglich sind. Manchmal ist es jedoch
so, dass wir wissen, dass ein Verschieben möglich ist, der Compiler dies jedoch
nicht erkennen kann. In so einem Fall müssen wir dem Compiler die
entsprechenden Informationen liefern.

Nehmen wir einmal an, dass wir eine ganz "normale" Funktion zum Vertauschen der
Argumente schreiben wollen. Solch eine Funktion wird oft "swap" genannt.

~~~{.cpp}
#include <iostream>

using namespace std;

void swap(string& a, string& b) {
    string tmp{a};
    a = b;
    b = tmp;
}

int main() {
    string s1{"foo"};
    string s2{"bar"};

    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    swap(s1, s2);
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
}
~~~

Die Ausgabe schaut wie erwartet folgendermaßen aus:

~~~{.sh}
s1 = foo
s2 = bar
s1 = bar
s2 = foo
~~~

Die Funktion `swap` bekommt ihre beiden Parameter als Referenz, womit auch in
gewisser Weise die Funktion zwei Werte zurückgeben kann. Der eigentliche
Rückgabewert wurde hier nicht verwendet. Damit einhergehend kommen auch keine
Kopieraktionen bei der Übergabe der beiden Parameter zustande.

Das klingt gut, aber leider kommt es sehr wohl zu Kopieraktionen, da bei der
Initialisierung der Variable `tmp` die erste Kopieraktion durchgeführt wird,
bei der Zuweisung an `a` und danach an `b` die nächsten beiden Kopieraktionen!

Wenn man sich überlegt, dass wir eigentlich die Variablen nicht kopieren wollen,
sondern nur deren Inhalte verschieben, dann müssen wir unsere Funktion
auf die Verwendung von rvalue-Referenzen umstellen:

~~~{.cpp}
void swap(string& a, string& b) {
    string tmp{static_cast<string&&>(a)};
    a = static_cast<string&&>(b);
    b = static_cast<string&&>(tmp);
}
~~~

Diese Umstellung bewirkt, dass nicht mehr die Inhalte der Strings kopiert
werden, sondern die Inhalte verschoben werden:

- Nach der Initialisierung der Variable `tmp` hat die Variable `a` keinen
    Inhalt mehr, da dieser zur Variable `tmp` verschoben wurde.

    Das wird vom Compiler deshalb durchgeführt, da die Variable `a` explizit zu einer
    rvalue-Referenz konvertiert wird. Damit kann der Compiler eine spezielle
    Operation zur Initialisierung von `tmp` aufrufen, die die Klasse `string`
    zur Verfügung stellt und die Verschiebe-Operation durchführt.

    Wie diese spezielle Verschiebe-Operation genau aussieht und wie man eine
    solche selber programmieren kann, werden wir uns im Abschnitt
    \in[copyandmove] noch detailliert ansehen.

- Bei den Zuweisungen zu den Variablen `a` und `b` funktioniert dies ähnlich,
    nur dass diese Variablen nicht initialisiert werden, sondern
    zugewiesen. Aufgrund der Konvertierung zu einer rvalue-Referenz kann der
    Compiler eine spezielle Operation zur Zuweisung aufrufen, die die Klasse
    `string` ebenfalls zur Verfügung stellt und wiederum die
    Verschiebe-Operation durchführt.

Damit kommt diese Funktion ohne aufwändige Kopieroperationen aus! Das ist nun
einmal nicht so schlecht, allerdings ist die Notation nicht gerade einfach und
eingängig. Deshalb stellt die Standardbibliothek eine Funktion `move` im Header
`<utility>` (wird schon von `<iostream>` inkludiert) zur Verfügung, die nichts
anderes macht, als die Konvertierung in eine rvalue-Referenz vorzunehmen:

~~~{.cpp}
void swap(string& a, string& b) {
    string tmp{move(a)};
    a = move(b);
    b = move(tmp);
}
~~~

Damit schaut die Funktion schon viel übersichtlicher aus und bewirkt genau das
Gleiche! Vielleicht könnte man meinen, dass damit die Performance leidet, da
zusätzliche Funktionen aufgerufen werden, aber dem ist nicht so! Die Funktionen
werden vom Compiler aufgerufen und nicht zur Laufzeit. Solche Funktionen
werden wir uns detailliert im Abschnitt \in[functiontemplates] ansehen.

Aber es geht eigentlich noch viel einfacher, weil eine solche Funktion `swap`
schon im Header `utility` vorhanden ist, die mit prinzipiell *allen* Typen
umgehen kann. Auch so etwas werden wir uns im Abschnitt \in[functiontemplates] noch
genauer ansehen.

Damit du die eingebaute Funktion `swap` verwenden kannst, brauchst du nur die
Definition der selbst geschriebenen Funktion `swap` aus deinem Programm löschen!

## Smart-Pointer {#smartpointer}

Smart-Pointer stellen eine Möglichkeit dar, mit den besprochenen Problemen beim
Umgang mit rohen Pointer, zu handhaben. Diese Smart-Pointer haben den Zweck, sich
um die Speicherverwaltung zu kümmern und sicherzustellen, dass der Speicher
genau zum richtigen Zeitpunkt wieder freigegeben wird.

Smart-Pointer stellen also eine Abstraktionsschicht zur Verfügung, die die Freigabe
des Speichers in die Implementierung des Smart-Pointers verlagert. Das Prinzip
ist, dass der Speicher freigegeben wird, wenn die Variable des Smart-Pointers
den Block verlässt, in dem diese definiert wird.

Die Standardbibliothek von \cppXI stellt verschiedene Arten von Smart-Pointer
zur Verfügung, die wir uns in Folge ansehen werden.

### `unique_ptr`

Zuerst wollen wir uns dem sogenannten "eindeutigen Smart-Pointer" `unique_ptr`
(engl. *unique pointer*) zuwenden, den wir ab jetzt einfach mit Unique-Pointer
bezeichnen wollen.

Dieses "unique" bedeutet, dass dieser Smart-Pointer für das Speicherobjekt auf
das dieser verweist, die Verantwortung übernimmt. Der Smart-Pointer "besitzt"
das Speicherobjekt. Das bedeutet, dass dieser Smart-Pointer die Verantwortung
über die korrekte Entfernung des Speicherobjektes übernimmt. Weiters gibt es
exakt eine Kopie von dieser Art von Smart-Pointer zu einer Zeit. Was dies genau
bedeutet werden wir uns jetzt ansehen.

Schauen wir uns dazu vorerst das einfachste Beispiel an und gehen die
verschiedenen Aspekte nach und nach durch.

Zuerst wollen wir den Fall durchspielen, dass vergessen wurde den Speicher
freizugeben. Unter Verwendung von `unique_ptr` kann dies nicht mehr passieren:

~~~{.cpp}
// smartpointer.cpp
#include <iostream>
#include <memory>

using namespace std;

int main() {
    {
        unique_ptr<int> pi{new int{1}};
    }
}
~~~

Es ist klar, dass dieses Programm keine besondere Funktionalität hat, trotzdem
folgt hier eine Erklärung der Funktionsweise:

- Zuerst wird die Headerdatei `memory` eingebunden, die die verschiedenen Arten
    der Smart-Pointer zur Verfügung stellt.

- Dann wird innerhalb von `main` ein Block erzeugt, der uns zeigen soll, dass
    der Speicher wieder freigegeben wird.

- Innerhalb dieses Blockes wird ein `unique_ptr` angelegt, der auf einen `int`
    verweisen kann. Zusätzlich wird dieser mit einem Pointer auf ein neu
    am Heap angelegtes `int`-Objekt initialisiert. Damit übernimmt dieser
    Smart-Pointer die Kontrolle über das Speicherobjekt.

- Beim Verlassen des Blockes endet die Lebenszeit des Smart-Pointers und es
    wird dieser entfernt. Beim Entfernen des Smart-Pointers wird eine spezielle
    Funktion (der Destruktor, siehe später) aufgerufen, der den Speicher des
    Speicherobjektes wieder freigibt. Damit gibt es keine Möglichkeit mehr,
    das Freigeben des Speichers zu "vergessen".

Natürlich kann man argumentieren, dass man "eh nicht vergisst". Ja, aber
schwieriger wird es, wenn Pointer an Funktionen übergeben werden oder von
Funktionen zurückgeliefert werden. Es müsste nämlich geklärt sein, wer für sich
für das Speicherobjekt verantwortlich fühlt und sich letztendlich um die
Freigabe des Speichers kümmert.

Bevor wir uns allerdings noch genauer mit den verschiedenen Möglichkeiten des
Einsatzes von Smart-Pointer auseinandersetzen, wollen wir uns vorerst die Frage
stellen, wie man eigentlich auf das referenzierte Speicherobjekt zugreift. Die
Antwort ist einfach: Wie bei einem normalen Pointer!

Füge einfach die nachfolgende Ausgabezeile direkt hinter der Definition des
`unique_ptr` an und probiere es aus:

~~~{.cpp}
cout << *pi << endl;
~~~

Wir sehen, dass der Operator `*` offensichtlich auch für Smart-Pointer
überladen wurde, damit diese sich wie echte Pointer verhalten.

Wer ist nun für die Freigabe eines Speicherobjektes am Heap verantwortlich?
Schauen wir uns vorerst dazu die folgende Situation für normale Pointer an:

~~~{.cpp}
void use_ptr(int* pi) {
    cout << *pi << endl;
}

int* pi{new int{2}};
use_ptr(pi);
~~~

Die Frage ist, wer sich um die Freigabe des Speichers kümmern soll? Die
Funktion `use_ptr` oder der Aufrufer? Was wenn beide den Speicher wieder
freigeben oder wenn keiner den Speicher freigibt. Was passiert, wenn die
Funktion den Speicher freigibt, aber der Aufrufer noch auf den Speicher
zugreifen will?

Weiters könnte es sein, dass die Funktion `use_ptr` eine Kopie des übergebenen
Pointers anlegt und diesen später weiterverwendet? Das betrifft hauptsächlich
die Situation, wenn es sich bei der Funktion um eine Methode (engl. *method*,
in \cpp meist *member function* genannt) handelt.

Damit kommen wir zur eigentlichen Fragestellung, nämlich, wer die
Eigentümerschaft über den Pointer erhält: Der Aufrufer oder die aufgerufene
Funktion? Die Antwort kann natürlich je nach Anwendungsfall unterschiedlich
sein. Es muss lediglich klar sein, wer die Verantwortung hat und derjenige Teil
muss sich um die Freigabe kümmern. Und nach einer Freigabe darf der andere Teil
nicht mehr auf das Speicherobjekt zugreifen.

Auch hier kann man `unique_ptr` einsetzen!

Schaue dir dazu die folgende naheliegende Lösung an:

~~~{.cpp}
// unique_ptr.cpp
#include <iostream>
#include <memory>

using namespace std;

void use_ptr(unique_ptr<int> upi) {
    cout << *upi << endl;
}


int main() {
    unique_ptr<int> upi{new int{1}};
    use_ptr(upi);
}
~~~

Diese Lösung lässt sich jedoch, aus gutem Grund, nicht übersetzen. Das liegt
daran, dass man `unique_ptr` nicht kopieren kann. Könnte man Unique-Pointer
kopieren, dann wäre in diesem Fall kein Unterschied zu einem normalen Pointer
gegeben! Und damit einhergehend wäre wiederum nicht klar, wer die Verantwortung
für diesen Pointer hätte.

Eine einfache Lösung ist, keine Kopie des Smart-Pointers übergeben zu wollen,
sondern eine Referenz. Wird eine Referenz übergeben, dann bedeutet das, dass
die Adresse des Smart-Pointers an die Funktion übergeben wird. Damit lässt sich
das Beispiel jetzt übersetzen:

~~~{.cpp}
void use_ptr(unique_ptr<int>& upi) {
~~~

Die Bedeutung dieser Änderung ist, dass der Aufrufer weiterhin die
Verantwortung über den Smart-Pointer behält.

Was jedoch, wenn der Aufrufer die Kontrolle über den Smart-Pointer an die
Funktion übergeben will? In diesem Fall muss man folgendermaßen vorgehen:

~~~{.cpp}
void use_ptr(unique_ptr<int> upi) {
    cout << *upi << endl;
}


int main() {
    unique_ptr<int> upi{new int{1}};
    use_ptr(move(upi));
    cout << ((upi.get() == nullptr) ? 0 : *upi) << endl;
}
~~~

Was passiert?

- Zuerst sehen wir, dass die Funktion den eigentlichen Unique-Pointer wieder
    ohne Referenz erhält. Das bedeutet, dass eine Kopie am Stack übergeben
    wird. Allerdings haben wir gesehen, dass man einen Unique-Pointer nicht
    als Kopie übergeben kann.

- Im Aufruf der Funktion sehen wir, dass der Unique-Pointer jetzt in einen
    Aufruf der Funktion `move()` gekapselt ist. Damit wird aus dem lvalue
    `upi` vom Typ `unique_ptr<int>` ein rvalue vom Typ `unique_ptr<int>&&`.
    Damit kann der Inhalt, also der rohe Pointer, in
    den Parameter `upi` der Funktion `use_ptr` verschoben werden.

- In der Funktion `use_ptr` ist das Argument `upi` jetzt im Besitz des
    verschobenen rohen Pointers. Am Ende der Funktion endet auch die Lebenszeit
    des Argumentes `upi` und damit wird auch der Speicher freigegeben auf den
    der rohe Pointer verweist.

- Die Ausgabe wird folgendermaßen aussehen:

    ~~~{.sh}
    1
    0
    ~~~

    Das liegt eben daran, dass der rohe Pointer in den Parameter der Funktion
    verschoben worden ist. Bei dieser Verschiebe-Operation wurde der alte rohe
    Pointer auf den Wert `nullptr` gesetzt. Mittels `get` erhält man den rohen
    Pointer.

Der Typ `unique_ptr` kennt noch weitere Methoden und überladene Methoden.

Leider kann es noch zu folgendem Problem kommen, dass Exceptions auftreten
und Speicher nicht freigegeben wird, obwohl man Unique-Pointer verwendet:

~~~{.cpp}
void use_ptr(unique_ptr<Game> a, unique_ptr<Game> b);

// Verwendung:
use_ptr(unique_ptr<Game>{new Game{1}},
        unique_ptr<Game>{new Game{2}});
~~~

Bei Game soll es sich um einen benutzerdefinierten Datentyp handeln, der über
einen Konstruktor verfügt. Wir gehen davon aus, dass dieser Konstruktor unter
Umständen auch eine Exception werfen kann.

Das Problem liegt wiederum darin, dass der Compiler die Ausdrücke auswerten
darf wie er möchte. Das bedeutet, dass es zu folgender Auswertungsreihenfolge
kommen könnte:

a. Speicher für das erste `Game`-Objekt anfordern
b. Konstruktor für `Game{1}` ausführen
c. Speicher für das zweite `Game`-Objekt anfordern
d. Konstruktor für `Game{2}` ausführen
e. `unique_ptr<Game>` für erstes `Game`-Objekt anlegen
f. `unique_ptr<Game>` für zweites `Game`-Objekt anlegen
g. `use_ptr` aufrufen

Jetzt könnte es sein, dass zum Beispiel beim Anfordern des Speichers für das
zweite `Game`-Objekt eine Exception geworfen wird oder der Konstruktor
`Game{2}` eine Exception wirft. Dann ist ein Speicherleck entstanden, da das
erste `Game`-Objekt nicht mehr freigegeben worden ist.

Es gibt prinzipiell zwei Lösungen:

- Man zerlegt diesen Aufruf der Funktion `use_ptr` in mehrere Anweisungen:

    ~~~{.cpp}
    unique_ptr<Game> game1{1};
    unique_ptr<Game> game2{2};
    use_ptr(move(game1), move(game2));
    ~~~

- Ab \cppXIV gibt es noch die Funktion `make_unique`, die folgendermaßen
    verwendet werden kann und diese Probleme nicht aufweist:
  
    ~~~{.cpp}
    use_ptr(make_unique<Game>(1), make_unique<Game>(2));
    ~~~

    Steht noch kein \cppXIV Compiler zur Verfügung, dann kann man diese
    Funktion als Template leicht selber definieren:

    ~~~{.cpp}
    template<typename T, typename... Args>
    std::unique_ptr<T> make_unique(Args&&... args) {
        return {new T(std::forward<Args>(args)...)};
    }
    ~~~


### `shared_ptr`

Komplizierter wird die Situation, wenn man die Verantwortung über den Speicher
aufteilen muss, da keinem Objekt die klare Verantwortung zugewiesen werden
kann. Das bedeutet, dass der Besitz eines Speichers aufgeteilt wird. Aus genau
diesem Grund wird so ein Smart-Pointer als Shared-Pointer bezeichnet.

Angelegt werden kann ein Shared-Pointer wie ein Unique-Pointer:

~~~{.cpp}
// shared_ptr.cpp
#include <iostream>
#include <memory>

int main() {
    shared_ptr<int> spi{new int{1}};
}
~~~

Die Unterschiede werden allerdings erst dann sichtbar, wenn Shared-Pointer
kopiert werden:

~~~{.cpp}
cout << spi.use_count() << endl;
{
    shared_ptr<int> spi2{spi};
    cout << spi2.use_count() << endl;
}
cout << spi.use_count() << endl;
~~~

Die Ausgabe wird folgendermaßen aussehen:

~~~{.sh}
1
2
1
~~~

Was bedeutet diese Ausgabe und was passiert in dem Programm?

- Die erste Ausgabe bedeutet, dass es einen Akteur gibt, der auf die ganze Zahl
    1 zugreifen kann, die am Heap liegt. Anders ausgedrückt: Es gibt genau
    einen Besitzer dieses Speicherobjektes.

- Danach wird innerhalb eines Blockes eine weitere lokale Shared-Pointer
    Variable `spi2` angelegt und mit einer Kopie von `spi` initialisiert.
    Du siehst, dass man Shared-Pointer sehr wohl kopieren kann.

- Die nachfolgende Ausgabe von 2 zeigt uns an, dass es jetzt 2 Besitzer
    dieses Speicherobjektes gibt. Diese Ausgabe zeigt uns, dass mit dem
    Initialisieren von `spi2` durch eine Kopie von `spi` erkannt worden ist,
    dass die Anzahl der Besitzer um eins erhöht hat.

- Die letzte Ausgabe zeigt uns, dass es nur mehr einen Besitzer gibt. Das
    bedeutet, dass es mit dem Entfernen der lokalen Variable `spi2` auch
    einen Besitzer weniger gibt.

Analog zu Unique-Pointern ist es so, dass das Speicherobjekt freigegeben wird,
wenn es keine Besitzer mehr gibt!

Zusätzlich zum Kopieren von Shared-Pointern ist es auch möglich diese zu
verschieben, wie wir es schon von den Unique-Pointern kennen. Weiters gibt es,
wie bei Unique-Pointer, die gewohnten überladenen Operatoren und auch weitere
Methoden.

Ab \cppXI gibt es, analog zu `make_unique` in \cppXIV, eine Funktion
`make_shared`, die ähnliche Funktionalität hat:

~~~{.cpp}
auto point = make_shared<double>(2.5);
~~~

Zusätzlich zu dem Vorteil, dass die Verwendung dieser Funktion für sicheres
Verhalten auch im Falle von Exceptions sorgt, ist diese auch von der
Performance dem expliziten Anlegen mittels `shared_ptr<double>{new
double{2.5}}` vorzuziehen.

Wenn wir uns die Implementierung benutzerdefinierter Datentypen wie Klassen
ansehen, dann bekommen die Shared-Pointer mehr an Bedeutung.

Wie wird jedoch diese Funktionalität implementiert? Im Standard ist keine
Implementierung vorgeschrieben, aber die gängigen Implementierungen verwenden
einen Referenzzähler, der die Anzahl der Referenzen zählt.

Es kann ein Problem im Zusammenhang mit Shared-Pointern geben, nämlich, wenn
es einen Zyklus in der Verwendung gibt. Schauen wir uns dazu folgendes Beispiel
an:

~~~{.cpp}
// shared_ptr_cycle.cpp
struct Engine;

struct Ship {
    shared_ptr<Engine> engine;
    ~Ship() {
        cout << "Ship destructed" << endl;
    }
};

struct Engine {
    shared_ptr<Ship> ship;
    ~Engine() {
        cout << "Engine destructed" << endl;
    }
};

int main() {
    {
        shared_ptr<Ship> ship{new Ship};
        shared_ptr<Engine> engine{new Engine};
        cout << ship.use_count() << ", "
             << engine.use_count() << endl;
        ship->engine = engine;
        engine->ship = ship;
        cout << ship.use_count() << ", "
             << engine.use_count() << endl;
    }
    Ship ship2;
}
~~~

Wir finden hier eine neue syntaktische Notation: Man kann innerhalb eines
`struct` auch Funktionen anschreiben, die in diesem Fall Methoden genannt
werden (siehe Abschnitt \in[memberfunctions]). Eine spezielle Methode ist der
Destruktor, den wir erstmals im Abschnitt \in[storageobject] kennengelernt
haben und innerhalb einer Klasse (hier `struct`) mittels einer Tilde `~`
gekennzeichnet ist. Dieser Destruktor wird eben aufgerufen, wenn das Objekt
entfernt wird und ist dafür da, noch benutzerdefinierte Aufräumaktionen
durchzuführen. Genauer werden wir uns dies noch im Abschnitt
\in[constructor] ansehen.

Nach dem Verlassen des Blockes werden wir ein Speicherleck haben, das auch sehr
schön in der Ausgabe zu erkennen ist:

~~~{.sh}
1, 1
2, 2
Ship destructed
~~~

Diese Ausgabe kommt alleinig von der Instanzvariable `ship2`! Wie kommt es
jetzt dazu, dass weder `ship` noch `engine` entfernt werden?

Nach dem Anlegen der beiden Shared-Pointer `ship` und `engine` stehen die
Referenzzähler jeweils auf 1. Nach den beiden Zuweisungen haben die
Referenzzähler beide den Wert 2. Beim Verlassen des Blockes werden die beiden
Shared-Pointer entfernt, aber die referenzierten Objekte vom Typ `Ship` und
`Engine` verweisen noch immer über Shared-Pointer aufeinander. Also werden die
Referenzzähler noch beide den Wert 1 aufweisen und damit werden auch die beiden
Objekte vom Heap nicht gelöscht werden!

Auf diese beiden Objekt kann jedoch nicht mehr zugegriffen werden und damit
erkennen wir, dass es zu einem Speicherleck gekommen ist. Schuld daran ist der
Zyklus über die beiden Shared-Pointer!

Was kann dagegen getan werden? Der Zyklus muss entfernt werden! Wir werden die
Klasse `Engine` wie folgt umbauen, indem wir den `shared_ptr` in einen
`weak_ptr` umändern:

~~~{.cpp}
struct Engine {
    weak_ptr<Ship> ship;
    ~Engine() {
        cout << "Engine destructed" << endl;
    }
};
~~~

Jetzt sieht die Ausgabe dazu folgendermaßen aus:

~~~{.sh}
1, 1
1, 2
Ship destructed
Engine destructed
Ship destructed
~~~

Hier ist sehr schön, die Auswirkung des Weak-Pointers zu erkennen: Dieser
bewirkt keine Erhöhung des Referenzzählers der `Ship`-Instanz! Das bedeutet,
dass dieser nur ein "schwacher" Pointer (engl. *weak pointer*) ist.

Damit ergibt sich allerdings auch, dass man sich bei einem Weak-Pointer nicht
sicher sein kann, ob dieser noch auf ein Speicherobjekt verweist oder nicht:

~~~{.cpp}
#include <memory>
#include <iostream>

using namespace std;

int main() {
    weak_ptr<int> wpi;
    {
        auto spi = make_shared<int>(1);
        wpi = spi;
    }
    cout << *wpi << endl;
    }
~~~

Das wird *nicht* übersetzen, da `weak_ptr` keinen überladenen Operator `*` hat!
Das macht auch gar keinen Sinn, da nicht sicher ist, dass das referenzierte
Objekt noch existiert.

Um auf das Speicherobjekt über einen Weak-Pointer zuzugreifen, muss man sich
sicher sein, dass dieses noch existiert. Dafür bietet `weak_ptr` die Methode
`lock` an, die einen Shared-Pointer zurückliefert, der auf das Speicherobjekt
referenziert, wenn es eines gibt, anderenfalls wird ein "Null"-Shared-Pointer
zurückgeliefert.

Tauschen wir jetzt bei unserem Beispiel den falschen Ausdruck `*wpi` durch
`*(wpi.lock())` aus. Es wird jetzt übersetzen, aber das Programm wird
vermutlich abstürzen! Das liegt daran, dass zu diesem Zeitpunkt das
Speicherobjekt nicht mehr existiert, da `spi` nicht mehr existiert. Damit
liefert `lock` einen Shared-Pointer zurück, der einen Null-Shared-Pointer
entspricht. Ändere daher die Ausgabe so ab, dass diese folgendermaßen aussieht:

~~~{.cpp}
cout << wpi.lock().get() << endl;
~~~

Die Methode `get()` eines `shared_ptr` liefert den rohen
Pointer auf das Speicherobjekt zurück. Die Ausgabe davon wird `0` sein, ein
Null-Pointer eben. Beachte, dass der von `lock()` zurückgelieferte
Shared-Pointer ein temporäres Objekt ist, das am Ende des vollständigen
Ausdruckes wieder gelöscht wird.

## Die Klasse `array`

Wie schon erwähnt, ist es nicht sinnvoll rohe Arrays zu verwenden. Besser ist
es auf die Möglichkeiten der Standardbibliothek zurückzugreifen.

Prinzipiell kann die Klasse `vector` verwendet werden, die jedoch über einen
gewissen Overhead verfügt, da diese Klasse über zusätzliche Features verfügt,
wie zum Beispiel, dass die Größe verändert werden kann. Das bedeutet, dass
diese Klasse Sinn macht, wenn man einen Container benötigt, dessen Größe sich
ändern kann.

Will man jedoch lediglich eine einfache, sichere Möglichkeit, um auf Arrays eines
bestimmten Typs zuzugreifen, dann bietet sich an, die Klasse `array` aus der
Standardbibliothek zu verwenden.

~~~{.cpp}
#include <iostream>
#include <array>

using namespace std;

int main() {
    array<int, 10> arr;
    cout << "size: " << arr.size() << endl;
}
~~~

Wir sehen hier, dass es bei einem `array` notwendig ist, die Größe des Arrays als
Template-Argument in die spitzen Klammern mit aufzunehmen. Das liegt daran,
dass Templates vom Compiler direkt zur Übersetzungszeit umgesetzt werden und
es damit de facto keinen Overhead im Vergleich zu einem rohen Array gibt!

Der Zugriff auf die einzelnen Elemente erfolgt genauso wie bei einem rohen
Array oder einem Vektor:

~~~{.cpp}
for (auto i : arr) {
    cout << i << " ";
}
~~~

Die Ausgabe kann folgendermaßen aussehen:

~~~{.sh}
size: 10
-1079045240 134514728 1 65535 -1217703472 -1220706901
-1219111904 -1220706922 1 134514939
~~~

Hier sieht man, dass die Elemente einer Instanz von `array` ebenfalls nicht
initialisiert werden. Der Grund sind wiederum
Performanceüberlegungen. Initialisierung eines `array`s geht wieder mit der
einheitlichen Initialisierung:

~~~{.cpp}
array<int, 10> arr2{1, 2, 3};
cout << "size: " << arr2.size() << endl;
   
for (auto i : arr2) {
    cout << i << " ";
}
~~~

Die diesbezügliche Ausgabe sieht dann folgendermaßen aus:

~~~{.sh}
size: 10
1 2 3 0 0 0 0 0 0 0
~~~

Wir sehen, dass jetzt die ersten drei Feldelemente mit den angegebenen Werten
aus der einheitlichen Initialisierung initialisiert sind und der Rest des
Arrays mit Nullwerten aufgefüllt wurde.

Der Zugriff über die Notation `[]` ist ebenfalls sehr effizient, überprüft aber
genauso wenig auf die Feldgrenzen wie dies auch bei der Klasse `vector` nicht
überprüft worden ist:

~~~{.cpp}
cout << endl;

cout << arr2[10000] << endl;
~~~

Diese Codezeile wird mit großer Wahrscheinlichkeit zu einem Absturz
aufgrund eines Speicherzugriffsfehlers führen. Teste!

Ändere jetzt diese Zeile wie folgt ab:

~~~{.cpp}
cout << arr2.at(10000) << endl;
~~~

Auch hier wird es zu einem Absturz kommen, allerdings mit einer Exception vom
Typ `std::out_of_range`, die leicht abgefangen werden kann:

~~~{.cpp}
try {
    cout << arr2.at(10000) << endl;
} catch (const out_of_range& ex) {
    cout << "error 'out of range': " << ex.what() << endl;
}
~~~

Exception werden wir uns im Abschnitt \in[exceptionfoundations] noch
detailliert ansehen.

Man könnte unter Umständen argumentieren, dass man sowieso die `[]` Notation
verwenden könnte, da beide Fälle zu einem Abbruch geführt haben. Dies ist
jedoch nicht so, da es zwei gravierende Unterschiede gibt:

- Der Abbruch über einen Adressbereichsfehler ist nicht abzufangen.
- Ein nicht korrekter Zugriff muss nicht unbedingt zu einem Adressbereichsfehler
    führen! Schauen wir uns diesen Fall an:

    ~~~{.cpp}
    cout << arr[10] << endl;
    ~~~

    Diese Anweisung gibt bei mir in diesem Fall einfach die Zahl 1 aus, obwohl
    der Zugriff nicht korrekt ist! Selbstverständlich kann es auch zu einer
    beliebigen anderen Ausgabe kommen oder auch einen Absturz nach sich
    ziehen. Eine Änderung zu `arr.at(10)` hätte dies erkannt!

Ein weiterer Vorteil an Instanzen von `array` ist, dass diese -- im Gegensatz
zu rohen Arrays -- leicht kopiert und verglichen werden können:

~~~{.cpp}
if (arr == arr2)
    cout << "arr == arr2" << endl;
else
    cout << "arr != arr2" << endl;

arr = arr2;

if (arr == arr2)
    cout << "arr == arr2" << endl;
else
    cout << "arr != arr2" << endl;
~~~

Diese Anweisungen werden zu folgender erwarteter Ausgabe führen:

~~~{.sh}
arr != arr2
arr == arr2
~~~
