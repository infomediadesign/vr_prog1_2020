#include <new>
#include <ctime>

#include "raylib.h"

#include "sprite.hpp"

Sprite::Sprite(Vector2 pos, Texture2D &texture) : pos(pos), texture(texture) {

}
