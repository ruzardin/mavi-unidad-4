#include "Adaptacion.h"

Adaptacion::Adaptacion() {

	//Cargamos la textura del archivo
	textura.loadFromFile("Unidad4_Assets\\fondo.jpg");
	sprite.setTexture(textura);

	//Creamos la ventana
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), " Adaptacion ");


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

			case sf::Event::Resized:
				// Asegurarnos de que el tamaño de la ventana no sea menor a 100x100 ni mayor a 1000x1000
				int newWidth = evt.size.width;
				int newHeight = evt.size.height;

				// Limitar el tamaño de la ventana
				if (newWidth < MIN_SIZE) newWidth = MIN_SIZE;
				if (newWidth > MAX_SIZE) newWidth = MAX_SIZE;
				if (newHeight < MIN_SIZE) newHeight = MIN_SIZE;
				if (newHeight > MAX_SIZE) newHeight = MAX_SIZE;

				// Establecer el nuevo tamaño de la ventana
				App.setSize(sf::Vector2u(newWidth, newHeight));
				break;

			}
			if (Keyboard::isKeyPressed(Keyboard::Escape) == true) {
				App.close();
			}


			App.clear();
			App.draw(sprite);
			App.display();


		}
	}
}
