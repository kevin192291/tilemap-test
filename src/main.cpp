// An SFML 3 program: each frame handles the window's events, then clears, draws and displays.
#include <SFML/Graphics.hpp>
#include "TileMap.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML Window");
    window.setFramerateLimit(60);

    sf::CircleShape circle(50.f);
    circle.setOrigin({50.f, 50.f});
    circle.setPosition({400.f, 300.f});
    circle.setFillColor(sf::Color(100, 200, 120));

    const std::vector<int> level = {11, 12, 13, 14, 15, 16, 17, 18}; // 4 wide, 2 high; -1 leaves a gap
    TileMap map;
    if (!map.load("assets/tileset.gif", {16, 16}, level, {4, 2}))
    {
        return 1;
    }

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (const auto* key = event->getIf<sf::Event::KeyPressed>())
            {
                if (key->code == sf::Keyboard::Key::Escape)
                {
                    window.close();
                }
            }
        }
        
        window.clear(sf::Color(30, 30, 40));
        window.draw(circle);
        window.draw(map);
        window.display();
    }
}
