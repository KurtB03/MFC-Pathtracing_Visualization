# Taschenrechner Code

Einige Wichtige Librarys werden eingebunden, am auffälligsten hier ist die SFML familie.

```c++
#include <iostream> // Standard Library

#include <SFML/Window.hpp> // SFML basic library, zur Fenster erstellung
#include <SFML/Graphics.hpp> // SFML Modul zum Grafic rendering
#include <SFML/Sound.hpp> // SFML Modul zur Audio Wiedergabe

#include "Calc.hpp" // Eigene Library, löst die 
```

Beginn des eigentlichen Programmes ohne argumenten übergabe durch die Aufruferin.
Einige richtgrößen werden deklariert.

> In der main definiert, denn Globale Variablen sind Böse !!

```c++
int main() {
    const int keys_x = 4;
    const int keys_y = 4;
    const int keys_with = 80;
    const int keys_hight = 100;
    const int keys_gap = 5;

    const int input_with = 340;
    const int input_hight = 40;
    const int output_with = input_with;
    const int output_hight = 60;
```

Der VideoMode definert das Renderverhalten, für all unsere Zwecke nehmen ihn wir in als default. Die ersten beiden Argumente geben die Fenster Größe in Pixel an, hier etwas umständlich aus den richt größen errechnet, eine gängige alternative wäre (1920, 1080) das entspricht Full-HD. Der String danach ist der Fenster Titel.

```c++
    
    sf::RenderWindow window(sf::VideoMode((keys_with + keys_gap) * keys_x, (keys_hight + keys_gap) * keys_y + output_hight + input_hight), "Calc"); //Erstellen der Fenster klasse.
    
```

Nun werden die benötigten variablend deklariert und Klassen instanziert.

```c++
    bool show_clear = true; // Sollen leere Text felder als solche gerenderd werden

    sf::RectangleShape keys[keys_x][keys_y]; // Die einzelen Tasten in einer x,y Matirx
    sf::Text key_lables[keys_x][keys_y]; // Die Beschriftung für die einzelnen Tasten.
    sf::Text text_out; // Ausgabe string für das ergebniss
    std::string term = "";
    sf::Text text_in; // Speicher String für die Eingabe
    std::string result = "";
    
    sf::Font font; // Schriftart deklariert
    font.loadFromFile("default.ttf"); // Und definert. - Hier jede beliebige .ttf Schrift art verwerdbar.

    sf::SoundBuffer autsch; // Bit buffer zum laden der Sound-Datei.
    autsch.loadFromFile("autsch.WAV"); // Laden der Sound Datei
    sf::Sound sound; // Instanzierung der Klasse Sound
    sound.setBuffer(autsch); // Bereitstellung der daten des SoundBuffers.

```

Nun werden allen Objekten ihre eigenschaften zugewiesen, die sie im verlauf des Programmes haben sollen.

> Keine Angst : wir können (und werden) sie im später noch dynamisch anpassen

```c++

    // Text rendering, nahezu indentich für Gleichung und Ergebinss
    text_in.setFillColor(sf::Color::White); // Schrift Farbe
    text_in.setFont(font); // Schriftart
    text_in.setPosition(0, output_hight); // Pesition (0, 60)
    text_out.setFillColor(sf::Color::White); // Schrift Farbe
    text_out.setFont(font); // Schriftart
    text_out.setCharacterSize(output_hight * 0.9); // Schriftgröße
    text_out.setStyle(sf::Text::Bold | sf::Text::Underlined); // Style Modifiers : Fett und Unterstrichen

    // Kommen wir zu den Tasten
    for (int i = 0; i < keys_x; i++) { // Diesen Beiden Schleifen iterieren durch Zeilen
        for (int j = 0; j < keys_y; j++) { // und Spalten der Tasten (und Lable) Matrix

            keys[i][j].setPosition(5 + (keys_gap + keys_with) * i, (input_hight + output_hight) + ((keys_gap + keys_hight) * j)); // Alle Tasten werden in mit einem Regelmäßigen offset, in einem gitter angeordnet.
            key_lables[i][j].setPosition((keys_with / 2.5) + (keys_gap + keys_with) * i,(keys_hight / 3) + (input_hight + output_hight) + ((keys_gap + keys_hight) * j)); //das selbe passiert mit den zu geordneten Lables

            if ((i + j) % 2) { // durch diese Kleine Abfrage erhalten wir ein Schachbrett Muster
                keys[i][j].setFillColor(sf::Color::Yellow); // aus Gelb
            }
            else {
                keys[i][j].setFillColor(sf::Color::Magenta); // und P!nk.
            }

            key_lables[i][j].setFillColor(sf::Color::Black); // Textfarbe
            key_lables[i][j].setCharacterSize(keys_hight / 3); // Schriftgröße
            key_lables[i][j].setFont(font); // Schriftart
            keys[i][j].setSize(sf::Vector2f{keys_with, keys_hight}); // Tastengröße
        }
    }

    // Alle Tasten erhalten ihre Individuelle Beschriftung
    key_lables[0][0].setString("7");
    key_lables[0][1].setString("4");
    key_lables[0][2].setString("1");
    ...
    key_lables[3][2].setString("-");
    key_lables[3][3].setString("+");
```

