
# Grundlagen zu den Datentypen {#basic_types}

<div class="drawer">
In diesem Kapitel erhältst du einen Überblick über die eingebauten Datentypen
von \cpp.

Hier werden wichtige Grundlagen erklärt und mit Beispielen untermauert, sodass
die weiteren Datentypen eingeordnet und verstanden werden können.
</div>


## Einteilung der Datentypen

Die Datentypen von \cpp können in eingebaute Datentypen
(engl. *built-in*) und benutzerdefinierte Datentypen (engl. *user-defined*)
eingeteilt werden.

Die eingebauten Typen unterteilen sich wiederum in die fundamentalen Datentypen
und in Typen, die mittels Deklaratoroperatoren (engl. *declarator operator*)
aus den fundamentalen Datentypen abgeleitet (erzeugt) werden können.

Die fundamentalen Datentypen sind:

- Boolescher Typ (engl. *boolean type*) für Wahrheitswerte: `bool`.
- Zeichentyp (engl. *character type*): `char`, `wchar_t`, `char16_t` und
    `char32_t`.
- Ganzzahltyp (engl. *integer type*): `short`, `int`, `long`, `long long`.
    Von nun an verwende ich der Einfachheit halber einfach den eingedeutschten
    Begriff Integer anstatt Ganzzahltyp.
- Gleitkommazahltyp (engl. *floating-point type*): `float`, `double`,
    `long double`.
- Der Typ `void`, der angibt, dass keine Information über den Typ vorhanden
    ist.

Aus diesen fundamentalen Datentypen und auch den benutzerdefinierten Datentypen
können mittels der folgenden Deklaratoroperatoren neue Datentypen definiert
werden:

- Zeigertyp (engl. *pointer type*), wie z.B. `int*`, der einen Zeiger
    (eingedeutscht *Pointer*) auf einen Integer darstellt. Ein Pointer stellt
    eine Adresse auf einen Speicherbereich dar. In dem konkreten Beispiel ist
    es eben die Adresse auf einen Speicherbereich, der als Integer vom Typ
    `int` betrachtet wird.

    Pointer sind ein wichtiges Konzept in \cpp, aber die Handhabung ist nicht
    immer ganz einfach. Wir werden die notwendigen Grundlagen nach und nach
    durcharbeiten.

- Arraytyp (engl. *array type*), wie z.B. `char[10]`, das ein Array von Zeichen
    darstellt. Ein Array ist ein Speicherbereich fester Größe, der eine Folge
    von Werten eines bestimmten Typs beinhaltet. Bei `char[10]` handelt es sich
    um einen Speicherbereich, der genau 10 Zeichen vom Typ `char` enthält.

- Referenztyp (engl. *reference type*), wie z.B. `double&`, das eine Referenz
    auf einen Speicherbereich vom Typ `double` ist. Eine Referenz ist nichts
    anderes als ein anderer Name für eine bestimmte Speicherstelle. Mehr dazu
    später.

Es gibt noch ein paar wichtige Begriffe:

- Der boolesche Typ, die Zeichentypen und Integer-Typen werden als integrale
    Typen (engl. *integral type*) bezeichnet. Ein integraler Typ ist dadurch
    gekennzeichnet, dass man mit diesem rechnen kann und bitweise logische
    Operationen (z.B. das bitweise Oder) durchführen kann!
    
- Ein arithmetischer Typ ist entweder ein integraler Typ oder ein
    Gleitkommazahltyp. Logischerweise kann man mit einem arithmetischen Typ
    arithmetische Operationen durchführen. Im Gegensatz zu integralen Typen
    kann man Gleitkommazahlen allerdings nicht mit bitweisen logischen
    Operationen verwenden.

    Die unterschiedlichen arithmetischen Datentypen können in
    Zuweisungen und in Ausdrücken (wie z.B. Berechnungen) beliebig miteinander
    verknüpft werden. Dabei werden implizite Konvertierungen vorgenommen.
    Mehr dazu später.

Zusätzlich zu den eingebauten Datentypen können noch gänzlich neue Typen,
sogenannte benutzerdefinierte Datentypen, definiert werden. Dabei handelt es
sich um Aufzählungen (engl. *enumeration*) und Klassen (engl. *class*).
Siehe später.

## Implementierungsspezifische Aspekte {#implementationaspects}

Wie schon erwähnt, gibt es etliche Teile von \cpp, die von der konkreten
Implementierung abhängig sind, da sie nicht spezifiziert sind. Das hat seinen
Grund darin, dass jede Implementierung auf ein spezielles System zugeschnitten
werden kann. Eine der Zielsetzungen von \cpp ist es, Hardware-nahe
Programmierung durchführen zu können. Das ist speziell in der
Programmierung eingebetteter Systeme wichtig, da zum Beispiel bei der
Programmierung eines Handys nicht der gleiche Prozessor vorausgesetzt werden
kann wie bei der Programmierung einer Desktop-Anwendung.

So verhält es sich auch mit den Datentypen, deren exakte Größe nicht
spezifiziert ist, sondern nur die Verhältnisse der Größen zueinander. So kann
man sich nicht darauf verlassen, dass eine ganze Zahl aus einer bestimmten
Anzahl von Bytes zusammengesetzt ist. Damit ist die größte und auch die
kleinste darstellbare Zahl des Typs `int` nicht definiert! Es ist lediglich
festgeschrieben, dass die Größe eines `int` mindestens so groß sein muss wie
die Größe eines `char`.

Schreibe folgenden Quelltext in ein Programm `size.cpp`:

~~~{.cpp}
#include <iostream>

using namespace std;

int main() {
    cout << sizeof(char) << endl;
    cout << sizeof(short) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(long long) << endl;
}
~~~

Bei mir unter Linux in einer 32 Bit Variante kommt es zu folgenden Ausgaben:

~~~{.sh}
1
2
4
8
~~~

Wichtig zu wissen ist, dass in \cpp die Speichergrößen in Vielfachen der
Größe eines `char` ausgedrückt werden. Damit ist per Definition `sizeof(char)`
immer 1! Damit ist auf meinem System ein `int` vier Mal so groß wie ein
`char`. Wie viel Bits ein `char` wirklich hat ist damit nicht zu erfahren.
Meist hat ein `char` 8 Bits, also ein Oktett. Üblicherweise hat ein Byte die
Größe eines Oktetts. Ich gehe in weiterer Folge davon aus, dass ein `char` die
Größe eines Bytes aufweist.

In diesem Zusammenhang werden wir auf das Schlüsselwort `static_assert`
kennenlernen, das vom Compiler selber verwendet und von diesem ausgewertet
wird. Hänge die folgende Zeile an das Programm an:

~~~{.cpp}
static_assert(3 == sizeof(int),
              "Größe eines ints hat nicht 3 Bytes");
~~~

Beim Versuch das Programm jetzt zu übersetzen, wird der *Compiler* eine
Fehlermeldung liefern, da ein `int` mit an Sicherheit grenzender
Wahrscheinlichkeit auf keinem System genau 3 Bytes lang ist oder genauer gesagt
die dreifache Größe eines `char` aufweist. Dazu muss der Compiler zur
Übersetzungszeit diese Anweisung ausführen. Dazu wertet der Compiler die
Bedingung aus und wenn diese nicht erfüllt ist, dann wird letztendlich der
Übersetzungsvorgang mit einer Fehlermeldung abgebrochen.

Ersetzt du diese Zeile durch die folgende Zeile, dann sollte auf einem PC mit
Windows, Linux oder einem MacOSX der Compiler dies übersetzen:

