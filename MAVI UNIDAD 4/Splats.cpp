#include "Splats.h"

Splats::Splats() {

	//Cargamos la textura del archivo
	texturaR.loadFromFile("Unidad4_Assets\\rcircle.png");
	texturaB.loadFromFile("Unidad4_Assets\\rcircleb.png");

	//Vector para almacenar los c�rculos
	std::vector <sf::Sprite> circulos;

	//Creamos la ventana
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), " Splats ");


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

			// Detectar el click izquierdo
			if (evt.type == Event::MouseButtonPressed && evt.mouseButton.button == Mouse::Left) {
				Vector2f mousePos = App.mapPixelToCoords(Mouse::getPosition(App));

				sf::Sprite circuloRojo(texturaR);
				
				//Calcula el origen al sacar la mitad del tamanio total del spite 
				circuloRojo.setOrigin(circuloRojo.getLocalBounds().width / 2, circuloRojo.getLocalBounds().height / 2);

				circuloRojo.setPosition(mousePos);

				circulos.push_back(circuloRojo); // A�adir el c�rculo al vector
			}

			// Detectar el click derecho
			if (evt.type == Event::MouseButtonPressed && evt.mouseButton.button == Mouse::Right) {
				Vector2f mousePos = App.mapPixelToCoords(Mouse::getPosition(App));

				sf::Sprite circuloAzul(texturaB);
				
				//Calcula el origen al sacar la mitad del tamanio total del spite 
				circuloAzul.setOrigin(circuloAzul.getLocalBounds().width / 2, circuloAzul.getLocalBounds().height / 2);

				circuloAzul.setPosition(mousePos);

				circulos.push_back(circuloAzul); // A�adir el c�rculo al vector
			}

		}

		App.clear();

		// Dibujar todos los c�rculos
		for (auto& circulo : circulos) {
			App.draw(circulo);
		}
			//auto&:
			//auto: Este es un tipo que hace que el compilador determine autom�ticamente el tipo de la variable c�rculo en funci�n del tipo de los elementos en el contenedor(en este caso, sf::Sprite).As�, no necesitas especificar expl�citamente el tipo de c�rculo(que ser�a sf::Sprite).
			//& : El ampersand significa que estamos usando una referencia al objeto.Esto es importante porque, al usar referencias, evitamos hacer una copia del objeto, lo que mejora la eficiencia, especialmente cuando se manejan objetos grandes como los sf::Sprite.
		
		App.display();
		

	}
}
