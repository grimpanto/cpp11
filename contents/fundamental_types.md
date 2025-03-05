
# Operatoren und fundamentale Datentypen

<div class="drawer">
In diesem Kapitel wird ein Überblick über Operatoren gegeben und es werden die
einzelnen fundamentalen Datentypen von \cpp näher beschrieben:

- Wahrheitswerte: `bool`
- Zeichen: `char`, `wchar_t`, `char16_t`, `char32_t`
- Ganze Zahlen: `int`, `long`
- Gleitkommazahlen: `float`, `double`
- `void`
</div>


## Grundlegendes zu Operatoren

Operatoren können verwendet werden, um eingebaute und benutzerdefinierte
Datentypen zu verknüpfen.

Man kann Operatoren nach der Anzahl der Operanden einteilen. In \cpp gibt es
Operatoren, die

- einen Operanden (unär), wie z.B. `++i` oder `*p`
- zwei Operanden (binär), wie z.B. `a + b`
- drei Operanden (ternär)

benötigen.

### Assoziativität {-}

Operatoren kann man weiter einteilen in linksassoziative und
rechtsassoziative Operatoren.

Bei linksassoziativen Operatoren erfolgt die Abarbeitung der Teilausdrücke von
links nach rechts. Das bedeutet, dass bei dem linksassoziativen Operator `+`
und dem Ausdruck `a + b + c` die Berechnung so durchgeführt wird, als ob der
Ausdruck folgende Gestalt hätte: `(a + b) + c`. Das entspricht auch dem
natürlichen Verhalten des Operators $+$, wie dieser aus der Mathematik bekannt
ist.

Natürlich ist `a + b + c` gleich dem Ergebnis von `a + (b + c)`, aber
bei der Subtraktion ist dies bekannterweise nicht so:

~~~{.cpp}
// operators.cpp
#include <iostream>

using namespace std;

int main() {
    int i{1};
    int j{2};
    int k{3};

    cout << "i = " << i << ", j = " << j
         << ", k = " << k << endl;
    cout << "i - j - k = " << i - j - k << endl;
    cout << "(i - j) - k = " << (i - j) - k << endl;
    cout << "i - (j - k) = " << i - (j - k) << endl;
}
~~~

Teste und betrachte das Ergebnis:

~~~{.sh}
i = 1, j = 2, k = 3
i - j - k = -4
(i - j) - k = -4
i - (j - k) = 2
~~~

Bei rechtsassoziativen Operatoren wird die Berechnung von rechts nach links
vorgenommen. Betrachten wir den Zuweisungsoperator (engl. *assignment
operator*) und füge folgende Codezeilen an:

~~~{.cpp}
i = j = k;
cout << "i = j = k;" << endl;
cout << "i = " << i << ", j = " << j << ", k = "
     << k << endl << endl;

i = 1; j = 2; k = 3;
i = (j = k);
cout << "i = (j = k);" << endl;
cout << "i = " << i << ", j = " << j << ", k = "
     << k << endl << endl;

i = 1; j = 2; k = 3;
(i = j) = k;
cout << "(i = j) = k;" << endl;
cout << "i = " << i << ", j = " << j << ", k = "
     << k << endl << endl;
~~~

Dann kommt es zu folgender Ausgabe:

~~~{.sh}
i = j = k;
i = 3, j = 3, k = 3

i = (j = k);
i = 3, j = 3, k = 3

(i = j) = k;
i = 3, j = 2, k = 3
~~~

Man sieht hier deutlich den Unterschied: Beim expliziten Setzen von
Klammern um `(i = j)` wird dies zuerst abgearbeitet und `i` erhält den Wert von
`j`. Der Wert von `(i = j)` ist eine Referenz auf `i`, das zu diesem Zeitpunkt
den Wert `2` enthält. Danach wird `i` mit dem Wert von `k` überschrieben und
`j` behält den alten Wert!

Unäre Operatoren und der Zuweisungsoperator sind rechtsassoziativ, alle anderen
Operatoren sind linksassoziativ.

### Operatorreihenfolge {-}

Wenn verschiedene Operatoren innerhalb eines Ausdrucks verwendet werden, dann
hängt die Abarbeitung von der Priorität (Vorrang) der Operatoren ab. Es ist in
der Mathematik selbstverständlich, dass die "Punktoperatoren", wie Multiplikation
und Division, vor den "Strichoperatoren", wie Addition und Subtraktion,
ausgerechnet werden. In \cpp ist es genauso, aber da es eine Vielzahl von
Operatoren gibt, sind diese Operatoren in einer Prioritätsfolge geordnet, die
eben die Reihenfolge der Abarbeitung festlegt. Die "Punktoperatoren" haben eine
höhere Priorität als die "Strichoperatoren".

Die folgende Liste gibt die Operatorreihenfolge *ausgewählter* Operatoren in
absteigender Prioritätenreihenfolge an:

1. Klammerung `()`, Lambda-Ausdrücke `[]{}`
2. Bereichsauflösung `::`
3. Zugriff auf Mitglieder `.`, `->`
4. Index `[]`, Funktionsaufruf `()`, Postfixinkrement `++`, Postfixdekrement
   `--`
5. Größenoperator `sizeof`, Präfixinkrement `++`, Präfixdekrement
   `--`, Komplement `~`, Negation `!`, Unäres Minus `-`, Unäres Plus `+`,
   Adresse `&`, Dereferenzierung `*`, Objekterzeugung `new`, Objektlöschung
   `delete`
6. Multiplikation `*`, Division `/`, Modulo `%`
7. Addition `+`, Subtraktion `-`
8. Verschiebung links `<<` und rechts `>>`
9. Vergleich: `<`, `<=`, `>=`, `>`
10. Gleichheit `==` und Ungleichheit `!=`
11. Bitweises UND `&`
12. Bitweises exklusives ODER `^`
13. Bitweises ODER `|`
14. Logisches UND `&&`
15. Logisches ODER `||`
16. Bedingungsoperator `?:`
17. Liste `{}`, Werfen einer Exception `throw`, Zuweisung `=`      |
18. Sequenzoperator `,`


Schauen wir uns die Funktionsweise der Prioritäten einmal mittels eines
Beispiels an:

~~~{.cpp}
// precedence.cpp
#include <iostream>

using namespace std;

int main() {
    int i{1};
    int j{2};
    int k{3};
    
    cout << i + j * k << endl;
}
~~~

Die Ausgabe ist -- vermutlich wie erwartet -- `7`, da der
Multiplikationsoperator eine höhere Priorität hat als der Additionsoperator.

So weit -- so gut, schauen wir uns jetzt den Inkrementoperator `++` in der
Präfixvariante an. Analog dazu funktioniert der Dekrementoperator `--`.

Hänge die beiden folgenden Anweisungen an dein Programm
an:

~~~{.cpp}
cout << i + ++j * k << endl;
cout << "j = " << j << endl;
~~~

Die Ausgabe wird jetzt folgendermaßen aussehen:

~~~{.sh}
7
10
j = 3
~~~

Der Präfixoperator `++` hat eine höhere Priorität als die anderen Operatoren
und wird deshalb zuerst ausgewertet. Außerdem bewirkt der Präfixoperator, dass
der inkrementierte Wert auch sofort im Ausdruck verwendet wird. Das
schlägt sich auch in der Ausgabe von `10` wieder.

Als Nächstes wollen wir die Funktion des Postfixoperators `++`
kennenlernen. Füge deshalb die beiden folgenden Zeilen zu deinem Programm
hinzu:

~~~{.sh}
cout << i + j++ * k << endl;
cout << "j = " << j << endl;
~~~

Es wird zu folgender Ausgabe kommen:

~~~{.sh}
7
10
j = 3
10
j = 4
~~~