~~~{.cpp}
static_assert(4 <= sizeof(int),
              "int hat nicht mindestens 4 Bytes");
~~~

In den folgenden Abschnitten werden wir etwas genauer auf diese Problematik
eingehen, werden aber nicht alle Regeln angeben, da dies einerseits in dieser
Form nicht möglich ist und auch nicht den Zielsetzungen dieses Buches
entspricht.

## Bezeichner {#identifier}

Wie schon besprochen muss jeder Bezeichner (engl. *identifier*, auch Name
genannt) in einem \cpp Programm vor der Verwendung deklariert werden. Damit
wird dem Compiler einerseits ein Name und andererseits ein zugeordneter Typ
bekannt gemacht.

Die folgenden Regeln gelten für den Aufbau von Bezeichnern:

- Bezeichner bestehen in \cpp aus Buchstaben, Ziffern und Unterstrichen (`_`),
    wobei ein Bezeichner nicht mit einer Ziffer beginnen darf. Groß- und
    Kleinbuchstaben werden unterschieden. 

- Allerdings dürfen Bezeichner nicht mit einem eingebauten Schlüsselwort
    übereinstimmen. Da es mehr als 80 Schlüsselwörter in \cpp gibt, nehme ich
    davon Abstand diese hier anzuführen. Ein Versuch ein Keyword als Bezeichner
    zu verwenden wird der Compiler zuverlässig melden.

- Beginne einen Bezeichner nicht mit einem oder mehreren Unterstrichen, wie
    z.B. `_tmp`!

    Die genaue Regel ist komplizierter und nachfolgend angegeben: Nicht lokale
    Bezeichner dürfen nicht mit genau einem Unterstrich beginnen
    (z.B. `_error`), da diese für die Implementierung beziehungsweise das
    Laufzeitsystem reserviert sind. Generell dürfen Bezeichner nicht mit
    zwei Unterstrichen (z.B. `__status`) oder genau einem Unterstrich
    gefolgt von einem Großbuchstaben (z.B. `_State`) beginnen, da auch
    diese reserviert sind.

Es gibt viele verschiedene Arten, wie man seine Bezeichner aufbauen kann. Ich
verwende die folgende Art:

- Handelt es sich um einen benutzerdefinierten Typ, dann beginnt dieser mit
    einem Großbuchstaben. Setzt sich dieser Typ aus mehreren
    Teilwörtern zusammen, dann wird jedes Teilwort ebenfalls groß
    geschrieben. Ein Beispiel: `NamesDirectory`.

    Eingebaute Datentypen und Datentypen aus der Standardbibliothek von \cpp
    beginnen mit Kleinbuchstaben. Damit ist eine klare Unterscheidung möglich.

- Handelt es sich um eine Variable oder eine Funktion, dann beginnen diese mit
    einem Kleinbuchstaben und die etwaigen Teilwörter sind jeweils durch einen
    Unterstrich (engl. *underscore*) voneinander getrennt. Ein Beispiel:
    `first_name`.

    Methoden (engl. *method*) werden in \cpp ebenfalls als Funktionen
    (engl. *function*) aufgefasst. Will man sich auf Methoden beschränken, dann
    verwendet man den Begriff Mitgliedsfunktion, jedoch ist dies lediglich eine
    sperrige Übersetzung des englischen Begriffes *member functions*.

Hier noch ein weiterer Tipp im Zusammenhang mit der Wahl der Identifier:
Bezeichner nur aus Großbuchstaben werden nicht empfohlen, da diese meist für
Makros im Kontext des Präprozessors verwendet werden.


## Deklaration und Definition {#declaration}

Bei einer Zuordnung von Name zu Typ handelt es sich um eine *Deklaration*. Ein
Name muss im Quelltext zuerst deklariert werden bevor dieser verwendet werden
kann.

Eine Deklaration wird in \cpp als Anweisung betrachtet. Das hat eine Bedeutung,
da damit auch der Geltungsbereich (siehe Abschnitt \in[scope]) und speziell die
Lebenszeit eines Speicherobjektes definiert ist.

Enthält eine Deklaration alle Angaben, um den Namen zu benutzen,
dann spricht man von einer *Definition*. Handelt es sich dabei um die
Definition einer Variable, dann wird vom Compiler für diese Variable
der Speicher reserviert. Das bedeutet, dass es sich bei einer
Definition um eine spezielle Deklaration handelt.  Hier einige Beispiele:

~~~{.cpp}
bool ready;  // Definition
char ch;  // Definition
extern int state;  // Deklaration
double result;  // Definition

double add(double, double);  // Deklaration
class User;  // Deklaration
~~~

Für `ready`, `ch` und `result` kennt der Compiler nicht nur den Namen und den
Typ, sondern es wird vom Compiler auch Speicherplatz reserviert werden, da alle
Informationen vorhanden sind, um diese Variable zu benutzen.

`extern` gibt an, dass es sich nur um eine Deklaration handelt und die
Definition an anderer Stelle (meist in einer anderen Datei) erfolgen muss.

Bei `add` handelt es sich um die Deklaration einer Funktion, da nur die
Informationen bezüglich der Typen der Parameter sowie des Rückgabewertes
vorhanden sind, aber der Rumpf der Funktion fehlt. So eine Funktionsdeklaration
wird in \cpp als Prototyp bezeichnet.  Damit ist es möglich, dass der Compiler
Funktionsaufrufe dieser Funktion übersetzen kann, aber das Linken wird
fehlschlagen, da der Linker nicht weiß welche Adresse für den Funktionsaufruf
eingesetzt werden muss.

Mittels `class User` wird dem Compiler mitgeteilt, dass es sich bei `User` um
einen Bezeichner handelt, der für einen benutzerdefinierten Typ steht, aber es
fehlt zu diesem Zeitpunkt noch die Information wie dieser Typ konkret aussieht.

Da es sich bei Definitionen um spezielle Deklarationen handelt, werde ich in
weiterer Folge Deklaration als Überbegriff verwenden.

Es kann in einem Programm mehrere Deklarationen -- solange es sich nicht um
Definitionen handelt -- des gleichen Namens im gleichen Geltungsbereich
geben, dann müssen diese allerdings identisch sein. Der folgende Quelltext ist
korrekt:

~~~{.cpp}
extern int res;
extern int res;
~~~

Allerdings wären die folgenden Deklarationen nicht korrekt, da die Typen für
den Namen `res` nicht übereinstimmen:

~~~{.cpp}
extern int res;
extern double res;
~~~

Im Gegensatz dazu muss es genau eine Definition eines Namens im gesamten
Programm geben, außer der Bezeichner wird nicht verwendet oder es handelt sich
bei der Verwendung lediglich um einen Pointer, der nicht dereferenziert wird
(siehe später). Das folgende Beispiel

~~~{.cpp}
int res;
int res;
~~~

oder auch

~~~{.cpp}
int res;
double res;
~~~

sind beide syntaktisch falsch, da es eben mehrere Definitionen des Bezeichners
gibt.

Deklarationen werden meist mit einem Strichpunkt abgeschlossen. Die Ausnahme
bildet die Funktionsdefinition, die nach der geschlossenen geschwungenen
Klammer keinen Strichpunkt hat.

## Struktur einer Deklaration {#structureofdeclarations}

