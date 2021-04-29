---
description : Cheatsheat für den Computer
toc : true
---

# Makefiles

## Watn dat ??

Makefiles sind Text-Dateien, die eine Anleitung für den Computer enthalten, wie
das (C++) Programm compiliert, installiert und/oder ausgeführt wird. Sie werden in
einer abwandlung der Script-Sprache [Bash](bash.md) geschrieben und enthalten **Keine** teile des eigentlichen Programmes.

## Warum ??

(Gut gemachte) Makefiles sind portabel, und können ebenfalls mit Git verwaltet
sowie verbreitet werden. Dazu sind sie theoretisch plattformunabhängig, was die
Zusammenarbeit erleichtert und für [CD/CI-Pipelines](pipeline.md) wichtig ist.

## Wie ??

### Targets

Makefiles bestehen aus mehreren Abschnitten, die mit  `make *name*` aufgerufen
werden. Außerdem ist es möglich sie im Makefile auf zu rufen, bzw. sie als
Abhängigkeit eines anderen Abschnittes an zu geben. Diese Abschnitte werden "Targets"
*(Deu.: Ziele)* genannt.

```bash
compile:
    # Hier stehen eigentlich Compile Anweisungen.
    echo "block compile \n"
    # Aus geführt wird dieser durch die Eingabe "make compile" in die Console.

run: compile # Hier werden andere Blöcke als dependency angegeben
    # Hier stehen eigentlich die anwiesunge zur ausführung.
    echo "block run \n"
    # die angegebenen Blöcke werden zu erst aufgerufen.
```

Bei diesem beispiel sähe der Output dann so aus :

```terminal
kurt@localhost:~$ make compile
# Hier stehen eigentlich Compile Anweisungen
echo "block compile\n"     
block compile 

# Aus geführt wird dieser durch die Eingabe "make compile" in die Console.
```

```terminal
kurt@localhost:~$ make run
# Hier stehen eigentlich Compile Anweisungen.
echo "block compile \n"
block compile

# Aus geführt wird dieser durch die Eingabe "make compile" in die Console.
# Hier stehen eigentlich die anwiesunge zur ausführung.
echo "block run \n"
block run

# Die angegebenen Blöcke werden zu erst aufgerufen.  
```

Wie man sieht wird bei `make run` zu erst der Block `compile` aufgerufen, wie vorher bei `make compile`.
Was zudem ins Auge fällt, ist die eigenschaft des Programmes die Anweisungen -
und Kommentare - wieder zu geben, nicht nur die Ergebnisse. Das hat den Vorteil,
das man auch bei Anweisungen ohne eigenen Output (in textform) weiß was gerade
passiert, wo der Rechner sich ggf. aufgehängt hat. Jedoch kann es auch nervig
sein, wenn man beim Debuggen ein bestimmtes Ergebniss beobachten will, das im
Text unter geht. Dafür gibt es das Präfix `@` um die Ausgabe auf das Ergebniss zu
beschränken.  

Beispiel :

```bash
test:
    @echo "Es wird nur dieser String ausgegeben, ohne das \"@echo\""
    @#Nerviger Kommentar, der auch nicht ausgegeben wird

```

```terminal
kurt@localhost:~$ make test
Es wird nur dieser String ausgegeben, ohne das "@echo"
```

### Variabelen

In Makefiles gibt es nur Variabelen des Types String, um etwa Dateipfade oder
Command-Argumente zu halten. Es gibt keine Rechen operationen mit den Variabelen, sie
werden nur eingesetzt (wie C++ Makros), um zwei Variabelen zu "addieren" können sie
einfach hinter einander verwendet werden. Wie in Bash (und C++) können Variabelen mit dem
ergebnis einer Funktion, bzw. anderen Befehles, deklariert werden. Verwendet werden sie
via `$(var)`. `$(shell command)` gibt das ergebnis des Commands zurück.

Beispiel:

```bash
COMMIT = $(shell git rev-parse --short HEAD)
NAME = name
VERSION = $(NAME)-$(COMMIT)

test:
    @echo "$(COMMIT)"
    @echo "$(NAME)"
    @echo "$(VERSION)"
    @echo "$(NAME)$(COMMIT)" # entspricht name + commit
```

```terminal
kurt@localhost:~$ make test
3a9158c
name
name-3a9158c
name3a9158c 
```