Du siehst, dass das Ergebnis noch immer 10 ist, obwohl der Wert von `j`
mittlerweile `4` beträgt und somit auch wirklich inkrementiert
wurde. Allerdings ist der Unterschied der Postfixschreibweise zur
Präfixschreibweise der, dass der alte Wert
von der Variable für die Auswertung des Ausdruckes verwendet wird
und nicht der inkrementierte Wert.

Ok, das Prinzip hast du verstanden, aber eine kleine Erweiterung zu unserem
bestehenden Programm wollen wir noch vornehmen. Probieren wir einmal eine
Kombination von der Präfixvariante und der Postfixvariante von `++`. Hänge
nochmals die folgenden Zeilen an und übersetze das Programm:

~~~{.cpp}
cout << i + ++j++ * k << endl;
cout << "j = " << j << endl;
~~~

Es geht nicht? Der Compiler meldet, dass er sich einen lvalue (L-Wert) als
Operanden erwartet! Es gibt noch einen weiteren Unterschied zwischen der
Präfixvariante und der Postfixvariante: Der Präfixoperator liefert einen lvalue
zurück und der Postfixoperator liefert einen rvalue!

Damit sehen wir schön, dass der Postfixoperator `++` eine
höhere Priorität hat als die Präfixvariante. Er liefert einen rvalue, der
jedoch natürlich nicht als Operand für den Präfixoperator dienen kann, da der
Präfixoperator den Wert einer Variable inkrementieren will und ein einfacher
Wert keine Variable ist.

Die Lösung besteht darin, dass Klammern gesetzt werden, sodass wir eine höhere
Priorität für den Präfixoperator erzwingen. Ändere deshalb die entsprechende
Codezeile folgendermaßen ab:

~~~{.cpp}
cout << i + (++j)++ * k << endl;
~~~

Die Ausgabe erscheint jetzt folgendermaßen:

~~~{.sh}
7
10
j = 3
10
j = 4
16
j = 6
~~~

Hier siehst du, dass die runden Klammern eine höhere Priorität haben, wie wir
uns das natürlich erwarten und wie es auch aus der Prioritätsreihenfolge
herauszulesen ist.

In der Ausgabe erkennen wir auch sehr schön das zweimalige Inkrementieren der
Variable `j`!

Es ist sinnvoll folgende Faustregel zu beachten: Verwende, wenn immer es geht,
die Präfixvariante der Inkrement- oder Dekrementoperatoren, da bei diesen
kein temporäres Speicherobjekt angelegt werden muss!


### Auswertungsreihenfolge {-}

Unabhängig von der Assoziativität, die die Reihenfolge der Abarbeitung bei
gleichen Operatoren betrifft und der Operatorpriorität, die die Abarbeitung
unterschiedlicher Operatoren regelt, ist die *Auswertung* der Teilausdrücke
eines Ausdruckes. Diese Reihenfolge bei der Auswertung der Teilausdrücke ist
allerdings nicht definiert!

Schauen wir uns das anhand eines Beispiels an:

~~~{.cpp}
#include <iostream>

using namespace std;

int f() {
    cout << "f()" << endl;
    return 1;
}

int g() {
    cout << "g()" << endl;
    return 2;
}

int h() {
    cout << "h()" << endl;
    return 3;
}

int main() {
    int i{};

    i = f() + g() * h();
}
~~~

Bei mir sieht die Ausgabe folgendermaßen aus:

~~~{.sh}
f()
g()
h()
~~~

Die Auswertung erfolgt aufgrund der höheren Priorität des
Multiplikationsoperators, sodass zuerst das Ergebnis von `g()` mit dem Ergebnis
von `h()` multipliziert wird und danach das Ergebnis von `f()` addiert
wird.

Die Auswertungsreihenfolge der Teilausdrücke ist aber offensichtlich eine
andere. Das muss allerdings nicht so sein, da ein anderer Compiler die
Auswertung so wie die Abarbeitung der Teilausdrücke vornehmen könnte.  Die
Auswertungsreihenfolge ist in \cpp eben nicht definiert und man kann sich auch
nicht darauf verlassen, dass diese von links nach rechts erfolgt, wie dies bei
mir in diesem konkreten Fall ist.

Das Ergebnis von `i` ist in diesem Fall jedoch unabhängig von der
Auswertungsreihenfolge richtig. Die Funktionen `f()`, `g()` und `h()`
haben jedoch den Nebeneffekt (engl. *side effect*), dass sie jeweils eine
Ausgabe tätigen und über die Reihenfolge dieser Ausgaben kann eben keine
Aussage getroffen werden.

Der eigentliche Sinn einer Funktion ist, dass diese einen Rückgabewert
liefert. Hat eine Funktion, jedoch eine zusätzliche Auswirkung auf ihre
Umgebung, dann wird das als Nebeneffekt bezeichnet.

Man kann argumentieren, dass die Aufrufreihenfolge einer Funktion, die
keine Nebeneffekte hat, kein Problem darstellt. Daher sollte man Funktionen
so schreiben, dass diese keine Nebeneffekte aufweisen.

Allerdings tritt das Problem der Auswertungsreihenfolge von Teilausdrücken auch
in anderen Zusammenhängen auf. Hänge folgende Zeilen wieder an deine Datei:

~~~{.cpp}
int v[]{9,9,9,9,9};
i = 1;
v[i] = i++;
cout << "v[1] = " << v[1] << endl;
cout << "v[2] = " << v[2] << endl;
~~~

Bei mir kommt es zu folgender Ausgabe:

~~~{.sh}
v[1] = 9
v[2] = 1
~~~

Die Anweisung `v[i] = i++;` besitzt die beiden Teilausdrücke `v[i]` und `i++`,
deren Auswertungsreihenfolge wiederum nicht definiert ist! `v[i]` liefert
wiederum einen lvalue auf das Element des Arrays zurück, das verändert werden
soll und `i++` inkrementiert einfach die Variable `i`. Aus diesem Grund kann es
-- je nach Reihenfolge der Auswertung der Teilausdrücke -- zu den beiden
verschiedenen Ergebnissen `v[1] == 1` und `v[2] == 1` kommen.

Die Quintessenz ist, dass man innerhalb eines Ausdruckes keine Teilausdrücke
verwenden sollte, die eine (oder mehrere) gemeinsame Variable verändern.

Es gibt allerdings drei Fälle in denen die Auswertungsreihenfolge von
Teilausdrücken klar definiert ist:

- Für die booleschen Operatoren `&&` und `||` ist die Auswertungsreihenfolge von
    links nach rechts festgelegt, denn diese funktionieren nach dem
    Kurzschlussprinzip (engl. *short-circuit evaluation*). Das bedeutet, dass
    der zweite Operand nicht mehr ausgewertet wird, wenn dies nicht mehr
    notwendig ist.  Eine Beschreibung dieser Operatoren samt Beispielen
    befindet sich im Abschnitt \in[booleanop] auf der Seite \at[booleanop].

- Der Bedingungsoperator ist der einzige Operator mit drei Operanden in
    \cpp. Er hat den folgenden Aufbau `(cond) ? expr1 : expr2`. Der Wert eines
    derartigen Ausdruckes ist der Wert des Teilausdruckes `expr1`, wenn die
    Bedingung `cond` wahr ist und anderenfalls der Wert des Teilausdruckes
    `expr2`.

    Zuerst wird `cond` ausgewertet und danach `expr1` oder `expr2`, nie jedoch
    beide.

    Schreibe folgendes kleines Testprogramm und teste:

    ~~~{.cpp}
    // condop.cpp
    #include <iostream>

    using namespace std;
    
    int main() {
        int age{};
    
        cout << "Alter? ";
        cin >> age;
        cout << ((age >= 18) ? "Erwachsen" :
                               "Nicht erwachsen");
    }
    ~~~