**Es ist ein Fenster!**  
Endlich ist der Augenblick gekommen, an dem alle Vorbereitungen getroffen sind und der "Echte" Programm ablauf beginnt.

```c++
    while (window.isOpen()){ // Solange das Fenster Geöffnet ist.
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) { // Wurde das "X" gedrückt ?
                window.close(); // Dann Schließen
            }
        }

        

```

Jetzt gehts ans eingemachte, und wir lassen die Nutzerinnen min unserem Programm interagieren.
        
```c++

        sf::Vector2i localPosition;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { // Wenn die Nutzerin Klickt
            localPosition = sf::Mouse::getPosition(window); // wird gespeichert Wo.
        }
            
        show_clear = false; // Nichts zu Sehen ist unpraktisch, wir wollen den alten Text erstmal behalten.

        if (keys[0][3].getGlobalBounds().contains(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y)) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) { // Diese Abfrage ist etwas sperrig, aber trotzdem recht simpel. Es wird geprüft, ob die Nutzerin diese Taste an geklickt ODER das Äquivalent auf der Tastaur gedrückt hat. - Hier Gleich bzw. Enter

            if (term != "") { // Wenn ein Term eingegeben Wurde Wird er Gelößt und zurück gesetzt.
                result = "=";
                result += std::to_string(calc::basic(term));
                term = "";
                sound.play(); // Und unser Grässlicher Sound "autsch" ab gespielt
                continue;
            }
                
        }

        if (keys[0][0].getGlobalBounds().contains(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y)) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7)) {
            term += "7"; // alle andere Tasten ergeben nur das zugehörige zeichen
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7)) {
                //Wait
            }
            continue;
        }
        if (keys[0][1].getGlobalBounds().contains(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y)) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4)) {
            term += "4";
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4)) {
                //Wait
            }
            continue;
        }

        ...

        if (keys[3][3].getGlobalBounds().contains(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y)) || sf::Keyboard::isKeyPressed(sf::Keyboard::Add)) {
            term += "+";
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Add)) {
                //Wait
            }
            continue;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace)) {
            term = "";
            show_clear = true;
            while (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace)) {
                // wait
            }
        }

        if (term != "" || show_clear) { // Wenn es einen Term gibt, oder Leer gerendert werden Soll, 
            text_in.setString(term); // wird der Ensprechende Text gerenderd.
            text_in.setCharacterSize((input_hight * 0.8)/(1 + (0.02 * term.length()))); // Wenn der Text lang wird, wird er kleiner, damit mehr hin passt.
        }
        text_out.setString(result);
        text_out.setCharacterSize((output_hight * 0.99) / (1 + (0.04 * result.length()))); // Selbes für das ergebniss

```

Zu guter letzt, werden Alle elementen auf ein leeres Fenster gerendert und dann Angezeigt.

```c++
        window.clear(); // das Leere Fenster wird bereit gestellt
        for (int i = 0; i < keys_x; i++) { // Mal wieder
            for (int j = 0; j < keys_y; j++) { // wird über die Matrix
                window.draw(keys[i][j]); // iteriert und jede Taste
                window.draw(key_lables[i][j]); // samt beschriftung gerendert.
            }
        }
        window.draw(text_in); // Term und
        window.draw(text_out); // Ergebniss ebenfalls
        
        window.display(); // Nun werden die Änderungen der Nutzerin angezeigt.

        window.setSize(sf::Vector2u{(keys_with + keys_gap) * keys_x, (keys_hight + keys_gap) * keys_y + output_hight + input_hight});
        // Zu guter letzt wird die Fenstergröße zurückgesetzt.
    }

	return 0; // Geschafft !!
```