
# List
Einfaches flexibles Einfügen und Löschen an beliebigen Positionen möglich und effizienter als bei vector und deque, <span style="background-color: red;">jedoch keinen direkten Zugriff auf Elemente über Indizes bietet.</span>
## Include
```cpp
#include <list>
```

## Konstruktoren
```cpp
std::list<int> lst1;               // Default Constructor 
std::list<int> lst2(5);            // List mit 5 Elementen, alle mit 0 initialisiert
std::list<int> lst3(5, 10);        // List mit 5 Elementen, alle mit dem Wert 10
std::list<int> lst4 = {1, 2, 3, 4, 5}; // List mit 5 Elementen mit den entsprechenden Werten
std::list<int> lst5(lst4);         // Copy List 
lst1 = lst5;                       // Zuweisung List 
```

## Methoden

Die häufigsten Methoden des `std::list` Containers

| Methode                     | Beschreibung                                                               | Beispiel                                      |
|----------------------------|---------------------------------------------------------------------------|-----------------------------------------------|
| `push_back(value)`         | Fügt ein Element am Ende der Liste hinzu.                               | `lst.push_back(7);`                          |
| `push_front(value)`        | Fügt ein Element am Anfang der Liste hinzu.                             | `lst.push_front(0);`                         |
| `pop_back()`               | Entfernt das letzte Element der Liste.                                   | `lst.pop_back();`                            |
| `pop_front()`              | Entfernt das erste Element der Liste.                                    | `lst.pop_front();`                           |
| `insert(position, value)`   | Fügt ein Element an der angegebenen Position in der Liste ein.          | `lst.insert(++lst.begin(), 5);`              |
| `erase(position)`          | Entfernt das Element an der angegebenen Position.                        | `lst.erase(++lst.begin());`                  |
| `clear()`                  | Entfernt alle Elemente aus der Liste.                                    | `lst.clear();`                               |
| `size()`                   | Gibt die Anzahl der aktuellen Elemente in der Liste zurück.              | `size_t n = lst.size();`                     |
| `empty()`                  | Überprüft, ob die Liste leer ist.                                        | `bool isEmpty = lst.empty();`                |

- Die Angabe der Position bei `insert()` und `erase()` muss entsprechend mit der Verwendung des Iterators angegeben werden, z.B. `lst.insert(++lst.begin(), 5);` (was die Position 1 ist, also das zweite Element).

1. **`insert(position, value)`**:
   - **Beschreibung**: Fügt ein Element an einer bestimmten Position in der Liste ein. Die Position wird durch einen Iterator angegeben.
   - **Beispiel**:
     ```cpp
     std::list<double> lst = {1.1, 2.2, 3.3}; // Liste hat: [1.1, 2.2, 3.3]
     lst.insert(++lst.begin(), 5.5); // Fügt 5.5 an der Position 1 hinzu
     // Liste hat jetzt: [1.1, 5.5, 2.2, 3.3]
     ```

2. **`erase(position)`**:
   - **Beschreibung**: Entfernt das Element an einer bestimmten Position in der Liste.
   - **Beispiel**:
     ```cpp
     lst.erase(++lst.begin()); // Entfernt das Element an Position 1 (5.5)
     // Liste hat jetzt: [1.1, 2.2, 3.3]
     ```

## Zugriff auf Elemente
- **Kein direkter Zugriff** über Indizes, da es sich um eine doppelt verkettete Liste handelt. Der Zugriff erfolgt normalerweise über Iteratoren.
- **`front()`**: Gibt das erste Element zurück (kein Bound Check).
- **`back()`**: Gibt das letzte Element zurück (kein Bound Check).

```cpp
#include <iostream>
#include <list>

int main() {
    std::list<int> lst = {1, 2, 3, 4, 5};
    
    // Zugriff auf das erste und letzte Element
    std::cout << "First element: " << lst.front() << std::endl; // Ausgabe: 1
    std::cout << "Last element: " << lst.back() << std::endl;   // Ausgabe: 5

    return 0;
}
```

## Iteratoren
- `begin()` und `end()`: Vorwärtsiteration
- `rbegin()` und `rend()`: Rückwärtsiteration
- `cbegin()` und `cend()`: Konstanten-Iteratoren (Keine Modifikation)

```cpp
#include <iostream>
#include <list>

int main() {
    std::list<int> lst = {1, 2, 3, 4, 5};

    // Iteration mit einem Iterator
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";  // Ausgabe: 1 2 3 4 5
    }
    std::cout << std::endl;

    // Rückwärtsiterieren mit rbegin() und rend()
    for (std::list<int>::reverse_iterator rit = lst.rbegin(); rit != lst.rend(); ++rit) {
        std::cout << *rit << " ";  // Ausgabe: 5 4 3 2 1
    }

    for (std::list<int>::const_iterator it = lst.cbegin(); it != lst.cend(); ++it) {
        std::cout << *it << " "; // Gibt die Werte aus, kann aber nicht modifiziert werden
    }

    return 0;
}
```