- Der Sequenzoperator findet oft im Schleifenrumpf einer `for`-Schleife
    Verwendung, sonst wird dieser nicht oft verwendet. Das Prinzip ist
    Folgendes: Der Gesamtausdruck besteht aus mehreren Teilausdrücken, die
    durch je ein Komma voneinander getrennt sind. Die einzelnen Teilausdrücke
    werden streng von links nach rechts abgearbeitet und der Wert des
    Gesamtausdruckes ist der Wert des letzten Teilausdruckes.

    Hier ein Beispiel:

    ~~~{.cpp}
    // commaop.cpp
    #include <iostream>

    using namespace std;
    
    int main() {
        int i{1};
        int res{};
    
        res = i++, i /= 2, i + 2;
        cout << res << endl;
    }
    ~~~

    Teste! Stimmt die Ausgabe meiner Beschreibung überein? Nein? Dann muss man
    sich wiederum die Operatorprioritäten ansehen! Der Zuweisungsoperator `=`
    hat eine höhere Priorität als der Sequenzoperator `,`. Das bedeutet, dass
    die Sequenzanweisung aus den 3 Teilausdrücken `res = i++`, `i /= 2` und
    `i + 2` besteht. Der Wert des gesamten Ausdruckes ist 3, der jedoch nicht
    verwendet wird. Natürlich macht dies keinen Sinn!

    Wenn man solch eine Konstruktion wirklich verwenden will (und ich rate
    davon wirklich ab), dann ist der gesamte Teil rechts des `=` in runde
    Klammern zu setzen! In diesem Fall wirst du `3` als Ergebnis in der
    Ausgabe erhalten. Damit sieht man auch sehr schön, dass der Sequenzoperator
    streng von links nach rechts auswertet und den letzten Teilausdruck als
    Wert des Gesamtausdruckes nimmt.


## Überladen von Operatoren

Schauen wir uns einmal das folgende uns schon bekannte Beispiel jetzt aus
dem Gesichtspunkt der Operatoren genauer an:

~~~{.cpp}
cout << 42 << endl;
~~~

Unter Umständen stellst du dir jetzt die Frage wie das funktionieren kann, da
der Operator `<<` ja den Verschiebeoperator für integrale Datentypen darstellt.
In \cpp ist es möglich, dass man weitgehend jeden Operator überladen kann.

Dieses Überladen (engl. *overloading*) bedeutet, dass ein Operator für
verschiedene Typen verwendet werden kann. Zum Beispiel ist der Operator `+` von
Haus aus überladen, da dieser sowohl mit dem Typ `int` als auch mit `double`
umgehen kann.

Dieses Überladen kann auch auf benutzerdefinierte Datentypen vorgenommen
werden, wie wir es gerade bei dem Operator `<<` im Zusammenhang mit der
Ausgabe von Daten auf die Standardausgabe gesehen haben. Der Operator `<<`
ist ein binärer Operator und erwartet sich daher zwei Operanden. In der
überladenen Variante sind dies zum Beispiel der benutzerdefinierte Datentyp
`ostream` und der fundamentale Datentyp `int`.

Man kann die meisten Operatoren in \cpp überladen, jedoch nicht deren Anzahl
der Parameter verändern noch deren Assoziativität oder Priorität abändern.

Wie man Operatoren selbst überlädt, werden wir uns später noch genau ansehen.

## Boolescher Datentyp {#booleanop}

Der boolesche Datentyp `bool` kann nur einen der beiden Werte `true` und
`false` annehmen.

Das folgende Programm zeigt die Verwendung von `bool`:

~~~{.cpp}
// bool.cpp
#include <iostream>

using namespace std;

int main() {
    bool ready{};
    char answer{};

    while (!ready) {
        cout << "[y/n] ";
        cin >> answer;
        ready = (answer == 'y' || answer == 'n');
    }

    cout << "Antwort: " << answer << endl;
}
~~~

Das Programm wartet auf eine Antwort, die entweder `y` oder `n` sein muss und
diese Antwort ausgibt. Es gibt lediglich ein paar interessante Aspekte:

- Die Initialisierung von `ready` ist notwendig und wird in dieser Form mit
    `false` vorgenommen, da `false` der "Nullwert" von `bool` ist.

- Die Bedingung der `while`-Anweisung verwendet den Operator `!`, der der
    Negationsoperator ist und aus dem Wert `false` den Wert `true` macht
    und aus `true` den Wert `false`.

    In eine sprachliche Form gebracht bedeutet diese `while` Anweisung: Solange
    die Eingabe noch nicht "ready" ist, wird der Schleifenrumpf ausgeführt.

- Nachdem die Eingabe des einzelnen Zeichens vorgenommen worden ist, wird diese
    überprüft, ob die Eingabe dem Wert `y` oder dem Wert `n` entspricht. Der
    Operator `||` ist der "ODER" Operator, der genau dann `true` als
    Ergebnis liefert, wenn mindestens einer der beiden Operanden den Wert
    `true` hat.

    Wie schon besprochen hat der Operator `||` die Eigenschaft, dass die
    Operanden von links nach rechts ausgewertet werden. Hat der linke
    Operand schon den Wert `true` ergeben, dann wird der zweite Operand nicht
    mehr ausgewertet und das Ergebnis der Operation ist `true`.  Im
    vorhergehenden Beispiel bedeutet das, dass der rechte Teil des `||`
    nicht mehr überprüft wird, wenn die Variable `answer` den Wert `y`
    hat.

    Zusätzlich zu dem `!` und dem `||` Operator gibt es auch noch den `&&`
    Operator, der genau dann den Wert `true` als Ergebnis liefert, wenn beide
    Operanden den Wert `true` haben. Auch hier werden die Operanden von links
    nach rechts ausgewertet. Ergibt der linke Operand den Wert `false`, dann
    wird der rechte Operand nicht mehr ausgewertet und das Ergebnis ist
    `false`.


### Konvertierungen

Aufgrund der Möglichkeit des Mixens verschiedener arithmetischer Datentypen
werden in arithmetischen und logischen Ausdrücken `bool`s immer zu `int`s
konvertiert, dann die Operationen mit den konvertierten Werten durchgeführt und
anschließend die Werte wieder zurück zu `bool`s konvertiert. Dabei gelten die
nachfolgenden Regeln:

- `true` bekommt den Wert `1`, wenn es zu einem Integer konvertiert wird und
    `false` bekommt den Wert `0`.
- Jeder Integer mit dem Wert `0` wird zu `false` konvertiert, wenn ein `bool`
    erwartet wird, jeder Wert ungleich `0` bekommt den Wert `true`.

Schauen wir uns dazu das folgende Beispiel an:

~~~{.cpp}
// bool_convert.cpp
#include <iostream>

using namespace std;

int main() {
    int i{9};
    bool a{i != 0};
    bool b{true};
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    int c{};
    c = a + b;
    cout << "a + b = " << c << endl;
    c = a - b;
    cout << "a - b = " << c << endl;
    c = a && b;
    cout << "a && b = " << c << endl;
}
~~~

Die Ausgabe wird folgendermaßen aussehen:

~~~{.sh}
a = 1
b = 1
a + b = 2
a - b = 0
a && b = 1
~~~

Was passiert? 

- Die beiden booleschen Variablen `a` und `b` werden beide mit `true`
    initialisiert.
- Die Ausgabe erfolgt allerdings jeweils als `1`. Das liegt daran, dass
    standardmäßig die Ausgabe eines booleschen Wertes mittels des `<<`
    Operators in Form einer ganze Zahl erfolgt. Da `1` dem Wert `true`
    entspricht wird eben dieser ausgegeben.
- Die fragwürdige Addition von booleschen Werten wird im Bereich der ganzen
    Zahlen durchgeführt. Daher kommt es zur Ausgabe von `2`. Genauso sieht es
    mit der Subtraktion aus.
- Bei `&&` handelt es sich wieder um den logischen short-circuit
    Operator "UND", aber auch bei diesem wird jeder Operand in eine ganze Zahl
    gewandelt, dann das bitweise "UND" vorgenommen. Auch aus diesem Grund kommt
    es zur Ausgabe von `1`.

Ändere jetzt den Typ von `c` in einen `bool` um und starte das Programm
nochmals. Es wird zu folgender Ausgabe kommen:

