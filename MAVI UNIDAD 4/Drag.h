#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

class Drag {
private:
	Texture textura;
	Sprite sprite, sprite2, sprite3, sprite4;
	Sprite* selectedSprite = nullptr;
	Vector2f offset;

	bool dragged = false;
	
public:
	Drag();
};

//La línea Sprite* selectedSprite = nullptr; define un puntero a un objeto de tipo Sprite, llamado selectedSprite
//En este contexto, selectedSprite se utiliza para almacenar el puntero al sprite que el usuario selecciona y está arrastrando. Cuando el usuario hace clic en un sprite, el código asigna la dirección de ese sprite a selectedSprite. De esta forma, mientras el usuario arrastra el mouse, podemos mover el sprite seleccionado usando selectedSprite, sin saber de antemano cuál de los cuatro sprites será.
//Cuando se suelta el botón del mouse, selectedSprite se vuelve a poner en nullptr, indicando que ningún sprite está siendo arrastrado.