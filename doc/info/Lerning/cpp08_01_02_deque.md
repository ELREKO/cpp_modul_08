

# Deque

Die Methoden und der Umgang mit Iteratoren sind ähnlich zu `std::vector`, aber mit zusätzlichen Methoden wie <span style="background-color: green;">push_front</span> und <span style="background-color: green;"> pop_front </span>, die spezifisch für die doppelseitige Warteschlange sind.

## Include
```cpp
#include <deque>
```

## Konstruktoren
```cpp
std::deque<int> deq1;               // Default Constructor 
std::deque<int> deq2(5);            // Deque mit 5 Elementen, alle mit 0 initialisiert
std::deque<int> deq3(5, 10);        // Deque mit 5 Elementen, alle mit dem Wert 10
std::deque<int> deq4 = {1, 2, 3, 4, 5}; // Deque mit 5 Elementen mit den entsprechenden Werten
std::deque<int> deq5(deq4);         // Copy Deque 
deq1 = deq5;                         // Zuweisung Deque 
```

## Methoden

Die häufigsten Methoden des `std::deque` Containers

| Methode                     | Beschreibung                                                               | Beispiel                                      |
|----------------------------|---------------------------------------------------------------------------|-----------------------------------------------|
| `push_back(value)`         | Fügt ein Element am Ende des Deques hinzu.                              | `deq.push_back(7);`                          |
| `push_front(value)`        | Fügt ein Element am Anfang des Deques hinzu.                            | `deq.push_front(0);`                         |
| `pop_back()`               | Entfernt das letzte Element des Deques.                                  | `deq.pop_back();`                            |
| `pop_front()`              | Entfernt das erste Element des Deques.                                   | `deq.pop_front();`                           |
| `insert(position, value)`   | Fügt ein Element an der angegebenen Position im Deque ein.               | `deq.insert(deq.begin() + 1, 5);`           |
| `erase(position)`          | Entfernt das Element an der angegebenen Position.                        | `deq.erase(deq.begin() + 1);`               |
| `clear()`                  | Entfernt alle Elemente aus dem Deque.                                    | `deq.clear();`                               |
| `size()`                   | Gibt die Anzahl der aktuellen Elemente im Deque zurück.                  | `size_t n = deq.size();`                     |
| `capacity()`               | Gibt die Kapazität des Deques zurück (nicht immer verfügbar).            | `size_t cap = deq.max_size();`               |
| `resize(new_size)`         | Ändert die Größe des Deques auf `new_size`.                             | `deq.resize(5);`                             |
| `shrink_to_fit()`          | Reduziert die Kapazität des Deques auf die aktuelle Größe (nicht immer verfügbar). | `deq.shrink_to_fit();`                       |

- Die Angabe der Position bei `insert()` und `erase()` muss entsprechend mit der Verwendung des Iterators angegeben werden, z.B. `deq.insert(deq.begin() + 1, 5);` (was die Position 1 ist, also das zweite Element).

1. **`insert(position, value)`**:
   - **Beschreibung**: Fügt ein Element an einer bestimmten Position im Deque ein. Die Position wird durch einen Iterator angegeben.
   - **Beispiel**:
     ```cpp
     std::deque<double> deq = {1.1, 2.2, 3.3}; // Deque hat: [1.1, 2.2, 3.3]
     deq.insert(deq.begin() + 1, 5.5); // Fügt 5.5 an der Position 1 hinzu
     // Deque hat jetzt: [1.1, 5.5, 2.2, 3.3]
     ```

2. **`erase(position)`**:
   - **Beschreibung**: Entfernt das Element an einer bestimmten Position im Deque.
   - **Beispiel**:
     ```cpp
     deq.erase(deq.begin() + 1); // Entfernt das Element an Position 1 (5.5)
     // Deque hat jetzt: [1.1, 2.2, 3.3]
     ```

## Zugriff auf Elemente
- `operator[]` -> kein Bound Check
- `at()` -> Bound Check -> `std::out_of_range`

```cpp
#include <iostream>
#include <deque>

int main() {
    std::deque<int> deq = {1, 2, 3, 4, 5};
    try {
        std::cout << deq.at(10) << std::endl;  // Ausnahme wird geworfen 
    } catch (const std::out_of_range& e) {
        std::cerr << "Index out of range: " << e.what() << std::endl;
    }

    return 0;
}
```

## Iteratoren
- `begin()` und `end()`: Vorwärtsiteration
- `rbegin()` und `rend()`: Rückwärtsiteration
- `cbegin()` und `cend()`: Konstanten-Iteratoren (Keine Modifikation)

```cpp
#include <iostream>
#include <deque>

int main() {
    std::deque<int> deq = {1, 2, 3, 4, 5};

    // Iteration mit einem Iterator
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it) {
        std::cout << *it << " ";  // Ausgabe: 1 2 3 4 5
    }
    std::cout << std::endl;

    // Rückwärtsiterieren mit rbegin() und rend()
    for (std::deque<int>::reverse_iterator rit = deq.rbegin(); rit != deq.rend(); ++rit) {
        std::cout << *rit << " ";  // Ausgabe: 5 4 3 2 1
    }

    for (std::deque<int>::const_iterator it = deq.cbegin(); it != deq.cend(); ++it) {
        std::cout << *it << " "; // Gibt die Werte aus, kann aber nicht modifiziert werden
    }

    return 0;
}
```



