#include "Enemigo.h"

Enemigo::Enemigo(const Texture& texture, Vector2f position, float scale, float lifetime) 
    : lifetime(lifetime) {
        sprite.setTexture(texture);
        sprite.setPosition(position);
        sprite.setScale(scale, scale);
    }

bool Enemigo::isClicked(Vector2i mousePos) const {
    return sprite.getGlobalBounds().contains(static_cast < Vector2f>(mousePos));
}

bool Enemigo::isExpired() const {
    return lifetime <= 0;
}