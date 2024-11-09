#include "Drag.h"

Drag::Drag() {

	//Cargamos la textura del archivo
	textura.loadFromFile("Unidad4_Assets\\rcircle.png");

	//Cargamos el material del sprite
	sprite.setTexture(textura);
	sprite2.setTexture(textura);
	sprite3.setTexture(textura);
	sprite4.setTexture(textura);


	//Creamos la ventana
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), " Drag ");

	sprite2.setPosition(670, 0);
	sprite3.setPosition(0, 470);
	sprite4.setPosition(670, 470);

	

	// Loop principal
	while (App.isOpen())
	{
		Event evt;

		while (App.pollEvent(evt)) {
			/////Procesar eventos//////
			switch (evt.type)
			{
				/////Si se cerro la ventana//////
			case sf::Event::Closed:
				App.close();
				break;
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape) == true)
				App.close();

			// Detectar el clic y arrastrar el sprite seleccionado
			if (evt.type == Event::MouseButtonPressed && evt.mouseButton.button == Mouse::Left) {
				Vector2f mousePos = App.mapPixelToCoords(Mouse::getPosition(App));

				// Comprobar si el mouse está sobre algún sprite
				if (sprite.getGlobalBounds().contains(mousePos)) {
					selectedSprite = &sprite;
				}
				else if (sprite2.getGlobalBounds().contains(mousePos)) {
					selectedSprite = &sprite2;
				}
				else if (sprite3.getGlobalBounds().contains(mousePos)) {
					selectedSprite = &sprite3;
				}
				else if (sprite4.getGlobalBounds().contains(mousePos)) {
					selectedSprite = &sprite4;
				}

				if (selectedSprite) {
					dragged = true;
					offset = selectedSprite->getPosition() - mousePos;
				}
			}

			// Soltar el sprite cuando se deja de presionar el botón
			if (evt.type == Event::MouseButtonReleased && evt.mouseButton.button == Mouse::Left) {
				dragged = false;
				selectedSprite = nullptr;
			}

			// Arrastrar el sprite mientras el botón del mouse está presionado
			if (dragged && selectedSprite) {
				Vector2f mousePos = App.mapPixelToCoords(Mouse::getPosition(App));
				selectedSprite->setPosition(mousePos + offset);
			}

		}

		App.clear();

		App.draw(sprite);
		App.draw(sprite2);
		App.draw(sprite3);
		App.draw(sprite4);

		App.display();

	}
}