~~~{.sh}
a = 1
b = 1
a + b = 1
a - b = 0
a && b = 1
~~~

Wieso? Die Konvertierungen von `bool` zu `int` und das anschließende Rechnen im
Bereich der ganzen Zahlen funktioniert wie vorher, nur wird jetzt jeweils das
Ganzzahlergebnis in einen booleschen Wert umgewandelt. Damit wird jeder Wert
ungleich `0` zu `true` umgewandelt, anderenfalls zu `false`. Die Ausgabe
erfolgt durch den `<<` Operator, der standardmäßig den booleschen Wert jedoch
als ganze Zahl ausgibt.

Die Ausgabe als `true` oder `false` lässt sich jedoch leicht erreichen, indem
man einen weiteren Manipulator bei der Ausgabe verwendet. Den ersten
Manipulator, den wir bis jetzt kennengelernt haben, ist `std::endl`, der einen
Zeilenvorschub in den Ausgabestrom einfügt. Jetzt benötigen wir den
`std::boolalpha` Manipulator, der bewirkt, dass nicht `1` respektive `0`,
sondern `true` respektive `false` ausgegeben wird.

Füge vor der ersten Ausgabeanweisung die folgende Anweisung ein und teste:

~~~{.cpp}
cout << boolalpha;
~~~

In \cpp handelt es sich bei `std::boolalpha` um einen Manipulator, der die folgende
Wirkung hat:

~~~{.sh}
a = true
b = true
a + b = true
a - b = false
a && b = true
~~~

Dieser Manipulator hat seine Wirkung so lange, bis dieser wieder zurückgesetzt
wird. Dies kann mittels des Manipulators `std::noboolalpha` erreicht
werden. Manipulatoren müssen nicht in einer eigenen Anweisung verwendet werden,
sondern können auch direkt in eine Ein- oder Ausgabeoperation eingefügt
werden. Du könntest auch die Ausgabeoperationen:

~~~{.cpp}
cout << boolalpha;
cout << "a = " << a << endl;
~~~

durch

~~~{.cpp}
cout << "a = " << boolalpha << a << endl;
~~~

ersetzen. Dies wiederum liegt daran, dass der Operator `<<` auch bei einem
Manipulator wieder das eigentliche Objekt zurückliefert. In unserem Fall eben
`cout`.

In weiterer Folge wollen wir die Werte der Variable `a` und `b` durch den
Benutzer eingeben lassen. Ersetze die Definitionen der Variablen `i`, `a` und
`b` durch:

~~~{.cpp}
bool a{};
bool b{};

cout << "a = ";
cin >> a;
cout << "b = ";
cin >> b;
~~~

Übersetze und teste jetzt dein Programm mit verschiedenen Werten für `a` und
`b`. Beachte, dass du für `a` und `b` die Zahlen `0` oder `1` eingeben
kannst.

Auch wenn es sicher nicht sinnvoll ist, ist es wahrscheinlich immer noch
benutzerfreundlicher, den Benutzer `true` oder `false` anstatt `1` oder `0`
eingeben zu lassen. Auch das kann leicht erreicht werden indem du folgende
Zeile vor der ersten Eingabeanweisung einfügst:

~~~{.cpp}
cin >> boolalpha;
~~~

Damit wird der Manipulator `boolalpha` auch für die Eingabe verwendet. Der
Manipulator kann auch direkt in die Anweisung zur Eingabe des ersten Wertes --
analog zur Ausgabe -- eingefügt werden.

Teste das Programm gleich mit verschiedenen Werten für `a` und `b`. Du kannst
auch die Operation `&&` durch `||` ersetzen, um den "ODER"-Operator zu testen.

Es gibt auch den Operator `^`, der bitweises "XOR" von ganzen Zahlen
durchführt. Da boolesche Werte in `int`s gewandelt werden, kann `^` auch für
`bool`s verwendet werden. Das Ergebnis einer "XOR" von zwei Operanden ist genau
dann `true`, wenn genau ein Operand `true` ist, anderenfalls `false`. Dieser
Operator hat *kein* Kurzschlussverhalten, was auch keinen Sinn ergeben würde.

Jetzt folgt noch ein Beispiel, das die implizite Konvertierung eines `bool`,
einen neuen Operator für ganze Zahlen, als auch die Schlüsselwörter `break` und
`continue` präsentiert, die in Schleifenanweisungen verwendet werden
können:

~~~{.cpp}
// countdown.cpp
#include <iostream>

using namespace std;

int main() {
    cout << "Startwert: ";
    int cnt{};
    cin >> cnt;

    if (cnt)
        cout << cnt << endl;

    while (cnt > 1) {
        --cnt;
        if (cnt > 5 && cnt % 2)
            continue;
        cout << cnt << endl;
    }
}
~~~

Übersetze und teste das Programm! Dieses Programm implementiert offensichtlich
einen "Countdown", wobei die genaue Funktion folgendermaßen beschrieben ist:

a. Der eingegebene Startwert wird ausgegeben.
b. Dann wird in geraden Schritten heruntergezählt, solange der aktuelle Stand
    des Countdown größer als Fünf ist.
c. Ab der Zahl Fünf wird jede Zahl ausgegeben bis Eins erreicht ist.

Wie ist es implementiert?

- Die erste `if` Anweisung hat eine Bedingung, die nur `cnt` enthält. An sich
    ist `cnt` allerdings vom Typ `int`. Aufgrund der impliziten
    Konvertierung wird diese Zahl allerdings als `bool` betrachtet und genau jeder
    Wert ungleich `0` wird als `true` interpretiert. Das bedeutet, dass der
    eingegebene Startwert nur ausgegeben wird, wenn dieser ungleich `0` ist.
- Danach folgt die `while` Schleife, deren Bedingung aussagt, dass `cnt` größer
    als `1` sein muss.
- Die erste Anweisung im Rumpf der `while` Anweisung dekrementiert (erniedrigt
    um `1`) den Wert von `cnt`.
- In der Bedingung der darauffolgenden `if` Anweisung wird überprüft, ob `cnt`
    größer als `5` *und* `cnt` ungerade ist.

    Die erste Teilbedingung überprüft, ob `cnt` größer als `5` ist, wobei
    `true` oder `false` als Wert auftreten kann. Da dieser boolesche Wert
    weiterverwendet wird, wird dieser als `int` aufgefasst und im `&&` Ausdruck
    weiterverwendet.
    
    Der Operator `%` der zweiten Teilbedingung ist der
    Restoperator (auch Modulooperator genannt), der den ersten Operanden durch
    den zweiten Operanden dividiert und den Rest ermittelt. Dieser Rest ist
    wiederum eine ganze Zahl.

    Diese beiden Werte werden gemäß UND verknüpft. Wenn die Bedingung erfüllt
    ist, dann wird die Anweisung `continue` ausgeführt, die zur Folge hat, dass
    der Programmablauf bei der geschlossenen geschwungenen Klammer der direkt
    umschließenden Schleife -- auch bei einer `for` Schleife -- fortgesetzt
    wird.

Damit ist das Programm, so wie wir es uns vorgestellt haben, auch
funktionstüchtig. Nur damit ich hier eine weitere Anweisung zeigen kann, wollen
wir das Programm ein wenig verändern. Ersetze den Schleifenkopf durch folgenden
Quelltext:

