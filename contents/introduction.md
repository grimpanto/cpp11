
# Einführung in \cpp\ {#introduction}

## Charakterisierung von \cpp

Bei \cpp handelt es sich um eine objektorientierte Programmiersprache, die
eine der weltweit am häufigsten eingesetzten Programmiersprachen ist.

Die Entwicklung der Programmiersprache \cpp wurde von Bjarne Stroustrup 1979
als eine objektorientierte Erweiterung zur Programmiersprache C unter dem Namen
"C with Classes" begonnen. 1984 erfolgte die Umbenennung in \cpp und der erste
kommerzielle Compiler erschien 1985. Seitdem entwickelt sich \cpp permanent
weiter und es folgten im Jahr 1989 und 2003 die Versionen `C++98` und `C++03`. Diese
Entwicklung hatte im Jahr 2011 mit \cppXI einen vorläufigen Höhepunkt mit
vielen substanziellen Neuerungen. \cppXI legte den Grundstein für die moderne
Entwicklung mit \cpp!

2014 wurde eine Zwischenversion mit Berichtigungen und kleinen Erweiterungen
herausgebracht, die als \cppXIV bekannt ist. Man sieht, dass \cpp sowohl eine
lange Vergangenheit hat und es permanent weiter entwickelt wird: 2017
soll die nächste große Version von \cpp erscheinen.

In diesem Sinne spreche ich in diesem Buch von "\cpp" wenn ich eine beliebige
Version von \cpp meine, von "\cppXI" wenn ich mich auf \cppXI oder \cppXIV
beziehe und von "\cppXIV" wenn ich speziell \cppXIV anspreche.

Der Erfinder von \cpp, Bjarne Stroustrup, beschreibt \cpp als eine allgemein
verwendbare Programmiersprache zum Entwickeln und Verwenden von eleganten und
effizienten Abstraktionen.

Bjarne Stroustrup hat zwei grundlegende Entwurfsprinzipien für \cpp
festgelegt: Einerseits soll es möglich sein, mit \cpp nahe der Hardware zu
programmieren und andererseits sollen \cpp Programme hoch performant sein.

Aus diesen beiden Vorgaben ergibt sich, dass \cpp eine überragende
Bedeutung im Bereich der Systemprogrammierung hat. Mit \cpp werden
Treiberprogramme, ganze Betriebssysteme, Compiler, Software für
eingebettete Systeme (engl. embedded systems) wie Software
in Autos, Industrieanlagen, Handys,... entwickelt.

\cpp wird nicht nur zur Systemprogrammierung, sondern auch großteils zur
Anwendungsprogrammierung verwendet. Die Arten dieser Anwendungen sind sehr
vielfältig. Es werden Systeme für die Finanzmärkte, Simulationen,
Büroanwendungen, Grafikprogramme, Spiele,... entwickelt. Große Bedeutung hat
\cpp auch im Grafikbereich, in der Verarbeitung von Multimediadaten wie
Bildern, Video und Audioinformationen, bei der Visualisierung, in der
Meteorologie, Physik, Genetik,...

Auch die Größe der Computer ist unterschiedlich auf denen diese
Programmiersprache zum Einsatz kommt. Abgesehen von den eingebetteten Systemen,
findet sich \cpp im Einsatz auf Personal Computern, in Serverlösungen bis hin zu
Supercomputer.

Große Firmen wie Adobe Systems Inc.\ (z.B.\ Photoshop),
Apple Inc. (z.B. Teile von Mac OSX), Google Inc. (z.B.\ Google Chrome),
Microsoft Corporation (z.B.\ Teile von Microsoft Windows),
Mozilla Corporation (z.B.\ Firefox), Oracle Corporation (z.B.\ MySQL) und
viele mehr setzen \cpp in ihren Produkten ein. Bei den hier genannten Firmen
handelt es sich um eine subjektive Auswahl ausgewählt nach bestem Wissen und
Gewissen.

\cpp wird allerdings von keiner Firma kontrolliert, sondern von einem
internationalen Komitee entwickelt. Die einzelnen Versionen von \cpp
werden als Standard bei der ISO (International Organization for
Standardization) herausgebracht und haben normativen Charakter.

Mit der Version von \cpp aus dem Jahre 2011, also \cppXI, ist ein weiterer
wichtiger Aspekt hinzugekommen: \cpp soll leicht erlernbar sein. Um mit *allen*
Aspekten von \cpp vertraut zu sein, benötigt man viele Jahre intensives
Auseinandersetzen und Übung. Um produktiv Programme in \cppXI zu entwickeln,
benötigt man nur *wenige Monate*.

Und genau das ist das Ziel dieses Buches: \cpp in dem Maße zu erlernen,
dass es möglichst schnell erlernt und produktiv verwendet werden kann!

## Merkmale von \cpp

### Typisierung {-}

Je nach Art wie Variablen einem Typ zugeordnet wird, unterscheidet man
verschiedene Arten der Typisierung. \cpp wird als *statisch* und *streng* getypte
Programmiersprache kategorisiert.

