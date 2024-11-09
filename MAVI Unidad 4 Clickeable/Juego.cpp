#include "Juego.h"
#include <iostream>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()


Juego::Juego() : App(VideoMode(800, 600), "Clickale"), defeatedEnemies(0), maxEnemies(5) {
    enemyTexture.loadFromFile("Unidad4_Assets\\et.png");
    crosshairTexture.loadFromFile("Unidad4_Assets\\crosshair.png");
    crosshair = new Crosshair(crosshairTexture);

    App.setFramerateLimit(60);
    srand(static_cast<unsigned>(time(0)));  // Inicializa el generador aleatorio

    Cursor cursor;
    if (cursor.loadFromSystem(sf::Cursor::Arrow)) {
        App.setMouseCursor(cursor);
    }
}

Juego::~Juego() {
    delete crosshair;
}

void Juego::run() {
    App.setMouseCursorVisible(false);
    while (App.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Juego::processEvents() {
    Event event;
    while (App.pollEvent(event)) {
        if (event.type == Event::Closed)
            App.close();
        if (event.type == Event::MouseButtonPressed && event.mouseButton.button ==Mouse::Left) {
            handleMouseClick(Mouse::getPosition(App));
        }
    }
}

void Juego::update() {

    crosshair->updatePosition(Mouse::getPosition(App));

    // Generar enemigo aleatoriamente
    if (enemies.size() < maxEnemies && rand() % 100 < 20) {
        Vector2f pos(static_cast<float>(rand() % App.getSize().x), static_cast<float>(rand() % App.getSize().y));
        enemies.push_back(Enemigo(enemyTexture, pos, 0.05f, 1.0f));  // Escala enemigo y tiempo de vida
    }

    for (auto i = enemies.begin(); i != enemies.end();) {
        i->lifetime -= 1.0f / 60.0f;  // Asume 60 FPS, reduce en ~0.016s por cuadro
        if (i->isExpired()) {
            i = enemies.erase(i);  // Elimina el enemigo si ha expirado
        }
        else {
            ++i;
        }
    }
}

void Juego::render() {
    App.clear();
   

    for (const auto& enemy : enemies)
        App.draw(enemy.sprite);

    App.draw(crosshair->sprite);
    App.display();
    App.setMouseCursorVisible(false);
}

void Juego::handleMouseClick( ::Vector2i mousePos) {
    for (auto i = enemies.begin(); i != enemies.end();) {
        if (i->isClicked(mousePos)) {
            i = enemies.erase(i);  // Elimina enemigo clickeado
            defeatedEnemies++;

            if (defeatedEnemies >= maxEnemies) {
                App.close();
                cout << "¡Ganaste! " << endl;
                return;
            }
        }
        else {
            ++i;
        }
    }
}