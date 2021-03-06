#include "Button.h"

NavMenu::NavMenu(int x, int y) {
    if (!font.loadFromFile("arial.ttf")) {
        // std::cout << "Font Not Found\n";
    }

    navbar.setFillColor(sf::Color(0, 0, 255, 20));
    navbar.setSize(sf::Vector2f(300, 50));
    navbar.setPosition(sf::Vector2f(x, y));

    menu[0].setFont(font);
    menu[0].setCharacterSize(20);
    menu[0].setColor(sf::Color::White);
    menu[0].setString("Save");
    menu[0].setPosition(sf::Vector2f(x + 20, y + 10));

    menu[1].setFont(font);
    menu[1].setCharacterSize(20);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("New map");
    menu[1].setPosition(sf::Vector2f(x + 100, y + 10));

    menu[2].setFont(font);
    menu[2].setCharacterSize(20);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(x + 220, y + 10));

    selected = false;
}

void NavMenu::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 3; i++) {
        window.draw(menu[i]);
    }
    window.draw(navbar);
}

void NavMenu::SelectedItem(int selectedItemIndex, bool selected) {

    menu[selectedItemIndex].setColor(selected ? sf::Color::Red : sf::Color::White);
    
    // if(selected) {
    //     menu[selectedItemIndex].setColor(sf::Color::Red);
    // } else {
    //     menu[selectedItemIndex].setColor(sf::Color::White);
    // }
}

void NavMenu::whichItemSelected(sf::RenderWindow &window) {
    if(sf::IntRect(480, 0, 100, 50).contains(sf::Mouse::getPosition(window))) {
        selectedItemIndex = 0;
        selected = true;
    }
    if(sf::IntRect(480 + 100, 0, 100, 50).contains(sf::Mouse::getPosition(window))) {
        selectedItemIndex = 1;
        selected = true;
    }
    if(sf::IntRect(480 + 200, 0, 100, 50).contains(sf::Mouse::getPosition(window))) {
        selectedItemIndex = 2;
        selected = true;
    }
}

ToolMenu::ToolMenu(int x, int y) {
    if (!font.loadFromFile("arial.ttf")) {
        // std::cout << "Font Not Found\n";
    }

    toolbar.setFillColor(sf::Color(100, 100, 100));
    toolbar.setSize(sf::Vector2f(260, 115));
    toolbar.setPosition(sf::Vector2f(x, y));

    texture[0].loadFromFile("draw.png");
    icon[0].setTexture(texture[0]);
    icon[0].setPosition(sf::Vector2f(x + 30, y + 10));

    tools[0].setFont(font);
    tools[0].setCharacterSize(20);
    tools[0].setColor(sf::Color::White);
    tools[0].setString("Drawing mode");

    texture[1].loadFromFile("remove.png");
    icon[1].setTexture(texture[1]);
    icon[1].setPosition(sf::Vector2f(x + 30, y + 70));

    tools[1].setFont(font);
    tools[1].setCharacterSize(20);
    tools[1].setColor(sf::Color::White);
    tools[1].setString("Removing mode");

    for(int i = 0, delta = 0; i < 2; ++i, delta += 60) {
        tools[i].setPosition(sf::Vector2f(x + 90, y + 15 + delta));
        icon[i].setPosition(sf::Vector2f(x + 30, y + 10 + delta));
    }

    selected = false;
}

void ToolMenu::draw(sf::RenderWindow& window) {
    window.draw(toolbar);
    for (int i = 0; i < 2; i++) {
        window.draw(icon[i]);
        window.draw(tools[i]);
    }
}

void ToolMenu::SelectedItem(int selectedItemIndex, bool selected) {
    if(selected) {
        for (int i = 0; i < 2; i++) {
            tools[i].setColor(sf::Color::White);
        }
        tools[selectedItemIndex].setColor(sf::Color::Blue);
    }
}

void ToolMenu::whichItemSelected(sf::RenderWindow &window) {

    const auto& rect1 = sf::IntRect(530, 90,  200, 35);
    const auto& rect2 = sf::IntRect(530, 150, 200, 35);

    const auto& mousePos = sf::Mouse::getPosition(window));

    if(rect1.contains(mousePos) {
        selectedItemIndex = 0;
        selected = true;
    } else if(rect2.contains(mousePos) {
        selectedItemIndex = 1;
        selected = true;
    }
}

HeroMenu::HeroMenu(int x, int y) {
    if (!font.loadFromFile("arial.ttf")) {
        // std::cout << "Font Not Found\n";
    }

    toolbar.setFillColor(sf::Color(100, 100, 100));
    toolbar.setSize(sf::Vector2f(260, 115));
    toolbar.setPosition(sf::Vector2f(x, y));

    texture[0].loadFromFile("draw.png");
    icon[0].setTexture(texture[0]);
    icon[0].setPosition(sf::Vector2f(x + 30, y + 10));

    tools[0].setFont(font);
    tools[0].setCharacterSize(20);
    tools[0].setColor(sf::Color::White);
    tools[0].setString("Pacman");

    texture[1].loadFromFile("remove.png");
    icon[1].setTexture(texture[1]);
    icon[1].setPosition(sf::Vector2f(x + 30, y + 70));

    tools[1].setFont(font);
    tools[1].setCharacterSize(20);
    tools[1].setColor(sf::Color::White);
    tools[1].setString("Ghost");

    for(int i = 0, delta = 0; i < 2; ++i, delta += 60) {
        tools[i].setPosition(sf::Vector2f(x + 90, y + 15 + delta));
        icon[i].setPosition(sf::Vector2f(x + 30, y + 10 + delta));
    }

    selected = false;
}

void HeroMenu::draw(sf::RenderWindow& window) {
    window.draw(toolbar);
    for (int i = 0; i < 2; i++) {
        window.draw(icon[i]);
        window.draw(tools[i]);
    }
}

void HeroMenu::SelectedItem(int selectedItemIndex, bool selected) {
    if(selected) {
        for (int i = 0; i < 2; i++) {
            tools[i].setColor(sf::Color::White);
        }
        tools[selectedItemIndex].setColor(sf::Color::Blue);
    } else {
        for (int i = 0; i < 2; i++) {
            tools[i].setColor(sf::Color::White);
        }
    }
}

void HeroMenu::whichItemSelected(sf::RenderWindow &window) {
    if(sf::IntRect(530, 220, 200, 35).contains(sf::Mouse::getPosition(window)) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        selectedItemIndex = 0;
        selected = true;
    }
    if(sf::IntRect(530, 280, 200, 35).contains(sf::Mouse::getPosition(window)) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        selectedItemIndex = 1;
        selected = true;
    }
}
