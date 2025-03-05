
# Einführung in die Standardbibliothek {#stl1}

## Überblick

Die Standardbibliothek von \cpp ist sehr umfangreich! In diesem Abschnitt
werden wir einen Überblick bekommen und die wesentlichen Prinzipien verstehen
werden.

Grob kann man die Standardbibliothek in verschiedene Kategorien
gliedern. Hier folgen die Kategorien gruppiert im Überblick:

### Sprachunterstützung,

In diese Kategorie fallen Header, die direkt als Ergänzung der
Programmiersprache \cpp zuzuordnen sind. Wichtige Headerdateien sind:
  
- `<limits>`: Diese Headerdatei haben wir schon kennengelernt, da diese uns
    wichtige Informationen über die Implementierung der arithmetischen
    Datentypen liefert.

- `<cstdint>`: Auch diese Headerdatei kennen wir bereits. Diese stellt
  weitere Typen für ganze Zahlen mit definierter Größe zur Verfügung.

- `<typeinfo>`: In `<typeinfo>` ist eine gewisse Unterstützung enthalten,
  um zur Laufzeit Information über die Typen von Speicherobjekten zu
  ermitteln.

- `<exception>`: Hier sind Funktionen und Typen enthalten, die für das
  Excpetion-Handling nützlich und notwendig sind.

- `<initializer_list>`: Diese Headerdatei kennen wir ebenfalls schon: Sie
  stellt den Typ `initializer_list` zur Verfügung.

### Utility

Diese Kategorie enthält sinnvolle Funktionen, die oft benötigt werden und
allgemeiner Natur sind. Hier gibt es die folgenden wichtigen Headerdateien:

- `<utility>`
- `<tuple>`
- `<bitset>`
- `<memory>`
- `<functional>`
- `<ration>`
- `<chrono>` und `<ctime>`

#### Tupel {#tuple}

pair vs. tuple

~~~{.cpp}
auto point3d = std::make_tuple(5, 6, 7);
std::cout << std::get<0>(point3d);
~~~

~~~{.cpp}
std::tie(x, y, z) = point3d;
~~~

### Mehrsprachigkeit

xxx

### Strings

xxx

### Ein- und Ausgabe

xxx

### Container, Algorithmen, Iterator

xxx

~~~{.cpp}
auto res = std::vector<int>{};
std::copy_if(lst.begin(),
             lst.end(),
             std::back_inserter(res),
             [](int x){ return x >= 0; });
~~~

### Numerik

xxx

### Reguläre Ausdrücke

xxx

### Unterstützung für Thread-basierte, nebenläufige Anwendungen

xxx


## Sortieren

Schauen wir uns folgendes Beispiel an, das es erlaubt beliebige Sequenzen zu
sortieren, ohne `begin` und `end` verwenden zu müssen:

~~~{.cpp}
// sorting.cpp
#include <iostream>
#include <algorithm>

namespace Estd {
    using namespace std;

    template <typename T>
    void sort(T& seq) {
        std::sort(begin(seq), end(seq));
    }
}

using namespace Estd;

int main() {
    int nums[]{3, 5, 2, 1, 4};

    sort(nums);

    for (auto n : nums) {
        cout << n << ' ';
    }
    cout << endl;
}
~~~

## vector

Die schon bekannte Möglichkeit ist, eine Instanz von `vector` zu verwenden, wie
wir diese schon kennengelernt haben. Ein `vector` unterscheidet sich von einem
rohen Array dadurch, dass es in der Größe veränderbar ist.

Wir wollen wir uns jetzt die Funktionsweise und wichtige Funktionen der Klasse
genauer ansehen. Ein `vector` hat eine aktuelle Größe und eine
Kapazität, die die Größe des reservierten Speicherbereiches angibt:

~~~{.cpp}
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v{1, 2};
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;
}
~~~

Die Ausgabe könnte folgendermaßen aussehen:

~~~{.sh}
size: 2
capacity: 2
~~~

Da zwei Elemente, nämlich die Zahlen 1 und 2, im Vektor enthalten sind, ist die
aktuelle Größe 2. Weiters ist die Kapazität ebenfalls 2.

Hängen wir in weiterer Folge diese Codezeilen an:

~~~{.cpp}
v.push_back(3);

cout << "push_back(3)" << endl;
cout << "size: " << v.size() << endl;
cout << "capacity: " << v.capacity() << endl;
~~~

Die Ausgabe sieht bei mir jetzt folgendermaßen aus:

~~~{.sh}
size: 2
capacity: 2
push_back(3)
size: 3
capacity: 4
~~~

Damit sind im Moment die Zahlen 1, 2 und 3 im Vektor enthalten und hiermit
beträgt die aktuelle Gräße ebenfalls 3. Nach der Initialisierung mit den beiden
Werten 1 und 2 hat der Vektor `v` nur einen Speicherbereich vom Betriebssystem
angefordert, der in der Lage war 2 Elemente aufzunehmen. Dann haben wir ein
weiteres Element hinten angehängt und hiermit hat der Vektor einen neuen
Speicherbereich anfordern müssen. Offensichtlich hat der Vektor den
Speicherbereich doppelt so groß angefordert.

Testen wir weiter durch Anfügen der folgenden Codezeilen:

~~~{.cpp}
v.push_back(4);
v.push_back(5);
cout << "push_back(4)" << endl;
cout << "push_back(4)" << endl;
cout << "size: " << v.size() << endl;
cout << "capacity: " << v.capacity() << endl;
~~~

Die zusätzliche Ausgabe sieht bei mir folgendermaßen aus:

~~~{.sh}
push_back(4)
push_back(4)
size: 5
capacity: 8
~~~

Hier sehen wir sehr deutlich, dass der Vektor in diesem Schritt wieder einen
doppelt so großen Speicherbereich angefordert hat. Prinzipiell hängt die
Vorgehensweise von der Implementierung der Standardbibliothek durch den
Hersteller zusammen, aber diese Art ist sehr sinnvoll. Wird ein neues Element
zum Vektor hinzugefügt, das in den bestehenden Speicherbereich nicht abgelegt
werden kann, dann muss der Vektor einen neuen Speicherbereich vom
Betriebssystem anfordern, die alten Inhalte in den neuen Speicherbereich
kopieren und den alten Speicherbereich dem Betriebssystem zurückgeben.

Damit dieser Vorgang nicht bei jedem Anfügen erfolgen muss, erhöht der Vektor
die zusätzliche Größe in der konkreten auf die doppelte Größe.
