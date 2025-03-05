
# Modularisierung

Ein Programm stellt eine Lösung für ein Problem dar. Bei wachsender Problemgröße
ergibt sich jedoch, dass der Umfang und die Komplexität der Problemlösung
ebenfalls größer wird.

Daraus ergeben sich die folgenden Konsequenzen:

- Meist kann ein großes Problem nicht in einem Lösungsschritt
    gelöst werden. Stattdessen wird das Problem sinnvollerweise in
    Teilprobleme zerlegt, die einzeln gelöst werden. Die Lösung des
    Gesamtproblems ergibt sich durch Zusammensetzen der Teillösungen.

- Selbst wenn eine Lösung in einem Schritt für ein großes Problem möglich wäre,
    wäre diese Lösung in der Regel ebenfalls groß und damit
    unübersichtlich. Mit der fehlenden Übersichtlichkeit ergeben sich beim
    Programmieren mehr Fehlerquellen und die Wartbarkeit des Programmes nimmt
    ab.

- Mit zunehmender Problemgröße kann ein Problem innerhalb eines vorgegebenen
    Zeitrahmens von einem einzelnen Entwickler nicht gelöst werden. Damit
    werden mehrere Entwickler benötigt, die sinnvollerweise jeder an einer
    eigenen Teillösung arbeiten.

- Hat man ein Teilproblem einmal gelöst, dann kann man diese Lösung unter
    Umständen auch in einem anderen Kontext wiederverwenden.

Aus diesen Gründen heraus, versucht man ein Programm in kleinere Teile
aufzuteilen. Jeder kleine Programmteil löst für sich ein Teilproblem des
gesamten Problems. Solche kleineren Teile werden Module genannt (siehe
Abschnitt \in[modules]).

Mit zunehmender Anzahl an Modulen wächst auch die Anzahl der Bezeichner, die in
einem Programm zur Verfügung stehen. Bei einer großen Anzahl an Bezeichnern, liegt
wiederum eine Unübersichtlichkeit vor und die Gefahr von Namenskollisionen
steigt. Deshalb gibt es das Konzept des Namensraumes, mit dem man eine
Strukturierung der Identifier vornehmen kann (siehe Abschnitt \in[namespace]).

Ein Programm besteht aus einzelnen Modulen, die
miteinander verbunden werden und einen gewissen Aufbau aufweisen.

## Module {#modules}

Ein Modul stellt seine Funktionalität über eine Schnittstelle zur Verfügung,
während die Implementierung der Funktionalität dem Benutzer verborgen
bleibt. Oft verwendet ein Modul andere Module, um die geforderte Funktionalität
erbringen zu können.

Derzeit bietet \cpp kein eigenes Konzept an, das Module direkt
unterstützt. Stattdessen wird ein Modul auf der Basis von *physischer
Strukturierung* des Quelltextes und sprachlichen Hilfsmitteln gebildet.

- In den meisten \cpp Implementierungen stehen uns Dateien zur *physischen
    Strukturierung* des Quelltextes zur Verfügung. An sich geht der \cpp Standard
    nicht explizit von Dateien als Container für den \cpp Quelltext aus, da der
    \cpp Standard offen lässt, wie \cpp Quelltext repräsentiert und gespeichert
    wird.  Da die meisten \cpp Implementierungen Dateien verwenden, werden wir
    weiterhin von Dateien sprechen.

    Das heißt, dass ein Modul in \cpp seine Funktionalität in einer `.cpp`-Datei
    ablegt und seine Schnittstelle durch eine Headerdatei (siehe Abschnitt
    \in[headers]) zur Verfügung stellt. Headerdateien haben in der Regel eine
    Erweiterung `.h`, allerdings sind prinzipiell beliebige Erweiterungen möglich.

- Als *sprachliche Hilfsmittel* stehen prinzipiell Variablen, Funktionen, Klassen
    und Namensräume zur Verfügung, die in einer Headerdatei angeführt werden und
    die Schnittstelle beschreiben.

    Als Hilfsmittel für die generische Programmierung stehen Templates zur
    Verfügung (siehe Abschnitt \in[templatefoundations]).

    Weiters gibt es Spezifizierungssymbole wie `inline`, `extern`, `static`,
    `const` und `constexpr`, die zur genaueren Schnittstellenbeschreibung
    herangezogen werden.

Nimmt ein Modul andere Module in Anspruch, dann inkludiert es deren Schnittstellen
wiederum als Headerdateien. Solch eine Headerdatei enthält hauptsächlich
Funktionen, Klassen und Objekte.

Die Implementierung des Moduls kann man vor dem Benutzer des Moduls
verbergen, sodass dieser nur die Schnittstelle zu Gesicht bekommt.

### Übersetzung zu einem Programm {#translationunit}

Der Übersetzungsschritt einer einzelnen Datei sieht so aus, dass der Compiler
zuerst in einem Vorverarbeitungsschritt den Präprozessor (von
engl. *preprocessor*, Vorverarbeiter) beauftragt, die Quelldatei in eine sogenannte
Übersetzungseinheit (engl. *translation unit*) zu übersetzen.

Bei dieser Vorverarbeitung werden zuerst alle Präprozessoranweisungen ausgeführt und
als Ergebnis entsteht reiner \cpp Quelltext ohne Präprozessoranweisungen. Wir
erkennen solche Präprozessoranweisungen an dem Rautezeichen `#`. Mehr dazu im
Abschnitt \in[headers].

Danach wird die entstandene Übersetzungseinheit vom eigentlichen Compiler in eine
Objektdatei übersetzt. Diese enthält nur Objektcode (auch Maschinencode
genannt), also Anweisungen in der Maschinensprache des Prozessors.

Im Zuge dieses Vorganges müssen die Teilergebnisse, wie zum Beispiel die
Objektdateien, nicht unbedingt als eigenständige Dateien vorliegen.

Sind alle benötigten Schritte vorgenommen worden, dann
geht es weiter mit dem sogenannten Linken (engl. *link*, binden). In
diesem Schritt, der durch einen Linker (engl. *linker* oder *link editor*)
vorgenommen wird, werden alle Bezeichner von Deklarationen mit den
entsprechenden Definitionen -- unter Umständen in anderen Objektdateien
vorhanden -- verbunden. Schauen wir uns die folgende einfache Anweisung
zur Ausgabe eines Textes an:

~~~{.cpp}
cout << "Test" << endl;
~~~

