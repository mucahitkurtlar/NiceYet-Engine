#include "TextureManager.h"

SDL_Texture* TextureManager::loadTexture(const char* filename, SDL_Renderer* renderer) {
    SDL_Surface* tempSurface = SDL_LoadBMP(filename);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return texture;
}

SDL_Rect TextureManager::createRect(int h, int w, int x,int y) {
    SDL_Rect temprect;
    temprect.h = h;
    temprect.w = w;
    temprect.x = x;
    temprect.y = y;

    return temprect;
}