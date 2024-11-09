#include "Crosshair.h"

Crosshair::Crosshair() {

	//Cargamos la textura del archivo
	textura.loadFromFile("Unidad4_Assets\\crosshair.png");

	//Cargamos el material del sprite
	sprite.setTexture(textura);

	//Creamos la ventana
	sf::RenderWindow App(sf::VideoMode(800, 800, 32), " Crosshair ");

	//Calcula el origen al sacar la mitad del tamanio total del spite 
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);

	sprite.setScale(1.5, 1.5);
	sprite.setPosition(400, 400);


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
		}

		App.draw(sprite);

		App.display();


	}
}