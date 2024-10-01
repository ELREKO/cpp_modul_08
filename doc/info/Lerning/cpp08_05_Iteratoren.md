
< [back](cpp08_04_Algoritmen.md) | [main](/) | [forward](cpp08_06_Funtoren.md) >

# Iteratoren

### Was sind Iteratoren?

In C++ sind **Iteratoren** spezielle Objekte, die dazu verwendet werden, über Elemente eines Containers (wie `std::vector`, `std::list`, `std::set` etc.) zu iterieren und auf sie zuzugreifen. Sie funktionieren ähnlich wie Zeiger, ermöglichen aber einen allgemeinen Zugriff auf Container und deren Elemente, unabhängig vom Typ des Containers.

### Verwendung von Iteratoren

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Iterator verwenden, um über den Vektor zu iterieren
    std::vector<int>::iterator it;  // Definiert einen Iterator für den Vektor

    for (it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";  // Dereferenzieren des Iterators, um das Element anzuzeigen
    }

    return 0;
}
```

### Iteratoren und Container

Die meisten C++-Container bieten Funktionen, die Iteratoren zurückgeben:
- **`begin()`**: Gibt einen Iterator auf das erste Element zurück.
- **`end()`**: Gibt einen Iterator auf das "eine-past-the-end"-Element zurück (also auf das Element nach dem letzten).
- **`rbegin()`**: Gibt einen Reverse-Iterator auf das letzte Element zurück (für rückwärts Iteration).
- **`rend()`**: Gibt einen Reverse-Iterator auf das Element vor dem ersten Element zurück.

### Beispiel für konstante Iteratoren

Ein konstanter Iterator erlaubt den Lesezugriff auf die Elemente, verhindert aber deren Modifikation:

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};

    std::vector<int>::const_iterator it;  // Konstanter Iterator

    for (it = vec.cbegin(); it != vec.cend(); ++it) {
        std::cout << *it << " ";  // Ermöglicht nur das Lesen der Elemente
        // *it = 100;  // Fehler: Versuch, ein Element zu modifizieren
    }

    return 0;
}
```

### Vergleich der Iterator-Typen

| Container        | Iterator-Typ          | Beschreibung |
|------------------|-----------------------|--------------|
| `std::vector`    | Random-Access-Iterator | Ermöglicht Zugriff auf beliebige Positionen |
| `std::list`      | Bidirectional-Iterator | Kann vorwärts und rückwärts iterieren |
| `std::set`       | Bidirectional-Iterator | Geordnete Mengen, iteriert in sortierter Reihenfolge |
| `std::deque`     | Random-Access-Iterator | Beliebiger Zugriff ähnlich wie `std::vector` |
| `std::stack`     | Keine Iteratoren       | `std::stack` bietet <span style="color:red"> keinen direkten Iterator-Zugriff</span> |

### Wichtige Iterator-Operationen und ihre Verwendung

| Operation         | Beschreibung                                      | Beispiel                                          |
|-------------------|---------------------------------------------------|---------------------------------------------------|
| `*it`             | Dereferenzierung: Zugriff auf das Element, auf das der Iterator zeigt. | `int value = *it;`                                |
| `it->member`      | Zugriff auf ein Member des Objekts, auf das der Iterator zeigt (ähnlich wie `(*it).member`). | `it->length();` (für Iteratoren auf Objekte)      |
| `++it`            | Präinkrement: Bewegt den Iterator zum nächsten Element (vorwärts). | `++it;`                                           |
| `it++`            | Postinkrement: Bewegt den Iterator vorwärts, gibt aber zuerst den alten Zustand zurück. | `it++;`                                           |
| `--it`            | Prädekrement: Bewegt den Iterator zum vorherigen Element (rückwärts, nur für bidirektionale Iteratoren). | `--it;`                                           |
| `it--`            | Postdekrement: Bewegt den Iterator rückwärts, gibt aber zuerst den alten Zustand zurück (nur für bidirektionale Iteratoren). | `it--;`                                           |
| `it == other_it`  | Vergleicht zwei Iteratoren auf Gleichheit.         | `if (it == vec.end())`                            |
| `it != other_it`  | Vergleicht zwei Iteratoren auf Ungleichheit.       | `if (it != vec.end())`                            |
| `it + n`          | Bewegt den Iterator um `n` Positionen vorwärts (nur für Random-Access-Iteratoren). | `it = it + 3;`                                    |
| `it - n`          | Bewegt den Iterator um `n` Positionen rückwärts (nur für Random-Access-Iteratoren). | `it = it - 2;`                                    |
| `it[n]`           | Greift auf das `n`-te Element relativ zum Iterator zu (nur für Random-Access-Iteratoren). | `std::cout << it[2];`                             |
| `std::distance(first, last)` | Gibt die Anzahl der Elemente zwischen zwei Iteratoren zurück. | `std::distance(vec.begin(), vec.end());`          |
| `std::advance(it, n)` | Bewegt den Iterator um `n` Positionen vorwärts oder rückwärts. | `std::advance(it, 3);`                            |

### Unterschiedliche Iterator-Kategorien

| Iterator-Typ              | Beispiel-Container       | Unterstützte Operationen            |
|---------------------------|--------------------------|-------------------------------------|
| **Input-Iterator**         | `std::istream_iterator`   | Lesen von Daten, nur Vorwärtsbewegung |
| **Output-Iterator**        | `std::ostream_iterator`   | Schreiben von Daten, nur Vorwärtsbewegung |
| **Forward-Iterator**       | `std::forward_list`       | Vorwärtsbewegung, Lesen und Schreiben |
| **Bidirectional-Iterator** | `std::list`, `std::set`   | Vor- und Rückwärtsbewegung          |
| **Random-Access-Iterator** | `std::vector`, `std::deque` | Vor- und Rückwärtsbewegung, Zufälliger Zugriff (`[]`, `+`, `-`) |

Iteratoren sind ein wesentliches Konzept in C++, das dir ermöglicht, generisch und effizient auf Container zuzugreifen und mit ihnen zu arbeiten.
