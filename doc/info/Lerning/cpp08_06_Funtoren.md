< [back](cpp08_05_Iteratoren.md) | [main](/) | [forward](cpp08_00_lerning.md) > 
# Funktoren in C++

## Was ist ein Funktor?
Ein **Funktor** ist ein Objekt in C++, das sich wie eine Funktion verhält. Dies wird erreicht, indem der **Funktionsaufrufsoperator** (`operator()`) überladen wird. Dadurch kann das Objekt wie eine Funktion aufgerufen werden.

## Merkmale von Funktoren
- **Klasse mit `operator()`**: Funktoren sind Klassen, die den `operator()` überladen.
- **Zustandsbehaftet**: Funktoren können internen Zustand speichern, was bei normalen Funktionen nicht möglich ist.
- **Flexibilität**: Sie ermöglichen eine einfache Parametrisierung von Algorithmen.

## Beispiel eines Funktors

```cpp
#include <iostream>

// Definition eines Funktors
class Adder {
public:
    // Überladener Funktionsaufrufsoperator
    int operator()(int a, int b) {
        return a + b; // Addiere die beiden Zahlen
    }
};

int main() {
    Adder add; // Instanziierung des Funktors
    std::cout << add(2, 3) << std::endl; // Ausgabe: 5
    return 0;
}
```

## Vorteile von Funktoren
1. **Zustand speichern**: Funktoren können Variablen haben, die ihren Wert zwischen Aufrufen behalten.
2. **Wiederverwendbarkeit**: Sie können auf verschiedene Datentypen oder Operationen spezialisiert werden.
3. **Integration in STL**: Funktoren können problemlos in STL-Algorithmen verwendet werden.

## Unterschied zu anderen Konzepten
- **Funktionszeiger**: Zeigen auf eine Funktion, haben jedoch keinen Zustand.
- **Überladung von `operator=`**: Bestimmt, wie eine Instanz einer Klasse einer anderen Instanz zugewiesen wird, <span style="color:red">ist aber kein Funktor</span>.

