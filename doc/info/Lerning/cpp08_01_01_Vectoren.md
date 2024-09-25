# Vectoren 
## include 
```cpp
#include <vector>
```

## Konstructoren 
```cpp
    std::vector<int> vec1; // Default Constructor 
    std::vector<int> vec2(5);  // Vector mit 5 Elementen, alle mit 0 initialisiert
    std::vector<int> vec3(5, 10);  // Vector mit 5 Elementen, alle mit dem Wert 10
    std::vector<int> vec4 = {1, 2, 3, 4, 5}; // Vector mit 5 Elemententen mit dem entsprechenden Wert
    std::vector<int> vec5(vec4); // Copy Vector 
    vec1 = vec5 // Zuweisung Vector 
```

## Methoden 

Die häufigsten Methoden des `std::vector` Containers

| Methode                     | Beschreibung                                                                 | Beispiel                                         |
|----------------------------|-----------------------------------------------------------------------------|--------------------------------------------------|
| `push_back(value)`         | Fügt ein Element am Ende des Vektors hinzu.                              | `vec.push_back(7.2);`                           |
| `pop_back()`               | Entfernt das letzte Element des Vektors.                                  | `vec.pop_back();`                               |
| `insert(position, value)`   | Fügt ein Element an der angegebenen Position im Vektor ein.               | `vec.insert(vec.begin() + 1, 5.5);`             |
| `erase(position)`          | Entfernt das Element an der angegebenen Position.                          | `vec.erase(vec.begin() + 1);`                   |
| `clear()`                  | Entfernt alle Elemente aus dem Vektor.                                    | `vec.clear();`                                  |
| `size()`                   | Gibt die Anzahl der aktuellen Elemente im Vektor zurück.                  | `size_t n = vec.size();`                        |
| `capacity()`               | Gibt die derzeitige Kapazität des Vektors zurück.                        | `size_t cap = vec.capacity();`                  |
| `resize(new_size)`         | Ändert die Größe des Vektors auf `new_size`.                             | `vec.resize(5);`                                |
| `shrink_to_fit()`          | Reduziert die Kapazität des Vektors auf die aktuelle Größe.              | `vec.shrink_to_fit();`                          |

- Die Angabe der Position bei `insert()` und `earase()` müssen entsprechend mit der zuhilfename des iterators angeben werden `vec.begin() + 1` (Was die Position 1 ist, also das 2 Element) z.B. `vec.insert(1,5.5)` würde zu einem Kompilierungsfehler führen. 

1. **`insert(position, value)`**:
   - **Beschreibung**: Fügt ein Element an einer bestimmten Position im Vektor ein. Die Position wird durch einen Iterator angegeben.
   - **Beispiel**:
     ```cpp
     std::vector<double> vec = {1.1, 2.2, 3.3}; // Vektor hat: [1.1, 2.2, 3.3]
     vec.insert(vec.begin() + 1, 5.5); // Fügt 5.5 an der Position 1 hinzu
     // Vektor hat jetzt: [1.1, 5.5, 2.2, 3.3]
     ```

1. **`erase(position)`**:
   - **Beschreibung**: Entfernt das Element an einer bestimmten Position im Vektor.
   - **Beispiel**:
     ```cpp
     vec.erase(vec.begin() + 1); // Entfernt das Element an Position 1 (5.5)
     // Vektor hat jetzt: [1.1, 2.2, 3.3]
     ```

## Zugriff auf Elemente 
- operator`[]` -> kein Bound Check
- `at()` -> Bound Check -> `std::out_of_range`

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    try {
        std::cout << vec.at(10) << std::endl;  // Ausnahme wird geworfen 
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
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Iteration mit einem Iterator
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";  // Ausgabe: 1 2 3 4 5
    }
    std::cout << std::endl;

    // Rückwärtsiterieren mit rbegin() und rend()
    for (std::vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        std::cout << *rit << " ";  // Ausgabe: 5 4 3 2 1
    }

    for (std::vector<int>::const_iterator it = vec.cbegin(); it != vec.cend(); ++it) {
        std::cout << *it << " "; // Gibt die Werte aus, kann aber nicht modifiziert werden
    }

    return 0;
}
```