#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char *filename, SDL_Rect src, SDL_Rect dst){
    texture = TextureManager::loadTexture(filename);

    srcRect = src;
    dstRect = dst;
}

void GameObject::update() {
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_A])
    {
        dstRect.x--;
    }
    if (state[SDL_SCANCODE_D])
    {
        dstRect.x++;
    }
    if (state[SDL_SCANCODE_W])
    {
        dstRect.y--;;
    }
    if (state[SDL_SCANCODE_S])
    {
        dstRect.y++;
    }
}

void GameObject::render() {
    SDL_RenderCopy(Game::renderer, texture, &srcRect, &dstRect);
}


