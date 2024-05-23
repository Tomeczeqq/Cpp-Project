#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;

bool buttonPressed(int curr) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 100);
    int random = dis(gen);
    if (curr < random) {
        cout << "Your result is: " << 100 - curr << "\n";
    }
    return curr >= random;
}

bool isInsideCircle(sf::Vector2f point, sf::Vector2f circleCenter, float radius) {
    float distance = sqrt(pow(point.x - circleCenter.x, 2) + pow(point.y - circleCenter.y, 2));
    return distance <= radius;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 550), "Game by Tomasz Janeczko");
    float radius = 220.f;
    sf::CircleShape shape(radius);
    shape.setOrigin(radius, radius);
    shape.setPosition(window.getSize().x / 2, window.getSize().y - radius - 10);
    shape.setFillColor(sf::Color::Green);
    sf::Vector2f shapePos = shape.getPosition();

    int current = 100, highest = 0;
    sf::Font font;
    if (!font.loadFromFile("D:/SFML-2.6.1/examples/shader/resources/tuffy.ttf")) {
        cerr << "Font doesn't load\n";
        return -1;
    }
    sf::Text highestText;
    highestText.setFont(font);
    highestText.setCharacterSize(27);
    highestText.setFillColor(sf::Color::Blue);
    highestText.setPosition(window.getSize().x / 4 + 25, 10);
    highestText.setStyle(sf::Text::Bold);
    sf::Text currentText;
    currentText.setFont(font);
    currentText.setCharacterSize(34);
    currentText.setFillColor(sf::Color::Red);
    currentText.setPosition(window.getSize().x / 4 , 50);
    currentText.setStyle(sf::Text::Bold);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                if (isInsideCircle(mousePos, shapePos, radius)) {
                    if (buttonPressed(current)) {
                        current--;
                    }
                    else {
                        highest = max(100 - current, highest);
                        current = 100;
                    }
                }
            }
        }
        highestText.setString("Highest Result: " + to_string(highest));
        currentText.setString("Current Result: " + to_string(100 - current));
        window.clear();
        window.draw(highestText);
        window.draw(currentText);
        window.draw(shape);
        window.display();
    }
    return 0;
}