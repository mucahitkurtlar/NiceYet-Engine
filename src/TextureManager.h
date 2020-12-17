#pragma once

#include "Game.h"

class TextureManager
{
public:
    static SDL_Texture* loadTexture(const char* filename, SDL_Renderer* renderer);
    static SDL_Rect createRect(int h = 32, int w = 32, int x = 0,int y = 0);
};