#include <iostream>
#include "SFML/Graphics.hpp"
#include "Game.h"


using namespace sf;
using namespace std;

void Menu()
{
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "Donkey Kong");
	
	sf::Texture texture;
	if (!texture.loadFromFile("Donkey1.png"))
	{
		std::cout << "load failed " << std::endl;
		system("pause");
	}

	sf::IntRect rectSourceSprite(0, 0, 231, 160);
	sf::Sprite Donkey(texture, rectSourceSprite);
	Donkey.setPosition(300, 200);

	sf::Clock clock;

	
	sf::Font font;
	if (!font.loadFromFile("Fonts/ARCADECLASSIC.ttf"))
		throw("No se pudo cargar la fuente");
	
	Text text;
	text.setFont(font);
	text.setFillColor(sf::Color::Blue);
	text.setCharacterSize(110);
	text.setString("DONKEY KONG");
	text.setPosition(100.f, window.getSize().y / 50);

	Text options;
	options.setFont(font);
	options.setCharacterSize(36);
	options.setString("Press Enter");
	options.setPosition(300,480);

	Text data;
	data.setFont(font);
	data.setCharacterSize(24);
	data.setString("1981  NINTENDO  OF  AMERICA  INC");
	data.setFillColor(sf::Color::Yellow);
	data.setPosition(230, 550);

	Text Exit;
	Exit.setFont(font);
	Exit.setCharacterSize(36);
	Exit.setString("ESC para salir ");
	Exit.setFillColor(Color::Red);
	Exit.setPosition(400, 100);



	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Key::Enter)
					window.close();
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Key::Escape)
					window.close();
			}
		}
		if (clock.getElapsedTime().asSeconds() > 1.f)
		{
			if (rectSourceSprite.left == 100)
				rectSourceSprite.left = 0;
			else
				rectSourceSprite.left += 231;
			Donkey.setTextureRect(rectSourceSprite);
			clock.restart();
		}

		window.clear();
		window.draw(text);
		window.draw(Donkey);
		window.draw(options);
		window.draw(data);
		window.draw(Exit);
		window.display();
		
	}
}

int main(int argc, char* args[])
{
	Menu();
	
	juego * partida1;
	partida1 = new juego(800, 900, "Donkey Kong");

	return 0;
}

	