Hier werden die Bezeichner `cout` und `endl` verwendet, die in der Headerdatei
`iostream` deklariert worden sind. Allerdings verweisen diese Bezeichner auf
Objekte, für die es auch eine eindeutige Definition geben muss, die in diesem
konkreten Fall in der Standardbibliothek enthalten ist. Diese
Standardbibliothek wird von der \cpp Implementierung zur Verfügung gestellt und
auch automatisch verwendet.

Objektdateien können zu Bibliotheksdateien (engl. *library*) zusammengefasst
werden und hiermit gemeinsam verwendet werden.

Prinzipiell können die zu verbindenden Bezeichner in beliebigen Objektdateien
oder in beliebigen Bibliotheken enthalten sein. Wichtig ist nur, dass der
Linker diese findet und die Adressen der Speicherobjekte den Bezeichnern
zuordnen kann. Das heißt, der Linker fügt den gesamten benötigten Code in eine
Datei zusammen und ersetzt die Stellen der Bezeichner mit den Adressen der
Speicherobjekte.

Damit haben wir -- vereinfacht ausgedrückt -- ein ausführbares Programm
erhalten. Üblicherweise ist der Linker in den Compiler integriert!

### Headerdateien {#headers}

Werfen wir einen genaueren Blick auf den Präprozessor. Bis jetzt haben wir uns
die `#include` Anweisung angesehen, die eine von mehreren
Präprozessoranweisungen ist. Abgesehen von der "if" und der "define" Anweisung
werden heute jedoch meist keine Präprozessoranweisung mehr verwendet.

Verwendet haben wir bis jetzt solche Präprozessoranweisungen nur um
Headerdateien aus der Standardbibliothek einzubinden, wie zum Beispiel:

~~~{.cpp}
#include <iostream>
~~~

Diese Anweisung bindet den gesamten Text der Headerdatei `iostream` anstelle
dieser Präprozessoranweisung ein. Unter Umständen enthält eine
Headerdatei wiederum Präprozessoranweisungen, dann werden diese im Zuge der
Einbindung vom Präprozessor entsprechend ausgeführt.

Wie schon erwähnt haben die Headerdateien meist die Dateinamenerweiterung `.h`,
dies muss jedoch nicht zwingend so sein. Das beste Beispiel sind die
Headerdateien der \cpp Standardbibliothek, die überhaupt keine Erweiterung
aufweisen, wie im obigen Beispiel zu sehen ist.

Es gibt zwei Arten wie die `#include`-Präprozessoranweisung verwendet werden
kann:

- Einerseits kann diese in der schon bekannten Form `#include <iostream>` --
    also mit dem Headernamen in spitzen Klammern -- verwendet werden. Dies
    bedeutet, dass der Präprozessor die angegebene Datei in den
    Standardverzeichnissen der \cpp Implementierung suchen soll.

    Innerhalb der Standardbibliothek gibt es eine spezielle Notation für
    Headerdateien, die von der Programmiersprache `C` kommen und in \cpp direkt
    verwendet werden können. Den Namen dieser Headerdateien ist ein kleines "c"
    vorangestellt, wie wir dies schon von `<cstdint>` kennen. Auch die
    Bezeichner dieser Headerdateien sind im Namensraum `std` enthalten
    und müssen deshalb zum Beispiel mittels `std::` oder `using namespace std;`
    zugreifbar gemacht werden.

- Andererseits kann man diese in der Form `#include "mathutils.h"` verwenden,
    also mit doppelten Anführungszeichen anstatt mit spitzen Klammern. Dies
    bedeutet, dass der Präprozessor die Datei in den Verzeichnissen des
    aktuellen Projektes suchen soll. Wird nichts weiter angegeben, dann
    bedeutet dies, dass im aktuellen Verzeichnis gesucht wird.

Nehmen wir einmal an, dass wir eine nützliche Funktion `squared` geschrieben
haben, die das Quadrat der übergebenen Zahl berechnet und das Ergebnis
zurückliefert und wir diese Funktion in mehreren Übersetzungseinheiten
verwenden wollen. Dann macht es Sinn, diese Funktion in eine eigene Datei zu
geben:

~~~{.cpp}
// mathutils.cpp
double squared(double val) {
    return val * val;
}
~~~

Wir können diese Datei übersetzen. Allerdings müssen wir dazu dem Compiler
mitteilen, dass dieser nur eine Objektdatei erzeugen soll, da dieser sonst ein
ausführbares Programm generieren will. Dies ist jedoch nicht möglich, da die
Funktion `main` nicht vorhanden ist und im Zuge des Bindens die
Funktionsdefinition für `main` nicht zur Verfügung steht.

Verwende deshalb die entsprechenden Optionen deines Compilers oder konfiguriere
deine Entwicklungsumgebung entsprechend. Für die Übersetzung eines Quelltextes
in eine Objektdatei ist im Abschnitt \in[compilation] die Anleitung für die
gebräuchlichen Compiler und Betriebssysteme vorhanden. Wir gehen jetzt davon
aus, dass eine Objektdatei vorliegt.

In einem weiteren Schritt legen wir eine neue Datei an, die diese Funktion
verwenden soll:

~~~{.cpp}
// main.cpp
#include <iostream>

using namespace std;

int main() {
    cout << squared(4) << endl;
}
~~~

Will man jetzt dieses Programm übersetzen, dann muss man dem Compiler (mit
Linker) auch alle Quelldateien bekannt geben. Allerdings wirst du feststellen,
dass eine Übersetzung nicht möglich ist, da der Bezeichner `squared` dem
Compiler nicht bekannt ist. Das ist auch verständlich, da wir keine Deklaration
und im Speziellen auch keine Definition dafür haben.

Die einfachste Möglichkeit dies zu lösen ist, dass die Definition dem
Compiler bekannt gegeben wird. Modifiziere den Quellcode bezüglich der
Präprozessoranweisungen folgendermaßen:

~~~{.cpp}
#include <iostream>

#include "mathutils.cpp"
~~~

Beim Übersetzen braucht nur die Datei `main.cpp` angegeben werden. Das
funktioniert, aber es ist nicht gut, denn es wurde die *Definition* der Funktion
zur Gänze in die Datei `main.cpp` eingebunden. Das führt in größeren Programmen
unweigerlich zu Fehlern und dupliziertem Maschinencode. Eigentlich
wollten wir, die Funktionsdeklaration der Funktion `squared()` dem Compiler
beim Übersetzen der Datei `main.cpp` bekanntgeben. Lege deshalb eine
Headerdatei `mathutils.h` mit folgendem Inhalt an, die die Schnittstelle
unseres Moduls definiert:

~~~{.cpp}
double squared(double val);
~~~

Ändere weiters in der Datei `main.cpp` die Präprozessoranweisung für das
Einbinden unserer Headerdatei wie nachfolgend ab.

