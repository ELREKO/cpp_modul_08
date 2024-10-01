
< [back](cpp08_03_Container_unsort.md) | [main](/) | [forward](cpp08_05_Iteratoren.md) >

# Zusammenfassung der `<algorithm>`-Bibliothek in C++

Die `<algorithm>`-Bibliothek in C++ bietet eine Vielzahl von Funktionen für das Durchsuchen, Sortieren, Modifizieren und Verwalten von Daten in `iterativen` Containern wie z.B. `std::vector`, `std::set`, usw. Diese Algorithmen arbeiten oft mit Iteratoren und erlauben die Manipulation der Elemente in Containern.

#### Einbinden der Bibliothek
```cpp
#include <algorithm>
```

### Wichtige Kategorien und Beispiele:

#### 1. **Suchen und Finden**
- **`std::find`**: Sucht nach einem bestimmten Wert in einem Bereich.
  ```cpp
  std::vector<int> vec = {1, 2, 3, 4, 5};
  auto it = std::find(vec.begin(), vec.end(), 3);
  ```
- **`std::find_if`**: Sucht nach dem ersten Element, das eine bestimmte Bedingung erfüllt.
  ```cpp
  auto it = std::find_if(vec.begin(), vec.end(), [](int i){ return i > 3; });
  ```

#### 2. **Sortieren**
- **`std::sort`**: Sortiert den Bereich [first, last) in aufsteigender Reihenfolge.
  ```cpp
  std::sort(vec.begin(), vec.end());
  ```
- **`std::stable_sort`**: Wie `std::sort`, aber stabil (gleiche Werte behalten ihre Reihenfolge).
- **`std::partial_sort`**: Sortiert nur die ersten *k* Elemente.
  ```cpp
  std::partial_sort(vec.begin(), vec.begin() + 3, vec.end());
  ```

#### 3. **Modifikation**
- **`std::reverse`**: Kehrt die Reihenfolge der Elemente um.
  ```cpp
  std::reverse(vec.begin(), vec.end());
  ```
- **`std::replace`**: Ersetzt alle Vorkommen eines Wertes durch einen anderen.
  ```cpp
  std::replace(vec.begin(), vec.end(), 2, 20);  // Ersetzt alle 2 durch 20
  ```
- **`std::transform`**: Wendet eine Funktion auf jeden Wert in einem Bereich an.
  ```cpp
  std::transform(vec.begin(), vec.end(), vec.begin(), [](int i){ return i * 2; });
  ```

#### 4. **Kopieren**
- **`std::copy`**: Kopiert den Bereich [first, last) in einen anderen Bereich.
  ```cpp
  std::vector<int> dest(vec.size());
  std::copy(vec.begin(), vec.end(), dest.begin());
  ```
- **`std::copy_if`**: Kopiert Elemente, die eine Bedingung erfüllen.
  ```cpp
  std::copy_if(vec.begin(), vec.end(), dest.begin(), [](int i){ return i > 3; });
  ```

#### 5. **Vergleichen**
- **`std::equal`**: Vergleicht zwei Bereiche und prüft, ob sie gleich sind.
  ```cpp
  std::vector<int> vec2 = {1, 2, 3, 4, 5};
  bool are_equal = std::equal(vec.begin(), vec.end(), vec2.begin());
  ```
- **`std::lexicographical_compare`**: Vergleicht zwei Bereiche lexikographisch.
  ```cpp
  bool result = std::lexicographical_compare(vec.begin(), vec.end(), vec2.begin(), vec2.end());
  ```

#### 6. **Anzahl und Zählen**
- **`std::count`**: Zählt, wie oft ein Wert im Bereich vorkommt.
  ```cpp
  int count = std::count(vec.begin(), vec.end(), 3);  // Zählt die Anzahl der 3en
  ```
- **`std::count_if`**: Zählt die Elemente, die eine bestimmte Bedingung erfüllen.
  ```cpp
  int count = std::count_if(vec.begin(), vec.end(), [](int i){ return i > 3; });
  ```

#### 7. **Min/Max**
- **`std::min_element` / `std::max_element`**: Gibt den Iterator auf das kleinste bzw. größte Element zurück.
  ```cpp
  auto min_it = std::min_element(vec.begin(), vec.end());
  ```
- **`std::min` / `std::max`**: Gibt den kleineren bzw. größeren von zwei Werten zurück.
  ```cpp
  int min_val = std::min(3, 7);  // Gibt 3 zurück
  ```

#### 8. **Bedingte Algorithmen**
- **`std::all_of`**: Prüft, ob alle Elemente eine Bedingung erfüllen.
  ```cpp
  bool all_positive = std::all_of(vec.begin(), vec.end(), [](int i){ return i > 0; });
  ```
- **`std::any_of`**: Prüft, ob irgendein Element eine Bedingung erfüllt.
  ```cpp
  bool any_negative = std::any_of(vec.begin(), vec.end(), [](int i){ return i < 0; });
  ```
- **`std::none_of`**: Prüft, ob kein Element eine Bedingung erfüllt.
  ```cpp
  bool none_negative = std::none_of(vec.begin(), vec.end(), [](int i){ return i < 0; });
  ```

#### 9. **Numerische Algorithmen (aus `<numeric>`)**
- **`std::accumulate`**: Summiert die Elemente in einem Bereich.
  ```cpp
  int sum = std::accumulate(vec.begin(), vec.end(), 0);
  ```
- **`std::adjacent_difference`**: Berechnet die Differenz zwischen benachbarten Elementen.
  ```cpp
  std::adjacent_difference(vec.begin(), vec.end(), vec.begin());
  ```

#### 10. **Zufällige Permutation**
- **`std::shuffle`**: Mischt die Elemente eines Containers zufällig.
  ```cpp
  #include <random>
  std::shuffle(vec.begin(), vec.end(), std::mt19937{std::random_device{}()});
  ```

### Iterator-Unterstützung:
Alle Algorithmen in `<algorithm>` arbeiten mit <span style="color:red">**Iteratoren**</span>, was bedeutet, dass sie mit einer Vielzahl von Containern funktionieren, die Iteratoren bereitstellen, wie z.B. `std::vector`, `std::list`, `std::deque`, `std::array`, etc.
