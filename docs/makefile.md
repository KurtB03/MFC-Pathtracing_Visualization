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

### Variablen

In Makefiles gibt es nur Variablen des Types String, um etwa Dateipfade oder
Command-Argumente zu halten. Es gibt keine Rechen operationen mit den Variablen,
sie werden nur eingesetzt (wie C++ Makros), um zwei Variablen zu "addieren"
können sie einfach hinter einander verwendet werden. Wie in Bash (und C++) können
Variablen mit dem ergebnis einer Funktion, bzw. anderen Befehles, deklariert
werden. Verwendet werden sie via `$(var)`. Noch ein Hinweis `$(shell command)`
gibt das ergebnis des Commands zurück.

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

### Real Beispiel

Die ersten Variabeln hatten bereits einen Auftritt im abschnitt über Varabeln, in
diesem Beispiel, werden sie genutzt um den Versionen einzigartige Namen zu geben,
basierend auf ihren Git-Commits.
> Hinweis : Git gibt jedem Commit als Einzigartige Identifikations-Nummer, den SHA1 hash des Repositories

```bash
#Vars
NAME = Taschenrechner # Gib ihm einen Namen.
COMMIT = $(shell git rev-parse --short HEAD) # So bekommt man die ersten 7 stellen des Hashes, des aktuellen Commits.
VERSION = $(NAME)-$(COMMIT) # Combinieren, des Namens mit dem Hash um eine Informative Versionsbezeichnung zu erzeugen.
```

> Pro Tip : Meist reichen die ersten paar zeichen um einen Commit zu identifizieren, und sich seinen inhalt anschauen, zu können.

Die nächsten 2 Variabeln, speichern die Arbeits umgebung, die 3te Setzt den Output für den Compiler zusammen.

```bash
WORKSPACE = $(shell pwd) # "pwd" steht für "print working directory" und gibt den vollständigen Pfad zum Ordner, aus welchem der Command ausgeführt wird, zurück.
HOME = $(shell echo $$HOME) # Erfragt die Variable "HOME" vom Betriebsystem, welche den Pfad des Ordners, der die Dateien, des eingeloggten Nutzers enthält.
BIN = $(WORKSPACE)/bin/$(VERSION) # Name und Pfad werden zusammen gefügt um eine valide Datei-Adresse zu erhalten.
```

Nun wird der input für den Compiler (und Linker) vorberitet.

```bash
LDFLAGS = -lGL -lGLU # Linker optionen, um vor compilerte Librarys ein zu binden. Hier OpenGL.
FILE = $(WORKSPACE)/src/main.cpp # Zu compilerende Datei.
LIB = $(WORKSPACE)/lib/*.cpp # Source dateien eingebundener Librarys, die nicht in Binär form vorliegen.
```

Jetzt kommen wir endlich zur *Action* der `build` block enthält üblicher weise die
Anweisungen um das Programm zu Compileren, und eine Ausführbare Binär-Datei zu
erstellen.

> Man Beachte das Präfix `-` vor dem `mkdir`, es sagt make weiter zu arbeiten, wenn der dazugehörige Command einen Fehler zurück gibt.

```bash
build:
        -mkdir $(WORKSPACE)/bin # Wenn der Ordner …/bin nicht existiert wird er erstellt.
        g++ $(FILE) $(LIB) $(CFLAGS) $(LDFLAGS) -o $(BIN) # g++ ist der Standard C++ copiler für Linux
```

`package-` Blöcke sind dazu da, Release-Versionen in ein Format zu bringen, das nutzer sich herunterladen und möglichst einfach installieren können, Das bekannte Paket-Formate sind .msi für Windows, .apk für Android, ,pkg für Apple sowie .deb und .rpm für die Linux Distributionen Debian(deb) und RHEL(rpm). In diesem fall wird nur ein .zip Archiv des Source-Codes erstellt, der vom Nutzer (platformunabhängig) Compiliert werden muss.

> Achtung : Nicht jedes Programm, das platformunabhängig Verpakt ist, ist tatsächlich paltformunabhängig geschrien/lauffähig.

```bash
package-src:
        -mv $(WORKSPACE)/../Download/Taschenrechner/src/*.zip $(WORKSPACE)/../Download/Taschenrechner/src/old/ # Verschiebe ggf. vorhandene vorangeganene Versionen.
        zip $(WORKSPACE)/../Download/Taschenrechner/src/$(VERSION).zip $(WORKSPACE)/* # ZZzzipp und zu.
```

Wie unschwer zu erraten sein sollte, ist die aufgabe des `run` Blockes, das Programm auszuführen.

```bash
run: build # Erst muss das Programm natürlich compiliert werden.
        @echo "" # Leere Zeilen zur abgrenzung vom vorherigen output.
        @$(BIN) # Aufruf des Programmes.
```

`clean` ist ähnlich selbst erklärend, es räumt auf. Nicht mehr benötigte Datien, wie .o oder .a Dateien früheren Compilierens. In diesem Beispiel werden nur die Binär-Bateien gelöscht, um "platz zu schaffen" für neue.

```bash
clean:
        -rm -Rrf $(WORKSPACE)/bin # Alles muss raus. Ausverkauf bei Roller.
```

> Pro Tip : Versucht euch schlechte humoristische Anmerkungen zu verkneifen.
