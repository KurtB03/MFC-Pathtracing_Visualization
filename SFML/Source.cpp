#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Calc.hpp"

// Muss im Release mode Compiliert werden !!!!!
// Dependency : OpenAL (für Sound)

int main() {
    //std::cout << "Hello" << std::endl;

    const int keys_x = 4;
    const int keys_y = 4;
    const int keys_with = 80;
    const int keys_hight = 100;
    const int keys_gap = 5;

    const int input_with = 340;
    const int input_hight = 40;
    const int output_with = input_with;
    const int output_hight = 60;

    //bool block_input = false;
    //bool pause = false;
    bool show_clear = true;

    sf::RenderWindow window(sf::VideoMode((keys_with + keys_gap) * keys_x, (keys_hight + keys_gap) * keys_y + output_hight + input_hight), "Calc");

    sf::RectangleShape keys[keys_x][keys_y];
    //sf::
    sf::Text key_lables[keys_x][keys_y];
    //sf::RectangleShape display_out;
    sf::Text text_out;
    //sf::RectangleShape display_in;
    sf::Text text_in;
    sf::Font font;
    font.loadFromFile("default.ttf");

    //sound
    sf::SoundBuffer autsch;
    autsch.loadFromFile("autsch.WAV");
    sf::Sound sound;
    sound.setBuffer(autsch);


    std::string term = "";
    std::string result = "";

    window.setKeyRepeatEnabled(false);

    //display_in.setSize(sf::Vector2f{ input_with, input_hight });
    text_in.setFillColor(sf::Color::White);
    text_in.setFont(font);
    text_in.setPosition(0, output_hight);
    //display_out.setSize(sf::Vector2f{output_with, output_hight });
    text_out.setFillColor(sf::Color::White);
    text_out.setFont(font);
    text_out.setCharacterSize(output_hight * 0.9);
    text_out.setStyle(sf::Text::Bold | sf::Text::Underlined);

    for (int i = 0; i < keys_x; i++) {
        for (int j = 0; j < keys_y; j++) {
            keys[i][j].setPosition(5 + (keys_gap + keys_with) * i, (input_hight + output_hight) + ((keys_gap + keys_hight) * j));
            key_lables[i][j].setPosition((keys_with / 2.5) + (keys_gap + keys_with) * i,(keys_hight / 3) + (input_hight + output_hight) + ((keys_gap + keys_hight) * j));
            if ((i + j) % 2) {
                keys[i][j].setFillColor(sf::Color::Yellow);
            }
            else {
                keys[i][j].setFillColor(sf::Color::Magenta);
            }
            key_lables[i][j].setFillColor(sf::Color::Black);
            key_lables[i][j].setCharacterSize(keys_hight / 3);
            key_lables[i][j].setFont(font);
            keys[i][j].setSize(sf::Vector2f{keys_with, keys_hight});
        }
    }

    key_lables[0][0].setString("7");
    key_lables[0][1].setString("4");
    key_lables[0][2].setString("1");
    key_lables[0][3].setString("=");
    key_lables[1][0].setString("8");
    key_lables[1][1].setString("5");
    key_lables[1][2].setString("2");
    key_lables[1][3].setString("0");
    key_lables[2][0].setString("9");
    key_lables[2][1].setString("6");
    key_lables[2][2].setString("3");
    key_lables[2][3].setString(".");
    key_lables[3][0].setString("/");
    key_lables[3][1].setString("*");
    key_lables[3][2].setString("-");
    key_lables[3][3].setString("+");

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            /*if (event.type == sf::Event::LostFocus) {
                pause = true;
            }
            if (event.type == sf::Event::GainedFocus) {
                pause = false;
            }*/

        }

        //if (pause) {
        //    continue;
        //}



        sf::Vector2i localPosition;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            localPosition = sf::Mouse::getPosition(window);
        }
            
        show_clear = false;

        if (keys[0][3].getGlobalBounds().contains(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y)) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                //keys[0][3].setFillColor(sf::Color::Cyan);
            if (term != "") {
                result = "=";
                result += std::to_string(calc::basic(term));
                term = "";
                sound.play();
                continue;
            }
                
        }

        if (keys[0][0].getGlobalBounds().contains(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y)) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7)) {
            term += "7";
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
        if (keys[0][2].getGlobalBounds().contains(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y)) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)) {
            term += "1";
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)) {
                //Wait
            }
            continue;
        }
        // Skipped [0][3] cause special function
        if (keys[1][0].getGlobalBounds().contains(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y)) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8)) {
            term += "8";
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8)) {
                //Wait
            }
            continue;
        }
        if (keys[1][1].getGlobalBounds().contains(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y)) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5)) {
            term += "5";
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5)) {
                //Wait
            }
            continue;
        }
        if (keys[1][2].getGlobalBounds().contains(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y)) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) {
            term += "2";
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) {
                //Wait
            }
            continue;
        }
        if (keys[1][3].getGlobalBounds().contains(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y)) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0)) {
            term += "0";
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0)) {
                //Wait
            }
            continue;
        }
        if (keys[2][0].getGlobalBounds().contains(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y)) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9)) {
            term += "9";
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9)) {
                //Wait
            }
            continue;
        }
        if (keys[2][1].getGlobalBounds().contains(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y)) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6)) {
            term += "6";
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6)) {
                //Wait
            }
            continue;
        }
        if (keys[2][2].getGlobalBounds().contains(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y)) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3)) {
            term += "3";
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3)) {
                //Wait
            }
            continue;
        }
        if (keys[2][3].getGlobalBounds().contains(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y)) || sf::Keyboard::isKeyPressed(sf::Keyboard::Period)) {
            term += ".";
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Period)) {
                //Wait
            }
            continue;
        }
        if (keys[3][0].getGlobalBounds().contains(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y)) || sf::Keyboard::isKeyPressed(sf::Keyboard::Divide)) {
            term += "/";
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Divide)) {
                //Wait
            }
            continue;
        }
        if (keys[3][1].getGlobalBounds().contains(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y)) || sf::Keyboard::isKeyPressed(sf::Keyboard::Multiply)) {
            term += "*";
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Multiply)) {
                //Wait
            }
            continue;
        }
        if (keys[3][2].getGlobalBounds().contains(static_cast<float>(localPosition.x), static_cast<float>(localPosition.y)) || sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract)) {
            term += "-";
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract)) {
                //Wait
            }
            continue;
        }
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

        if (term != "" || show_clear) {
            text_in.setString(term);
            text_in.setCharacterSize((input_hight * 0.8)/(1 + (0.02 * term.length())));
        }
        text_out.setString(result);
        text_out.setCharacterSize((output_hight * 0.99) / (1 + (0.04 * result.length())));

        window.clear();
        for (int i = 0; i < keys_x; i++) {
            for (int j = 0; j < keys_y; j++) {
                window.draw(keys[i][j]);
                window.draw(key_lables[i][j]);   
            }
        }
        window.draw(text_in);
        window.draw(text_out);
        
        window.display();
        window.setSize(sf::Vector2u{(keys_with + keys_gap) * keys_x, (keys_hight + keys_gap) * keys_y + output_hight + input_hight});
    }

	return 0;
}