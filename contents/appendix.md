
# Anhang

## Entwicklungswerkzeuge {#devtools}

Um mit \cpp entwickeln zu können, werden Entwicklungswerkzeuge wie Compiler,
Linker und Debugger benötigt. Diese sind naturgemäß je Betriebssystem
unterschiedlich. Prinzipiell steht die Gnu Compiler Collection sowohl für
Windows als auch für Mac OSX und Linux zur Verfügung. Trotzdem macht es
durchaus Sinn, eine auf die jeweilige Betriebssystemplattform abgestimmte
Variante zu wählen:

- Unter *Windows* wird meist der Compiler Microsoft Visual \cpp
    verwendet, der in der Entwicklungsumgebung Microsoft Visual Studio
	enthalten ist. Es wird von Microsoft auch in einer kostenlosen Version
	angeboten.

- Unter *Mac OSX* muss die Entwicklungsumgebung XCode von der Entwicklersite
    von Apple besorgt und installiert werden. Bei der Installation ist zu
    beachten, dass die *command line tools* zu installieren sind.
	Die aktuelle Version enthält den \cpp Compiler Clang. 

- Unter Linux sind die Entwicklungswerkzeuge ebenfalls getrennt zu
	installieren. Hier wird meist der \cpp Compiler `g++` der Gnu
	Compiler Collection verwendet.
	
    Für Ubuntu sieht der Befehl zur Installation folgendermaßen aus:

    ~~~{.sh}
    sudo apt-get install build-essential libgl1-mesa-dev
    ~~~

	Verwendest du eine andere oder nicht kompatible Distribution, dann wende
	dich bitte and die entsprechende Dokumentation.

    Willst du unter Linux mit \cppXIV programmieren, dann benötigst du `g++`
    mindestens in der Version 4.9, falls diese in deiner Distribution angeboten
    wird oder du installierst den \cpp Compiler Clang. Das kann in Ubuntu
    folgendermaßen realisiert werden:

    ~~~{.sh}
    sudo apt-get install clang-3.4 libc++-dev binutils
    ~~~

## Übersetzung eines \cpp Programmes {#compilation}

Hier geht es nur darum, die Installation zu testen und zu zeigen, wie
ein \cpp Programm kompiliert wird. Natürlich kann zum Schreiben als
auch zum Übersetzen und zum Ausführen eine Entwicklungsumgebung verwendet
werden, aber werden wir hier eine Shell benützen.

<div class="drawer">
Eine Shell (zu Deutsch: Schale) ist ein Programm, das wie eine Schale
sich um das Betriebssystem legt und dem Benutzer eine Schnittstelle bietet,
um mit dem Betriebssystem per Kommandos zu kommunizieren.

Diese Kommandos werden mittels textbasierter Befehle eingegeben und die
Antworten des Betriebssystem werden als Text wieder angezeigt.

Solch eine Shell wird oft auch als Kommandozeileninterpreter bezeichnet,
weil es eben ein Programm ist, der Kommandos zeilenweise interpretiert,
ausführt und die Ergebnisse zeilenweise anzeigt.

Je Betriebssystem gibt es verschiedene derartige Programme.
</div>

Erstelle das klassische "Hello World" Programm mit einem Texteditor deiner
Wahl. Im Abschnitt \in[helloworld] auf der Seite \at[helloworld] wird der
gesamte Quellcode detailliert erklärt:

~~~{.cpp}
#include <iostream>

int main() {
    std::cout << "Hello, world!" << std::endl;
}
~~~

Speichere diesen Quelltext in eine Datei `hello.cpp`.

Da es sich bei \cpp um eine "compiled language" handelt, muss der Sourcecode
zuerst noch in eine ausführbare Datei übersetzt werden, bevor das Programm
verwendet werden kann.

Jetzt geht es darum diese Quelldatei in eine ausführbare Datei zu
übersetzen und mit den notwendigen Bibliotheken zu linken.


### Windows

Öffne eine Shell! Unter Windows kannst du `cmd` oder die PowerShell verwenden.

Wird Visual Studio verwendet, dann sollte der Befehl

~~~{.sh}
cl /clr hello.cpp
~~~

