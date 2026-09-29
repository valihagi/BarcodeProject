# Code-128 Barcode Encoder (Subset B)

Encoder Projekt das eine CLI Anwendung bereitstellt welche ASCII Eingaben zun einer Code128 Sequenz übersetzt.

## Voraussetzungen
- C++17-fähiger Compiler
- CMake ≥ 3.14

## Build
    cmake -S . -B build
    cmake --build build

## Encoder ausführen
    ./build/BarcodeProject
- Eine CLI Anwendung wird gestartet welche nach einem Input String fragt welcher dann in Code128 kodiert wird. Alternativ kann das Programm auch mit "quit" beendet werden.

## Tests ausführen
    ctest --test-dir build

## Beispiel
Eingabe:  HELLO123
Ausgabe:  104 40 37 44 44 47 17 18 19 8 106

```text
Please enter an ASCII string or type "quit" to exit: HELLO123
You entered 104 40 37 44 44 47 17 18 19 8 106 
------------

Please enter an ASCII string or type "quit" to exit: 
```


## Design
- Für das Design des Programms wurden zwei Klassen erstellt welche unterschiedliche Teile der Funktionalität beinhalten.
- Code128Encoder: Diese Klasse stellt den tatsächlichen Encoder dar, welcher den Input String übergeben bekommt und validiert sowie mithilfe der zweiten Klasse Zeichen für Zeichen encodet, die Checksum (analog zu https://free-barcode.com/barcode/barcode-types/check-digit-calculation-code-128.asp) berechnet und somit die gesamte Logik beinhaltet.
- Code128SymbolTable: Diese Klasse stellt die Werte für Start- und Endcodes bereit und fungiert als "Lookup Table". Die Encoder-Klasse "übersetzt" die einzelnen Charakters dann mithilfe dieses "Lookup Tables". (Der Lookup Table ist allerdings kein wirklicher Table sondern macht sich die Konvention zunütze, dass für den gewünschten Code128 Wert einfach 32 vom ASCII Wert abgezogen werden muss.) 

- Ungültige Eingaben (zb leere Strings oder Strings welche unerlaubte Zeichen enthalten) werden erkannt und eine entsprechende Fehlermeldung wird ausgegeben.
