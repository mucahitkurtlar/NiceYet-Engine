#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char *filename, SDL_Renderer *rend, SDL_Rect src, SDL_Rect dst){
    renderer = rend;
    texture = TextureManager::loadTexture(filename, rend);

    srcRect = src;
    dstRect = dst;
}

void GameObject::update() {
    dstRect.x++;
}

void GameObject::render() {
    SDL_RenderCopy(renderer, texture, &srcRect, &dstRect);
}