in der Shell eingegeben werden können. Damit wird eine ausführbare Datei mit
dem Namen `hello.exe` erzeugt, die einfach durch Eingabe von `hello`
gestartet werden kann.

Um Warnungen zu sehen, empfehle ich die Option `/Wall` mitzugeben.

Will man eine einzelne Datei lediglich in seine Objektdatei übersetzen, dann
ist die Option `/c` (für "compile") zu verwenden. Die entstehende Datei heißt
`hello.obj` (für Objektdatei).

Unter Umständen müssen mehrere Dateien angegeben werden, dann sind diese
einfach in der Kommandozeile hintereinander anzugeben.

### Mac OSX

Öffne eine Shell! Verwende unter Mac OSX die Applikation `Terminal`, in
das die eigentliche Shell läuft.

Aktuelle XCode Versionen verwenden den \cpp Compiler clang. Gib den folgenden
Befehl in der Shell ein:

~~~{.sh}
clang++ -stdlib=libc++ -std=c++11 -lc++abi -o hello hello.cpp
~~~

Die Option `-o` (engl. *output*) bewirkt, dass das lauffähige Programm mit dem
Namen `hello` erstellt wird. `-std=c++11` gibt an, dass die Sprachversion
\cppXI verwendet werden soll. Die restlichen Parameter geben die zu
verwendete Bibliothek an.

Anstatt `-std=c++11` kann auch `-std=c++1y` verwendet werden, wenn eine
aktuelle Version von `clang` installiert ist. Dies ermöglicht dann auch
Features von \cppXIV zu verwenden.

Auch `clang` kennt die Option `-Wall`, um Warnungen anzuzeigen.

Für die weiteren Beispiele gehe ich davon aus, dass die Umgebungsvariable
`PATH` so gesetzt ist, dass das aktuelle Verzeichnis enthalten ist. D.h.,
dass der Punkt `.` enthalten ist.

Jetzt kann durch Eingabe von `hello` einfach das Programm gestartet werden.

Will man eine einzelne Datei lediglich in seine Objektdatei übersetzen, dann
ist die Option `-c` (für "compile") anzuhängen und die Option `-o hello` nicht
anzugeben. Die entstehende Datei heißt `hello.o` (für Objektdatei).

Unter Umständen müssen mehrere Dateien angegeben werden, dann sind diese
einfach in der Kommandozeile hintereinander anzugeben.


### Linux

Öffne eine Shell! Unter Linux kannst du eines der vielen verschiedenen
Terminalprogramme verwenden. Unter Linux läuft innerhalb des Terminalprogrammes
die eigentliche Shell.

Für die weiteren Beispiele gehe ich davon aus, dass die Umgebungsvariable
`PATH` so gesetzt ist, dass das aktuelle Verzeichnis enthalten ist. D.h.,
dass der Punkt `.` enthalten ist.

Unter Linux sieht der Befehl folgendermaßen aus:

~~~{.sh}
g++ hello.cpp -std=c++11 -o hello
~~~

Die Option `-o` (engl. *output*) bewirkt, dass das lauffähige Programm mit dem
Namen `hello` erstellt wird. `-std=c++11` gibt an, dass die Sprachversion
\cppXI verwendet werden soll.

Anstatt `-std=c++11` kann auch `-std=c++14` oder `-std=c++1y` verwendet werden,
wenn eine aktuelle Version von `g++` installiert ist. Dies ermöglicht dann auch
Features von \cppXIV zu verwenden.

Will man sich Warnungen anzeigen lassen, dann empfehle ich die Optionen
`-Wconversion` und `-Wall` anzugeben. `g++` hat sehr viele Optionen und diese
sollten je Bedarf ausgesucht werden.

Für die weiteren Beispiele gehe ich davon aus, dass die Umgebungsvariable
`PATH` so gesetzt ist, dass das aktuelle Verzeichnis enthalten ist. D.h.,
dass der Punkt `.` enthalten ist.

Jetzt kann durch Eingabe von `hello` einfach das Programm gestartet werden.

Will man eine einzelne Datei lediglich in seine Objektdatei übersetzen, dann
ist die Option `-c` (für "compile") anzuhängen und die Option `-o hello` nicht
anzugeben. Die entstehende Datei heißt `hello.o` (für Objektdatei).