Den einfachsten Aufbau einer Deklaration haben wir uns schon angesehen, nämlich
Typangabe gefolgt von Bezeichner. Aber es gibt noch viel mehr. Im letzten
Abschnitt haben wir schon gesehen, dass es weitere Schlüsselwörter wie `extern`
gibt oder, dass es Deklaratoroperatoren gibt und vieles mehr.

Vereinfacht sieht der Aufbau einer Deklaration folgendermaßen aus:

a. Am Anfang kann ein Präfix (engl. *prefix*), wie z.B. `extern` oder `static`
    stehen.

b. Danach folgt verpflichtend der Basistyp wie z.B. `int`, `User` oder
    `vector<string>`

c. Anschließend folgt ein Deklarator. Dieser besteht entweder aus einem Namen,
    einem Deklaratoroperator oder beidem.

d. Optional kann für Funktionen ein Suffix (engl. *suffix*) kommen wie
    z.B. `noexcept`.

e. Am Ende kann optional noch eine Initialisierung oder im Falle einer
    Funktionsdefinition der Funktionsrumpf stehen.

Diese Struktur ist hier angeführt, sodass du einen allgemeinen Überblick
bekommst. Welche Möglichkeiten es detailliert gibt und wie du diese einsetzen
kannst, erfolgt in folgenden Kapiteln.  Damit du dir trotzdem
etwas vorstellen kannst, wie so eine Deklaration aussehen kann, hier noch ein
kleines Beispiel: `static int* p{new int{3}};` Eine Erklärung dazu kommt
später.

Die Verwendung von Deklaratoroperatoren ist komplex, deshalb beschränke ich
mich wieder auf die notwendigen und wichtigen Elemente. Eine Erklärung der
wichtigen Anwendungen dieser Deklaratoroperatoren erfolgt ebenfalls später. Als
Tipp empfehle ich, die Deklaration von rechts nach links zu lesen:

- Ein Pointer wird durch `*` gekennzeichnet. Ein einfaches Beispiel ist:
    `int* p`. Das bedeutet, dass `p` ein Pointer auf ein `int` ist.
- Eine Referenz (konkret eine lvalue Referenz, siehe später) wird durch ein `&`
    gekennzeichnet. Ein Beispiel wäre: `int& current{value}`. Das bedeutet,
    dass `current` ein anderer Name für die Variable `value` ist. Wird
    `current` verändert, wie z.B. mit `current = 3;` dann wurde eben der
    Speicherbereich von `value` verändert, d.h. auf den Wert 3 gesetzt.
- Ein Array wird mittels eckiger Klammern angegeben: `char first_name[20]`
    stellt ein Array dar, das sich aus 20 Zeichen zusammensetzt.
- Eine Funktion wird von \cpp durch ein folgendes Klammernpaar erkannt, wie
    z.B. `int sqrt();`.

Wichtig: Außer bei Definitionen von Funktionen und Namensräumen ist eine
Deklaration immer mit einem Strichpunkt abzuschließen!

Prinzipiell kann man in \cpp mehrere Namen in einer Deklaration
deklarieren. Das ist nicht zu empfehlen und wird hier auch nicht erklärt. Das
bedeutet, dass wir jede Deklaration einer Variable in genau einer Zeile
schreiben, also so:

~~~{.cpp}
int age;
int count;
~~~

## Geltungsbereich {#scope}

Nachdem wir jetzt wissen was eine Deklaration ist und außerdem den Aufbau einer
Deklaration kennen, stellt sich weiters die Frage wo so eine Deklaration gültig
ist. Der Geltungsbereich (engl. *scope*, eingedeutscht
Scope) legt eben fest in welchem Bereich der eingeführte Bezeichner gültig ist.

Als generelle Regel lässt sich sagen, dass ein Bezeichner vom Beginn der
Deklaration bis zum Ende des Blockes, in dem er deklariert wird, seine Gültigkeit
behält. Von dieser Regel gibt es drei Ausnahmen:

- Bezeichner, die Instanzvariablen oder Methoden einer Klasse darstellen, sind
    in der gesamten Klassendeklaration gültig. Wir werden uns das später noch
    ansehen.

- Globale Bezeichner sind in keinem Block enthalten und behalten ihre
    Gültigkeit bis zum Ende der Datei. Auch das werden wir uns später noch
    ansehen.

- Bezeichner, die innerhalb der runden Klammern einer `for`, `while` oder
    `switch` Anweisung oder einer Funktionsdefinition deklariert wurden
    erstrecken sich vom Beginn der Deklaration des Bezeichners bis zum Ende des
    folgenden Blockes. Ein Beispiel für so eine Deklaration haben wir schon im
    Abschnitt \in[exasort] auf der Seite \at[exasort] gesehen.

Bezeichner können durch andere Deklarationen überschattet werden
(engl. *shadowing*). Das kann durch verschachtelte Geltungsbereiche
erreicht werden. Teste dies in folgendem Programm:

~~~{.cpp}
// scope.cpp
#include <iostream>

using namespace std;

int x;

int main() {
    cout << "global x: " << x << endl;
    
    int x;

    cout << "local x: " << x << endl;
}
~~~

Die lokale Variable `x` überschattet die globale Variable `x`. Bei mir kommt es
deshalb zu folgender Ausgabe:

~~~{.sh}
global x: 0
local x: 134514675
~~~

Was hier zu sehen ist:

- Zuerst wird eine globale Variable `x` definiert, aber nicht explizit
    initialisiert.
- In `main` erfolgt die Ausgabe der globalen Variable `x`. Es handelt sich hier
    noch um die globale Variable, da die Gültigkeit der lokalen Variable erst
    mit deren Deklaration beginnt. Weiters sieht man, dass der Wert 0
    ausgegeben wird. Das hat damit zu tun, dass globale Variablen mit dem
    Nullwert initialisiert werden.
- Danach folgt die Deklaration einer lokalen Variable `x`. Auch diese Variable
    wird nicht initialisiert. Dies sieht man gut bei der nachfolgenden Ausgabe
    dieser lokalen Variable: es wird der Wert der Speicherstelle ausgegeben,
    bei mir eben 134514675.

Hänge an das Programm die folgenden Anweisungen an:

~~~{.cpp}
x = 1;

{
    int x;
    cout << "x in block: " << x << endl;
}

cout << "local x (after block): " << x << endl;
~~~

Jetzt kommt es bei mir zu folgender Ausgabe:

~~~{.sh}
global x: 0
local x: 134514787
x in block: -1076411604
local x (after block): 1
~~~

Analysieren wir diese Ausgabe:

- Wir bemerken, dass die Ausgabe einer uninitialisierten Variable nicht
    immer den gleichen Wert aufweisen muss!
- Als Nächstes bemerken wir, dass eine lokale Variable in einem Block eine
    außenliegende Variable mit dem gleichen Namen "überschattet". Damit haben
    die Änderungen der lokalen Variable im Block keine Auswirkungen auf die
    Variable außerhalb des Blockes.

Erweitern wir das Programm nochmals durch Anhängen der folgenden Anweisungen:

~~~{.cpp}
for (int x{2}; x < 3; ++x) {
    cout << "x in statement: " << x << endl;
}

cout << "local x (after assignment): " << x << endl;
~~~

Teste das Programm! Du siehst, dass die Deklaration der Variable innerhalb der
runden Klammern der `for` Anweisung für die gesamte `for` Anweisung gilt, aber
nicht außerhalb. Sehr praktisch.

Jetzt wollen wir das Beispiel über die Geltungsbereiche abschließen, indem wir
eine neue Funktion definieren und diese aufrufen. Füge deshalb die nachfolgende
Funktionsdefinition vor `main` ein:

