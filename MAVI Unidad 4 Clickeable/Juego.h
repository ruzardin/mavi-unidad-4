#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Enemigo.h"
#include "Crosshair.h"

using namespace sf;
using namespace std;



class Juego {
private:
    RenderWindow App;
    Texture enemyTexture;
    Texture crosshairTexture;
    Crosshair* crosshair;
    vector<Enemigo> enemies;
    int defeatedEnemies;
    const int maxEnemies;

public:
    Juego();
    ~Juego();
    void run();

private:
    void processEvents();
    void update();
    void render();
    void handleMouseClick(Vector2i mousePos);
};