Statische Typisierung bedeutet, dass der Typ einer Variable schon bei
Kompilierung feststeht. Kompilieren bedeutet, dass der Quelltext in eine
ausführbare Datei übersetzt wird. Bei dynamisch getypten Programmiersprachen
ist solch eine Kompilierung in der Regel nicht notwendig, da der Typ einer
Variable erst zur Laufzeit feststeht.

Strenge Typisierung bedeutet hingegen, dass Operationen nur auf kompatiblen
Typen durchgeführt werden und Typkonversionen nur beschränkt implizit
durchgeführt werden. Das Gegenstück ist die schwache Typisierung, die
Operationen weitgehend zwischen beliebigen Typen ermöglicht.

Es gibt keine exakte Definition von strenger oder schwacher Typisierung.

### Unterstützte Programmierparadigmen {-}

\cpp ist eine Programmiersprache, die mehrere Programmierparadigmen
unterstützt:

Imperative und prozedurale Programmierung
  : Da du ja schon Programmierer in einer objektorientierten Programmiersprache
    bist, bist du prinzipiell auch in der Lage imperativ (basierend auf
    Befehlen und Anweisungen) und prozedural (strukturiert mittels Prozeduren
    und Funktionen) zu programmieren.

	<!--
    Die entsprechenden sprachlichen Mittel dazu werden in den Kapiteln XXX bis
    XXX besprochen.
	-->

Generische Programmierung
  : Mittels der generischen Programmierung versucht man Algorithmen
    möglichst allgemein zu definieren, sodass diese später mittels
    verschiedensten Datentypen verwendet werden können. Der Vorteil, der
    gegenüber einer überhandnehmenden Objektorientierung gesehen wird, ist,
    dass es in vielen Fällen eine einfachere und performantere Implementierung
    in statisch getypten Programmiersprachen bietet.

    \cpp bietet hierfür mittels der Templates einen ausgefeilten Mechanismus
    an, der generische Programmierung ermöglicht.

	<!--
    Das Kapitel XXX liefert
    hierfür die nötigen Grundlagen.
	-->

Objektorientierte Programmierung
  : Die objekt-orientierte Programmierung ist eines der wichtigsten
    Paradigmen und bietet richtig angewandt enorme Vorteile bei der
    Abbildung des Problemraumes in ein adäquates Modell.

	In \cpp nimmt die objektorientierte Programmierung
    nicht mehr einen so großen Stellenwert ein wie früher. Das liegt daran,
    dass die generische Programmierung einen großen Anteil übernommen hat.

	<!--
    In den Kapiteln XXX werden die Möglichkeiten von \cpp zur
    objektorientierten Programmierung detailiert vorgestellt.
	-->

Funktionale Programmierung
  : In der funktionalen Programmierung bestehen Programme ausschließlich
    aus Funktionen, deren Verarbeitung wie die Berechnung mathematischer
    Funktionen gehandhabt wird. Diese Funktionen haben keinen Zustand
    und auch keine Nebeneffekte. Das kann Vorteile bringen und kann unter
    \cpp auch in gewissen Maßen umgesetzt und genutzt werden.

    Auch wenn \cpp keine rein funktionale Sprache ist, bietet es doch
    mittels den Sprachkonstrukten Funktionen, Funktionsobjekten,
    Lambda-Ausdrücken und der Standardbibliothek (`std::function`,
    `std::bind`, Higher-order Funktionen in den Algorithmen, `std::async`)
    Möglichkeiten, um funktional zu programmieren.

    <!-- Im Kapitel XXX werden teilweise diese technischen Hilfsmittel vorgestellt. -->

Im weiteren Verlauf dieses Buches werden wir diese verschiedenen Seiten von
\cpp noch kennenlernen.

## Benötigte Software

In diesem Abschnitt werde ich die *prinzipiellen* Möglichkeiten beschreiben,
mit der \cpp Programme erstellt werden können.

Es gibt mehrere Möglichkeiten, wie du deine Werkzeuge auswählen kannst.

### Entwicklungswerkzeuge {-}

Je nach Betriebssystem gibt es für die Entwicklungswerkzeuge wie Compiler,
Linker und Debugger verschiedene Möglichkeiten, die im Abschnitt \in[devtools]
auf der Seite \at[devtools] prinzipiell besprochen werden. Es liegt an dir eine
der Varianten zu wählen.

### Entwicklungsumgebung {-}

Zum Erstellen und Verwalten des \cpp Sourcecodes wird entweder eine
integrierte Entwicklungsumgebung (IDE, engl. integrated develeopment
environment) oder ein vernünftiger Editor benötigt.

Auch hier gibt es je nach verwendetem Betriebssystem mehrere Wahlmöglichkeiten.
Es gibt allerdings auch die ausgezeichnete Entwicklungsumgebung QtCreator, die
plattformübergreifend zur Verfügung steht.

### Framework {-}