~~~{.cpp}
void func(int y) {
    cout << "x in func (global): " << x << endl;
    ++y;
    cout << "y in func (local): " << y << endl;
}
~~~

Hänge weiters die folgenden Anweisungen in `main` hinten an:

~~~{.cpp}
int y{1};

cout << "local y (before function call): " << y << endl;

func(y);

cout << "local y (after function call): " << y << endl;
~~~

Der relevante Teil der Ausgabe sieht folgendermaßen aus:

~~~{.sh}
local y (before function call): 1
x in func (global): 0
y in func (local): 2
local y (after function call): 1
~~~

Hier sehen wir zwei Aspekte:

- Bei `y` innerhalb der Funktion handelt es sich um einen anderen Bezeichner
    als `y` innerhalb von `main`. Da eine Variable standardmäßig *kopiert*
    wird, hat eine Änderung innerhalb der Funktion `func` keine Auswirkung auf
    die Variable `y` innerhalb von `main`.
- In `func` wird mit dem Namen `x` auf die globale Variable `x` zugegriffen und
    nicht auf die lokale Variable `x` in der Funktion `main`.


## Initialisierung {#initialization}

### Arten der Initialisierung

An sich gibt es vier Möglichkeiten, wie man in \cpp Variablen initialisieren
kann. Hier folgen Beispiele für diese verschiedenen Varianten:

~~~{.cpp}
int i1{1};
int i2 = {1};
int i3 = 1;
int i4(1);
~~~

Die erste Variante wird als "uniform initialization" also die einheitliche
Initialisierung bezeichnet, da sie weitgehend überall verwendet werden kann, wie
zum Beispiel bei Arrays, Strukturen, Klassen und Templates.

Die erste unterscheidet sich von der zweiten Variante geringfügig, wenn ein
benutzerdefinierter Datentyp über einen Konstruktor verfügt, der mit `explicit`
markiert ist. Das werden wir uns später noch ansehen.

Die erste und zweite Variante haben die wichtige Eigenschaft, dass sie keine
Konvertierungen zulassen, die nicht werterhaltend sind.  Werterhaltend
bedeutet, dass der Wert gleich dem ursprünglichen Wert sein muss, wenn er
wieder in den ursprünglichen Typ gewandelt wird.

Das folgende Beispiel demonstriert dies, da die dritte und vierte Variante
nicht-werterhaltende Konvertierungen durchführen:

~~~{.cpp}
int i5 = 2.5;  // 2.5 hat den Typ double
int i6(0.5);
~~~

Damit wird `i5` mit dem Wert `2` und `i6` mit dem Wert `0` initialisiert.  Das
wird als *narrowing* (dt. einengen) bezeichnet, da diese Konvertierung
nicht werterhaltend ist.  Genau das ist aber hier der Fall, denn würde
man den Wert von `i5` wieder in einen `double` wandeln, dann erhält man
lediglich den Wert `2.0`.

Es handelt sich hierbei wahrscheinlich um einen Programmierfehler. Warum sollte
man eine `int` Variable mit `2.5` initialisieren wollen? Man würde in diesem
konkreten Fall doch einfach `2` schreiben, nicht wahr? Hätte man stattdessen
die einheitliche Initialisierung verwendet, hätte der Compiler eine
entsprechende Fehlermeldung erzeugt.

Die vierte Form hat einen weiteren Nachteil. Nehmen wir einmal an, dass wir
die folgende Deklaration `int i6();` haben, mit der Absicht eine Variable `i6`
vom Typ `int` anzulegen und diese mit dem Nullwert zu initialisieren. In
Wirklichkeit wird der Compiler dies als eine Funktionsdeklaration
interpretieren, die eine Funktion mit dem Namen `i6` einführt, die keine
Parameter besitzt und einen `int` zurückliefert!

Das bedeutet, dass die dritte und die vierte Variante jeweils zu vermeiden
sind, wenn sich das erreichen lässt, da es hier zu sogenannten einengenden
impliziten Konvertierungen kommen kann und diese beiden Varianten von der
Syntax von \cpp auch nicht *überall* verwendet werden können.

### Ausnahmen zur einheitlichen Initialisierung

Von diesen vier Möglichkeiten kann nur die erste Variante weitgehend überall
eingesetzt werden. Es gibt allerdings zwei Ausnahmen:

- Wenn eine `auto` Deklaration verwendet wird. Eine `auto` Deklaration kann sehr
    praktisch sein, da der Compiler den Typ selbständig ermittelt. Das
    reduziert die Redundanz und andererseits ist es manchmal gar nicht so
    einfach, den richtigen Typ bei der Verwendung der Standardbibliothek
    herauszufinden. Schreibe das folgende Beispiel und probiere es aus:

    ~~~{.cpp}
    // auto.cpp
    #include <iostream>
    #include <vector>
    #include <algorithm>
    
    using namespace std;
    
    int main() {
        auto words = vector<string>{"prolog", "java", "lisp",
                                    "python", "c++"};
        
        sort(words.begin(), words.end());
    
        for (int i{0}; i < words.size(); ++i) {
            cout << words[i] << endl;
        }
    }
    ~~~

    Hier verwenden wir eine lokale Variable `words`, die beim Anlegen mit einer
    Liste initialisiert wird. Diese in geschwungenen Klammern eingeschlossene
    Liste von Werten entspricht dem Typ `std::initializer_list` und wird in der
    Standardbibliothek oft verwendet und kann auch für eigene Zwecke ebenfalls
    verwendet werden.

    Da es sich bei solch einer Initialisierungsliste um diesen Typ
    `std::initializer_list<int>` handelt, erhält man mit `auto i{1};` auch
    nicht das meist erwünschte Ergebnis, äquivalent zu `int i{1}`, sondern
    `std::initializer_list<int> i{1}`! Das bedeutet, dass bei Verwendung von
    `auto` in der Regel die Initialisierungsvariante mit `=` verwendet werden
    muss!

    Der Rest des Beispiels ist wieder gleich. Allerdings wollen wir die
    Gelegenheit gleich nutzen, um die Schleife mit der Ausgabe ebenfalls
    umzugestalten. Ersetze dazu die Schleife durch das folgende Konstrukt und
    teste:

    ~~~{.cpp}
    for (string elem : words) {
        cout << elem << endl;
    }
    ~~~

    Es handelt sich hierbei um eine "for each" Schleife, wie diese auch von
    anderen Programmiersprachen bekannt sein dürfte: Es wird über alle
    Elemente des Vektors `words` iteriert und je Schleifendurchgang erhält die
    Laufvariable das jeweils aktuelle Element.

    So, jetzt können wir auch dieses Beispiel noch verbessern. Dem Compiler ist
    der Typ von `words` bekannt, nämlich `vector<string>`. Daher weiß der
    Compiler auch, dass der Typ von `elem` nur `string` sein kann und das wird
    von ihm auch überprüft. Das kannst du leicht überprüfen indem du einen
    anderen Typ für `elem` angibst, wie z.B. `int`. Du wirst einen Syntaxfehler
    erhalten.

    Da dem Compiler bekannt ist, um welchen Typ es sich handelt, kann er diesen
    auch selbst ermitteln, womit wir wiederum das Schlüsselwort `auto` zum
    Einsatz bringen können:

    ~~~{.cpp}
    for (auto elem : words) {
        cout << elem << endl;
    }
    ~~~

    Nicht schlecht, oder? Verwenden wir in solch einem Fall `auto` hat das den
    weiteren Vorteil, dass wir den Typ von `words` z.B. auf `vector<int>`
    ändern könnten. Die `for` Schleife müsste nicht verändert werden!

    Eine andere Variante wäre eine Referenz für die Schleifenvariable
    zu verwenden. Füge die folgende Schleife vor die schon bestehende Schleife
    ein und teste:

    ~~~{.cpp}
    for (auto& elem : words) {
        elem = elem + "!";
    }
    ~~~

    Damit wird die Schleifenvariable als neuer Name für das jeweils aktuelle
    Schleifenobjekt verwendet, womit das aktuelle Schleifenobjekt direkt
    in unserem `vector` verändert werden kann. Das bedeutet, dass das
    Schleifenobjekt nicht kopiert wird.

    Es gibt noch einen Grund nicht kopieren zu wollen, wenn nämlich das
    Kopieren einen beträchtlichen Aufwand darstellt, da das zu kopierende
    Schleifenobjekt groß ist. Unter Umständen will man allerdings das
    Schleifenobjekt nicht verändern und sicherstellen, dass es zu keiner
    Veränderung kommt, dann schreibt man das Schlüsselwort `const` direkt
    vor `auto&`. Das könnte dann folgendermaßen aussehen:

    ~~~{.cpp}
    for (const auto& elem : words) {
        cout << elem << endl;
    }
    ~~~