Unter Umständen müssen mehrere Dateien angegeben werden, dann sind diese
einfach in der Kommandozeile hintereinander anzugeben.


## Zugreifen auf den Exit-Code eines Programmes {#access_exit_code}

Will man auf den Exit-Code eines Programmes zugreifen und weiß nicht wie dann
hilft dieser Abschnitt weiter.

Schreibe zuerst den folgenden Code in eine Datei `minimal.cpp` und übersetze dieses
Programm in eine ausführbare Datei `minimal`:

~~~{.cpp}
int main() {
    return 0;
}
~~~

Im folgenden wird erklärt wie auf den Rückgabewert je verwendetem
Betriebssystem zugegriffen werden kann.

### Windows

Unter Windows gibt es je nach verwendeter Shell verschiedene
Möglichkeiten. Wird eine `cmd` Shell verwendet, dann kommt man mit folgendem
Befehl ans Ziel:

~~~{.sh}
minimum
echo %ERRORLEVEL%
0
~~~

Danach wird in unserem konkreten Fall der Wert `0` angezeigt.

Wird die PowerShell verwendet, dann sieht der korrekte Befehl folgendermaßen
aus:

~~~{.sh}
minimum
echo $LastExitCode
0
~~~

### Mac OSX und Linux

Sowohl für Mac OSX als auch für Linux gibt es eine Vielzahl von verschiedenen
Shells. Normalerweise kommt eine Shell zum Einsatz, die `bash` heißt. Viele
Shells sind bezüglich der Ermittlung des Rückgabewertes kompatibel zu dieser
Shell.

Unter Mac OSX und Linux kann man meist auf der Kommandozeile folgendermaßen
auf diesen Rückgabewert zugreifen:

~~~{.sh}
minimum
echo $?
0
~~~

Auch hier wird mit unserem Beispiel natürlich wieder `0` angezeigt werden.

Verwendest du die sehr gute Shell `fish`, dann sieht der Befehl folgendermaßen
aus:

~~~{.sh}
minimum
echo $status
0
~~~

Solltest du eine andere Shell verwenden, die sich diesbezüglich wiederum anders
verhält, dann bist du wahrscheinlich ein Spezialist und benötigst
wahrscheinlich keine weitere Hilfe.

## Literaturhinweise

Hier möchte ich sinnvolle Ergänzungen für das weitere Studium in \cpp anführen.

Die folgendenden Bücher gelten als "Standard":

- Die "Bibel" ist sicher das Buch des Erfinders Bjarne Stroustrup von \cpp{}
    [see @stroustrup2013].
- Als das Standardwerk zur Standardbibliothek gilt das Buch [see @josuttis2012]
    von Nicolai Josuttis.
- Als Online-Quelle hauptsächlich zur Standardbibliothek empfehle ich
    [see @cppreference].

Bist du mehr an einer Einführung interessiert, dann sind die folgenden Werke
unter Umständen für dich interessant:

- Ist man mehr an einer eher deutschsprachigen, umfassenden Einführung
    interessiert, die sich auch an Nicht-Programmierer richtet, dann ist
    [see @wolf2014] zu empfehlen.
- Ein ebenfalls gutes deutschsprachiges und ebenfalls umfangreiches Buch, das
    viele praktische Algorithmen enthält ist [see @breymann2011].
- Will man eher ein englischsprachige, gute Einführung, dann ist
    [see @deitel2014] zu empfehlen.

Hast du schon Erfahrungen mit \cpp und möchtest speziell die neuen Features von
\cppXI kennenlernen oder möchtest diese kompakt in einem Buch nachlesen können,

- dann empfehle ich das Buch [see @will2012]!

Zu guter letzt kann ich noch zwei ausgezeichnete Bücher empfehlen, die jedoch
eindeutig schon in die Kategorie weiterführende Literatur einzuordnen sind:

- Interessiert man sich für parallele Anwendungen, dann empfehle ich
    [see @williams2012].
- Ist man eher daran interessiert, wie man gute, wiederverwendbare Programme
    entwickelt, dann ist [see @reddy2011] sehr zu empfehlen.