~~~{.cpp}
#include "mathutils.h"
~~~

Du siehst hier, dass der Name der Headerdatei in doppelte Hochkommas
eingeschlossen ist und nicht in spitzen Klammern, wie bei den Headerdateien der
Standardbibliothek.

Übersetze nun wiederum nur die Datei `main.cpp`. Das Übersetzen wird jetzt
problemlos funktionieren, aber das Binden wird mit einer Fehlermeldung
scheitern. Diese Fehlermeldung sagt aus, dass es eine undefinierte Referenz zu
der Funktion `squared(double)` gibt.

Das ist leicht zu beheben, indem du auch die Datei `mathutils.cpp` dem Compiler
mitgibst. Damit wird immer die Datei `main.cpp` als auch die Datei
`mathutils.cpp` übersetzt. Es macht natürlich wenig Sinn alle Dateien immer zu
übersetzen, wenn nur eine Datei verändert worden ist. Deshalb können beim
Übersetzen anstatt der nicht geänderten Quelldateien die Objektdateien
angegeben werden, der Compiler (mit integriertem Linker) wird nur die
abgeänderten Quelldateien übersetzen und die Objektdateien binden.

Eine weitere Verbesserung werden wir jetzt einbauen, die uns in Zukunft vor
(Tipp-)Fehlern schützen kann. Füge die gleiche Präprozessoranweisung
`#include "mathutils.h"` auch an den Anfang der Datei `mathutils.cpp` ein. Damit
kann der Compiler beim Übersetzen der Datei `mathutils.cpp` die Definitionen
gegen die Deklarationen in der Datei `mathutils.h` prüfen. Damit ist
sichergestellt, dass diese Deklarationen immer zu den Definitionen passen und
beim Einbinden der Includedatei in andere Dateien wissen wir, dass die
Deklarationen richtig sind.

Eigentlich ist es so, dass sogenannte Make-Systeme verwendet werden oder die
Entwicklungsumgebung nach erfolgter Konfiguration sich selber um das Übersetzen
und Linken der relevanten Dateien kümmert. Weiters wird es in der Regel so
sein, dass mehrere zusammenhängende Objektdateien zu einer Bibliothek
zusammengefasst werden, sodass nur mehr die Bibliothek beim Linken angegeben
werden muss.

Das ist soweit schon einmal ganz gut, allerdings gibt es noch immer ein
Problem, dass sich dadurch äußert, dass eine Headerdatei durchaus auch mehrmals
eingelesen werden kann. Damit dies nicht passiert greift man zu folgender
Technik, die als Wächter (engl. *guard*) bezeichnet wird. Dazu wird die
Headerdatei so umgebaut, dass der gesamte Inhalt mit einer
if-Präprozessoranweisung umschlossen wird:

~~~{.cpp}
#ifndef MATHUTILS_H
#define MATHUTILS_H

double squared(double val);

#endif
~~~

Das bedeutet, dass der Präprozessor den if-Zweig der `#ifndef` Anweisung (if
not defined) nur betreten wird, wenn das Präprozessormakro `MATHUTILS_H`
noch nicht definiert ist. In diesem Fall wird diese im if-Zweig definiert und
die eigentlichen Deklarationen folgen. Abgeschlossen wird mit einem
`#endif`. Wird diese Headerdatei ein zweites Mal beim Übersetzen eingelesen,
dann ist das Präprozessormakro `MATHUTILS_H` schon definiert und die
Deklarationen werden nicht beachtet.

Damit verhindern wir auch rekursives Einlesen von Headerdateien! Nehmen wir an,
dass wir eine Headerdatei `a.h` und eine Headerdatei `b.h` haben. Dann könnte
es sein, dass `a.h` die Datei `b.h` inkludieren will und `b.h` wiederum `a.h`
inkludieren will. Ohne einen Wächter ergibt sich eine Endlosrekursion.

Im Abschnitt \in[headercontents] wird festgehalten welcher Inhalt in
Headerdateien enthalten sein darf und welcher nicht.


## Binden

Wir haben schon gesehen, dass mehrere Übersetzungseinheiten durch den Linker
gebunden werden. Jetzt werden wir uns ansehen, welche Möglichkeiten es gibt,
Bezeichner miteinander zu binden.

Es gibt zwei Arten wie in \cpp Bezeichner an Objekte gebunden werden können:

- Bei der externen Bindung (engl. *external linkage*) kann ein Bezeichner
    einer Übersetzungseinheit auch in anderen Übersetzungseinheiten verwendet
    werden.

- Bei der internen Bindung (engl. *internal linkage*) steht der Bezeichner nur
    innerhalb einer Übersetzungseinheit zur Verfügung.

### Externe Bindung {#externbinding}

Wenn wir uns diese Einteilung ansehen, dann erkennen wir, dass
Funktionsdeklarationen offensichtlich in die Kategorie "external linkage"
fallen, sonst hätte das Binden des Funktionsaufrufes `squared(4)` zur
Definition in der Objektdatei von `mathutils.cpp` nicht funktioniert.

Der Spezifizierer `extern` hat im Zusammenhang mit Funktionen die Bedeutung,
dass die Funktion eine externe Bindung aufweist. Dies ist redundant, da eine
Funktion ja automatisch eine externe Bindung aufweist.

Ebenfalls in diese Kategorie fallen die globalen Variablen! Erweitern wir dazu
unser Beispiel um die Variable `pi`. In der Datei `mathutils.cpp` fügen wir
eine globale Variable hinzu:

~~~{.cpp}
#include <cmath>

double pi{atan(1)*4};
~~~

In der zugehörigen Headerdatei fügen wir eine entsprechende Deklaration hinzu:

~~~{.cpp}
extern double pi;
~~~

Dann können wir in der Datei `main.cpp` auf `pi` zugreifen:

~~~{.cpp}
cout << pi << endl;
~~~

Das `extern` bedeutet, dass es sich hierbei um eine Deklaration handelt, die
aussagt, dass sich die zugehörige Definition in einer anderen
Übersetzungseinheit befindet. Ohne `extern` würde es sich um eine Definition
handeln und es sind keine doppelten Definitionen von Bezeichnern erlaubt, die
auf Speicherobjekte verweisen. Dies würde der Linker als Fehler melden.

Etwas komplizierter wird es bei Definitionen von Klassen, Templates und
inline-Funktionen und dergleichen, denn hier gilt die sogenannte
"one-definition rule".

Prinzipiell ist es so, dass es exakt eine Definition einer Klasse, eines
Templates,... innerhalb eines Programmes geben darf. Eine
solche Definition darf nicht in mehreren Objektdateien enthalten sein.
\cpp kann dies in dieser Form allerdings nicht überprüfen.