- Kommen wir jetzt zum zweiten Fall wo `auto` nicht einzusetzen ist. Bei dem
    Typ der Variable handelt es sich um einen benutzerdefinierten Typ, der
    sowohl einen Konstruktor mit genau den angegebenen Initialisierungswerten
    hat und außerdem einen Konstruktor besitzt, der eine Initialisierungsliste
    als Parameter erwartet.

    Wie wir schon gesehen haben, kann man einen Vektor mithilfe einer
    Initialisierungsliste mit Werten initialisieren, wie z.B.
    `vector<int> nums{1, 2, 3, 4}`. Andererseits gibt es auch einen Konstruktor
    mit dem man den Vektor mit einer bestimmten Anzahl von Nullwerten
    initialisieren kann. Angenommen man will einen Vektor mit 10 Elementen anlegen,
    dann kann natürlich auch `vector<int> nums{10}` nicht funktionieren, da man
    damit einen Vektor mit einem Element anlegt, das den Wert 10 hat.

    In diesem Fall ist es notwendig auf die explizite Konstruktorform
    zurückzugreifen: `vector<int> nums(10)` legt einen Vektor mit 10 Elementen
    an, die jeweils mit 0 belegt sind.

    Das bedeutet, dass die Klasse `vector` sowohl einen Konstruktor hat, der
    sich eine Initialisierungsliste erwartet als auch einen Konstruktor, der
    sich eine ganze Zahl erwartet. Das Verhalten der beiden Konstruktoren ist
    eben unterschiedlich und genau wie im vorhergehenden Absatz beschrieben.

    Beachte, dass gerade die Notation mit den runden Klammern seine Tücken hat,
    die wir uns im Abschnitt \in[functiondeclaration] über Funktionen noch
    ansehen werden.

### Fehlende Initialisierungen

Fehlt bei einer Definition einer Variable eines eingebauten Datentyps die
Initialisierung, dann hängt es davon ab, um welche Art der Initialisierung es
sich handelt. Bei benutzerdefinierten Datentypen wird immer der Konstruktor
aufgerufen.

Es gelten die beiden nachfolgenden Regeln:

- Eine globale Variable, eine Variable aus einem Namespace, eine lokale
    `static` Variable oder eine `static` Member-Variable wird jeweils mit dem
    entsprechenden Nullwert initialisiert. Bei einem benutzerdefiniertem
    Datentyp entspricht dies dem Aufruf des Defaultkonstruktors (siehe
    Abschnitt \in[constructor]).

    Solch eine Initialisierung wird durchgeführt bevor die Funktion `main`
    gestartet wird und findet in der Reihenfolge der Deklaration
    statt. Zwischen verschiedenen Übersetzungseinheiten (siehe Abschnitt
    \in[translationunit]) ist die Reihenfolge der Initialisierung nicht
    definiert.

- Eine lokale Variable oder ein Speicherobjekt, das am Heap angelegt wurde,
    wird hingegen nicht initialisiert.


## Speicherobjekte und Werte

### Speicherobjekt {#storageobject}

Wir wollen hier die Grundlagen schaffen, um die spätere Behandlung von
Referenzen besser verstehen zu können.

Dazu betrachten wir vorerst den Begriff "object" (dt. Objekt,
Speicherobjekt). Es handelt sich hierbei *nicht* um ein Objekt im Sinne der
Objektorientierung!  Vielmehr bezeichnet dieser Begriff in \cpp einen
zusammenhängenden Bereich im Speicher.

Ein Speicherobjekt liegt im Speicher, beginnt an einer bestimmten Adresse und
hat eine bestimmte Größe. Die Adresse ist die eindeutige Möglichkeit auf dieses
Speicherobjekt zuzugreifen.

Über das Typkonzept von \cpp wird diesem Speicherobjekt eine bestimmte
Bedeutung zugewiesen und damit sind wiederum die Operationen festgelegt wie mit
diesem Speicherobjekt verfahren werden kann.

Haben wir zum Beispiel eine Variable vom Typ `int`, die mittels `int result;`
definiert worden ist, dann kann der Compiler diese Variable in einem
Speicherobjekt anlegen. Da diesem Speicherobjekt jetzt über das Typsystem der
Typ `int` zugewiesen ist, sind hiermit auch die Operationen eindeutig
definiert, wie auf die Speicherstelle zugegriffen werden kann. Außerdem ist
natürlich auch klar, dass man daher mit den üblichen arithmetischen
Operationen rechnen kann.

Jedes Objekt hat eine Lebenszeit. Das bedeutet, dass es erzeugt wird, dann wird
es verwendet und am Ende wird der Speicher wieder freigegeben. Die Lebenszeit
eines Objektes beginnt, wenn der Konstruktor abgeschlossen ist und endet, wenn
der Destruktor mit der Ausführung beginnt. Ein Konstruktor ist eine Funktion,
die für die Initialisierung eines Objektes zuständig ist und ein Destruktor ist
eine Funktion, die die Beendigungsaktionen durchführt. Hat der Typ des
Objektes, wie zum Beispiel ein `int`, keinen Konstruktor oder Destruktor, dann
wird dies so betrachtet als hätte dieser Typ einen leeren Konstruktor oder einen
leeren Destruktor.

In \cpp gibt es verschiedene Arten von Lebenszeit. Die folgenden Erläuterungen
greifen bezüglich der Begriffe vor und müssen beim ersten Durcharbeiten nicht
verstanden werden:

Automatic
  : Ein Objekt mit der Lebenszeit *automatic*, wird bei der Deklaration erzeugt
    und beendet sich, wenn der Geltungsbereich der Deklaration endet. Lokale
    Variable haben diese Lebenszeit.

    ~~~{.cpp}
    void f() {
        int i{1};  // Lebenszeit beginnt
        {
            int j{1};  // Lebenszeit beginnt
        }  // hier endet die Lebenszeit von j
    }  // hier endet die Lebenszeit von i
    ~~~

Static
  : *Static* bedeutet, dass das Objekt genau einmal initialisiert wird und
    seine Lebenszeit erst beim Beenden des Programmes verliert. Dazu zählen
    globale Variable, Variable in Namensräumen, `static` deklarierte Variable
    in Funktionen und `static` Member-Variablen.

    ~~~{.cpp}
    // Lebenszeit beginnt mit dem Start des Programmes
    int i;  // globale Variable; initialisiert mit 0;

    int main() {
    
    }  // hier endet die Lebenszeit von i
    ~~~

