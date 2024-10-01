# Stack
## Include
```cpp
#include <stack>
```

## Konstruktoren
```cpp
std::stack<int> stack1; // Standardkonstruktor
std::stack<int, std::vector<int>> stack2; // Mit einem bestimmten Container-Typ (hier std::vector)
std::stack<int> stack3(stack2); // Copy-Constructor
stack1 = stack3; // Zuweisung
```

`std::stack` ist ein <span style="color:red">Container-Adapter</span>, der auf einem anderen Container (wie `std::deque`, `std::vector`, oder `std::list`) basiert und das **LIFO**-Prinzip (Last In, First Out) verwendet.

### Standardmäßig wird `std::deque` als zugrunde liegender Container verwendet:
```cpp
std::stack<int, std::deque<int>> stack; // Standardmäßiger zugrunde liegender Container
```

## Methoden
Die häufigsten Methoden des `std::stack` Containers:

| Methode                     | Beschreibung                                                                 | Beispiel                                         |
|-----------------------------|-----------------------------------------------------------------------------|--------------------------------------------------|
| `push(value)`                | Fügt ein Element an die Spitze des Stacks hinzu.                            | `stack.push(10);`                                |
| `pop()`                      | Entfernt das oberste Element des Stacks.                                    | `stack.pop();`                                   |
| `top()`                      | Gibt das oberste Element des Stacks zurück (ohne es zu entfernen).           | `int val = stack.top();`                         |
| `empty()`                    | Prüft, ob der Stack leer ist (`true` oder `false`).                         | `if (stack.empty()) { ... }`                     |
| `size()`                     | Gibt die Anzahl der Elemente im Stack zurück.                               | `size_t n = stack.size();`                       |

## Beispielcode

```cpp
#include <iostream>
#include <stack>

int main() {
    std::stack<int> stack;

    // Elemente in den Stack einfügen
    stack.push(1);
    stack.push(2);
    stack.push(3);

    // Oberstes Element des Stacks
    std::cout << "Top element: " << stack.top() << std::endl;  // Ausgabe: 3

    // Element entfernen
    stack.pop();

    // Neues oberstes Element
    std::cout << "New top element: " << stack.top() << std::endl;  // Ausgabe: 2

    // Stack-Größe und ob er leer ist
    std::cout << "Stack size: " << stack.size() << std::endl;  // Ausgabe: 2
    std::cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << std::endl;  // Ausgabe: No

    return 0;
}
```

## Zugriff auf Elemente
- `top()`: Gibt das oberste Element des Stacks zurück, ohne es zu entfernen.
- `pop()`: Entfernt das oberste Element, aber gibt es **nicht** zurück.

```cpp
std::stack<int> stack;
stack.push(10);
stack.push(20);

int topElement = stack.top(); // topElement == 20
stack.pop(); // Entfernt 20 vom Stack
topElement = stack.top(); // topElement == 10
```

## Standard-Container
`std::stack` verwendet standardmäßig `std::deque` als zugrunde liegenden Container. Alternativ kann ein anderer Container (z. B. `std::vector` oder `std::list`) spezifiziert werden:

```cpp
#include <stack>
#include <vector>

std::stack<int, std::vector<int>> stackWithVector; // Verwendet std::vector anstelle von std::deque
```

## Einschränkungen
- <span style="color:red">**Keine direkten Iteratoren**</span>: Anders als bei `std::vector` oder `std::deque` erlaubt `std::stack` keinen direkten Zugriff auf seine Elemente (kein `begin()`, `end()`, etc.).
- Nur Zugriff auf das oberste Element mit `top()`.

## Anwendung von `std::stack`
- **Backtracking**: Algorithmen wie Depth-First Search (DFS) verwenden oft Stacks.
- **Klammerauswertung**: Stacks werden oft verwendet, um Ausdrücke wie Klammern in Compiler-Implementierungen zu analysieren.
- **Undo-Funktion**: Stacks werden in Software mit Undo-Funktionalität verwendet, um die Reihenfolge von Aktionen zu speichern und rückgängig zu machen.