Aus diesem Grund gibt es die "one-definition rule" (ODR), die besagt, dass
zwei Definitionen einer Klasse, eines Templates oder einer inline-Funktion
als Exemplare einer eindeutigen Definition angesehen werden, wenn sich diese
in verschiedenen Übersetzungseinheiten befinden und aus der Sicht der
Programmiersprache \cpp als gleich angesehen werden.

Es ist leider so, dass der Compiler diese Regel nicht absolut überprüfen kann
(bei mehreren Übersetzungseinheiten) und es daher sinnvoll ist, seine
Headerdateien geschickt zu verwenden sowie Module einzusetzen.

Hier folgt noch ein Beispiel, das diese Situation demonstriert. Nehmen wir an,
wir schreiben ein Modul, das einen Record beinhalten soll, der aus einer `id`
und `name` besteht. Weiters gibt es eine Funktion, die für einen 
Zeiger auf einen Record die `id` zurückliefert:

~~~{.cpp}
// record.h
struct Record {
    T id;
    char* name;
};

T get_id(Record* ptr);
~~~

Wir sehen hier, dass der Typ `T` bis jetzt nicht festgelegt wurde. Das wird
jetzt ausgenutzt, um den "Fehler" zu demonstrieren. Implementieren wir jetzt
das Modul:

~~~{.cpp}
#include <iostream>

using T = std::string;

#include "record.h"

T get_id(Record* ptr) {
    return ptr->id;
}
~~~

Wir sehen hier, dass `T` als ein `std::string` festgelegt wurde und die
Funktion `get_id` gemäß unserer Anforderung implementiert wurde.

Jetzt wollen wir dieses Modul verwenden:

~~~{.cpp}
// recorduser.cpp
#include <iostream>

using namespace std;

using T = char;
#include "record.h"

int main() {
    Record rec;
    rec.id = 'a';
    cout << get_id(&rec) << endl;
}
~~~

Das Programm wird wahrscheinlich fehlerfrei übersetzen, obwohl es die
ODR verletzt! Allerdings wird das Programm beim Ausführen mit hoher
Wahrscheinlichkeit mit einem Adressbereichsfehler abstürzen. Teste!

Dies liegt daran, dass wir den Typ `T` hier verschieden deklariert haben und
die \cpp-Implementierung diesen Fehler nicht erkennen konnte. Natürlich ist
es in diesem Fall einfach, den Fehler zu vermeiden, da man lediglich den Typ von
`T` in der Headerdatei `record.h` deklarieren hätte müssen.

### Interne Bindung

#### `static`-Variable und `static`-Funktion {#staticfunc}

Globale Variablen, die mittels `static` markiert sind, weisen eine
interne Bindung auf. `static` ist in diesem Zusammenhang ein Relikt aus der
Programmiersprache `C` und wird bei globalen Variablen dazu verwendet, um die
externe Bindung in eine interne Bindung zu wandeln.

~~~{.cpp}
static int num_people;
~~~

Damit ist die globale Variable `num_people` nur mehr in der aktuellen
Übersetzungseinheit sichtbar und wird vom Linker nicht gesehen. In
Headerdateien haben solche Definitionen nichts zu suchen!

Funktionen, die mittels `static` gekennzeichnet werden, bekommen automatisch
interne Bindung. Nehmen wir einfach an, dass wir unsere Funktion `squared` mit
einem `static` versehen:

~~~{.cpp}
static double squared(double);
~~~

Die Wirkung ist, dass diese nur in der aktuellen Übersetzungseinheit zur Verfügung
steht. Damit einhergehend macht es wieder keinen Sinn, so eine
Funktionsdeklaration in eine Headerdatei zu geben.

#### Konstante

Wenn wir uns jetzt das Beispiel mit der Variable `pi` noch einmal ansehen, dann
werden wir sicher feststellen, dass es sich bei `pi` weniger um eine Variable
als mehr um eine Konstante handelt.

In \cpp kann eine Konstante zum Beispiel mit dem Schlüsselwort `const`
definiert werden. Gehen wir also her und fügen an den Anfang der Definition von
`pi`, in der Datei `mathutils.cpp`, das Schlüsselwort `const` hinzu:

~~~{.cpp}
const double pi{atan(1)*4};
~~~

Wenn du jetzt das Programm wieder übersetzen willst, dann wirst du mit einem
Linker-Fehler konfrontiert werden. Das liegt daran, dass eine `const` Variable
in \cpp defaultmäßig interne Bindung aufweist. Es gibt prinzipiell zwei
Möglichkeiten, wie man dies lösen kann:

- Man kann der Konstante bei der Definition explizit mittels `extern` eine
    externe Bindung zuweisen. Das bedeutet, dass vor `const` noch ein
    `extern` hinzugefügt werden muss:

    ~~~{.cpp}
    extern const double pi{atan(1)*4};
    ~~~
    
    Durch `extern` wird die defaultmäßige interne Bindung von `const` auf
    externe Bindung umgewandelt.

- Alternativ dazu kann man die Konstante zur Gänze in die Headerdatei
    verschieben (ohne Angabe von `extern`). Daher gibt es jetzt nicht
    nur eine Konstante, sondern so viele Exemplare der Konstante wie es
    Übersetzungseinheiten gibt, die diese Konstante verwenden, also die
    Headerdatei `mathutils.h` einbinden.

    Das hat aber den Nachteil, dass es einerseits die Konstante mehrmals im
    Objektcode und damit auch im Hauptspeicher gibt. Weiters können sich auch
    leichter Fehler einschleichen, wenn man Änderungen in der
    Headerdatei vornimmt, aber "vergisst" eine oder mehrere Quelldateien zu
    übersetzen, die diese Headerdatei einbinden. Damit kann es unterschiedliche
    Werte für die Konstante im laufenden Programm geben.

    Bei einer Verwendung eines korrekt konfigurierten Buildsystems wird dies
    nicht vorkommen und daher wird es auch nicht zu unterschiedlichen Werten
    kommen. Trotzdem wird es mehrere Speicherobjekte geben und daher werden wir
    diesen Ansatz auch nicht weiter betrachten.

Als Alternative zu `const` kann eine Konstante auch mit dem Schlüsselwort
`constexpr` definiert werden. Bezüglich Bindung verhält sich `constexpr` wie
`const` und kann auch so verwendet werden. Zwei spezielle Punkte sind jedoch zu
beachten:

