# Sequenzielle Container
## [std::vector](cpp08_01_01_Vectoren.md) 
- Art dynamische Array mit einem Speicherblock
### Vorteile
- dynamisches vergrössern und verkleinern in bezug auf das Ende. 
- Schneller Zufallszugriff Zeitkomplexität `O(1)`
## Nachteile  
- Elemente die am Anfang oder der Mitte eingefügt werden brauchen `O(n)` Koplieranweisungen und sind daher sehr Teuer. 
## std::deque
- Art die dynamisches Array mit mehren Speicherblöcken
### Vorteile:
- **Schnelles Einfügen** und Entfernen am Anfang und am Ende.
- Zufälliger Zugriff auf die Elemente, ähnlich wie bei vector.
### Nachteile 
- Da aus mehren Speicherblöcken bestehnde -> Overhead -> mehr Speicherbedarf
## std::list
- doppelt verkettete Liste 
### Vorteile 
- **Effizientes Einfügen und Löschen** an jeder beliebigen Stelle (O(1)).
- Ideal für Löschen und Einfuegen im Listeninneren 
### Nachteile 
- Da viele Speicherblöcke -> Overhead -> mehr Speicherbedarf
- Kein Schneller Zugriff wie bei `array`, `Vectoren`, `deque`
## std::array (since c++11)
-  statische Version des Arrays
### Vorteile 
- Effizienter Speicher da Grösse zur Kompile Zeit bekannt sein muss
### Nachteile
- Keine dynamische Grössenanpassung möglich
## std::forward_list (since c++11)
- einfach verkettete Liste
### Vorteile 
- Weniger Speicherplatzbedarf als `list`
- Effizentes Einfügen eines Elementes in die Liste 'O(1)`
### Nachteile
- Richtungsgebunden 
- Keine Zufälliges zugreifen auf Elemente 

---

![übersicht](../pic/sequence_containers.png)