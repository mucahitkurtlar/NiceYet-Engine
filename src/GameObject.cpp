#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char *filename, SDL_Rect src, SDL_Rect dst){
    texture = TextureManager::loadTexture(filename);

    srcRect = src;
    dstRect = dst;
}

void GameObject::update() {
    dstRect.x++;
}

void GameObject::render() {
    SDL_RenderCopy(Game::renderer, texture, &srcRect, &dstRect);
}