- Im Standard \cppXI und auch in \cppXIV ist die Funktion `atan` nicht als
    `constexpr` markiert (zu `constexpr`-Funktionen siehe Abschnitt
    \in[constexprfunc]) und deshalb kann diese Funktion eigentlich nicht zur
    Berechnung von \pi{} verwendet werden. Es ist allerdings so, dass bestimmte
    Compiler wie zum Beispiel der GNU `g++` in einer aktuellen Version die
    Funktion `atan` sehr wohl als `constexpr` deklariert und damit einer
    Verwendung in der Initialisierung der `constexpr` Konstante `pi` nichts im
    Wege steht.

- Da eine `constexpr` Konstante nicht notwendigerweise eine Speicheradresse
    besitzt, macht es hier eindeutig mehr Sinn, diese in einer Headerdatei zu
    platzieren!


#### `inline`-Funktionen {#inlinefunc}

Entwickeln wir das Beispiel wieder ein bisschen weiter. Warum soll für die
Berechnung des Quadrats, die nur aus einer einzelnen Multiplikation besteht, auch
zusätzlich ein Funktionsaufruf durchgeführt werden, der einen gewissen Overhead
erzeugt? Besser wäre es, wenn wir den Compiler dazu bewegen könnten, anstatt
des Funktionsaufrufes die Berechnung an Ort und Stelle durchzuführen.

Dies kann man dadurch erreichen, dass man der Funktionsdefinition ein `inline`
voranstellt, das dem Compiler nahe legt, dass der Inhalt der Funktion anstatt
des Funktionsaufrufes eingefügt wird. Damit dies funktioniert, muss der Compiler
bei jedem Übersetzen die Definition der Funktion zur Hand haben. Das bedingt,
dass die Definition einer `inline`-Funktion in der Headerdatei vorhanden sein
muss.

Verschiebe deshalb die Definition von `squared` in die Headerdatei, stelle ein
`inline` voran und lösche die Deklaration. Damit ist in der Headerdatei `mathutils.h`
folgendes bezüglich der Funktion `squared` enthalten:

~~~{.cpp}
inline double squared(double val) {
    return val * val;
}
~~~

`inline` Funktionen weisen eine interne Bindung auf, obwohl es sich um eine
Funktionsdefinition handelt. Analog dazu verhält es sich mit
`constexpr`-Funktionen.

Der Sinn einer derartigen `inline`-Spezifikation liegt darin, dass der Aufruf einer
Funktion zugunsten einer größeren Codemenge eingespart wird. Damit ergibt sich,
dass so eine Art von Optimierung nur dann Sinn macht, wenn die Funktion relativ
klein ist.


#### `constexpr`-Funktionen {#constexprfunc}

Wie wir uns schon im Abschnitt \in[constants] über `constexpr` Ausdrücke
angesehen haben, kann eine Funktion in einem `constexpr` Ausdruck normalerweise
nicht verwendet werden. Um eine Funktion in einem solchen Ausdruck verwenden zu
können, muss diese ebenfalls mit `constexpr` markiert sein.

Schauen wir uns dazu die folgende Funktion `digitsum` an, die die Quersumme
einer dezimalen Zahl berechnet:

~~~{.cpp}
// constexprfunc.cpp
#include <iostream>

using namespace std;

constexpr unsigned int digitsum(unsigned int number) {
    return (number > 9) ?
        (number % 10) + digitsum(number / 10) : number;
}

int main() {
    constexpr unsigned int number{digitsum(12345)};
    cout << number << endl;
}
~~~

Die Ausgabe wird in diesem Fall `15` sein, da $1+2+3+4+5 = 15$ ist.

In diesem Fall wird die Funktion `digitsum` zur Übersetzungszeit durch den
Compiler ausgewertet und nicht zur Laufzeit! Zur Laufzeit wird in diesem
konkreten Fall lediglich eine Konstante ausgegeben, aber keine Berechnung
durchgeführt.

Der Compiler überprüft, ob innerhalb eines `constexpr`-Ausdruckes nur
`constexpr`-Konstanten und `constexpr`-Funktionen vorkommen. Du kannst dies
leicht überprüfen, indem du `constepxr` bei der Definition der Funktion
`digitsum` entfernst. Der Compiler wird eine Fehlermeldung liefern.

`constexpr`-Funktionen können auch außerhalb von `constexpr`-Ausdrücken
verwendet werden. Ändere dazu die Funktion `main` wie folgt ab:

~~~{.cpp}
int main() {
    unsigned int number{};
    cin >> number;
    cout << digitsum(number) << endl;
}
~~~

Damit wird die Funktion `digitsum` jetzt zur Laufzeit ausgeführt und nicht mehr
zur Übersetzungszeit.

Allerdings kann eine `constexpr` Funktion in \cppXI nur sehr einfach aufgebaut
sein! Sie muss aus einer einzelnen `return`-Anweisung bestehen und darf auch keine
Schleifen und keine lokalen Variablen beinhalten. Weiters darf so eine Funktion
keine Nebeneffekte bewirken. Das bedeutet, dass eine `constexpr`-Funktion auf keine
Variablen außerhalb schreibend zugreifen darf. Auch Veränderungen von
Referenz-Parametern sind nicht erlaubt.

So eine Funktion wird an sich als "pure function" bezeichnet. Also keine
Änderungen und für die gleichen Argumente wird immer das gleiche Ergebnis
zurückgeliefert.

<div class="c++14">
In \cppXIV wurden diese strengen Auflagen gelockert. Es sind jetzt auch
Schleifen und lokale Variablen erlaubt, wie du im nächsten Beispiel sehen
kannst, das die kleinste Zahl aus allen übergebenen Zahlen bestimmt.
</div>

~~~{.cpp}
#include <iostream>
#include <limits>

using namespace std;

constexpr int min(std::initializer_list<int> numbers) {
    int min = std::numeric_limits<int>::max();
    for (int n : numbers)
        if (n < min) min = n;
            return min;
}

int main() {
    constexpr int min_number = min({5, 1, 8, -3, 9});
    cout << min_number << endl;
}
~~~

Analog zu `constexpr`-Konstanten und `inline`-Funktionen, weisen auch
`constexpr`-Funktionen interne Bindung auf.


## Programm {#program}

Ein Programm ist eine Sammlung kompilierter Übersetzungseinheiten, die der Linker
zu einer ausführbaren Datei bindet. Jedes Programm muss genau eine Funktion
`main` enthalten, die eine der folgenden Formen aufweist:

- `int main() { /* ... */ }`
- `int main(int argc, char* argv[]) { /* ... */}`

Der Rückgabewert wird an das aufrufende Programm weitergegeben. Jeder Wert
ungleich Null wird in der Regel als Fehler interpretiert.