Um Programme mit grafischer Oberfläche, mit Netzwerkfunktionalitäten
oder mit Datenbankzugriffen zu entwickeln, wird noch ein Framework
benötigt.

Bezüglich des verwendeten Frameworks ist die Zielplattform von entscheidender
Bedeutung. Will man seine Programme exakt für Windows auf den Markt bringen,
dann wählt man sinnvollerweise die entsprechende Möglichkeit von Microsoft.
Ähnlich sieht die Situation für die Plattform Mac OSX und Linux aus.

Ist es allerdings das Ziel seine Programme sowohl unter Windows als auch unter
Mac OSX und Linux zur Verfügung stellen zu wollen, dann bietet sich das
plattformübergreifende Framework Qt an. Dieses Framework bietet die folgenden
Vorteile:

- Da es plattformübergreifend ist, steht es für die Betriebssysteme Windows,
    Mac OSX und Linux zur Verfügung. Außerdem kann man damit auch Programme
    für die Betriebssysteme Android und iOS entwickeln!
- Es bietet uns die Möglichkeit portablen Code für grafische Oberflächen,
    Netzwerkfunktionen und Datenbankzugriffen produktiv zu entwickeln.
- Mit Qt wird außerdem die Entwicklungsumgebung QtCreator mitgeliefert, die für
    die Entwicklung von \cpp Programmen ausgezeichnet geeignet ist.
- Für die Entwicklung von privaten Programmen oder von Open Source Programmen
    ist die Verwendung von Qt kostenlos.

Bei diesen überwältigenden Vorteilen stellt sich natürlich auch die Frage
nach etwaigen Nachteilen:

- Unter Umständen ist dieses Framework nicht für *jeden* Anwendungsfall und
    für *jeden* Entwickler die optimale Lösung.
- Für die Entwicklung von kommerzieller Software muss eine Lizenz gekauft
    werden, wogegen die Entwicklung von privaten Programmen und Open Source
    Programmen kostenlos möglich ist.

    <div class="annotation">
    Eigentlich ist es so, dass sogar die Entwicklung von proprietärer Software
    unter Einhaltung der LGPL (Lesser General Public License) möglich ist.
    Dies kann dadurch erreicht werden, dass das infrage kommende Programm
    dynamisch gegen die Qt Bibliotheken gelinkt wird.
    </div>

Das SDK (software development kit) von Qt kann von <http://qt-project.org>
heruntergeladen und installiert werden.

Da du ein Programmierer bist, wird in weiteren davon ausgegangen, dass
du dir deine Entwicklungsumgebung selbständig aussuchst und installierst.


## Ausführbares \cpp{}

\cpp ist eine Programmiersprache bei der Quelltext zuerst in die
Maschinensprache der jeweiligen Zielplattform übersetzt werden muss.  Das wird
mittels eines Übersetzungsvorganges (auch Kompilierung genannt) von einem
Compiler (eingedeutscht von engl. *compiler*) durchgeführt, der den Quelltext
(engl.\ *source code*) in eine ausführbare Form (engl. *executable*) übersetzt.

Besteht das Programm aus mehreren Programmdateien, die getrennt übersetzt
worden sind, dann müssen diese noch miteinander verbunden werden. Dieses Binden
wird durch einen Linker (eingedeutscht von engl. *linker* oder *link editor*)
durchgeführt. In der Regel muss man sich darum nicht kümmern, da dies durch das
Compiler-Frontend, also das Compiler-Programm selbsttätig vorgenommen wird.

Die gängigen Implementierungen von \cpp erwarten sich, dass der Quelltext in
Dateien abgespeichert ist. Als Dateierweiterung (engl. *filename extension*)
\index{Dateierweiterung}\index{Dateierweiterung+\cpp Datei} wird in \cpp meist
`.cpp` verwendet, aber auch `.C`, `.cc`, `.cxx` oder `.c++` kommen zum Einsatz.
Wir verwenden `.cpp`.

Weiters gibt es sogenannte Headerdateien (wird später noch erklärt), deren
Dateierweiterung meist `.h` besitzt, aber auch `.H` oder `.hpp` kommen zeitweise
zum Einsatz. Wir verwenden `.h`.

Im Abschnitt \in[compilation] auf Seite \at[compilation] findest du
eine Kurzanleitung wie aus einem \cpp Quelltext mittels einer Shell
eine ausführbare Datei erstellt werden kann.

Danach kann das ausführbare Programm gestartet werden, es entsteht ein Prozess,
der sich irgendwann einmal beenden wird. Beim Beenden gibt der Prozess einen
Exitcode an den Prozess zurück, der ihn gestartet hat. Mittels dieses Exitcodes
kann der beendete Prozess eine Information an den aufrufenden Prozess zurückgeben.

Im Anhang \in[access_exit_code] auf der Seite \at[access_exit_code] befindet
sich eine Kurzanleitung wie du je, verwendetem Betriebssystem, auf diesen
Exitcode mittels der Shell zugreifen kannst.