Free store
  : Als *free store* wird in \cpp der Heap bezeichnet. Objekte, die dort liegen
    müssen explizit angefordert und explizit wieder freigegeben werden. Dazu
    gibt es in \cpp die Operatoren `new` und `delete`.

    ~~~{.cpp}
    int* p{new int{1}};  // Lebenszeit beginnt

    delete p;  // Lebenszeit endet
    ~~~


Temporary objects
  : Temporäre Objekte (*temporary objects*) entstehen als Zwischenschritt in
    der Auswertung eines Ausdruckes. Ihre Lebenszeit endet entweder mit dem
    Ende des vollständigen Ausdruckes in dem diese erzeugt worden sind oder mit
    der Lebenszeit der Referenz, wenn dieses temporäre Objekt an eine Referenz
    gebunden worden ist.

    ~~~{.cpp}
    int i;
    int j;
    i = (i + j) * 4;
    ~~~

    Temporäre Objekte sind in diesem Beispiel der Wert von `i + j` und der Wert
    von `(i + j) * 4`. Der vollständige Ausdruck ist `i = (i + j) * 4`. Mit dem
    Ende dieses vollständigen Ausdruckes beenden sich auch die Lebenszeiten
    aller enthaltenen temporären Objekte. Natürlich macht es in diesem Fall
    keinen Sinn sich darüber Gedanken zu machen, da es unerheblich ist, wann
    die Lebenszeit von derartigen `int` Speicherobjekten endet. Handelt es sich
    aber um benutzerdefinierte Datentypen, die einen Destruktor haben, dann ist
    es unter Umständen sehr Wohl von Interesse zu wissen, wann der Destruktor
    aufgerufen wird, da dieser Destruktor Nebeneffekte haben kann.

Thread-local objects
  : Der Vollständigkeit halber erwähne ich auch noch die Objekte, deren
    Lebenszeit an die Lebenszeit des Threads gebunden ist.


### Werte {#values}

Jeder Ausdruck hat einen Wert (engl. *value*). Man unterscheidet zwei Arten von
Werten: *lvalue* und *rvalue*.

Als *lvalue* wird ein Ausdruck verstanden, der auf ein Objekt verweist, das
über den Ausdruck hinaus erhalten bleibt. Ein lvalue hat seinen Namen davon,
dass dieser auf der linken Seite einer Zuweisung ("left-hand side", abgekürzt
lhs) vorkommen kann. Es gibt allerdings auch lvalues, die nicht auf der linken
Seite vorkommen können, da diese `const` sind und hiermit nicht veränderbar.

Als Faustregel gilt: Ein Ausdruck, von dem du mittels des `&` Operators eine
Adresse ermitteln kannst, ist ein lvalue.

Das folgende Beispiel enthält auch Pointer (Zeiger), die erst später
beschrieben werden:

~~~{.cpp}
int i{};
int* p{&i};  // Pointer p wird mit Adresse von i initialisiert
const int j{1};

i = 2;
*p = 3;  // Objekt auf das p verweist wird mit 3 belegt
j = 4; // Compilerfehler, da j konstant ist
~~~

Hier ist `i` ein lvalue, da `i` ein Name (auch ein Ausdruck) ist, der
direkt auf ein Objekt verweist. `*p` ist ebenfalls ein lvalue, da in das Objekt
der Wert 3 geschrieben wird, auf das `p` verweist. `j` ist zwar ein lvalue,
kann aber nicht verändert werden, da dieser konstant ist.

Beachte, dass du die Definition der Konstante `j` auch folgendermaßen
anschreiben kannst:

~~~{.cpp}
int const j{1};
~~~

Damit funktioniert die "lese von rechts nach links"-Regel in 100% der
Fälle.  Allerdings ist die andere Schreibweise gebräuchlicher.

Das Gegenstück zu einem lvalue ist ein *rvalue*. Ein rvalue ist ein Ausdruck,
der auf ein Objekt verweist, das nicht über den Ausdruck hinaus erhalten
bleibt. Vereinfacht kann man sagen, dass ein rvalue ein Ausdruck ist, der kein
lvalue ist.

Betrachten wir dazu den folgenden Quelltext:

~~~{.cpp}
int i;
int j;

i = (i + j) * 4;
~~~

Hier handelt es sich bei dem Ergebnis von `i + j` um einen rvalue und auch das
Ergebnis von `(i + j) * 4` ist ein rvalue. `i` auf der linken Seite von `=` ist
jedoch ein lvalue.

Kann man von einem Ausdruck eine Adresse bestimmen, dann handelt es sich
typischerweise um einen lvalue, ansonsten um einen rvalue. Das bedeutet aber
auch, dass für einen gegebenen Typ `T` es sowohl lvalues von dem Typ `T` als
auch rvalues von dem Typ `T` geben kann!

## Konstanten {#constants}

Konstanten sind Bezeichner, deren Werte nicht mehr verändert werden
können. Dadurch ist es notwendig, dass Konstanten bei der Definition auch
initialisiert werden müssen.

Es gibt in \cpp zwei Arten wie man Konstanten definieren kann:

- Durch die Verwendung des Schlüsselwortes `const`, wie wir dies schon
    kennengelernt haben. Hier wollen wir den Schwerpunkt allerdings auf die
    Initialisierung legen.

    Die Initialisierung wird bei der Verwendung von `const` zur Laufzeit
    vorgenommen und kann in weiterer Folge nicht mehr verändert werden.  Das
    folgende Beispiel demonstriert dies:

    ~~~{.cpp}
    // constants.cpp
    #include <iostream>
    
    using namespace std;
    
    int main() {
        int min;
        int size;
    
        cout << "Minimum: ";
        cin >> min;
        cout << "Größe: ";
        cin >> size;
    
        const int max{min + size};
        cout << "Maximum = " << max << endl;
        //max = 3;  // Fehler!
    }
    ~~~

- Die zweite Möglichkeit besteht in der Verwendung des Schlüsselwortes
    `constexpr`, das so viel wie "constant expression" -- also konstanter
    Ausdruck -- bedeutet.

    Der Unterschied zu `const` liegt darin, dass die Initialisierung nicht zur
    Laufzeit, sondern zur Übersetzungszeit vorgenommen wird. Das bedeutet, dass
    der Compiler den Wert der Konstante bestimmt. Dazu muss der gesamte
    Ausdruck der Initialisierung entweder aus Literalen, `constexpr`-Konstanten
    oder `constexpr`-Funktionen zusammengesetzt sein. Als Ausnahme dürfen auch
    `const`-Konstanten verwendet werden, soferne diese mit einem konstanten
    Ausdruck initialisiert worden sind.

    Hänge folgende Codezeilen an dein Programm:

    ~~~{.cpp}
    const int months{12};
    constexpr int days_per_month{30};
    constexpr int days_per_year{months * days_per_month};
    cout << "Ein Bankenjahr hat " << days_per_year << " Tage"
         << endl;
    ~~~

    Es gibt einen weiteren Unterschied zu der Verwendung von `const`, da es
    sich dabei prinzipiell nicht um Speicherobjekte handelt. Das bedeutet, dass
    in der obigen Ausgabe anstatt `days_per_year` vom Compiler direkt der
    berechnete Wert 360 eingesetzt wird.

    Erst wenn wir den Adressoperator explizit verwenden, wird ein Speicherobjekt
    angelegt. Hänge die folgenden Codezeilen an und es wird ein Speicherobjekt
    angelegt. Die Ausgabe erfolgt natürlich wieder wie erwartet:

    ~~~{.cpp}
    const int* p{&days_per_year};
    cout <<  "Ein Bankenjahr hat " << *p << " Tage" << endl;
    ~~~


