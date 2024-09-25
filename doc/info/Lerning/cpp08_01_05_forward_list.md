
# Forward List
Wie `list` keine zufälliger Elementzugriff möglich! 
Benötigt weniger Speicher als list ist!


## Include
```cpp
#include <forward_list>
```

## Konstruktoren
```cpp
std::forward_list<int> flst1;                  // Default Constructor 
std::forward_list<int> flst2(5);               // Forward List mit 5 Elementen, alle mit 0 initialisiert
std::forward_list<int> flst3(5, 10);           // Forward List mit 5 Elementen, alle mit dem Wert 10
std::forward_list<int> flst4 = {1, 2, 3, 4, 5}; // Forward List mit 5 Elementen mit den entsprechenden Werten
std::forward_list<int> flst5(flst4);            // Copy Forward List 
flst1 = flst5;                                  // Zuweisung Forward List 
```

## Methoden

Die häufigsten Methoden des `std::forward_list` Containers

| Methode                     | Beschreibung                                                              | Beispiel                                      |
|----------------------------|--------------------------------------------------------------------------|-----------------------------------------------|
| `push_front(value)`        | Fügt ein Element am Anfang der Forward List hinzu.                     | `flst.push_front(0);`                        |
| `pop_front()`              | Entfernt das erste Element der Forward List.                            | `flst.pop_front();`                          |
| `insert_after(position, value)` | Fügt ein Element nach der angegebenen Position in der Liste ein.  | `flst.insert_after(flst.begin(), 5);`       |
| `erase_after(position)`     | Entfernt das Element nach der angegebenen Position.                   | `flst.erase_after(flst.begin());`           |
| `clear()`                  | Entfernt alle Elemente aus der Forward List.                            | `flst.clear();`                              |
| `size()`                   | Gibt die Anzahl der Elemente in der Forward List zurück.                | `size_t n = std::distance(flst.begin(), flst.end());` |
| `empty()`                  | Überprüft, ob die Forward List leer ist.                                 | `bool isEmpty = flst.empty();`               |

1. **`insert_after(position, value)`**:
   - **Beschreibung**: Fügt ein Element nach einer bestimmten Position in der Forward List ein. Die Position wird durch einen Iterator angegeben.
   - **Beispiel**:
     ```cpp
     std::forward_list<double> flst = {1.1, 2.2, 3.3}; // Forward List hat: [1.1, 2.2, 3.3]
     flst.insert_after(flst.begin(), 5.5); // Fügt 5.5 nach der Position 0 hinzu
     // Forward List hat jetzt: [1.1, 5.5, 2.2, 3.3]
     ```

2. **`erase_after(position)`**:
   - **Beschreibung**: Entfernt das Element nach einer bestimmten Position in der Forward List.
   - **Beispiel**:
     ```cpp
     flst.erase_after(flst.begin()); // Entfernt das Element nach der Position 0 (5.5)
     // Forward List hat jetzt: [1.1, 2.2, 3.3]
     ```

## Zugriff auf Elemente
- **Kein direkter Zugriff** über Indizes, da es sich um eine einfach verkettete Liste handelt. Der Zugriff erfolgt normalerweise über Iteratoren.
- **`front()`**: Gibt das erste Element zurück (kein Bound Check).

```cpp
#include <iostream>
#include <forward_list>

int main() {
    std::forward_list<int> flst = {1, 2, 3, 4, 5};
    
    // Zugriff auf das erste Element
    std::cout << "First element: " << flst.front() << std::endl; // Ausgabe: 1

    return 0;
}
```

## Iteratoren
- `begin()` und `end()`: Vorwärtsiteration
- `cbegin()` und `cend()`: Konstanten-Iteratoren (Keine Modifikation)

```cpp
#include <iostream>
#include <forward_list>

int main() {
    std::forward_list<int> flst = {1, 2, 3, 4, 5};

    // Iteration mit einem Iterator
    for (std::forward_list<int>::iterator it = flst.begin(); it != flst.end(); ++it) {
        std::cout << *it << " ";  // Ausgabe: 1 2 3 4 5
    }
    std::cout << std::endl;

    for (std::forward_list<int>::const_iterator it = flst.cbegin(); it != flst.cend(); ++it) {
        std::cout << *it << " "; // Gibt die Werte aus, kann aber nicht modifiziert werden
    }

    return 0;
}
```