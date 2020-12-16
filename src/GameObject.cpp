#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char *filename, SDL_Renderer *rend){
    renderer = rend;
    texture = TextureManager::LoadTexture(filename, rend);
}

void GameObject::update() {
    xpos = 0;
    ypos = 0;

    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    dstRect.h = 64;
    dstRect.w = 64;
    dstRect.x = 0;
    dstRect.y = 0;

    /*
    
    srcRect.h = 32;
    srcRect.w = 32;
    destRect.h = 64;
    destRect.w = 64;
    */
}

void GameObject::render() {
    SDL_RenderCopy(renderer, texture, &srcRect, &dstRect);
}