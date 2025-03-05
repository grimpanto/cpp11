
# Templates

## Generelles zu Templates {#templatefoundations}

Deklaration und Definition

## Funktionstemplates {#functiontemplates}

\cpp bietet einen sehr mächtigen Mechanismus an, um generische Funktionen und
auch Klassen zu entwickeln. In diesem Abschnitt werden wir uns ansehen, wie wir
generische Funktionen entwickeln können.

Nehmen wir nochmals unsere Funktion `swap` aus dem Abschnitt \in[rvalueref] an:

~~~{.cpp}
void swap(string& a, string& b) {
    string tmp{move(a)};
    a = move(b);
    b = move(tmp);
}
~~~

Was ist jetzt wenn, wir eine weitere Funktion wollen, die genau das Gleiche
erledigt, nur für ganze Zahlen. Natürlich können wir einfach die obige Funktion
kopieren und jedes Vorkommen von `string` durch `int` ersetzen. Damit haben wir
eine überladene Funktion geschrieben, die genau dies erledigt. Jetzt könnte es
sein, dass wir noch so eine Funktion wollen, die dies für Gleitkommazahlen
erledigt. Natürlich können wir wieder mit dem Kopieren und Abändern beginnen
und es würde auch funktionieren, aber es macht keinen Sinn! Das kann der
Compiler viel besser als wir.

Deshalb wollen wir Schablonen (engl. *templates* oder eingedeutscht Templates)
einsetzen:

~~~{.cpp}
// swaptemplate.cpp
#include <iostream>
#include <memory>

template <typename T>
void swap(T& a, T& b) {
    T tmp{std::move(a)};
    a = std::move(b);
    b = std::move(tmp);
}


int main() {
    int i1{1};
    int i2{2};

    swap(i1, i2);
    std::cout << "i1 = " << i1 << ", i2 = " << i2 << std::endl;
}
~~~

Die Ausgabe wird genau das Ergebnis der Funktion `swap` widerspiegeln. XXX

Variable Anzahl an Parameter

### Generische Lambdafunktion in Templates {#genericlambdatemplates}

<div class="c++14">
Generische Lambdafunktionen (siehe Abschntt \in[lambdafunc]) können im
Zusammenhang mit Templates sinnvoll eingesetzt werden:

XXX ist abzuändern und fertigzustellen

~~~{.cpp}
template<class C>
void print_elements(const C & c) {
    std::for_each(begin(c), end(c), [](auto & x) {
        std::cout << x << " ";
    });
    std::cout << std::endl;
}
~~~

~~~{.cpp}
vector<int> v{ 1, 2, 3 };
list<string> w{ "C++", "is", "cool" };

print_elements(v);
print_elements(w);
~~~
</div>

## Variablentemplates

\cppXI erlaubt Templates nur für Funktionen, Klassen und Typaliase und \cppXIV
erweitert die Verwendung von Templates auf Variablen:

<div class="c++14">

~~~{.cpp}
// vartemplates.cpp
#include <iostream>

using namespace std;

template <typename T>
constexpr T pi = T{3.1415926535897932385};

template <typename T>
T circle_perimeter(T r) {
    return 2 * r * pi<T>;
}

int main() {
    cout << circle_perimeter(2.5) << endl;
}
~~~

</div>
