
# Einstieg in `C++` {#first_steps}

<div class="drawer">
Dieses Kapitel gibt einen Überblick über die prozedurale Programmierung mit
\cpp und führt die wichtigsten syntaktischen Elemente ein. Am Ende bist du in
der Lage einfache textorientierte Programme zu schreiben.

Folgende Konzepte werden *überblicksmäßig* beschrieben:

- Programmgerüst und Kommentare
- Einfache Ausdrücke und Anweisungen
- Variable und Datentypen: C-Strings und `string`, Zeichen, Zahlen,
    Wahrheitswerte
- Präprozessoranweisungen, Namensräume
- Verarbeitung der Kommandozeilenargumente
- Ein- und Ausgabe über die Standardkanäle
- Zusammengesetzte Anweisungen: Bedingte Anweisung, Auswahl- und
    Schleifenanweisungen
- Arrays und Pointer
- Klasse `vector` und Verwendung von `sort`
- Definition einer eigenen Funktion
</div>

## Das minimale Programm {#minimal_program}

Jedes \cpp Programm muss *genau* eine Funktion haben, die `main` heißt.  Diese
Funktion `main` wird ausgeführt, wenn das Programm gestartet wird. Für das
kürzeste \cpp Programm sieht diese Funktion `main` aus wie im nachfolgenden
Quelltext zu ersehen:\index{main}\index{main+ohne Parameter}