~~~{.cpp}
while (true) {
    if (cnt <= 1)
        break;
~~~

Das Programm sollte wieder genauso funktionieren. Die Bedingung des
Schleifenkopfes ist immer wahr, also benötigen wir eine andere Möglichkeit die
Schleife abzubrechen. Hier kommt die `break` Anweisung ins Spiel, die die
direkt umschließende Schleife abbricht und direkt *nach* der geschlossenen
geschwungenen Klammer im Programmablauf fortsetzt. Man sieht natürlich, dass
dies hier zu keiner Verbesserung geführt hat, da das Programm länger und nicht
mehr so leicht zu lesen geworden ist.

Wir setzen gleich in diesem Sinne fort und verändern das Programm nochmals
zu demonstrativen Zwecken. Ändere den Schleifenkopf nochmals ab:

~~~{.cpp}
while (1 != 2) {
~~~

Es ist klar, dass `1` immer ungleich als `2` ist und damit die Bedingung
ebenfalls immer wahr ist. Abgesehen von der schlechteren Lesbarkeit hat dies
allerdings keine Auswirkung auf die Laufzeit des Programmes, da der Compiler
diesen Ausdruck auswertet und die Bedingung intern auf `true` abändert. Damit
ist dies äquivalent zu `while (true)`.

### Boolesche Operatoren

Aufgrund der impliziten Konvertierung zu `int` können für boolesche Werte
alle arithmetischen und bitweisen Operatoren verwendet werden, die im Abschnitt
\in[arithmeticops] auf Seite \at[arithmeticops] beschrieben sind.

An eigenen booleschen Operatoren stehen `||`, `&&` und `!` zur Verfügung.

Weiters gibt es diese Operatoren `||` und `&&` auch als Zuweisungsoperatoren
`||=` und `&&=`. Zuweisungsoperatoren werden im Abschnitt \in[arithmeticops]
beschrieben.

## Zeichentypen

In \cpp gibt es mehrere verschiedene Datentypen für einzelne Zeichen, deren
Einteilung sich prinzipiell auf die Größe bezieht:

- Der grundlegende Datentyp für Zeichen ist `char`, der in weiterer Folge noch
    genauer behandelt wird.
- Es gibt einen Datentyp `wchar_t`, der für Unicode-Zeichen ist. Es ist keine
    Größe explizit im \cpp Standard für diesen Datentyp festgehalten. Dies ist
    abhängig von der Implementierung des Compilers und der vorhandenen
    Zeichensätze am jeweiligen System. Es ist lediglich definiert, dass ein
    `wchar_t` mindestens so groß wie ein `char` sein muss.
- Meist werden UTF-16 kodierte Unicode-Zeichen für mehrsprachige Anwendungen
    verwendet. \cppXI unterstützt dies durch einen Datentyp, der in der Lage
    ist genau ein Zeichen aus UTF-16 abzuspeichern. Der Typ heißt `char16_t`.
- Um alle definierten Unicode-Zeichen in einer Kodierung mit fester Größe
    abspeichern zu können, benötigt man UTF-32. \cppXI bietet dafür den
    Datentyp `char32_t`.

Viele Anwendungen verwenden als Datentyp einfach `char`. Dieser ist allerdings
im Standard nicht detailliert definiert und ist von der jeweiligen Implementierung
des Compilers am jeweiligen System abhängig:

- Es ist nicht definiert, ob es sich bei diesem Datentyp um einen
    vorzeichenbehafteten oder einen vorzeichenlosen Datentyp handelt. Wie
    bitte? Wieso Vorzeichen? Es handelt sich doch um einen Zeichendatentyp! Ja,
    schon, aber erinnere dich, dass auch die Zeichentypen zu den integralen
    Datentypen gehören und deshalb in arithmetischen Operationen verwenden
    können. Daher muss man wissen, wie diese als Zahlen interpretiert werden.

    Aus diesem Grund gibt es auch noch die Möglichkeit, dass man explizit mit
    `signed char` ein Vorzeichen angeben kann oder explizit mit `unsigned char`
    kein Vorzeichen fordert. Das sind zwei weitere Zeichentypen, die exakt
    dieselbe Größe wie ein `char` haben.

    Wie kann man jetzt die eigentliche Größe eines Datentyps herausfinden? Es
    gibt hierzu die Header-Datei `limits`, das ein Template
    `numeric_limits::is_signed` zur Verfügung stellt. Erstelle den folgenden
    Code und teste auf deinem System:

    ~~~{.cpp}
    // characters.cpp
    #include <iostream>
    #include <limits>
    
    using namespace std;
    
    int main() {
        cout << "char hat Vorzeichen: " << boolalpha
            << numeric_limits<char>::is_signed
            << endl;
    }
    ~~~

    Bei mir wird `true` ausgegeben. Und bei dir?

- Es ist keine Größe definiert. Es gibt lediglich eine Mindestgröße und die ist
    mit 8 Bits im Standard angegeben. Mehr wird über die Größe nicht
    ausgesagt. Das bedeutet, dass es auch Systeme geben kann, bei denen ein
    `char` 16 Bits oder unter Umständen auch 32 Bits lang sein kann.

    Wie schon im Abschnitt \in[implementationaspects] auf der Seite
    \at[implementationaspects] beschrieben, wird diese Größe als Grundeinheit
    zur Bestimmung der Größe der anderen Datentypen herangezogen. Das bedeutet
    natürlich auch, dass es sich um die kleinste Einheit handelt!

    Du kannst die aktuelle Größe eines eingebauten Datentyps mit dem
    Template `numeric_limits::digits` bestimmen, das die Anzahl der
    Binärstellen ermittelt.  Hänge dazu folgenden Code an das Programm an:

    ~~~{.cpp}
    cout << "char hat Vorzeichen: " << boolalpha
         << numeric_limits<char>::digits << endl;
    ~~~

    Teste dein Programm! Und wie sieht es aus? Du erhältst wahrscheinlich `7`
    und nicht `8`. Das liegt daran, dass `numeric_limits::digits` die Anzahl
    der Bits (Binärstellen) *ohne* dem Vorzeichenbit zurückliefert! Wenn dein
    `char` Typ vorzeichenbehaftet ist, dann musst du noch `1` hinzuaddieren!

- Diese beiden vorherigen Einschränkungen -- nämlich die Mindestgröße eines
    `char` von 8 Bits und die Unbestimmtheit des Vorzeichens -- haben
    Auswirkungen über die Annahme des vorhandenen Zeichenvorrats. Damit
    verbleiben 128 verschiedene Zeichen, womit man sinnvollerweise nur
    davon ausgehen kann, dass die Ziffern, die 26 lateinischen Buchstaben
    und etliche Satzzeichen zur Verfügung stehen, wenn man allgemein
    portable Programme schreiben will.

    Daher nehmen wir für die weiteren Betrachtungen einfach an, dass
    wir auf einem System sind, das einen `char` Typ mit genau 8 Bit hat, der
    zumindest ASCII unterstützt.

    In der ASCII Kodierung sind sowohl die Buchstaben als auch die Ziffern
    jeweils hintereinander angeordnet. Wir nutzen dies jetzt aus, um unser
    Programm um die Bestimmung und Ausgabe aller Dezimalziffern, mittels einer
    Schleife zu erweitern:

    ~~~{.cpp}
    for (int i{0}; i < 10; ++i) {
        cout << '0' + i << endl;
    }
    ~~~

    Hier nehmen wir wiederum eine Zählschleife her, die wir von `0` bis `9`
    zählen lassen. Im Schleifenrumpf nutzen wir aus, dass ein `char` ein
    integraler Datentyp ist, der zu einem `int` konvertiert wird. Dann zählen
    wir unsere Schleifenvariable hinzu und geben das Ergebnis aus. Teste!

    Na ja, das ist nicht das Ergebnis, das wir gerne hätten: 48, 49, 50,... Wieso
    das? In der ASCII Kodierung hat die Ziffer `0` eben den dezimalen Wert 48
    und von dort aufsteigend folgen die restlichen Ziffern. Aufgrund der
    Promotion wird `char` in einen `int` gewandelt. Zu 48 wird 0,1,2... addiert
    und deshalb werden die Zahlen 48, 49,... ausgegeben.

    Deshalb müssen wir den Typ von `int` wieder in ein `char`
    zurückwandeln. Dazu verwenden wir den Konvertierungsoperator `static_cast`.
    Ersetze dazu die Ausgabe im Schleifenrumpf durch die folgende Zeile:

    ~~~{.cpp}
    cout << static_cast<char>('0' + i) << endl;
    ~~~

    Dies gibt an, dass der `int`-Wert in einen `char`-Wert konvertiert werden
    soll. Ein `static_cast` konvertiert zwischen verwandten Typen. Kann nicht
    konvertiert werden, dann wird der Compiler eine Fehlermeldung liefern.

Das klingt jetzt alles sehr umständlich (was es auch ist), aber das ist der
Preis, den man zu zahlen hat, wenn man eine Programmiersprache verwenden will,
die von der kleinsten Prozessoreinheit bis zum Superrechner einsetzbar ist.
Üblicherweise stehen die Zielplattformen fest und damit kennt man auch die
Rahmenbedingungen. Damit ist die Verwendung auch schon wieder definiert und
einfach.

### Zeichenliterale {#characterliterals}

Wie schon gesehen, werden Zeichenliterale durch Zeichen, die in einfachen
Hochkommas eingeschlossen sind angeschrieben. Innerhalb dieser einfachen
Hochkommas hat das Zeichen `\` (engl. *backslash*) eine spezielle Bedeutung. Es
wird als Escape-Zeichen verwendet, wodurch das folgende oder die folgenden
Zeichen eine spezielle Bedeutung erhalten.

Das folgende Beispiel gibt fünf Wörter mit einem anschließenden Zeilenumbruch
aus, der durch `'\n'` angegeben ist:

~~~{.cpp}
cout << "Danach beginnt eine neue Zeile!" << '\n';
~~~

Beachte bitte die Unterschiede zwischen dem C-String-Literal mit den doppelten
Hochkommas und dem Zeichenliteral mit den einfachen Hochkommas.

Hier eine Liste der häufiger verwendeten Zeichenliterale:

`\n`
  : Newline: Zeilenvorschub (engl. *line feed*).
`\r`
  : Carriage return: zurück an die erste Position der Zeile
`\t`
  : Horizontal tabulator: ein Tabulator
`\\`
  : Ein einzelner Backslash
`\'`
  : Ein einzelnes Hochkomma
`\ooo`
  : Der oktale Wert für das Zeichen, wobei die oktale Zahl 1, 2 oder 3 oktale
    Ziffern `o` umfassen kann.
`\xhhh`
  : Der hexadezimale Wert für das Zeichen, wobei die hexadezimale Zahl eine
    beliebige Anzahl an hexadezimalen Ziffern `h` umfassen kann.

Besonders `\n` wird oft verwendet, da man es auch anstatt des Manipulators
`endl` verwenden kann:

~~~{.cpp}
cout << "Hello \n";  // als Teil des C-String-Literals
cout << "World!" << '\n';  // als eigenes Zeichen
~~~

Sowohl die Verwendung von `\n` als auch der Einsatz von `endl` bewirken in
beiden Fällen einen Zeilenumbruch, wenn der Stream im Textmodus geöffnet
ist. Dabei wird vom Compiler für die Plattform, für die übersetzt wird, das
richtige Zeilenumbruchszeichen eingesetzt. Das ist insofern interessant als
zum Beispiel unter Windows ein Zeilenumbruch durch die ASCII-Zeichenfolge
`\r\n` und unter Unix nur `\n` verwendet wird.

Der Unterschied von `\n` zu `endl` ist, dass mittels `endl` auch der Puffer des
Streams geleert wird (engl. *flush*), in den die Zeichen geschrieben werden,
während bei `\n` nur ein Zeilenumbruch erzeugt wird. Dieser Unterschied ist
wichtig, wenn in Dateien geschrieben wird, da in diesem Fall das Leeren eines
Puffers die Laufzeit durchaus erhöhen kann.

Da es in \cppXI auch die Möglichkeit gibt, Zeichen aus dem Unicode Standard in
verschiedenen Kodierungen darzustellen, gibt es auch eine syntaktische
Möglichkeit, diese anzugeben. Schaue dir die folgenden Beispiele an:

~~~{.cpp}
u'\xC0DE'
u'\uC0DE'
U'\UDEADC0DE'
~~~

Du siehst, dass es dazu einerseits ein Präfix vor dem ersten Hochkomma gibt
und andererseits innerhalb der Hochkommas analog zu `\ooo` und `\xhhh` eine
weitere Notation angibt, um durch 4 oder 8 hexadezimale Ziffern ein einzelnes
Zeichen aus dem Unicode Standard anzugeben. Die Form mit den 4 hexadezimalen
Ziffern wie z.B. `u'\uC0DE'` ist eine Abkürzung für `U'\U0000C0DE'`.


## Ganze Zahlen

Ganze Zahlen gibt es ebenfalls in verschiedenen Größen. Im Abschnitt
\in[implementationaspects] auf der Seite \at[implementationaspects] wurde schon
prinzipiell auf die Speichergrößen eingegangen. Es ist wichtig zu wissen, dass
zwar die absoluten Speichergrößen nicht fixiert sind, sehr wohl aber die
Größenverhältnisse:

`short int`
  : Das ist im Bereich der ganzen Zahlen die prinzipiell kleinste
    Größe. Anstatt `short int s;` kann man einfach `short s;` schreiben. Dieser
    Datentyp sollte nur verwendet werden, wenn es ein API erfordert oder wenn
    man bezüglich der Speichergröße ganz bestimmte Anforderungen hat. Das
    bedeutet, dass man im Zweifelsfall die Finger davon lässt.

`int`
  : Das ist der Standarddatentyp für ganze Zahlen! Es ist sichergestellt, dass
    dieser Typ mindestens die gleiche Größe hat wie ein `short`.

`long int`
  : Das ist die nächste Größe und kann einfach als `long` verwendet werden.
    Der Standard schreibt vor, dass ein `long` mindestens die Größe eines `int`
    haben muss.

`long long int`
  : Die größte Variante kann man abgekürzt als `long long` schreiben und muss
    mindestens die Größe eines `long` haben.

Ganze Zahlen sind im Gegensatz zum Zeichendatentyp immer vorzeichenbehaftet.
Will man das Vorzeichen explizit angeben, dann kann man dies mit den Schlüsselwörtern
`signed` beziehungsweise `unsigned` erreichen. Anstatt `signed int si;` kann auch
nur `signed si;` und analog dazu kann anstatt `unsigned int ui;` auch nur
`unsigned ui;` verwendet werden.

Es ist dringend zu empfehlen immer bei den vorzeichenbehafteten Typen zu
bleiben, da es zu weniger Fehlern bei den Berechnungen kommen kann. Verwende
einen `unsigned` Typ nur, wenn ein API es direkt verlangt oder wenn bitweise
Operationen ausgeführt werden müssen!

Werden Typen mit einer definierten Größe benötigt, dann kann man Typen aus der
Headerdatei `<cstdint>` verwenden wie zum Beispiel `int64_t` (genau 64 Bits),
`int_least32_t` (mindestens 32 Bits), `uint16_t` (vorzeichenlos, genau 16 Bits)
oder `int_fast16_t` (mindestens 16 Bits, der schnellste Ganzzahltyp mit
mindestens 16 Bits).

Ein Ganzzahltyp, der nicht zum Rechnen verwendet wird, aber extrem wichtig ist,
ist `size_t`, der ein implementierungsabhängiger, vorzeichenloser Typ ist, der
die Größe jedes beliebigen Objektes annehmen kann. Aus diesem Grund wird dieser
Typ oft verwendet, wenn die Größe eines Objekts anzugeben ist. Der Operator `new`
(siehe später) erwartet sich zum Beispiel einen Wert vom Typ `size_t` und der
Operator `sizeof` liefert einen Wert dieses Typs zurück.

### Arithmetische Operatoren {#arithmeticops}

Für die arithmetischen Datentypen, also für alle integralen Typen und die
Gleitkommazahlen, stehen die schon bekannten Operatoren `+`, `-`, `*`, `/`, `%`
und `++`, `--` zur Verfügung.

Weiters gibt es für die arithmetischen Datentypen noch die Zuweisungsoperatoren
`+=`, `-=`, `*=`, `/=` und `%=`. `a += 2;` ist äquivalent zu `a = a + 2;`,
wobei `a` jedoch nur ein Mal ausgewertet wird! Vollständig äquivalent zu `a++;`
zu `a += 1;`.

Diese einmalige Auswertung ist im folgenden Beispiel zu sehen, wobei das
Konstrukt `int&` schon im Abschnitt \in[values] prinzipiell besprochen worden
ist. Im Zusammenhang mit dem Rückgabewert von Funktionen werden wir uns dies
detailliert im Abschnitt \in[functionarguments] auf der Seite
\at[functionarguments] ansehen:

~~~{.cpp}
// arithmeticops.cpp
#include <iostream>

using namespace std;

int i;

int& f() {
    cout << "f()" << endl;
    return i;
}

int main() {
    cout << "i == " << i << endl;
    f() = f() + 1;
    cout << "i == " << i << endl;
    f() += 1;
    cout << "i == " << i << endl;
    f()++;
    cout << "i == " << i << endl;
}
~~~

Die Ausgabe dazu sieht folgendermaßen aus und lässt klar erkennen, wann die
Funktion `f` zweimal aufgerufen wird, d.h. der Ausdruck `f()` zweimal
ausgewertet wird:

~~~{.sh}
i == 0
f()
f()
i == 1
f()
i == 2
f()
i == 3
~~~

Beachte, dass die Funktion `f` eine Referenz zu einer globalen Variablen
zurückliefert. Das bedeutet, dass es sich bei `f()` um einen lvalue handelt!

Das Zurückliefern von Referenzen ist in den wenigsten Fällen sinnvoll und
sollte nur verwendet werden, wenn man sich ganz sicher ist. Hätte man eine
Funktion `g()` so definiert, dann lässt sich das Programm zwar übersetzen
und ausführen, wobei das Verhalten undefiniert ist:

~~~{.cpp}
#include <iostream>

using namespace std;

int& g() {
    int i;
    return i;
}

int main() {
    cout << g() << endl;
}
~~~

Bei mir liefert das Programm folgende Ausgabe, wobei das Verhalten in \cpp
wie gesagt nicht definiert ist:

~~~
-1073792860
~~~

Das liegt daran, dass eine Referenz auf die lokale Variable `i` zurückgeliefert
wird, die am Stack liegt und am Ende der Funktion der Speicher von `i` wieder
freigegeben wird.

Die Situation verschärft sich, wenn man dieser lvalue - Referenz einen Wert
zuweist:

~~~{.cpp}
g() = 1;
~~~

Damit beschreibt man einen Speicherbereich, der einem nicht mehr zur Verfügung
steht. Das Verhalten ist undefiniert, aber im besten Fall wird lediglich der
Wert eines anderen Speicherobjektes überschrieben.

### Bitweise Operatoren

Für ganze Zahlen gibt es auch die bitweisen Operatoren `~`, `|`, `&` und `^`:

- `~` bezeichnet für die Negation. Die bitweise Negation wandelt jedes `0`-Bit
    in ein `1`-Bit und jedes `1`-Bit in ein `0`-Bit und liefert diesen Wert zurück.

- `|` steht für das inklusive Oder. Das inklusive Oder liefert ein `1`-Bit an
    der entsprechenden Bitstelle, wenn eines der Bits der beiden Operanden an
    dieser Bitstelle den Wert `1` aufweist, ansonsten wird das `0`-Bit für
    diese Stelle als Ergebnis produziert.

- `&` bezeichnet das Und. Beim Und wird an der entsprechenden Bitstelle des
    Ergebnisses nur dann ein `1`-Bit produziert, wenn beide Operanden an dieser
    Stelle ein `1`-Bit aufweisen, ansonsten ein `0`-Bit.

- `^` ist der Operator für das exklusive Oder. Ein exklusives Oder liefert nur
    dann ein `1`-Bit an der entsprechenden Bitstelle, wenn genau ein Bit der
    beiden Operanden an dieser Bitstelle den Wert `1` aufweist, ansonsten wird
    das `0`-Bit für diese Stelle als Ergebnis produziert.


Das folgende Beispiel demonstriert diese Operatoren:

~~~{.cpp}
// bitops.cpp
#include <iostream>
#include <bitset>

using namespace std;

int main() {

    unsigned int u1{0x0F};
    unsigned int u2{0x3C};

    cout << "u1 = " << bitset<8>{u1} << endl;
    cout << "u2 = " << bitset<8>{u2} << endl;
    cout << "u1 | u2 = " << bitset<8>{u1 | u2} << endl;
    cout << "u1 & u2 = " << bitset<8>{u1 & u2} << endl;
    cout << "u1 ^ u2 = " << bitset<8>{u1 ^ u2} << endl;
    cout << "~u1 = " << bitset<8>{~u1} << endl;
}
~~~

In der Headerdatei `<bitset>` ist der Typ `bitset` enthalten, der hier
lediglich verwendet wurde, um auf einfache Art und Weise den Wert als Bitmuster
*auszugeben*. Ansonsten ist dies hier nicht wichtig und es hätte genauso ein
`int` verwendet werden können.

Es kommt zu folgender Ausgabe:

~~~{.sh}
u1 = 00001111
u2 = 00111100
u1 | u2 = 00111111
u1 & u2 = 00001100
u1 ^ u2 = 00110011
~u1 = 11110000
~~~

Dieses Beispiel zeigt sehr schön die bitweisen Operationen! Achte aber immer
auf die Prioritäten der Operatoren oder, besser noch, setze explizit
Klammern. Das folgende Beispiel zeigt dies deutlich:

~~~{.cpp}
if (u1 & 0x07 == 1) {
    cout << "Bit 0 oder 1 oder 2 von u1 ist gesetzt!";
} else {
    cout << "Keines der Bits 0, 1, 2 von u1 ist gesetzt!";
}
~~~

Die diesbezügliche Ausgabe wird folgendermaßen aussehen:

~~~{.sh}
Keines der Bits 0, 1, 2 von u1 ist gesetzt!
~~~

Diese Aussage ist jedoch falsch, da das niederwertigste Bit (mit der Position
0), also das am weitesten rechts stehende Bit, in `u1` eindeutig `1` ist! Das
liegt daran, dass der Gleichheitsoperator eine höhere Priorität als der
Operator `&` hat. Damit wird festgestellt, dass `0x7` (also die drei
niederwertigsten Bits) ungleich `1` ist und daher zu `false`
evaluiert. Infolge einer impliziten Konvertierung wird `false` zu `0` gewandelt
und bitweise UND verknüpft mit `u1`, womit nur `0` als Ergebnis entstehen kann.
Dieses Ergebnis `0` entspricht in weiterer Folge dem booleschen Wert `false`
und hiermit folgt die entsprechende Ausgabe!

Zusätzlich gibt es auch noch Verschiebeoperatoren, die in einem integralen
Datentyp den enthaltenen Wert um eine bestimmte Anzahl von Bits nach links
oder nach rechts verschieben und den resultierenden Wert zurückliefern. Handelt
es sich um einen vorzeichenlosen Typ, dann werden rechts beziehungsweise links
`0`-Bits nachgeschoben. Bei einem vorzeichenbehafteten Typ wird bei einem
Rechtsverschieben das Vorzeichenbit (das höchstwertigste Bit) nachgeschoben.

Erweitere die Datei um die folgenden Zeilen und teste wiederum:

~~~{.cpp}
cout << "u1 << 2 = " << bitset<8>{u1 << 2} << endl;
cout << "u1 << 3 = " << bitset<8>{u1 << 3} << endl;
cout << "u1 >> 2 = " << bitset<8>{u1 >> 2} << endl;

int8_t i1{-127};
cout << "i1 = " << static_cast<int>(i1) << " = "
     << bitset<8>{static_cast<uint8_t>(i1)} << endl;
cout << "i1 >> 2 = "
     << bitset<8>{static_cast<uint8_t>(i1 >> 2)} << endl;
~~~

Die Ausgabe dieser Anweisungen sieht folgendermaßen aus:

~~~{.sh}
u1 << 2 = 00111100
u1 << 3 = 01111000
u1 >> 2 = 00000011
i1 = -127 = 10000001
i1 >> 2 = 11100000
~~~

In der letzten Zeile ist auch sehr schön zu sehen, wie das Vorzeichenbit
zweimalig von links nachgeschoben wurde!

Zusätzlich gibt es diese Art von Operatoren auch als Zuweisungsoperatoren:
`|=`, `&=`, `^=`, `<<=` und `>>=`.


### Literale für ganze Zahlen

An sich sind die Literale für ganze Zahlen in ihrer Grundform einfach: Die Ziffern werden
hintereinander angeschrieben, optional mit einem Vorzeichen als Präfix. Der Typ
des Literals wird von \cpp automatisch bestimmt, wobei je nach Größe entweder
ein `int`, ein `long` oder ein `long long` verwendet wird.

Allerdings gibt es abgesehen von dieser Grundform viele verschiedene
Möglichkeiten, wie Zahlenliterale angeschrieben werden können:

Oktale und hexadezimale Notation
  : Mit dem Präfix `0` kann eine oktale Zahl angeschrieben werden und mit dem
    Präfix `0x` eine hexadezimale Zahl. In diesem Fall funktioniert die
    Typbestimmung wie in der Grundform, nur wird ebenfalls versucht, den Typ in eine
    `unsigned` Form zu bringen.

    Schreibe den folgenden Quellcode:

    ~~~{.cpp}
    // integers.cpp
    #include <iostream>
    
    using namespace std;
    
    int main() {
        cout << 377 << endl;
        cout << 0377 << endl;
    }
    ~~~

    Als Ausgabe wirst du erhalten:

    ~~~{.sh}
    377
    255
    ~~~

    In der ersten Ausgabe sieht man, dass diese gleich ist mit dem dezimalen
    Literal im Quellcode. Bei der zweiten Zahl handelt es sich eben um das
    dezimale Äquivalent der oktalen Zahl $377_8$. Das bedeutet, dass eine
    führende Null eine Bedeutung hat!

Notation für vorzeichenlose Zahlen
  : Mittels dem Suffix `U` (auch `u` möglich) kann explizit eine vorzeichenlose
    ganze Zahl angegeben werden.

Notation für `long` und `long long` Zahlen
  : Weiters können Zahlenliterale mittels dem Suffix `L` als `long`
    und mit `LL` als `long long` ausgezeichnet werden. Alternativ
    können anstatt `L` und `LL` auch die Kleinbuchstaben `l` und `ll`
    verwendet werden. Allerdings rate ich davon ab, da diese im Quelltext
    schlechter zu erkennen sind.

    Diese Angabe kann auch noch mit der Angabe für vorzeichenlose Zahlen
    kombinierbar, wie zum Beispiel `UL` oder `ULL`.

<div class="c++14">
Es besteht auch die Möglichkeit binäre Literale anzugeben, indem man das Präfix
`0b` verwendet, also z.B. `0b1001` entspricht dem dezimalen Literal `9`.

Weiters kann man Zahlenliterale mittels dem einfachen Hochkomma gliedern,
sodass eine bessere Lesbarkeit gegeben ist. Die ganze Zahl für eine Million
kann als `1'000'000` angeschrieben werden. Die einfachen Hochkommas haben für
\cpp in diesem Fall keine Bedeutung und können beliebig gesetzt werden.
</div>

<div class="c++14">
Eine weitere Erweiterung ist, dass Zahlenliterale zum Zwecke der besseren
Lesbarkeit mittels dem Trennzeichen `'` beliebig unterteilt werden können:

~~~{.cpp}
// digitseps.cpp
#include <iostream>

using namespace std;

int main() {
    cout << 1'000'000 << endl;
    cout << 0644'711 << endl;
    cout << 0xFF'00 << endl;
    cout << 1'234.5 << endl;
    cout << 0b1111'0000 << endl;
}
~~~
</div>

## Gleitkommazahlen

Es gibt insgesamt drei verschiedenen Typen für Gleitkommazahlen, wobei auch hier
die absoluten Größen von der Implementierung abhängig sind:

`float`
  : kennzeichnet eine Gleitkommazahl mit einfacher Genauigkeit. Diese sollte
    nur verwendet werden, wenn man genau weiß warum man diese einsetzen will.

`double`
  : gibt doppelte Genauigkeit an und ist der Standard für
    Gleitkommazahlen. Alle Literale sind ohne weitere Kennzeichnung von diesem
    Typ. Ein `double` ist mindestens so groß wie ein `float`.

`long double`
  : steht für erweiterte Genauigkeit. Es ist definiert, dass `long double`
    mindestens so groß ist wie `double`.

Du solltest am besten immer `double` verwenden.

Achtung, es gibt keine Promotion von `float` auf `double`, wie du im folgenden
Beispiel sehen kannst!

~~~{.cpp}
// floatings.cpp
#include <iostream>

using namespace std;

int main() {
    cout << sizeof(2.5F) << endl;
    cout << sizeof(2.5) << endl;
    cout << sizeof(2.5L) << endl;
}
~~~

Die Ausgabe auf meinem System ist:

~~~{.sh}
4
8
12
~~~

Konvertierungen auf den gemeinsamen größeren Datentyp in Ausdrücken finden sehr
wohl statt. Hänge folgende Anweisungen an:

~~~{.cpp}
cout << sizeof(f + d) << endl;
cout << sizeof(ld + d) << endl;
~~~

Die Ausgabe dieser beiden Anweisungen sieht dann folgendermaßen aus:

~~~{.sh}
8
12
~~~

Damit siehst du deutlich, dass die implizite Konvertierung zum größeren
Datentyp von \cpp vorgenommen wird.

### Literale für Gleitkommazahlen

Gleitkommazahlen können in der üblichen Form angeschrieben werden, wie
z.B. `-2.5` oder `.1e-3` ($0.1 \cdot 10^{-3}$). Der Datentyp eines solchen Literals
ist per Default `double`.

Auch hier gibt es Suffixe für die beiden anderen Gleitkommazahltypen:

Einfache Genauigkeit
  : Mit dem Suffix `F` (oder alternativ `f`) kann ein Literal als `float`
    angeschrieben werden, wie zum Beispiel `1.2F`.

Erweiterte Genauigkeit
  : Um Literale als `long double` zu kennzeichnen, wird das Suffix `L` (oder `l`)
    verwendet, wie zum Beispiel `1.5L`.

## void

Der Datentyp `void` wird in zwei verschiedenen Arten gebraucht:

- Einerseits wird `void` als Rückgabetyp einer Funktion gebraucht, wenn diese
    *keinen* Wert zurückliefert. Solch eine Funktion wird in der Informatik oft
    auch als Prozedur (engl. *procedure*) genannt.

    Die folgende Funktion liefert keinen Rückgabewert zurück und hat auch keine
    formalen Parameter:

    ~~~{.cpp}
    void say_hello() {
        cout << "hello" << endl;
    }
    ~~~
  
    In diesem Fall wird die Funktion beendet, wenn der Programmablauf bei der
    geschwungenen Klammer angekommen ist. Alternativ kann auch eine `return`
    Anweisung ohne Wert verwendet werden:
  
    ~~~{.cpp}
    void say_hello() {
        cout << "hello" << endl;
        return;
    }
    ~~~

- Im Zusammenhang mit Zeigern (siehe Abschnitt \in[pointer] auf Seite
    \at[pointer]) wird `void*` verwendet, um einen Zeiger auf einen Wert
    unbekannten Typs anzugeben. In high-level \cpp ist dies zu vermeiden.
