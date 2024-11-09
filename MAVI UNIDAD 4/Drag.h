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

//La l�nea Sprite* selectedSprite = nullptr; define un puntero a un objeto de tipo Sprite, llamado selectedSprite
//En este contexto, selectedSprite se utiliza para almacenar el puntero al sprite que el usuario selecciona y est� arrastrando. Cuando el usuario hace clic en un sprite, el c�digo asigna la direcci�n de ese sprite a selectedSprite. De esta forma, mientras el usuario arrastra el mouse, podemos mover el sprite seleccionado usando selectedSprite, sin saber de antemano cu�l de los cuatro sprites ser�.
//Cuando se suelta el bot�n del mouse, selectedSprite se vuelve a poner en nullptr, indicando que ning�n sprite est� siendo arrastrado.