~~~{.cpp #minimalCpp}
int main() {
}
~~~

Schreibe diesen Text in eine Datei mit dem Namen `minimal.cpp` und übersetze
diese Datei in ein ausführbares Programm `minimal` bzw.\ `minimal.exe` unter
Windows. Führe danach dieses Programm folgendermaßen aus:

~~~{.sh}
$ minimal
~~~

Das Zeichen `$` gefolgt von einem Leerzeichen sind meine definierten
Promptzeichen, die bei dir durchaus anders aussehen können. Der Prompt ist das
Zeichen deiner Shell, dass sie auf eine Eingabe wartet. Oft wird im Prompt auch
noch das aktuelle Verzeichnis oder zusätzliche Information angezeigt. Bei mir
sind es lediglich die beiden Zeichen, damit du siehst was eingegeben wird
und was die Ausgabe ist.

Du bemerkst, dass es zu keiner Ausgabe kommt. Das ist natürlich klar, da keinerlei
Anweisungen im Programm enthalten sind.

Eine Funktion ist in \cpp so aufgebaut, dass zuerst der Typ
des Rückgabewertes angegeben wird, danach der Name der Funktion, gefolgt
von der Parameterliste in runden Klammern und am Ende folgt der Rumpf
der Funktion in geschwungenen Klammern.

Wir bezeichnen in weiterer Folge einen Abschnitt, der beliebig viele
Anweisungen (engl. *statements*) enthalten kann und mit einer offenen und einer
schließenden geschwungenen Klammer eingeschränkt ist, als einen Block (engl. *block*).

Damit stellt der Funktionsrumpf ebenfalls einen Block dar.

Der Typ des Rückgabewertes der Funktion `main` muss `int`
sein. `int` ist eine Typangabe für ganze Zahlen (engl. *integer*) in
\cpp. Es ist für die Funktion `main` allerdings nicht erforderlich,
dass sie tatsächlich einen Wert zurückliefert. Wir kommen etwas später
darauf zu sprechen.

Bei `int` handelt es sich weiter um ein Schlüsselwort (engl. *keyword*,
eingedeutscht Keyword). Ein Keyword ist Teil der Programmiersprache und kann
nicht als Name einer Funktion, einer Variable,... verwendet werden.

Die Parameterliste ist in dieser von uns derzeit verwendeten Form für die
Funktion `main` leer und auch der Rumpf dieser Funktion ist derzeit noch leer.
Damit wird dieses Programm bei der Ausführung auch überhaupt nichts bewirken.

Ein Programm besteht aus einer Folge von Anweisungen.  Anweisungen werden in
\cpp herangezogen, um die Reihenfolge der Ausführung der einzelnen
Prozessorinstruktionen anzugeben.

Viele Anweisungen werden in \cpp oft mit einem Strichpunkt
(engl. *semicolon*) abgeschlossen. Die leere Anweisung ist einfach ein
einzelner Strichpunkt. Das folgende Programm besitzt ebenfalls keine
Funktionalität, da im Rumpf der Funktion `main` nur eine leere Anweisung steht:

~~~{.cpp #minimalCpp}
int main() {
    ;
}
~~~

Es ist zu erwähnen, dass in \cpp sogenannte Whitespace-Zeichen wie
einzelne Leerzeichen, Leerzeilen und Tabulatorzeichen ignoriert werden.
Davon ausgenommen sind natürlich Whitespace-Zeichen in Strings.

Damit im Rumpf der Funktion `main` irgendetwas steht, schreiben wir
zwei Kommentare hinein:

~~~{.cpp #minimalCpp}
int main() {
    // das ist ein einzeiliger Kommentar
    /* und dieser Kommentar erstreckt sich
       über mehrere Zeilen.
    */
}
~~~

Einzeilige Kommentare werden mit den Zeichen `//` eingeleitet und enden mit dem
Ende der Zeile. Jedes beliebige Zeichen kann in einen einzeiligen Kommentar
geschrieben werden.

Mehrzeilige Kommentare beginnen mit `/*` und enden mit `*/` und können mit
Ausnahme von `*/` jede beliebige Zeichenkombination enthalten.  `*/` darf nicht
enthalten sein, da diese Zeichenkombination den mehrzeiligen Kommentar beendet.
Damit sind keine verschachtelten mehrzeiligen Kommentare möglich.

## Rückgabewert der Funktion `main`

Jetzt erinnern wir uns daran, dass die Funktion `main` einen Rückgabewert
`int` haben muss und dass dieser bei `main` nicht angegeben werden muss.

Damit stellen sich drei Fragen:

- Wie kann man auf den Rückgabewert zugreifen?

    Es hängt davon ab, wie das Programm, das den Rückgabewert zurückliefert
    gestartet worden ist. Das kann einerseits durch ein "normales" Programm
    (z.B. auch in \cpp geschrieben) oder durch eine Shell erfolgen.

    Für unser Ausprobieren ist es am einfachsten den Rückgabewert nach
    dem Ausführen unseres Programmes durch die Shell abzufragen. Dieses
    Zugreifen auf den Rückgabewert erfolgt je Betriebssystem und Shell
    unterschiedlich. Eine Kurzanleitung ist im Anhang im Abschnitt
    \in[access_exit_code] auf der Seite \at[access_exit_code] zu finden.

- Wie kann eine Funktion einen Rückgabewert zurückgeben?

    Eine Funktion kann einen Wert mittels des Schlüsselwortes `return`
    zurückgeben:

    ~~~{.cpp #minimalCpp}
    int main() {
        return 0;
    }
    ~~~

    In diesem Fall wird 0 zurückgegeben. Das bedeutet, dass der Exit-Code in
    der Shell dann ebenfalls 0 beträgt. Der Wert 0 wird in der Regel als Erfolg
    gedeutet, während allen anderen Werten je Anwendung unterschiedliche
    Bedeutung zugewiesen wird.

- Welchen Wert erhält man, wenn man keinen Wert von `main` zurückgibt?

    Durch Ausprobieren kannst du leicht herausfinden, dass defaultmäßig 0
    zurückgeliefert wird. `main` ist die einzige Funktion, die in \cpp explizit
    keinen Wert zurückliefern muss (mittels \type{return}), obwohl sie einen
    Typ als Rückgabewert (nämlich `int`) angegeben hat.


## Hello World {#helloworld}

Jetzt nehmen wir die nächste Hürde und schreiben das klassische "Hello World"
Programm in eine Datei `hello.cpp`:

~~~{.cpp}
// hello.cpp
#include <iostream>

int main() {
    std::cout << "Hello, world!" << std::endl;
}
~~~

Nach dem Übersetzen und Linken kommt es zu folgender erwarteter Ausgabe bei dem
Ausführen des Programmes:

~~~{.sh}
$ hello
Hello, world!
~~~

Ok, und was passiert eigentlich im Programm?

- In Zeile 2 wird eine sogenannte Header-Datei eingebunden. Das bedeutet, dass
    der Inhalt der angegebenen Datei `iostream` an dieser Stelle, an der die
    `#include` Direktive (Befehl) steht eingelesen wird. Damit steht alles was
    sich in dieser Datei befindet an dieser Stelle zu Verfügung. Dieses
    Einbinden wird *vor* dem eigentlichen Übersetzen durch einen Präprozessor
    (engl. *preprocessor*) durchgeführt. Der Compiler sieht danach sowohl den
    Inhalt der eingebundenen Datei als auch den Rest der Datei `hello.cpp`.

    Der Präprozessor wird in C-basierten Sprachen dazu verwendet,
    Textersetzungen vorzunehmen, bevor der eigentliche Compiler den Quellcode
    bekommt. Der Präprozessor liest die Präprozessordirektiven, die immer mit
    dem Rautezeichen `#` (Hashzeichen, Nummernzeichen) beginnen und führt diese
    aus.

    In Header-Dateien sind Deklarationen enthalten. Eine Deklaration ist zum Beispiel
    eine Funktionsdeklaration, die den Namen, den Rückgabewert und die Typen
    der Parameter festlegt. Ein Name einer Funktion (oder Variable, Typ,...)
    wird als Bezeichner (engl. *identifier*) bezeichnet.

    Im Fall der Header-Datei `iostream` sind unter anderem die Deklarationen von
    `cout` und `endl` enthalten.  Allerdings sind diese in einem Namensraum
    (engl. *namespace*) `std` enthalten auf die hier mittels `::` zugegriffen wird.

    Ein Namensraum ist ein Behälter, der Bezeichner beinhalten kann, die
    unabhängig von Bezeichnern außerhalb dieses Behälters sind. Ein Beispiel
    aus dem täglichen Leben wären die Vorwahlen von Telefonnummern. Eine
    Vorwahl dient als Behälter für die nachfolgende Rufnummer, sodass es zu
    keinem Konflikt mit einer gleichen Rufnummer aber einer anderen Vorwahl
    kommt.

    Als einfache Regel gilt: Alle Bezeichner der Standardbibliothek von \cpp
    sind im Namensraum `std` enthalten.

- In der Zeile 5 wird auf das Objekt `cout` im Namensraum `std` mittels des
    Operators `::` (Bereichsauflösungsoperator, engl. *scope resolution
    operator*) zugegriffen.

- In Zeile 5 wird weiters mittels des Operators `<<` die C-String-Konstante
    `"Hello, world!"` (engl. *C string literal*) ausgegeben.  Werte, die direkt
    im Quellcode geschrieben werden können, bezeichnet man als Literal
    (engl. *literal*). Beispiele sind eben hier das C-String-Literal `"Hello,
    world!"` oder die ganze Zahl `3`.

    Bei `std::cout` handelt es sich um ein Objekt, das den `stdout`
    Kanal repräsentiert. Alle Daten, die in diesen Kanal geschrieben werden,
    werden auf der Shell zur Ausgabe gebracht, wenn das Programm mittels
    einer Shell gestartet worden ist.

    Der Operator `::` liefert wieder das ursprüngliche Objekt `cout` zurück,
    sodass wiederum der Operator `<<` verwendet werden kann. Dies wird
    ausgenützt, um einen Zeilenumbruch zu erzwingen, da danach der Manipulator
    `std::endl` (*end line*, Zeilenende) an die Ausgabe gesendet wird.

- Die Zeile 5 beinhaltet genau eine einfache Anweisung, die mit einem
    Strichpunkt (engl. *semicolon*) abgeschlossen sein muss.

Weiter oben wurde noch von dem "Linken" gesprochen, das in unserem konkreten
Fall `std::cout` und `std::endl` sowie die Operatorfunktion(en) `<<` mit den
entsprechenden Definitionen verbinden muss (siehe Abschnitt \in[declaration] auf
Seite \at[declaration]). Normalerweise wird die Funktion des Präprozessors,
das eigentliche Übersetzen und auch das Linken von einem Programm übernommen.

## Eingabe und Ausgabe {#greetme_program}

Bis jetzt haben wir lediglich Ausgaben getätigt, nun werden wir uns auch
mit der Eingabe beschäftigen.

Um Daten einzugeben, existiert das Objekt `std::cin`, das den Kanal `stdin`
repräsentiert und die Eingabe zur Laufzeit des Programmes ermöglicht. Dafür
wird ebenfalls die Headerdatei `iostram` benötigt und die Funktionsweise von
`std::cin` ist analog zu `std::cout`. Schreiben wir gleich einmal das nächste
Programm, das eine Abwandlung unseres "Hello World" Programmes darstellt. Es
soll den Benutzer nach seinem Namen fragen und ihn danach nett begrüßen:

~~~{.cpp}
// greetme.cpp
#include <iostream>

using namespace std;

int main() {
    string name;
    cout << "Ihr Name bitte: ";
    cin >> name;
    cout << "Nett Sie zu sehen, " << name << "!" << endl;
}
~~~

Übersetze das Programm wie gewohnt und starte es, du wirst nach deinem
Namen gefragt und danach wird der Begrüßungstext ausgegeben:

~~~{.sh}
$ greetme
Ihr Name bitte: Maxima
Nett Sie zu sehen, Maxima!
$
~~~

Gut was ist hier Neues zu finden?

- Die Zeile 4 legt fest, dass alle Bezeichner aus dem Namensraum `std` ab jetzt
    nicht mehr mit dem Bereichsauflösungsoperator `::` qualifiziert werden
    müssen, sondern einfach verwendet werden können. Das heißt also, dass wir
    den Namensraum `std` von nun an benutzen und dies gilt bis zum Ende der
    Datei.

- In Zeile 7 wird hier zum ersten Mal eine Variable definiert. In Zeile 6 wird
    `name` als eine neue Variable definiert, die den Typ `string` hat. `string`
    ist ein \cpp Typ, der eine Zeichenkette repräsentiert, aber im Gegensatz zu
    den C-Strings ein Objekttyp ist.

    In der folgenden Zeile `cout << "Ihr Name bitte: ";` siehst du wieder eine
    C-String-Konstante. Bei einem C-String handelt es sich lediglich um eine
    Folge von Zeichen im Speicher, die mit einem Nullzeichen (`'\0'`, ein Wert
    mit allen Bits 0) abgeschlossen ist und durch eine Adresse im Speicher
    referenziert wird. Eine C-String-Konstante ist eine Möglichkeit, wie ein
    C-String im Quelltext angegeben werden kann.

    Da es sich bei `string` um einen Objekttyp handelt, gibt es dafür auch
    eine Klasse. Die Deklaration dieser Klasse steht in der Headerdatei
    `string`, die wiederum mit `#include <string>` eingebunden werden
    hätte müssen. Allerdings bindet die Headerdatei `iostream` diese
    Headerdatei `string` von selber ein und deshalb kann es in diesem Fall
    unterlassen werden.
    
    Wir werden uns den Objekttyp `string` später genauer ansehen und auch die
    Unterschiede zu einem C-String herausarbeiten.

- Weiters wird diese Variable `name` mittels des `>>` Operators aus dem
    Objekt `cin` befüllt. Da es sich bei dem Typ von `name` um einen
    `string` handelt, werden die eingegebenen Zeichen -- so wie sie sind --
    in diese Variable gespeichert.

So weit, so gut. Vielleicht hast du es schon ausprobiert einen vollständigen
Namen mit Vornamen und Nachnamen einzugeben, dann wirst du folgendes Verhalten
festgestellt haben:

~~~{.sh}
Ihr Name bitte: Maxima Muster
Nett Sie zu sehen, Maxima!
~~~

Was passiert hier? Der Operator `>>` liest maximal bis zum ersten Leerzeichen
und damit erhalten wir in unserem Fall nur den Vornamen! Ändern wir
daher das Programm nochmals ab, sodass der Vorname als auch der Nachname
eingegeben werden kann:

~~~{.cpp}
// greetme2.cpp
#include <iostream>

using namespace std;

int main() {
    string first_name;
    string last_name;
    cout << "Ihr Name bitte: ";
    cin >> first_name;
    cin >> last_name;
    cout << "Nett Sie zu sehen, " << first_name
         << " " << last_name << "!" << endl;
}
~~~

In diesem Programm lesen wir einfach zwei Strings ein und speichern diese
in zwei Variablen ab, die danach mit einem Leerzeichen getrennt ausgegeben
werden:

~~~{.sh}
Ihr Name bitte: Max Muster
Nett Sie zu sehen, Max Muster!
~~~

Diese Lösung hat allerdings den Nachteil, dass nämlich jetzt wirklich
zwei Namen eingegeben werden müssen. Probiere einfach einmal aus, nur
den Vornamen einzugeben und du wirst bemerken, dass das Programm nach der
ersten Eingabe noch auf eine zweite Eingabe wartet!

Was kann man bei der Ausführung dieses Programmes also tun?

- Einerseits kann natürlich das Programm abgebrochen werden. Das kann in
    der Regel mit der Tastenkombination `CTRL+C` erreicht werden. In diesem
    Fall bricht aber das Programm eben ab und es wird zu keiner Ausgabe
    kommen.

- Die zweite Möglichkeit besteht darin, dem Programm mitzuteilen, dass die
    Eingabe beendet ist, d.h. dass der Eingabekanal für diese Operation
    geschlossen wird. Das kann unter Linux oder Mac OSX mittels der
    Tastenkombination `CTRL+D` und unter Windows mittels `CTRL+Z`
    erreicht werden. D.h. nach der erfolgreichen Eingabe des ersten
    Wertes wird die zweite Eingabe mit einem Leerstring versehen.

Bei beiden Varianten handelt es sich eigentlich um keine vernünftigen Lösungen.

Verändern wir deshalb das Programm nochmals:

~~~{.cpp}
// greetme3.cpp
#include <iostream>

using namespace std;

int main() {
    string name;
    cout << "Ihr Name bitte: ";
    getline(cin, name);
    cout << "Nett Sie zu sehen, " << name << "!" << endl;
}
~~~

In diesem Programm verwenden wir die Funktion `getline`, die sowohl das Objekt
`cin` als auch eine Variable vom Typ `string` mitbekommt.  Die Funktionsweise
ist, dass eine gesamte Zeile des Eingabekanals in die Variable `name`
eingelesen wird. Beachte, dass es in \cpp möglich ist, Parameter zu übergeben,
die in der Funktion verändert werden, wie dies bei `name` zu sehen ist und wie
es die Funktion `getline` handhabt.

Weiters siehst du auch, dass diese Funktion `getline` anscheinend in
der Headerdatei `iostream` enthalten ist, da der Compiler keinen Fehler
meldet.

Durch diese Lösung ist natürlich auch keine Aufteilung in Vorname und Nachname
mehr möglich, dafür sind aber auch mehrere Namensteile wie mehrere Vornamen
oder Doppelnamen möglich. Probiere es einfach aus!

<div class="drawer">
Es könnte sein, dass die Behandlung von Sonderzeichen unter Umständen nicht
korrekt funktioniert. Das liegt daran, dass dein System wahrscheinlich nicht
richtig konfiguriert ist. Kontrolliere deine Systemeinstellungen!
</div>

## Ganze Zahlen und `if` {#agetest_program}

Im nächsten Schritt wollen wir uns mit einem weiteren grundlegenden Datentyp,
nämlich den ganzen Zahlen beschäftigen und als erste Kontrollstruktur die `if`
Anweisung einsetzen.

Schreiben wir jetzt ein Programm, das das Alter des Benutzers abfragt und
danach eine Altersüberprüfung vornimmt. Ist das Alter unter 18 Jahren, dann
soll ausgegeben werden, dass der Benutzer noch nicht volljährig ist, ansonsten,
dass er volljährig ist.

Schreibe deshalb folgendes Programm:

~~~{.cpp}
// agetest.cpp
#include <iostream>

using namespace std;

int main() {
    int age;

    cout << "Wie alt sind Sie? ";
    cin >> age;
    
    if (age < 18) {
        cout << "Sie sind noch minderjährig!" << endl;
    } else {
        cout << "Sie sind volljährig!" << endl;
    }
}
~~~

Probiere das Programm jetzt aus und dann werden wir es besprechen.

Fertig? Dann schauen wir uns das einmal an:

- Zuerst sehen wir, dass wir eine Variable `age` vom Typ `int` (Abkürzung für
    *integer*, ganze Zahl) definieren.  Das heißt, wir drücken aus, dass wir
    eine Variable mit dem Bezeichner "age" wollen, die ganze Zahlen speichern kann.

- Weiters sehen wir, dass wir den Operator `>>` nicht nur zur Eingabe von
    Strings, sondern auch zur Eingabe von ganzen Zahlen verwenden
    können. Der Benutzer gibt eine Zeichenkette ein und `>>` wandelt diese
    in eine ganze Zahl um, wenn dies möglich ist (mehr dazu später).

    Weiters gehen wir davon aus, dass der Benutzer nur erlaubte Eingaben
    tätigt. Wir werden uns später noch eingehend damit auseinandersetzen, wie
    man mit fehlerhaften Eingaben umgehen kann.

- Außerdem sehen wir danach die erste zusammengesetzte Anweisung, nämlich die
    Bedingungsanweisung, die die Bedingung nach dem Schlüsselwort `if`
    (zu Deutsch: wenn, falls) in runden Klammern enthält. Ist die Bedingung wahr, dann
    werden die direkt folgenden Anweisungen des ersten Anweisungsblockes (in
    den geschwungen Klammern) ausgeführt, anderenfalls die Anweisung
    nach dem Schlüsselwort `else` (dt. anderenfalls).

    Bedingungen setzen sich meist aus Vergleichsoperatoren und logischen
    Operatoren zusammen.

    An Vergleichsoperatoren stehen uns für Zahlen die üblichen Kandidaten
    `<` (kleiner), `<=` (kleiner gleich), `!=` (ungleich), `==` (gleich), `>=`
    (größer gleich) und `>` (größer) zur Verfügung.

    Die logischen Operatoren werden wir später noch besprechen.

    Ein `else` Teil ist nicht notwendig. Dieser kann auch weggelassen werden.
    Damit kann das Programm auch ohne Verwendung von `else` Teilen
    umgeschrieben werden. Dies ist zwar nicht so elegant und lesbar, aber
    möglich. Die entsprechenden Bedingungsanweisungen sehen danach
    folgendermaßen aus:

    ~~~{.cpp}
    if (age < 18) {
        cout << "Sie sind noch minderjährig!" << endl;
    }

    if (age >= 18) {
        cout << "Sie sind volljährig!" << endl;
    }
    ~~~

- Die Anweisungen in einer zusammengesetzten Anweisung wie der `if`
    Anweisung müssen prinzipiell in geschwungenen Klammern geschrieben
    werden, wie wir es schon gesehen haben.

    Es gibt allerdings eine Ausnahme: Handelt es sich jeweils nur um eine
    einzelne Anweisung, dann können die geschwungenen Klammern entfallen, d.h.
    die Verzweigungsanweisung kann in diesem Fall auch folgendermaßen
    geschrieben werden:

    ~~~{.cpp}
    if (age < 18)
        cout << "Sie sind noch minderjährig!" << endl;
    else
        cout << "Sie sind volljährig!" << endl;
    ~~~

    Das bedeutet, dass Anweisungen innerhalb von geschwungenen Klammern
    überall dort verwendet werden können wo auch eine einzelne Anweisung steht.

    Ich empfehle diese Vorgangsweise aber *nicht*: Fügst du später weitere
    Anweisungen ein, dann kann man leicht darauf vergessen die geschwungenen
    Klammern hinzuzufügen und das Programm lässt sich entweder nicht übersetzen
    oder es wird nicht richtig funktionieren.


Wie sieht es aus, wenn wir eine feinere Unterscheidung haben wollen:

 Altersgruppe    von   bis
--------------  ----- -----
    Kind          0    <14
 Jugendlicher    14    <18
 Erwachsener     18     -

Mit den uns bekannten Mitteln kann man diese Aufgabenstellung ohne Probleme
folgendermaßen lösen.  Beachte, dass ich jetzt absichtlich keine geschwungenen
Klammern gesetzt habe:

~~~{.cpp}
if (age < 18)
    if (age < 14)
        cout << "Du bist noch ein Kind." << endl;
    else 
        cout << "Sie sind ein Jugendlicher!" << endl;
else
    cout << "Sie sind volljährig!" << endl;
~~~

Das ist soweit verständlich und funktionsfähig. Nehmen wir nun einmal an, dass
uns nicht interessiert, ob jemand jugendlich ist oder nicht. Uns interessiert
nur, Kind oder Erwachsener. Die naheliegende Lösung ist, den entsprechenden
`else` Zweig einfach zu löschen:

~~~{.cpp}
    if (age < 18)
        if (age < 14)
            cout << "Du bist noch ein Kind." << endl;
    else
        cout << "Sie sind volljährig!" << endl;
~~~

Damit funktioniert das Programm nicht mehr gemäß unseren Erwartungen. Wir haben
zwar sinnvoll eingerückt, aber in \cpp wird Whitespace nicht betrachtet. Damit
zählt das `else` zur zweiten `if` Anweisung! Das wäre nicht passiert, hätten
wird geschwungene Klammern verwendet!

Allerdings sollte man solche Art von verschachtelten Verzweigungen eher
vermeiden. Schreibt man das Programm um, dann funktioniert es wie erwartet und
ist auch besser zu lesen:

~~~{.cpp}
if (age < 14) {
    cout << "Du bist noch ein Kind." << endl;
} else if (age < 18) {
    cout << "Sie sind ein Jugendlicher!" << endl;
} else {
    cout << "Sie sind volljährig!" << endl;
}
~~~


## Addieren von ganzen Zahlen

Nehmen wir einmal an, wir wollen ein einfaches Programm schreiben, das einfach
nur zwei Zahlen einliest, die erste Zahl zu der zweiten Zahl addiert und das
Ergebnis ausgibt.

Eine sehr einfache Problemstellung, aber trotzdem können wir hier wieder
einiges über \cpp lernen. Beginnen wir gleich einmal mit dem folgenden
Programm:

~~~{.cpp}
// add.cpp
#include <iostream>

using namespace std;

int main() {
    int num1;
    int num2;
    int res;

    cout << "Die erste Zahl: ";
    cin >> num1;
    cout << "Die zweite Zahl: ";
    cin >> num2;

    cout << "Das Ergebnis ist: " << res << endl;
}
~~~

Was gibt es hier wieder Neues? Eigentlich gar nichts. Aber starte einmal das
Programm, gib beliebige Werte für die beiden Zahlen ein und schaue dir die
Ausgabe an. Sie wird in *etwa* folgendermaßen aussehen und wird bei dir
vermutlich ein anderes Ergebnis anzeigen.

~~~{.sh}
$ div
Die erste Zahl: 1
Die zweite Zahl: 2
Das Ergebnis ist: -1218654208
~~~

Die Variable `res` wurde **nicht** initialisiert, d.h. es wird kein Wert in
diese Variable geschrieben. Was ist aber der Wert von `res` nach der
Definition?  Die Variable enthält den Wert, den der Speicherinhalt zu dieser
Zeit repräsentiert. Damit ist es vom aktuellen Bitmuster des Speicherinhaltes
abhängig.

Die Variable `res` ist eine lokale Variable, da diese innerhalb der Funktion
`main` definiert wurde. Merke: Lokale Variable, die einen fundamentalen
Datentyp (eingebaute Datentypen wie ganze Zahlen, Gleitkommazahlen,...)
besitzen werden in \cpp{} **nie** automatisch initialisiert.  Wir werden später
noch auf die fundamentalen Datentypen eingehen.

Was können wir also machen?  Wir könnten nach der Definition der Variable
`res` dieser einen Wert *zuweisen*:

~~~{.cpp}
int res;

res = 0;
~~~

Ok, das ändert aber nichts daran, dass diese Variable am Beginn noch immer
nicht initialisiert wurde. Gut, dann lernen wir gleich wie man eine Variable
in \cppXI korrekt initialisiert:

~~~{.cpp}
int res{0};
~~~

D.h. der Initialisierungswert wird in geschwungenen Klammern nach dem
Variablennamen geschrieben. In diesem konkreten Fall ist der Effekt gleich
wie wenn man die Variable nicht initialisiert und ihr dann einen Wert
zuweist. Verwendet man jedoch komplexe Objekte, dann kann dies zu einem
Performanceverlust führen.

<div class="thumb">
Lokale Variable **immer** initialisieren!

Es gibt eigentlich nur eine Ausnahme von dieser Regel: Hat das zu
initialisierende Objekt einen hohen Initialisierungsaufwand und wird es zuerst
beschrieben und erst dann gelesen, kann man die Initialisierung weglassen.  Im
Abschnitt \in[array] findest du auf der Seite \at[array] eine Beschreibung der
Auswirkung der Initialisierung eines Arrays.  </div>

Allerdings geht es mit der vereinheitlichten Initialisierung in diesem Fall
noch einfacher:

~~~{.cpp}
int res{};
~~~

Du siehst, dass du die `0` weglassen kannst. In diesem Fall wird die Variable
mit dem "Nullwert" initialisiert, falls es sich um einen sogenannten
fundamentalen Datentyp handelt.

Es besteht auch die Möglichkeit den Wert direkt bei der Definition der Variable
anstatt der geschwungenen Klammern mit einem `=` Zeichen zu initialisieren:

~~~{.cpp}
int res = 0;
~~~

Das hat den gleichen Effekt. Trotzdem empfehle ich die Form mit den
geschwungenen Klammern, die als einheitliche Initialisierung (engl. *uniform
initialization*) bezeichnet wird und in \cppXI zum Sprachstandard hinzugekommen
ist. Der Vorteil dieser Form ist, dass diese weitgehend *überall* in \cpp
zur Initialisierung verwendet werden kann (im Kontrast zu der Form mit `=`).

Ändern wir jetzt das Programm so ab, dass es die gewünschte Addition
durchführt. Füge dazu direkt nach der Eingabe der zweiten Zahl folgende
Anweisung in das Programm ein:

~~~{.cpp}
res = num1 + num2;
~~~

Damit wird die erste Zahl zur zweiten Zahl addiert und in das Ergebnis
der Variable `res` zugewiesen. Schaut man sich das Programm jetzt an, dann sieht
man unschwer, dass die Initialisierung der Variable `res` jetzt nicht mehr
nötig wäre. Wir lassen das Programm trotzdem in dieser Form, da wir unsere
Faustregel beachten!

Das Zuweisen des Ergebnisses zu der Variable `res` geschieht mittels des
Zuweisungsoperators `=`. Es handelt sich hier **nicht** um eine
Initialisierung, sondern um eine Zuweisung. Das ist wichtig für das weitere
Verständnis von \cpp.

Als ein Ausdruck (engl. *expression*) wird ein syntaktisches Konstrukt
bezeichnet, das zu einem *Wert* ausgewertet werden kann. `num1 + num2` ist
ein Ausdruck. In \cpp ist `res = num1 + num2` ebenfalls ein Ausdruck, da der
Wert dieses Ausdruckes das Ergebnis der Addition ist.

Dieser Ausdruck `res = num1 + num2` beinhaltet eben einen weiteren Ausdruck,
nämlich `num1 + num2`, der wiederum zwei Ausdrücke beinhaltet, nämlich `num1`
und `num2`. Wir sehen, dass ein Ausdruck wieder aus (Teil-)Ausdrücken bestehen
kann.  Als vollständiger Ausdruck (engl. *full expression*) wird ein Ausdruck
verstanden, der nicht Teil eines anderen Ausdruckes ist. In unserem konkreten
Fall handelt es sich bei `res = num1 + num2` um einen vollständigen Ausdruck und
bei `num1 + num2` beziehungsweise bei `num1` oder `num2` um *keine*
vollständigen Ausdrücke.

Hängt man an einen Ausdruck einen Strichpunkt, wird daraus eine Anweisung! Damit
handelt es sich bei `res = num1 + num2;` um eine Anweisung. Im Unterschied zu
einem Ausdruck hat eine Anweisung *keinen* Wert.

Die anderen grundlegenden arithmetischen Operatoren sind `-` (Subtraktion), `*`
(Multiplikation) und `/` (Division). \cpp kennt selbstverständlich die üblichen
Regeln zur Punkt- und Strichrechnung, wobei Klammern gesetzt werden können, um
eine beliebige Berechnungsreihenfolge herzustellen (z.B. `a * (b + c)`).

Jedem Operator ist nicht nur eine Priorität zugewiesen, die die Reihenfolge der
Berechnung festlegt, sondern auch eine Assoziativität. Die Assoziativität
bestimmt wie Ausdrücke wie `a + b + c` ausgerechnet werden. `a + b + c` wird von links
nach rechts ausgerechnet (links assoziativ) und ist damit gleichwertig zu `(a +
b) + c`. Damit muss man die Klammern bei diesem speziellen Ausdruck nicht
verwenden, sie sind in diesem Fall redundant.

So, übersetze das Programm wieder und probiere es aus:

~~~{.sh}
Die erste Zahl: 1
Die zweite Zahl: 2
Das Ergebnis ist: 3
~~~

Das Ergebnis erwartet man sich natürlich. Damit wäre die geforderte
Funktionalität erfüllt.

Schauen wir uns trotzdem an was passiert, wenn der Benutzer ungültige
Werte eingibt:

- Probiere folgende Interaktion aus:

    ~~~{.sh}
    Die erste Zahl: 1
    Die zweite Zahl: 2a
    Das Ergebnis ist: 3
    ~~~

    Was passiert hier? Die erste Eingabe ist klar, es wird die ganze Zahl 1
    eingelesen. Bei der zweiten Eingabe sieht es so aus, dass eine 2 eingelesen
    wird und das Zeichen `a` weiter im Eingabestrom gelassen wird.

    Schauen wir uns das einmal an, indem wir den folgenden Text hinten als
    letzte Anweisung im Rumpf von `main` schreiben:

    ~~~{.cpp}
    string rest;
    cin >> rest;
    cout << "Der verbleibende Rest: " << rest << endl;
    ~~~

    `cin >> rest` liest genau ein Zeichen in die neue Variable `rest` ein und
    dieses wird danach ausgegeben.

    Probiere jetzt dein Programm mit den Eingaben wieder aus. Du siehst, dass
    das Zeichen `a` als Rest ausgegeben wird. Du siehst, dass die zweite Zahl
    nur soweit eingelesen wird, bis eine vollständige Zahl erkannt wird.
    Hier folgt die Ausgabe:

    ~~~{.sh}
    Die erste Zahl: 1
    Die zweite Zahl: 2a
    Das Ergebnis ist: 3
    Der verbleibende Rest: a
    ~~~

- Starte jetzt dieses Programm noch einmal und gib nur gültige Eingaben
    ein. Du bemerkst, dass die Anweisung `cin >> rest` sich jetzt die Eingabe
    eines Zeichens erwartet und du daher eines eingeben musst. Allerdings wird
    kein Leerzeichen akzeptiert, da dieses ja überlesen wird.

    Entweder du gibst ein beliebiges Zeichen ein oder du brichst die Eingabe
    ab. Das geht unter Windows mit der Tastenkombination `CTRL-Z` und unter Mac
    OSX oder Linux mittels `CTRL-D`.

- Starte jetzt das Programm noch einmal und gib zuerst `1a` ein und drücke wie
    gewohnt die Return-Taste. Die Ausgabe wird folgendermaßen aussehen:

    ~~~{.sh}
    Die erste Zahl: 1a
    Die zweite Zahl: Das Ergebnis ist: 1
    Der verbleibende Rest: 
    ~~~

    Tja, hier sehen wir, dass es überhaupt nicht funktioniert hat. Die erste
    Zahl wird richtig gelesen, die zweite Zahl kann nicht mehr gelesen werden,
    da lediglich das Zeichen `a` im Eingabestrom vorhanden ist. Damit handelt
    es sich aus Sicht von \cpp um eine fehlerhafte Eingabe, da eine ganze Zahl
    erwartet wird. Das bedeutet, die fehlgeschlagene Eingabe bewirkt, dass
    `num2` auf den Nullwert gesetzt wird und der Eingabestrom in einen
    Fehlermodus versetzt wird. Damit schlägt auch die Eingabe des Rests fehl!

    Wie man mit solchen Situationen umgeht, werden wir uns noch anschauen. Jetzt
    einmal ist es wichtig zu erkennen, wie in \cpp die Eingabe prinzipiell
    funktioniert. Hier noch einmal eine Kurzzusammenfassung:

    - Es werden Leerzeichen prinzipiell überlesen.
    - Es werden dann alle Zeichen eingelesen, sodass die Eingabe gültig für den
        eingesetzten Datentyp ist.
    - Kann nicht gültig eingelesen werden, dann wird der Variable der Nullwert
        zugewiesen und der Eingabestrom in einen Fehlermodus versetzt.

## Rechnen mit Zahlen {#minicalc}

Nachdem wir jetzt wissen wie die Eingabe und Ausgabe prinzipiell funktioniert,
und die fundamentalen Datentypen `int` und `char` kennengelernt haben und auch
die Anweisung `if` kennen, wollen wir einen kleinen Rechner entwickeln, der
einen arithmetischen Ausdruck bestehend aus zwei Operanden und einem der
Operatoren `+` (Addition), `-` (Subtraktion), `*` (Multiplikation), `/`
Division ausrechnen kann.

Gültige Ausdrücke wären: `1 + 2` (wie gehabt), `2 - 2`, `2 * 3` oder `4 / 2`.

Wir legen fest, dass wir die Eingabe wie gehabt gestalten, also zuerst die
erste Zahl eingeben, dann die Operation und danach die zweite Zahl. Das
Ergebnis wird zum Schluss angezeigt.

Ein erster Versuch führt uns zu dem folgenden Quelltext in der Datei
`calc.cpp`, wobei ich in diesem Fall nur mehr den Rumpf von main wiedergebe:

~~~{.cpp}
int num1;
int num2;
char op;  // eine Abkürzung für operator (keyword in C++!)

cout << "Die erste Zahl: ";
cin >> num1;
cout << "Operator [+,-,*,/]: ";
cin >> op;
cout << "Die zweite Zahl: ";
cin >> num2;

if (op == '+') {
    cout << "Das Ergebnis ist: " << num1 + num2 << endl;
} else if (op == '-') {
    cout << "Das Ergebnis ist: " << num1 - num2 << endl;
} else if (op == '*') {
    cout << "Das Ergebnis ist: " << num1 * num2 << endl;
} else if (op == '/') {
    cout << "Das Ergebnis ist: " << num1 / num2 << endl;
}
~~~

Bei diesem Programm verwenden wir einen neuen fundamentalen Datentyp, nämlich
`char`, das für ein einzelnes Zeichen steht. Die Variable nennen wir `op`,
da wir `operator` nicht verwenden können, da es sich um ein Keyword in \cpp
handelt. Beachte, dass Zeichenliterale des Typs `char` jeweils mit einem
einfachen Hochkomma eingeschlossen sind.

Probiere das Programm gleich aus. Es funktioniert weitgehend mit gültigen
Eingaben. Lediglich bei der Division kommt es zu zwei Problemen:

- Teste das Programm einmal mit der Berechnung von `1 / 0`. Es wird in etwa zu
    folgender Ausgabe kommen:

    ~~~{.sh}
    Die erste Zahl: 1
    Operator [+,-,*,/]: / 
    Die zweite Zahl: 0
    fish: Job 1, 'calc' durch Signal SIGFPE (Fliesskomma-Ausnahmefehler) beendet
    ~~~

    Das Programm bricht mit einer Fehlermeldung ab, weil die Division durch die
    Zahl 0 nicht definiert ist. Durch 0 kann man eben nicht dividieren.

    Dieses Problem kannst du relativ leicht beheben, indem du `0` als Eingabe
    für die zweite Zahl nicht zulässt. D.h., du kannst eine Überprüfung einbauen
    und danach das Programm beenden. Beenden kannst du es in diesem Fall
    einfach mit einer `return` Anweisung. Baue die folgende `if` Anweisung
    direkt vor die Ausgabe des Ergebnisses der Division ein:

    ~~~{.cpp}
    if (num2 == 0) {
        cerr << "Der Divisor darf nicht 0 sein!" << endl;
        return 1;
    }
    ~~~

    In diesen Fall wird eine Fehlermeldung auf `cerr` ausgegeben. Dabei handelt
    es sich um ein Objekt, das wie das Objekt `cout` funktioniert, nur dass es
    mit dem Kanal `stderr` verknüpft ist.  Dieser Kanal wird verwendet, um
    Fehlermeldungen auszugeben.  Die Ausgaben dieses Kanals sind ganz normal in
    der Shell sichtbar.

    Dann wird die Funktion vorzeitig beendet und der Wert der
    `return` Anweisung wird als Exit-Code an das aufrufende Programm zurückgegeben.

- Teste weiters die Division mit den Zahlen `1` und `2` und du wirst das
    Ergebnis `0` anstatt dem Ergebnis `0.5` erhalten. Wie in den meisten
    Programmiersprachen üblich, wird auch in \cpp zur Trennung der
    Nachkommastellen von den Vorkommastellen der Punkt verwendet.

    Warum also wird `0` angezeigt? Das hat damit zu tun, dass beide Operanden
    ganze Zahlen sind und \cpp in diesem Fall auch nur mit ganzen Zahlen
    rechnet. D.h., dass das Ergebnis den gleichen Typ hat wie die beiden
    Operanden (vorausgesetzt diese haben beide denselben Typ).

    Dieses Problem lässt sich leicht beheben indem der Datentyp der beiden
    Zahlen zu `double` geändert wird. Bei dem fundamentalen Datentyp
    `double` handelt es sich um einen Typ, der Gleitkommazahlen repräsentiert:

    ~~~{.cpp}
    double num1;
    double num2;
    ~~~

    Probiere das Programm wieder aus. Jetzt liefert es auch bei der Division
    das erwartete Ergebnis!

    In diesem Zusammenhang ist es erwähnenswert, dass die Behandlung der
    Division durch 0 bei Gleitkommazahlen anders funktioniert als bei ganzen
    Zahlen. Damit du dieses andere Verhalten sehen kannst, nimm zeitweise
    die kürzlich hinzugefügte Überprüfung auf die Zahl 0 wieder aus dem
    Programm. Das geht am besten indem du die Überprüfung mit den Kommentarzeichen
    `/*` und `*/` umschließt:

    ~~~{.cpp}
    /*
    if (num2 == 0) {
        cerr << "Der Divisor darf nicht 0 sein!" << endl;
        return 1;
    }
    */
    ~~~

    Die Ausgabe wird für die Zahlen 1 und 0 folgendermaßen aussehen:

    ~~~{.sh}
    Die erste Zahl: 1
    Operator [+,-,*,/]: /
    Die zweite Zahl: 0
    Das Ergebnis ist: inf
    ~~~

    Es kommt zu keinem Programmabbruch! Stattdessen ergibt die Division durch 0
    einen eigenen Wert, der als "inf" (für infinity, dt. unendlich) in der
    Ausgabe erscheint. Bei Division von -1 durch 0 ergibt sich "-inf".

    Wir sehen, dass es für Gleitkommazahlen einen eigenen Wert gibt, der
    anzeigt, dass eine Division durch 0 keinen definierten Wert hat. Mehr dazu
    später.

Als Nächstes wollen wir die Struktur unseres Programmes verbessern. An sich ist
an der `if` Anweisung nichts auszusetzen, aber es besteht die Möglichkeit, dass
wir die nächste Kontrollanweisung, nämlich die `switch` Anweisung kennenlernen.
Ersetze deshalb die gesamte `if` Anweisung durch folgende Anweisungen: 

~~~{.cpp}
switch (op) {
  case '+':
    res = num1 + num2;
    break;
  case '-':
    res = num1 - num2;
    break;
  case '*':
    res = num1 * num2;
    break;
  case '/':
    res = num1 / num2;
    break;
}

cout << "Das Ergebnis ist: " << res << endl;
~~~

Hier lernen wir eine neue zusammengesetzte Anweisung kennen, die `switch`
Anweisung. Diese ist dafür gedacht, dass man eine Auswahl treffen kann. Hier
wird in Abhängigkeit des Inhaltes der Variable `op` zu einem der Fälle
(engl. *case*) verzweigt. In diesem Fall kommt eine weitere einfache
Anweisung, die `break`-Anweisung vor. Diese bewirkt, dass die Ausführung
direkt nach der `switch` Anweisung weitergeführt wird und nicht die
Anweisungen des nachfolgenden `case` abgearbeitet werden.

Würden die `break` Anweisungen entfernt werden, dann würde als Ergebnis
immer das Ergebnis der Division ermittelt werden. Probiere es aus!

Und wie sieht es aus, wenn wir mehrere Berechnungen hintereinander ausführen
wollen? Wir programmieren eine Schleife und beginnen mit einer `while`
Schleife: Der gesamte Quelltext der Eingabe, der `switch` Anweisung und auch
der Ausgabe kommt in den Rumpf folgender `while` Anweisung:

~~~{.cpp}
while (true) {
    // hierher!
}
~~~

Übersetze dein Programm und führe es aus. Wichtig ist nur zu wissen wie du so
ein Programm wieder beenden kannst. Startest du dein Programm in einer Shell,
dann beendet die Tastenkombination `CTRL-C` in der Regel das Programm, sonst
ist das Programm ganz normal über die Möglichkeiten der graphischen Oberfläche
zu beenden.

Die `while`-Anweisung erwartet sich eine Bedingung (fundamentaler Datentyp
`bool`) in runden Klammern und führt den Rumpf solange aus solange diese
Bedingung wahr ist. In \cpp gibt es zwei Wahrheitswerte, nämlich `true` und
`false`. Da wir in die runden Klammern das Literal `true` geschrieben haben,
das sich nicht ändert, wird die Schleife programmgesteuert nie abgebrochen.
Das ist auch der Grund, dass das laufende Programm letztendlich mittels
`CTRL-C` abgebrochen werden muss.

Da dies natürlich keine benutzerfreundliche Lösung ist, bauen wir das Programm
folgendermaßen um. Die Zeile mit dem Schlüsselwort `while` wird durch die
folgenden Zeilen ersetzt:

~~~{.cpp}
char proceed{'y'};

while (proceed == 'y') {
~~~

Direkt nach der Anzeige des Ergebnisses werden die folgenden Zeilen eingefügt:

~~~{.cpp}
cout << "Weiter? [y/n] ";
cin >> proceed;
cout << endl;
~~~

Der Benutzer wird gefragt, ob dieser weitermachen will und muss mit dem Zeichen
`y` bestätigen. Gibt er ein beliebiges anderes Zeichen ein, dann bricht das
Programm ab.

Wiederholen wir: Eine Zeichenkonstante ist in einfachen Hochkommas
einzuschließen und kann auch nur ein Zeichen beinhalten. Eine
C-String-Konstante ist in doppelte Hochkommas einzuschließen und kann beliebig
viele Zeichen beinhalten.

Das funktioniert schon soweit gut, solange der Benutzer nur gültige Eingaben
tätigt, wenn dieser allerdings falsche Eingaben macht, dann kann es bei dieser
Art von Programmierung ziemlich unangenehm werden. Probiere einmal aus statt
einer Zahl zum Beispiel das Zeichen `a` einzugeben. Zuvor erinnere dich wie
du das Programm beenden kannst.

Ich möchte noch einmal die Erklärung für dieses Verhalten liefern: Ist das
Objekt `cin` im Fehlermodus, dann muss dieser Fehlermodus wieder verlassen
werden, damit die nachfolgenden Operationen funktionieren. Das haben wir bis
jetzt noch nicht gemacht.

Deshalb werden wir zumindest eine rudimentäre Fehlerbehandlung
einführen. Ersetze die Eingabeanweisung für die Variable `num1` durch
folgenden Code und verfahre analog für die Variable `num2`:

~~~{.cpp}
if (!(cin >> num1)) {
    cerr << "Keine gültige Zahl. Abbruch" << endl;
    return 1;
}
~~~

Was passiert hier?

- Der Operator `!` bildet die Negation eines Wahrheitswertes, also aus `true`
    wird `false` und aus `false` wird `true`.

- Der Operator `>>` liefert wieder das ursprüngliche Objekt zurück auf das er
    angewendet wird, also in unserem Fall `cin`. Da es sich dabei um keinen
    Wahrheitswert handelt, aber der Operator `!` verwendet wird, wird von \cpp
    eine implizite Konvertierung vorgenommen (mehr dazu später). Konnte die
    Eingabeoperation nicht erfolgreich durchgeführt werden, dann wird der
    Operator `!` den Wert `true` zurückliefern. Damit wird der Programmablauf
    in den Rumpf der `if` Anweisung verzweigen, die Fehlerausgabe tätigen und
    das Programm beenden.

Natürlich ist dies auch noch keine wirklich zufriedenstellende Lösung, denn man
würde den Benutzer normalerweise auffordern die Eingabe zu wiederholen, aber
das verschieben wir auf später.

Da wir gerade dabei sind potenzielle Eingabefehler zu behandeln, fehlt in
diesem Zusammenhang noch die Fehlerbehandlung bei falscher Operatoreingabe.
Da ein einzelnes Zeichen eingelesen wird, kann der Eingabestrom nicht in einen
Fehler gelangen, aber es kann sich trotzdem um ein falsches Operatorzeichen
handeln. D.h., es ist weder ein `+` noch ein `-`, ein `*` oder ein `/`.

Jetzt müssen wir uns entscheiden wie in solch einem Fall vorgegangen werden
soll. Konsequenterweise sollten wir das Programm ebenfalls beenden. Füge
deshalb in der `switch` Anweisung vor der letzten geschwungenen Klammer
folgenden Codeteil ein:

~~~{.cpp}
default:
  cerr << "Kein gültiger Operator. Abbruch" << endl;
  return 1;
~~~

Dieses `default:` bewirkt, dass der Programmablauf hier fortgesetzt wird, wenn
keine der Alternativen zutreffen. Das setzt voraus, dass überall
`break` Anweisungen eingebaut worden sind, da sonst der Programmablauf mit dem
direkt nachfolgenden `case` oder letztendlich dem `default` fortgeführt wird.

Können wir dieses Programm noch verbessern? Ja, wir können. Schauen wir uns
doch einmal die Schleife etwas genauer an! Zuerst setzen wir die Variable
`proceed` und darauffolgend fragen wir diese im Schleifenkopf der `while`
Schleife gleich wieder ab. Das müssen wir so tun, damit wir die Schleife
zumindest einmal betreten. Genau für derartige Anwendungsfälle gibt es die
`do`-`while` Anweisung!

Baue das Programm so um, dass aus der ursprünglichen Struktur

~~~{.cpp}
char proceed{'y'};

while (proceed == 'y') {
    // Inhalt der Schleife
}
~~~

die folgende Struktur wird:

~~~{.cpp}
char proceed;

do {
    // Inhalt der Schleife
} while (proceed == 'y');
~~~

Die Bedeutung der `do`-Anweisung ist ähnlich der `while`-Anweisung, nur dass
der Schleifenrumpf mindestens einmal ausgeführt wird und dies so lange, solange
die Bedingung am Ende erfüllt ist.

Zwei Dinge solltest du beachten:

- Ich habe in der neuen Struktur die Initialisierung der Variable `proceed`
    weggelassen, da dies jetzt nicht mehr notwendig ist. Erinnere dich aber,
    dass das unserer Regel widerspricht und daher nicht zu empfehlen ist. Hier
    habe ich dies nur zu Demonstrationszwecken eingebaut.
    
- Am Ende der `do` Anweisung ist nach der Bedingung ein Strichpunkt zwingend
    notwendig!

Die normale `while` Anweisung wird oft auch als kopfgesteuerte Schleife und die
`do` Anweisung analog dazu als fußgesteuerte Schleife bezeichnet.

## Zählschleife, Container, Funktion {#exasort}

Als Nächstes wollen wir eine kleine Applikation schreiben, die die
übergebenen Kommandozeilenargumente sortiert ausgibt. Das Programm soll also
folgende Funktionsweise haben:

~~~{.sh}
$ sort Wien Amsterdam Paris Berlin Lissabon
Amsterdam
Berlin
Lissabon
Paris
Wien
~~~

Bei Wien, Amsterdam, Paris,... handelt es sich um die zu sortierenden
Kommandozeilenparameter, die danach sortiert und zeilenweise ausgegeben werden sollen.

Beginnen wir mit dem Auslesen der Kommandozeilenparameter und der Ausgabe auf
`stdout` und schreiben folgenden Code in die Datei `sort.cpp`:

~~~{.cpp}
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    for (int i{0}; i < argc; ++i) {
        cout << argv[i] << endl;
    }
}
~~~

Teste es und du wirst folgendes Ergebnis erhalten, wenn dein ausführbares
Programm ebenfalls `sort` heißt:

~~~{.sh}
$ sort a b c
sort
a
b
c
~~~

Du siehst, dass hier der eigentliche Programmname und alle übergebenen
Kommandozeilenargumente zeilenweise ausgegeben werden.

Gut, aber was ist in diesem Programm enthalten?

- Zuerst bemerkst du, dass der Funktionskopf von `main` jetzt anders ist, da
    dieser jetzt zwei Parameter enthält. 

    `argc` ist vom Typ `int` und enthält die Anzahl der übergebenen Kommandozeilenargumente.
    In unserem Fall hat `argc` mindestens den Wert 1, da der Programmname ebenfalls
    enthalten ist.

    `argv` ist ein Array (ein Feld), das Elemente vom Typ `char*`
    enthält. `char*` bedeutet Pointer (eingedeutscht von engl. *pointer*,
    dt. *Zeiger*) auf ein `char`. Ein Pointer ist ein Speicherelement -- das
    die Adresse des referenzierten Speicherelementes, in unserem Fall ein
    `char` -- enthält. Es handelt sich hierbei um die Darstellung wie C-Strings
    im Speicher abgelegt sind, nämlich ein Pointer, der an den Anfang eines
    Speicherbereiches -- an die Adresse des ersten Zeichens -- zeigt, der eine
    Folge von Zeichen (Typ `char`) enthält, die mit einem Nullzeichen (`\0`)
    abgeschlossen ist. Das bedeutet, dass keine Länge eines C-Strings
    gespeichert wird, da das Nullzeichen das Ende kennzeichnet.

    Ein Array ist ein Speicherbereich fester Größe, der hintereinander Elemente
    eines festgelegten Datentyps beinhaltet. Der Index in einem Array beginnt
    bei 0 und es wird ebenfalls keine Länge mitgespeichert. Das ist auch der
    Grund, warum der Parameter `argc` mit der Größe des Arrays mitgegeben
    wird. Die Größe eines Arrays kann sich in \cpp nicht ändern.

- Im Rumpf der Funktion `main` ist die nächste Kontrollanweisung enthalten. Es
    handelt sich um die `for` Schleife, die in diesem Fall wie eine
    Zählschleife funktioniert.

    Diese `for` Schleife -- in dieser Variante auch Zählschleife genannt --
    besteht aus dem Schlüsselwort `for`, gefolgt von einem runden Klammernpaar
    und danach dem eigentlichen Schleifenrumpf in geschwungenen Klammern. Innerhalb
    des Klammernpaares gibt es genau 3 Teile, die jeweils durch einen
    Strichpunkt voneinander getrennt sind.
    
    Der erste Teil beinhaltet die Initialisierung, die genau einmal
    durchgeführt, der zweite Teil beinhaltet eine Bedingung, die vor jedem
    Schleifendurchgang überprüft wird und der dritte Teil beinhaltet eine
    Anweisung, die am Ende jedes Schleifendurchganges ausgeführt wird:

    a. Bei Beginn der Ausführung der Schleife wird eine Variable `i` vom Typ `int`
        angelegt und initialisiert, die nur innerhalb der Schleife gültig ist und
        zur Verfügung steht. Anstatt `i{0}` wird oft auch `i=0` geschrieben.

    b. Danach wird die Bedingung überprüft und wenn diese zutrifft, wird der
        Schleifenrumpf ausgeführt.

        Der Schleifenrumpf besteht in unserem Fall aus einer bekannten
        Ausgabe. Neu ist allerdings wie auf die Elemente eines Arrays
        zugegriffen werden kann: `argv[i]` greift auf das Element mit dem
        Index `i` aus dem Array zu. Dabei handelt es sich bei uns um einen
        `char` Pointer. Der Ausgabeoperator `<<` von `cout` behandelt so einen
        Pointer indem alle Zeichen ab dem ersten Zeichen ausgegeben werden bis
        exklusive dem erkannten Nullzeichen.

    c. Am Ende des Schleifenrumpfes wird die Variable `i` um 1 erhöht
        (inkrementiert). Das kann in \cpp mittels des Inkrementoperators `++`
        erreicht werden. Danach wird bei b.  fortgefahren.

    Das bedeutet, dass eine derartige `for` Schleife äquivalent zu folgender
    `while` Schleife ist:

    ~~~{.cpp}
    {
        int i{0};
        while (i < argc) {
            cout << argv[i] << endl;
            ++i;
        }
    }
    ~~~

    Wir hätten also genauso gut eine `while` Schleife programmieren können,
    aber eine derartige `for` Schleife ist kürzer und prägnanter.

Das ist soweit erledigt, aber wir bemerken natürlich, dass ebenfalls der
Programmname ausgegeben wird. Das lässt sich leicht beheben indem die
Zählvariable mit 1 anstatt 0 initialisiert wird!

Nun fehlt noch das Sortieren. Wir werden das Sortieren am Datentyp `vector`
demonstrieren. Ein `vector` funktioniert in der Art wie ein Array,
unterscheidet sich von einem Array jedoch dadurch, dass ein `vector` ein
Objekttyp ist und außerdem in der Größe veränderlich ist.

Ein Datentyp, der prinzipiell mehrere Elemente beinhalten kann wird als
ein Container bezeichnet. Der Typ `vector` stellt also einen Container dar.

~~~{.cpp}
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    vector<string> words;
    
    for (int i{1}; i < argc; ++i) {
        words.push_back(argv[i]);
    }

    for (int i{0}; i < words.size(); ++i) {
        cout << words[i] << endl;
    }
}
~~~

Teste es, es sollte funktionieren wie bisher. Und jetzt schauen wir uns
den Sourcecode einmal genauer an:

- Zuerst muss natürlich eine neue Header-Datei eingebunden werden, da ja ein
    neuer Datentyp aus der Standardbibliothek verwendet wird.

- Innerhalb von `main` wird am Anfang eine Variable `words` angelegt, bei der
    es sich um einen Vektor handelt, der lauter `string` Objekte beinhalten
    kann.

    Die spitzen Klammern geben den Typ der beinhalteten Objekte an. Es handelt
    sich hierbei um die Verwendung eines Template - Datentyps `vector` für den
    man bei der Instanziierung des Templates einen spezifischen Datentyp -- hier
    `string` -- mitgeben muss. Wir werden das später noch im Detail besprechen.

- Die erste `for` - Schleife durchläuft alle Kommandozeilenargumente und hängt
    diese jeweils hinten mittels der Methode `push_back` an den Vektor `words`
    an.

    In \cpp wird -- wie in vielen anderen Programmiersprachen auch -- eine
    Methode eines Objektes mittels des Punktoperators `.`
    aufgerufen. Daher bedeutet `word.push_back(argv[i])`, dass für den Vektor `word`
    die Methode `push_back` aufgerufen wird und dieser das Argument `argv[i]`
    als Parameter übergeben wird.

- Die zweite Schleife gibt den Inhalt dieses Vektors wie gewohnt aus. Zwei
    Dinge sind hier zu beachten. Erstens die Verwendung der Methode `size`, die
    die aktuelle Größe des Vektors zurückgibt und die Verwendung der eckigen
    Klammern, um auf den Inhalt an dem angegebenen Index zuzugreifen. D.h., ein
    Vektor verhält sich bezüglich des Zugriffes wie ein Array.

<div class="drawer">
Die Schnittstelle, die ein Objekt (oder eine andere Art von Software) anbietet,
um als Programmierer mit diesem programmieren zu können, wird als API
(application programming interface) bezeichnet.

Hier haben wir von dem API der Klasse `vector` kennengelernt, dass wie wir

- einen `vector` eines bestimmten Typs anlegen
- ein weiteres Element zum `vector` hinzufügen
- die Größe eines `vector`s abfragen
- auf ein einzelnes Element des `vector`s über seinen Index zugreifen

können.

`vector` bietet noch viele Methoden an, von denen wir in weiterer Folge noch
etliche besprechen werden.
</div>

Jetzt fehlt nur mehr das Sortieren des Vektors. Dies ist aber einfach, da die
Standardbibliothek von \cpp sehr durchdacht und umfangreich ist:

~~~{.cpp}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
    vector<string> words;
    
    for (int i{1}; i < argc; ++i) {
        words.push_back(argv[i]);
    }

    sort(words.begin(), words.end());

    for (int i{0}; i < words.size(); ++i) {
        cout << words[i] << endl;
    }
}
~~~

Wir verwenden die vordefinierte Funktion `sort`, die mittels der Headerdatei
`algorithm` eingebunden werden kann. `sort` benötigt zwei Argumente, nämlich
den Beginn der zu sortierenden Werte und das Ende der zu sortierenden Werte,
die jeweils über die entsprechenden Methoden vom Vektor `words` erhalten werden
können (`begin()` respektive `end()`). Bei diesem "Anfang" und dem "Ende"
handelt es sich jeweils um einen sogenannten *Iterator*, aber das werden wir
uns später noch genau ansehen. Fertig!

Eine kleine Verbesserung wollen wir trotzdem noch anbringen, da wir den Aufruf
der Funktion `sort` mit den beiden Parametern nicht als besonders komfortabel
empfinden. Besser wäre es, wenn wir die beiden Parameter nicht mitgeben
müssten. Also schreiben wir noch eine Funktion, die diesen Aufruf kapselt.

Ändere den Quellcode so ab, dass vor der Funktion `main` die folgende
Funktionsdefinition kommt:

~~~{.cpp}
vector<string> sort(vector<string> words) {
    sort(words.begin(), words.end());
    return words;
}
~~~

Danach ersetze den alten Aufruf der Funktion `sort` durch den neuen Aufruf der
Funktion `sort`:

~~~{.cpp}
words = sort(words);
~~~

Teste! Du solltest wieder das gleiche Ergebnis erhalten, nur hast du jetzt den
Vorteil, dass du einen einfacheren Funktionsaufruf hast.

Wie funktioniert es?

- Zuerst wird eine Funktion definiert. Das funktioniert so ähnlich wie die
    Funktion `main`, nur dass diese Funktion einen Vektor von `string` Objekten
    als Parameter bekommt. In diesem konkreten Fall wird eine Kopie übergeben,
    die auf gewohnte Weise innerhalb der Funktion sortiert wird. Da es sich um
    eine Kopie handelt müssen wir diese mittels einer `return` Anweisung an den
    Aufrufer zurückgeben.

- In der Funktion `main` wird lediglich die Funktion aufgerufen und der
    Rückgabewert, der wiederum eine Kopie darstellt wird, in der Variable
    `words` abgelegt.

So, nun haben wir auch noch eine eigene Funktion definiert und auch
aufgerufen. Dabei haben wir gelernt, dass Parameter und Rückgabewert in \cpp
standardmäßig als Kopie übergeben werden.

## \quotation{foreach}-Schleife, Struktur, Lambdafunktion {#structlambda}

Nehmen wir einmal an, dass wir jetzt Personen in unserem Programm speichern und
sortieren wollen. Eine Person soll bei uns über einen Vornamen und einen
Nachnamen sowie unter Umständen über weitere Attribute verfügen.

Es bietet sich an, diese Daten in einem benutzerdefinierten Datentyp `Person`
abzulegen, der über die entsprechenden Attribute (in \cpp{} 'member variable')
verfügt:

~~~{.cpp}
// person.cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
    string first_name;
    string last_name;
    int year_of_birth;
};
~~~

Bis jetzt handelt es sich noch um kein fertiges Programm. Lediglich der
benutzerdefinierte Datentyp `Person` wurde definiert, der aus drei
Instanzvariablen besteht. Ein `struct` ist in \cpp genau das gleiche wie eine
Klasse (`class`) nur, dass alle Attribute und Methoden defaultmäßig öffentlich
zugreifbar sind (`public`).

Jetzt erweitern wir den bestehenden Code, sodass ein fertiges Programm
entsteht:

~~~{.cpp}
int main() {
    Person p1{"Max", "Mustermann", 1990};
    Person p2{"Otto", "Normalverbraucher", 1950};
    Person p3{"Susi", "Musterfrau", 1991};
}
~~~

In `main` werden jetzt drei Personen angelegt. Das Interessante daran ist, dass
die einheitliche Initialisierung verwendet werden kann, um die Attribute
jeweils initialisieren zu können.

Zum Speichern werden wir wieder auf unseren bewährten `vector` setzen:

~~~{.cpp}
vector<Person> persons{p1, p2, p3};
~~~

Auch hier sehen wir, dass dieser mit der einheitlichen Initialisierung sehr
elegant mit Anfangswerten versehen werden kann.

Jetzt wollen wir uns an das Sortieren wagen. Aber nach welchem Kriterium soll
sortiert werden und wie setzt man es um? Wir wollen nach dem Geburtsjahr
sortieren und die Umsetzung sieht folgendermaßen aus:

~~~{.cpp}
sort(persons.begin(),
     persons.end(),
     [](Person p1, Person p2) {
         return p1.year_of_birth < p2.year_of_birth;
     });
~~~

Hier sehen wir, dass unsere Sortierfunktion einen dritten Parameter bekommen
kann. Es handelt sich hier um eine Lambdafunktion. So eine Lambdafunktion ist
eine anonyme Funktion, eine Funktion ohne Namen, die direkt bei der Verwendung
definiert wird.

Ohne jetzt genau auf die Syntax eingehen zu wollen, sehen wir, dass diese mit
eckigen Klammern beginnt und danach wie eine normale Funktion aussieht. Diese
Funktion wird von `sort` für je zwei Elemente der zu sortierenden Datenstruktur
aufgerufen, um die Reihenfolge zu bestimmen. Liefert die Lambdafunktion `true`
zurück, dann soll `p1` vor `p2` angeordnet werden, ansonsten umgekehrt.

Die Ausgabe erfolgt über eine "foreach" Schleife:

~~~{.cpp}
for (auto p : persons) {
    cout << p.first_name << " " << p.last_name << " "
         << p.year_of_birth << endl;
}
~~~

Schauen wir uns diese Schleife im Detail an:

- Der Schleifenkopf beinhaltet ein für uns neues Schlüsselwort `auto`, das in
    Deklarationen verwendet werden kann. Es gibt an, dass der Compiler den Typ
    in dieser Deklaration selber ermitteln soll. In unserem Fall soll der Typ
    der Laufvariable `p` selbsttätig bestimmt werden.

    Der nachfolgende Doppelpunkt bedeutet hier, dass die Schleife über alle Elemente
    des nachfolgenden Vektors `persons` iterieren soll: In jedem einzelnen
    Schleifendurchgang nimmt die Variable `p` den nächsten Wert an. Da der Typ
    von `persons` der Typ `vector<Person>` ist, wird vom Compiler der Typ von
    `p` als `Person` bestimmt.

- Im Schleifenrumpf steht die Laufvariable `p` zur Verfügung. Mittels des
    Punktoperators kann auf die einzelnen Instanzvariablen von `p` zugegriffen werden.

## Zusammenfassung

In diesem Kapitel haben wir die grundlegenden syntaktischen Fähigkeiten von
\cpp kennengelernt, um einfache textorientierte, kleine, prozedurale Programme
zu erstellen.