Ein Programm wird durch eine der folgenden Möglichkeiten beendet:

- Wenn die Funktion durch die Funktion `exit(int)` aus der Headerdatei
    `<cstdlib>` der Standardbibliothek aufgerufen wird. Damit wird das Programm
    an dieser Stelle beendet.

    Dies wird als normale Beendigung interpretiert und es wird
    eine ganze Zahl als Argument mitgegeben, die als Rückgabewert an das
    aufrufende Programm zurückgegeben wird.

    Bei Aufruf der Funktion `exit()` werden einige Aufräumarbeiten
    durchgeführt. Es werden die Destruktoren der `static`-Variablen und der
    thread-lokalen Variablen aufgerufen, jedoch nicht die der lokalen
    Variablen. Außerdem werden geöffnete Dateien geschlossen.

    Es besteht außerdem die Möglichkeit, dass man Funktionen mittels `atexit()`
    registrieren kann, die durch `exit()` zur Ausführung gebracht werden. Damit
    kann man abschließende Aktionen erzwingen.

    Schauen wir uns vorerst einmal das folgende Programm an:

    ~~~{.cpp}
    #include <iostream>
    #include <cstdlib>
     
    using namespace std;
     
    struct Variable {
        string name;
        ~Variable() {
            cout << name << " var destructed" << endl;
        }
    };
     
    int main() {
        Variable local_var{"local"};
        static Variable static_var{"static"};
    }
    ~~~

    Damit wird es zu folgender erwarteter Ausgabe kommen:

    ~~~{.sh}
    local var destructed
    static var destructed
    ~~~

    Rufen wir jetzt die Funktion `exit()` innerhalb von `main` auf:

    ~~~{.cpp}
    exit(EXIT_SUCCESS);
    ~~~

    Damit wird der Prozess mit einem implementierungsabhängigen Rückgabewert
    beendet, der auf der jeweiligen Plattform als Erfolg interpretiert wird.

    Dann werden wir feststellen, dass für die lokale Variable `local_var` nicht
    mehr der Destruktor aufgerufen wird!

    Als Nächstes können wir noch einen "exit handler" in Form einer Funktion
    `exit_handler` schreiben:

    ~~~{.cpp}
    void exit_handler() {
        cout << "exit handler..." << endl;
    }
    ~~~

    Diese Funktion muss noch registriert werden, sodass diese beim Beenden
    des Programmes aufgerufen wird. Füge deshalb den folgenden Code vor den
    Aufruf der Funktion `exit` ein:

    ~~~{.cpp}
    int result = atexit(exit_handler);
 
    if (result != 0) {
        cout << "exit_handler registration failed" << endl;
        return EXIT_FAILURE;
    }
    ~~~

    Damit wird die Funktion `exit_handler` als "exit-handler" registriert und
    beim Beenden des Programmes aufgerufen. Analog zu `EXIT_SUCCESS` gibt es
    auch ein `EXIT_FAILURE`, das in diesem konkreten Fall aufgerufen wird, wenn
    die Registrierung fehlschlägt.

    Will man, dass überhaupt keine Destruktoren aufgerufen werden, dann kann
    anstatt `exit` die Funktion `quick_exit(int)` verwendet werden. Analog zu
    `atexit()` steht in diesem Fall `at_quick_exit()` zur Verfügung.

- Wenn die Funktion `main` beendet mittels der
    `return`-Anweisung und Angabe eines Rückgabewertes oder durch
    Erreichen des Ende der Funktion erreicht wird. Wird das Ende der Funktion
    erreicht, dann wird der Rückgabewert 0 zurückgegeben.

    Diese Art der Beendigung ist äquivalent zu der normalen Beendigung einer
    Funktion und anschließendem Aufruf von `exit` mit dem angegebenen
    Rückgabewert.
    
- Wenn die Funktion `abort()` aufgerufen wird. Dies gilt als Abbruch und es
    werden keinerlei Destruktoren aufgerufen und keine mittels `atexit()` oder
    `at_quick_exit()` registrierten Funktionen aufgerufen.

    Ob geöffnete Dateien geschlossen werden, ist von der konkreten
    Implementierung abhängig.

    Das aufrufende Programm erhält einen implementierungsabhängigen
    Rückgabewert, der eine fehlerhafte Beendigung anzeigen soll.

- Wenn eine Exception aufgetreten ist, die nicht abgefangen wurde. Anders
    ausgedrückt heißt dies, dass kein Exception-Handler diese Exception
    behandelt hat. Was dies genau bedeutet werden wir uns noch im Abschnitt
    \in[exceptionfoundations] ansehen.

    Weiters wird das Programm beendet, wenn eine Exception innerhalb einer
    Funktion geworfen wird, obwohl die Funktion mit `noexcept` deklariert
    wurde (siehe Abschnitt \in[noexceptfunc]).
    

## Namensraum {#namespace}

Die zugrunde liegende Problematik ist, dass mit der Anzahl der Bezeichner die
Wahrscheinlichkeit steigt, dass sich Bezeichner überschneiden und man bei
vielen Dateien nicht leicht herausfinden kann, wo ein Bezeichner deklariert
ist.

In \cpp wird mit einem Namensraum (engl. *namespace*) ein Geltungsbereich
erzeugt, von dem von außerhalb mittels expliziter Qualifizierung auf die
Bezeichner des Namensraumes zugegriffen werden kann.

### Bereichsauflösungsoperator

Schauen wir uns einmal das folgende Beispiel an, das sich nicht übersetzen
lässt:

~~~{.cpp}
// scoperesolution.cpp
#include <iostream>

using namespace std;

double sum(double op1, double op2) {
    return op1 + op2;
}

int main() {
    double sum;
    sum = sum(1, 2);
    cout << sum << endl;
}
~~~

Der Fehler ist, dass die Definition der lokalen Variable `sum` die Definition
der globalen Funktion überschattet (siehe Abschnitt \in[scope]). Daher muss
man dem Compiler explizit mitteilen, dass man die globale Funktion
`sum` meint und nicht die lokale Variable mit dem gleichen Namen.

Das geht mit dem Bereichsauflösungsoperator (engl. *scope resolution
operator*) `::` in der folgenden Art und Weise:

~~~{.cpp}
sum = ::sum(1, 2);
~~~

Dieser Bereichsauflösungsoperator gibt in dieser Form an, dass auf den globalen
Namensraum zugegriffen werden soll.


### Definition eines Namensraums

