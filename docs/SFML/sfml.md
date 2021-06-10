# SFML

## Die Library(s)

SFML ist eine Sammlung Libraries, die für die 2D spiele entwicklung gemacht wurden.
Die wichtigsten Komponenten sind der Wrapper für Fenster management sowie das Grafik rendering. Außerdem stehen Audio und Netzwerk APIs zu verfügung.

## Installation

[Offizielle Anleitung](https://www.sfml-dev.org/tutorials/2.5/start-vc.php)

![Image Missing](../assets/pictures/1Capture.PNG)

![Image Missing](../assets/pictures/2Capture.PNG)

![Image Missing](../assets/pictures/3Capture.PNG)

![Image Missing](../assets/pictures/4Capture.PNG)

![Image Missing](../assets/pictures/5Capture.PNG)

![Image Missing](../assets/pictures/6Capture.PNG)

![Image Missing](../assets/pictures/7Capture.PNG)

![Image Missing](../assets/pictures/8Capture.PNG)

![Image Missing](../assets/pictures/9Capture.PNG)

![Image Missing](../assets/pictures/10Capture.PNG)

![Image Missing](../assets/pictures/11Capture.PNG)

![Image Missing](../assets/pictures/12Capture.PNG)

![Image Missing](../assets/pictures/Capture16.PNG)

![Image Missing](../assets/pictures/13Capture.PNG)

![Image Missing](../assets/pictures/16Capture.PNG)

![Image Missing](../assets/pictures/14Capture.PNG)

![Image Missing](../assets/pictures/15Capture.PNG)

![Image Missing](../assets/pictures/17Capture.PNG)

![Image Missing](../assets/pictures/18Capture.PNG)

Grüner Kreis Beispielcode :

```c++
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
```
