# Makefiles

## Watn dat ??

Makefiles sind text dateien, die eine anleitung für den Computer enthalten, wie 
das (C++) Programm compilert, installiert und/oder ausgeführt wird. Sie werden in
einer abwandlung der Script sprache bash geschrieben und enthalten **Keine** teile des eigentlichen programms.

## Warum ??

(Gut gemachte) Makefiles sind portabel, und können ebenfalls mit Git verwaltet 
sowie Verbreitet werden. Dazu sind sie theoretisch plattform unabhängig, was die 
zusammen arbeit erleichtert und für CD/CI-Pipelines wichtig ist.

## Wie ??

Makefiles bestehen aus mehreren abschnitten, die mit  `make *name*` aufgerufen 
werden. Außerdem ist es möglich sie im Makefile auf zu rufen, bzw. sie als 
abhängigkeit an zu geben.
```bash
    compile:
        # Hier stehen eigentlich Compile anweisungen.
        echo "block compile \n"
        # Aus geführt wird dieser durch die eingaba "make compile" in die console.

    run: compile # Hier werden andere blöcke als dependency angegeben
        # Hier stehen eigentlich die anwiesunge zur ausführung.
        echo "block run \n"
        # die angegebenen blöcke werden zu erst aufgerufen.
```
Bei diesem beispiel sähe der Output dann so aus :
```
kurt@localhost:~$ make compile
# Hier stehen eigentlich Compile anweisungen
echo "block compile\n"     
block compile 

# Aus geführt wird dieser durch die eingaba "make compile" in die console.
```
```
kurt@localhost:~$ make run
# Hier stehen eigentlich Compile anweisungen.
echo "block compile \n"
block compile

# Aus geführt wird dieser durch die eingaba "make compile" in die console.
# Hier stehen eigentlich die anwiesunge zur ausführung.
echo "block run"
block run

# die angegebenen blöcke werden zu erst aufgerufen.  
```
Wie man sieht wird bei `make run` zu erst der block `compile` aufgerufen, wie vorher bei `make compile`.
Was zudem ins auge fällt, ist die eigenschaft des programmes die anweisungen -
und Kommentare - wieder zu geben, nicht nur die ergebnisse. Das hat den vorteil,
das man auch bei anweisungen ohne eigenen output (in textform) weiß was gerade 
passiert, wo der Rechner sich ggf. aufgehängt hat. Jedoch kann es auch nervig 
sein, wenn man beim debuggen ein bestimmtes ergebniss beobachten will, das im 
text unter geht. Dafür gibt es das Präfix `@` um die ausgabe auf das ergebniss zu
beschränken.  
Beispiel :
```bash
    test:
        @#Nerviger Kommentar, der auch nicht ausgegeben wird
        @echo "Es wird nur dieser String ausgegeben, ohne das \"@echo\""
```
```
kurt@localhost:~$ make test
Es wird nur dieser String ausgegeben, ohne das "@echo"
```