Stellen wir uns jetzt einmal vor, dass wir mehrere verschiedene Bibliotheken
verwenden und jede Bibliothek uns eigene Headerdateien zur Verfügung stellt,
die von uns alle inkludiert werden. Damit ist die Wahrscheinlichkeit relativ
hoch, dass es zu Namenskollisionen im globalen Namensraum kommt!

Damit dies nicht passiert, könnte jede Bibliothek einen eigenen Namensraum
definieren, in dem alle dessen Bezeichner verpackt werden. Ein Namensraum
gruppiert also logisch zusammengehörige Bezeichner und es sind die Bezeichner
der einzelnen Bibliotheken voneinander unabhängig.

Mit der Definition des folgenden Namensraums ist die Funktion `sum` nicht
mehr im globalen Namensraum vorhanden. Ein Namensraum stellt deshalb einen
eigenen Scope dar. Die folgende Definition legt einen benannten Namensraum an,
der vorerst nur eine Funktion `sum` enthält:

~~~{.cpp}
// namespace.cpp
#include <iostream>

using namespace std;

namespace MathUtils {
    double sum(double op1, double op2) {
        return op1 + op2;
    }
}
~~~

Nur die folgende `main`-Funktion zu verwenden funktioniert jetzt nicht mehr, da
es jetzt keine globale Funktion `sum` mehr gibt:

~~~{.cpp}
int main() {
    double sum;
    sum = ::sum(1, 2);
    cout << sum << endl;
}
~~~

Auch `sum = sum(1, 2)` kann mit der gleichen Begründung natürlich nicht
verwendet werden.

Um auf die Funktion jetzt zuzugreifen, muss auf eine der im Abschnitt \in[using]
angeführten Möglichkeiten zurückgegriffen werden.

Zusätzlich besteht die Möglichkeit mittels des Bereichsauflösungsoperators
direkt auf die Funktion `sum` des Namensraumes `MathUtils` zuzugreifen:

~~~{.cpp}
cout << MathUtils::sum(1, 2) << endl;
~~~

Namensräume sind in \cpp offen. Im folgenden Beispiel sieht man dies sehr
schön, da mit den beiden `namespace`-Deklarationen sowohl die Funktion `sum`
als auch die Funktion `mul` im Namensraum `MathUtils` enthalten sind:

~~~{.cpp}
namespace MathUtils {
    double sum(double, double);
}

namespace MathUtils {
    double mul(double, double);
}
~~~

Natürlich können diese Namensraumteile auf verschiedene Dateien verteilt werden.

Außerdem können Namensräume verschachtelt werden. Dies macht Sinn, wenn ein
Namensraum sehr groß wird und sich in logisch zusammenhängende Teilnamensräume
teilen lässt.

~~~{.cpp}
// namespace_nested.cpp
#include <iostream>

using namespace std;

namespace MathUtils {
    namespace Arithmetic {
        double sum(double op1, double op2) {
            return op1 + op2;
        }
    }
}

int main() {
    cout << MathUtils::Arithmetic::sum(1, 2) << endl;
}
~~~

Es besteht natürlich auch eine gewisse Gefahr, dass verschiedene Bibliotheken
die gleichen Bezeichner für ihre Namensräume verwenden. Daher ist es sinnvoll,
diese Bezeichner relativ lange und aussagekräftig zu wählen. Damit einhergehend
ist die Verwendung mittels des Bereichsauflösungsoperators natürlich mühsam.

Nehmen wir einmal an, dass ein Namensraum `Com_Musterfirma_MathUtils` heißt. Da
hier offensichtlich der umgekehrte Domänenname als Anfang des Bezeichners dieses
Namensraumes gewählt wurde, ist es relativ unwahrscheinlich, dass eine andere
Bibliothek den selben Bezeichner verwendet hat. Der Nachteil ist, dass dieser
Bezeichner lange und unhandlich ist.

Es besteht in \cpp die Möglichkeit einen Namensraumalias zu definieren:

~~~{.cpp}
namespace MU = Com_Musterfirma_MathUtils;

cout << MU::Arithmetic::sum(1, 2) << endl;
~~~

### Argument-Dependent Lookup {#adl}

Nehmen wir an, dass eine Funktion `f` einen Parameter vom Typ `T`
erwartet. Dann ist es meist so, dass diese Funktion im selben
Namensraum definiert ist wie der Typ `T`. Aufgrund dieser Überlegung, wird in
\cpp eine Funktion `f`, wenn diese nicht im aktuellen Scope oder den
überliegenden Scopes gefunden wird, ebenfalls im Scope des Typs `T` gesucht.
Diese Regel wird als "Argument-Dependent Lookup" (ADL, dt. argumentabhängiges
nachschlagen) bezeichnet.

Schauen wir uns das anhand eines Beispiels an:

~~~{.cpp}
#include <iostream>
 
int main() {
  std::cout << "Hello World";
}
~~~

In diesem Beispiel haben wir keine `using namespace std;` Direktive
verwendet. Auf das Objekt `cout` aus dem Namensraum `std` wird mittels direkter
Qualifizierung zugegriffen. Aus dem Operator `<<` wird vom Compiler folgender
äquivalenter Code erzeugt:

~~~{.cpp}
operator<<(std::cout, "Hello World");
~~~

Eigentlich ist der Operator `<<`, den wir verwenden wollen, ebenfalls im
Namensraum `std` enthalten. Der Compiler kann allerdings nicht wissen, welchen
Operator wir verwenden wollen. Trotzdem funktioniert das Beispiel wie wir uns
das vorgestellt haben, da der Compiler sich das Argument `std::cout` ansieht
und auf Grund der Zugehörigkeit von `cout` zu `std` den Operatorfunktionsaufruf
ebenfalls im Namensraum `std` sucht und auch findet.

Die genauen Regeln für ADL sind etwas komplizierter. Im Standard wird von
*associated namespaces* gesprochen, die herangezogen werden, um nach der Funktion
zu suchen:

- Wenn der Parameter ein Mitglied einer Klasse ist, dann besteht der Namensraum
    aus der Klasse selbst und auch aus den Namensräumen in dem die Klasse enthalten
    ist.

- Wenn der Parameter ein Mitglied eines Namensraumes ist, dann werden die
    umschließenden Namensräume herangezogen.

- Wenn der Datentyp des Parameters ein eingebauter Datentyp ist, dann gibt es
    keinen Namensraum in dem zusätzlich gesucht wird.

ADL ist extrem praktisch, da es eine Menge an Tipparbeit erspart, aber es kann
auch teilweise zu unerwarteten Ergebnissen kommen.  Es ist wichtig zu wissen,
dass alle über ADL ermittelten Funktionen prinzipiell gleichwertig sind und
auf Grund des Überladens durchaus auch eine Funktion aus einem anderen
Namensraum gewählt wird, als man es unter Umständen erwartet:

~~~{.cpp}
// adl.cpp
#include <iostream>
#include <vector>

using namespace std;

namespace MathUtils {
    class IntVector {};
    int size(IntVector, int) {
        return 1;
    }
}

namespace GameEngine {
    MathUtils::IntVector v;

    int size(MathUtils::IntVector, unsigned) {
        return 2;
    }

    int calculate() {
        return size(v, 10);
    }
}

int main() {
    cout << GameEngine::calculate() << endl;
}
~~~

Bei der leeren Klasse `IntVector` handelt es sich um die
Definition eines benutzerdefinierten Datentyps. Wir werden uns
benutzerdefinierte Datentypen im Abschnitt \in[classdeclaration] noch ansehen.

Wahrscheinlich erwartet man sich, dass dieses Beispiel `2` ausgeben wird, nicht
wahr? In Wirklichkeit wird aber `1` ausgegeben werden!

Es ist zwar so, dass es eine Definition `int size(MathUtils::IntVector,
unsigned)` in diesem Namensraum gibt, jedoch wird diese in diesem speziellen
Fall nicht verwendet. Das liegt daran, dass diese nicht die einzige Definition
ist, die zur Auswahl herangezogen wird. Es exisitiert jedoch auch noch die
Definition `int size(MathUtils::IntVector, int)` im globalen Namensraum,
wodurch es zu einer Überladung kommt. Da der aktuelle Parameter den Typ
`int` hat, wird die Definition im globalen Namensraum verwendet.

Wäre die Variante mit dem `unsigned` Parameter die einzige Definition, dann
würde die ganze Zahl `10` vom Typ `int` auch implizit in einen `unsigned`
konvertiert werden und es würde diese Funktion des Namensraum `GameEngine`
ausgeführt werden.

Da es aber über die ADL noch eine Funktion `size` gibt, die verwendet werden
kann, sieht die Sache anders aus. Es gibt zwei Funktionen, die gleich heißen
und sich durch die Typen der Parameter unterscheiden. Also liegt eine Form der
Funktionsüberladung vor. Da die Funktion `size` im Namensraum `MathUtils` in
diesem Fall keine Konvertierung der Argumente erfordert, wird diese für den
Funktionsaufruf herangezogen.

### Unbenannte Namensräume

Es gibt noch eine weitere Form der Definition eines Namensraumes, indem der
Namensraum selbst keinen Namen erhält. Der Zweck von unbenannten Namensräumen
liegt darin, dass alle enthaltenen Bezeichner automatisch im globalen
Namensraum für diese Übersetzungseinheit sind. Allerdings stehen diese *nicht*
zum externen Linken zur Verfügung, da diese Bezeichner interne Bindung
aufweisen.

Man kann sich das so vorstellen, dass ein unbenannter Namensraum äquivalent zu
folgendem Konstrukt ist:

~~~{.cpp}
namespace unique_for_scope {
    /* ... */
}
using unique_for_scope;
~~~

Das Besondere daran ist, dass der Bezeichner vom Compiler eindeutig gewählt
wird und es daher keinen anderen gleichen Bezeichner gibt.

Das folgende Beispiel -- bei dem es sich um keinen guten Programmierstil
handelt -- demonstriert auf einfache Weise die Handhabung von unbenannten
Namensräumen.

~~~{.cpp}
// namespace_unnamed.cpp
#include <iostream>
#include <vector>

using namespace std;

namespace {
    int sum;
    void count(vector<int> v) {
        for (auto i : v)
            sum += i;
    }
}

int main() {
    count({1, 2, 3, 4, 5});
    cout << sum << endl;
}
~~~

## Headerdateien {#headercontents}

Aus den Überlegungen des Kapitels ergibt sich, dass nur gewisse Deklarationen in
Headerdateien sinnvoll sind und deshalb in Headerdateien vorkommen dürfen:

- Typaliase, also zum Beispiel:

    ~~~{.cpp}
    using IntStack = std::vector<int>;
    ~~~

- Funktionsdeklarationen, aber keine Funktionsdefinitionen:

    ~~~{.cpp}
    void push(IntStack, int);
    ~~~

- `inline`-Funktionsdefinitionen, wie zum Beispiel:

    ~~~{.cpp}
    inline
    double max(double a, double b) { return (a > b) ? a : b; }
    ~~~

- `constexpr`-Funktionsdefinitionen:

    ~~~{.cpp}
    constexpr double squared(double x) { return x * x; }
    ~~~

- Definitionen von Konstanten, also mit `const` oder mit `constexpr`:

    ~~~{.cpp}
    const double pi{atan(1) * 4};
    constexpr double area2{squared(2) * pi};
    ~~~

- Variablendeklarationen, die keine Definitionen sind, wie zum Beispiel:

    ~~~{.cpp}
    extern int errno;
    ~~~

- Namensräume entweder in einer benannten Form oder in einer inline-Variante,
    jedoch nicht als unbenannte Namensräume! Hier folgt ein benannter Namensraum:

    ~~~{.cpp}
    namespace math {
    }
    ~~~

- Deklarationen und Definitionen von Klassen, Strukturen und Aufzählungen
    (siehe Abschnitt \in[classdeclaration])

- Template-Deklarationen und Template-Definitionen (siehe Abschnitt
    \in[templatefoundations])

Gewisse syntaktische Elemente sollten *niemals* in einer Headerdatei vorkommen:

- Gewöhnliche Funktionsdefinitionen, also solche, die weder `inline`
    noch `constexpr` und auch keine Templatefunktion sind, da es sonst
    mehrfache Definitionen dieser Funktion geben würde. Das würde zu
    Fehlern beim Linken führen.

- Variablendefinitionen dürfen ebenfalls nicht enthalten sein, da es sonst zu
    mehrfachen Vorkommen von Variablen und damit wieder
    zu Fehlern beim Linken kommen würde.

- Unbenannte Namensräume, da diese zwar die Bezeichner im globalen Namensraum
    der aktuellen Übersetzungseinheit einpflanzen, aber diese interne Bindung
    aufweisen. Es ist der Sinn und Zweck von unbenannten Namensräumen den
    Zugriff zu beschränken und haben sie in Headerdateien nichts verloren.

- `using` Direktiven, wie zum Beispiel `using namespace std;`, da diese die
    Gefahr von Namenskollisionen stark erhöhen und zu unübersichtlichen
    Programmen führen, da man nur schwer eruieren kann, woher ein Bezeichner
    kommt.
