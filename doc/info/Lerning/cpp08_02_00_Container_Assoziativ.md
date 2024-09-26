# Assoziative Container 

## std::set
- Speicherung in sotrierten Reihenfolge -> Binaersuchstuktur (Rot-Schwarz-Baum)
- keine Dublikate 
- Such-, Einfuege und Loeschopperation brauchen `O(log(n))`

### Vorteile 
- Bei Einduetigen Zahlen so wie Mengenoperationen 
- Effiziente Suche 

### Nachteile
- Kein Zugriff auf Elemente über **Index**
- hoher Speicherbedarf als `vector`

## std::multiset
- gleich wie `set` jedoch dublikate sind erlaubt

### Vorteile 
- duplikate sind erlaubt 

### Nachteile 
- kein eindeutiges Speichern 

## std::map
- Sortierung in Baumstrucktur wie bei `set` 
- Es gibt einen Schlüssel 
- Ein eindeutiger Schüsselwert 

### Vorteile 
- Schlüssel sind automatisch sortiert 
- Kein Duplikate 
- Bei Suche Logarithmische Zeitkomplexität `O(log(n))`

### Nachteile 
- Grosser Speicherverbrauche und Overhead
- Lansame Einfügungsoperation 

## std::multimap
- Siehe map nur Duplikate sind erlaubt. 

### Vorteile 
- Duplicate sind erlaubt 

### Nachteile 
- Groesser Overhead 


