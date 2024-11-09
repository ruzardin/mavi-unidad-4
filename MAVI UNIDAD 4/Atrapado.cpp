#include "Atrapado.h"

Atrapado::Atrapado() {

	//Cargamos la textura del archivo
	texturaCirculo.loadFromFile("Unidad4_Assets\\rcircle.png");
	texturaCuadrado.loadFromFile("Unidad4_Assets\\cuad_yellow.png");

	SpriteCirculo.setTexture(texturaCirculo);
	SpriteCuadrado.setTexture(texturaCuadrado);

	SpriteCirculo.setPosition(400, 440);
	SpriteCirculo.setOrigin(SpriteCirculo.getLocalBounds().width / 2, SpriteCirculo.getLocalBounds().height / 2);

	SpriteCuadrado.setPosition(400, 400);
	SpriteCuadrado.setOrigin(SpriteCuadrado.getLocalBounds().width / 2, SpriteCuadrado.getLocalBounds().height / 2);

	SpriteCuadrado.setScale(200 / (float)texturaCuadrado.getSize().x, 200 / (float)texturaCuadrado.getSize().y);
	SpriteCirculo.setScale(200 / (float)texturaCirculo.getSize().x, 200 / (float)texturaCirculo.getSize().y);
	
	//Creamos la ventana
	sf::RenderWindow App(sf::VideoMode(800, 800, 32), " Atrapado ");


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

			// Mover el cuadrado con las teclas de dirección
			if (!isCircle) {
				if (Keyboard::isKeyPressed(Keyboard::Up)) {
					if (SpriteCuadrado.getPosition().y > 100) {
						SpriteCuadrado.move(0.f, -1.f);
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Down)) {
					if (SpriteCuadrado.getPosition().y < App.getSize().y - SpriteCuadrado.getGlobalBounds().height) {
						SpriteCuadrado.move(0.f, 1.f);
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Left)) {
					if (SpriteCuadrado.getPosition().x > 100) {
						SpriteCuadrado.move(-1.f, 0.f);
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Right)) {
					if (SpriteCuadrado.getPosition().x < App.getSize().x - SpriteCuadrado.getGlobalBounds().width) {
						SpriteCuadrado.move(1.f, 0.f);
					}
				}
			}

			// Cambiar entre cuadrado y círculo al presionar la barra espaciadora
			if (Keyboard::isKeyPressed(Keyboard::Space)) {
				isCircle = !isCircle;
			}

			App.clear();

			if (isCircle) {
				SpriteCirculo.setPosition(SpriteCuadrado.getPosition());
				App.draw(SpriteCirculo);
			}
			else {
				App.draw(SpriteCuadrado);
			}

			App.display();

		}

	}
}