## Implizite Konvertierungen {#implicitconv}

Dieser Abschnitt erklärt die Konvertierungen, die von \cpp implizit vorgenommen
werden. Da die fundamentalen Datentypen noch nicht im Detail erläutert worden
sind, kann dieser Abschnitt beim ersten Lesen "überflogen" werden. Spätestens
beim Durcharbeiten der einzelnen fundamentalen Datentypen kann dieser
Abschnitt zwecks genaueren Verständnis nochmals aufgesucht werden.

Von \cpp werden implizite Konvertierungen selbständig vorgenommen. Nehmen wir
an wir haben eine Zuweisung der Form `x = expr`, wobei es sich bei `expr` um
einen arithmetischen Ausdruck handelt. Die nachfolgenden Ausführungen gelten
analog auch nur für den Ausdruck `expr` alleine. \cpp geht folgendermaßen vor:

a. Zuerst wird eine Aufweitung der integralen Datentypen
    (engl. *integral promotion*, eingedeutscht Promotion) vorgenommen. Das
    bedeutet, dass `int`s aus kleineren Datentypen erzeugt werden und hat den
    Sinn, dass die Operanden in das "natürliche" Format für arithmetische
    Operationen gebracht werden.

    Im speziellen werden die folgenden Promotions durchgeführt:

    - Ein `char`, `signed char`, `unsigned char`, `short int` oder
      `unsigned short int` wird in einen `int` konvertiert, wenn der `int` alle
      Werte repräsentieren kann, anderenfalls in einen `unsigned int`.

    - Ein `char16_t`, `char32_t`, `wchar_t` oder ein einfacher Enumerationstyp
      (kein `enum class`) werden zum ersten der folgenden Typen konvertiert,
      der alle Werte repräsentieren kann: `int`, `unsigned int`, `long`,
      `unsigned long`, `unsigned long long`.

    - Ein `bool` wird zu einem `int` konvertiert.

    Schauen wir uns dazu wieder ein Beispiel an:

    ~~~{.cpp}
    // promotions.cpp
    #include <iostream>
    
    using namespace std;
    
    int main() {
        char a{'0'};
        char b{'0'};
    
        cout << "a = " << a << "; sizeof(a) = " << sizeof(a)
             << endl;
        cout << "b = " << b << "; sizeof(b) = " << sizeof(b)
             << endl;
         cout << "a + b = " << a + b << "; sizeof(a + b) = "
              << sizeof(a + b) << endl;
    }
    ~~~

    Als Ergebnis erhältst du dann:

    ~~~{.sh}
    a = 0; sizeof(a) = 1
    b = 0; sizeof(b) = 1
    a + b = 96; sizeof(a + b) = 4
    ~~~

    Obwohl die Größe eines `char` per Definition in \cpp immer 1 ist, ist die
    Größe von `a + b` gleich 4. Das liegt eben daran, dass ein `char` mittels
    Promotion zu einem `int` aufgeweitet wird. Im Bereich der ganzen Zahlen
    wird danach die Addition durchgeführt, womit das Ergebnis dann auch die
    Größe eines `int`s aufweist.

    Als Ergebnis kommt 96 heraus, weil das dezimale Äquivalent des Zeichens
    `'0'` in der ASCII Kodierung der Wert 48 ist.

b. Danach werden Konvertierungen vorgenommen, um die Typen eines Ausdruckes auf
    einen gemeinsamen Typ zu bringen. Die exakten Regeln sind am Besten in
    einer Referenz nachzulesen, aber das zugrunde liegende Prinzip ist, dass
    jeweils auf den nächst größeren Datentyp konvertiert wird.

    Das folgende Beispiel in der Datei `conversions.cpp` soll dies
    demonstrieren:

    ~~~{.cpp}
    #include <iostream>
    
    using namespace std;
        
    int main() {
        long long int ll{};
        char c{};
    
        cout << "sizeof(ll) = " << sizeof(ll) << endl;
        cout << "sizeof(c) = " << sizeof(c) << endl;
        cout << "sizeof(ll + c) = " << sizeof(ll + c) << endl;
    }
    ~~~

    Auf meinem System kommt es zu folgender Ausgabe:

    ~~~{.sh}
    sizeof(ll) = 8
    sizeof(c) = 1
    sizeof(ll + c) = 8
    ~~~

    Du siehst, dass auf meinem System ein `long long int` die Größe 8 hat,
    während die Größe eines `char` eben 1 ist. Das Ergebnis der Addition hat
    ebenfalls die Größe 8, weil eben der kleinere Typ `char` zuerst auf einen
    `int` aufgeweitet wird und danach per impliziter
    Konversion in einen `long long int` konvertiert worden ist.

c. Als Spezialfall von b. wird der Typ des Werts des Ausdruckes in den Typ von
    der Variable der linken Seite der Zuweisung gebracht. Hier muss man
    speziell aufpassen! Hänge folgende Codezeilen an das Programm an:

    ~~~{.cpp}
    int i{};
    i = 3.5;
    cout << i << endl;
    ~~~

    Das Programm übersetzt einwandfrei und liefert selbstverständlich den Wert
    `3` auf der Ausgabe. Gegen eine einengende Konvertierung bei der
    Initialisierung können wir uns mit der einheitlichen Initialisierung
    wehren, aber bei einer Zuweisung kommt es -- aufgrund der Wurzeln in der
    Programmiersprache -- zu impliziten Konvertierungen, die in der Regel nicht
    gewollt sind.

    Leider kann es noch viel unangenehmer werden. Füge folgende Zeile an das
    Programm an:

    ~~~{.cpp}
    char c = 128;
    cout << c << endl;
    ~~~

    Auf einem System mit 8 Bit vorzeichenbehafteten `char`s, kommt es zu einem
    Überlauf und zu undefiniertem Verhalten. Daher sollten derartige
    Konvertierungen weitgehend vermieden werden. Kann dies nicht erreicht
    werden, dann sollte eine explizite Konvertierung zwecks Dokumentation
    vorgenommen werden.

    Helfen kann man sich, indem man den Compiler beauftragt, eine Warnung
    anzuzeigen, wenn eine derartige implizite, nicht werterhaltende
    Konvertierung vorgenommen wird. Für die entsprechende Option für den
    Compiler siehe Anhang \in[compilation].

## Automatische Typbestimmung

Es gibt in \cpp zwei Möglichkeiten wie man den Typ im Zuge einer Deklaration
von \cpp bestimmen lassen kann:

- Einerseits kann das schon bekannte `auto` verwendet werden (siehe Abschnitt
    \in[initialization]). Der große Vorteil tritt zutage, wenn `auto` im
    Zusammenhang mit Templates verwendet wird.

    In \cpp gibt es -- wie in vielen anderen Programmiersprachen auch -- ein
    Iteratorkonzept. Ein Vektor kann nicht nur mittels einer Zählschleife und
    Zugriff über den Index oder einer "for each" Schleife, sondern auch mittels
    eines Iterators durchlaufen werden.

    Teste das folgende Programm:

    ~~~{.cpp}
    // iterators.cpp
    #include <iostream>
    #include <vector>
    
    using namespace std;
    
    int main() {
        vector<int> v{1, 2, 3, 4, 5};
        
        for (vector<int>::iterator it{v.begin()};
             it != v.end(); ++it)
            cout << *it << endl;
    }
    ~~~

    Was passiert? Zuerst wird ein Vektor mit `int` Werten angelegt und
    initialisiert. Dann werden mittels einer `for` Schleife alle Werte des
    Vektors durchlaufen und ausgegeben.

    Der interessante Aspekt liegt in den Iteratoren. Am Beginn der Schleife
    wird ein Iterator mittels `begin()` initialisiert. Dieser Iterator zeigt an
    den Beginn des Vektors. Solange der Iterator nicht an das Ende zeigt, wird
    der Schleifenrumpf betreten und am Ende der Iterator weitergesetzt.

    Das Komplizierte an dieser Schleife ist, den korrekten Typ des Iterators zu
    bestimmen und anzuschreiben. Dazu muss man entweder das Wissen haben, wie
    dieser Typ aussieht oder die Dokumentation zurate ziehen. Unabhängig davon
    ist es jedoch mühselig diesen anzuschreiben. Hier kommt das Schlüsselwort
    `auto` gerade recht. Ändere den Schleifenkopf entsprechend ab:

    ~~~{.cpp}
    for (auto it = v.begin(); it != v.end(); ++it)
    ~~~

    Das sieht ja schon viel einfacher aus!  Der Compiler kennt ja den
    Rückgabewert von `vector::begin()` und deshalb können wir den Compiler den
    Typ selbständig bestimmen lassen. Beachte lediglich, dass die
    Initialisierung mittels der geschwungenen Klammern -- wie schon besprochen
    -- durch ein Gleichheitszeichen ersetzt wurde.

- Die zweite Möglichkeit besteht darin, `decltype()` zu verwenden, das
    hauptsächlich bei der Deklaration von Templates Verwendung findet. Für eine
    Verwendung verweise ich auf Abschnitt \in[functiontemplates] auf der Seite
    \at[functiontemplates].

## `using` Direktive und Deklaration {#using}

Das Schlüsselwort `using` wird in drei verschiedenen Arten verwendet:

- Die erste Variante kennen wir schon (`using`-Direktive), die bewirkt, dass
    *alle* Bezeichner des angegebenen Namensraumes im aktuellen Geltungsbereich
    zugreifbar sind. Obwohl alle Bezeichner zugreifbar sind, werden diese nicht
    zum lokalen Scope hinzugefügt.

    Das klassische Beispiel ist `using namespace std;`, das jedoch **nie** in
    Headerdateien (siehe Abschnitt \in[headers]) verwendet werden
    soll. Die Gefahr ist, dass der aktuelle Namensraum durch eine Unmenge von
    Bezeichnern überflutet wird und man nicht genau ermitteln kann, woher ein
    spezieller Bezeichner stammt.

    Wichtig ist, dass zwar alle Namen aus dem angegebenen Namensraum zugreifbar
    sind, diese aber nicht im aktuellen Bereich als deklariert gelten:

    ~~~{.cpp}
    // namespace_directive.cpp
    #include <iostream>
    
    int main() {
        using namespace std;

        int cin{0};
        cout << cin << endl;
    }
    ~~~

    Als Ausgabe wird erwartungsgemäß nur `0` erscheinen.

- Weiters kommt `using` in Form eines Typalias (*type alias declaration*) vor,
    der einen neuen Namen im bestehenden Bereich für einen bestehenden Typ
    deklariert. Es wird kein neuer Typ erzeugt und es kann auch kein
    bestehender Typ verändert werden. Es wird ein neuer Name für einen schon
    bestehenden Typ zum lokalen Scope hinzugefügt.

    Das macht manchmal Sinn, wenn der ursprüngliche Typname zu kompliziert oder
    zu lange ist. Im folgenden Beispiel ist dies zu sehen:

    ~~~{.cpp}
    // using.cpp
    #include <iostream>
    #include <vector>
    
    int main() {
        using IntStack = std::vector<int>;
        
        IntStack stack{};
        
        stack.push_back(1);
        stack.push_back(2);
        stack.push_back(3);
    
        std::cout << "top: " << stack.back() << std::endl;
        stack.pop_back();
        std::cout << stack.back() << std::endl;
        stack.pop_back();
        std::cout << "bottom: " << stack.back() << std::endl;
        stack.pop_back();
    }
    ~~~

    Es kommt erwartungsgemäß zu folgender Ausgabe:

    ~~~{.cpp}
    top: 3
    2
    bottom: 1
    ~~~

    Die Funktionsweise ist folgende:

    - Hier wird dem Typ `std::vector<int>` der neue Name `IntStack` gegeben, der
        in weiterer Folge zur Definition der Variable `stack` verwendet wird.
    - Mittels `push_back()` kann man einem Vektor hinten Elemente anfügen.
    - Der Zugriff auf das letzte Element erfolgt mittels `back()`.
    - Das letzte Element kann mittels `pop_back()` aus dem Vektor entfernt
      werden. Diese Methode liefert keinen Wert zurück.
    - Beachten muss man, dass man jetzt auf `cout` und `endl` explizit mittels dem
      `::` Operator zugreifen muss, da keine `using namespace std;` Direktive
      im Programm enthalten ist.

    Beachte, dass es sich um eine Deklaration handelt und hiermit das folgende
    Programm der Compiler *nicht* übersetzen wird, da es zwei Deklarationen mit
    dem gleichen Bezeichner enthält:

    ~~~{.cpp}
    // using_wrong.cpp
    #include <iostream>
    #include <vector>
    
    int main() {
        using IntStack = std::vector<int>;

        using IntStack = std::vector<char>;
    }
    ~~~

- In der Form einer `using`-Deklaration wird diese verwendet, um gezielt einen
    Bezeichner aus einem Namensraum im aktuellen Geltungsbereich verwenden
    zu können. Auch hierbei wird ein Bezeichner zum lokalen Scope hinzugefügt.

    - Einerseits handelt es sich um eine Kurzschreibweise eines Typalias. Die
        folgende `using`-Deklaration:

        ~~~{.cpp}
        using std::vector;
        ~~~

        ist äquivalent zu dem folgenden Typalias:

        ~~~{.cpp}
        using vector = std::vector;
        ~~~

    - Andererseits kann eine `using`-Deklaration auch verwendet werden, um
        einen Bezeichner, der keinen Typ darstellt, im aktuellen Bereich
        verwenden zu können:
        
        Im gerade besprochenen Programm, das den Typalias demonstriert hat,
        haben wir gesehen, dass wir jetzt explizit `std::cout` und `std::endl`
        verwenden mussten. Da es sich allerdings um derart häufig verwendete
        Objekte handelt, macht es Sinn, diese gezielt im aktuellen
        Geltungsbereich zu importieren.

        Füge deshalb in deiner Datei `using.cpp` *vor* dem Beginn von `main`
        die folgenden beiden Zeilen ein:

        ~~~{.cpp}
        using std::cout;
        using std::endl;
        ~~~
    
        Damit kannst du in weiterer Folge die Objekte `cout` und `endl` wieder
        unqualifiziert verwenden. Beachte den kleinen Unterschied, der hier
        absichtlich eingebaut wurde: Die beiden `using`-Deklarationen sind in der
        gesamten Datei verfügbar, während der Typalias `IntStack` nur in der
        Funktion `main` zur Verfügung steht.
