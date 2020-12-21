#pragma once

#include "Game.h"

class TextureManager
{
public:
    static SDL_Texture* loadTexture(const char* filename);
    static SDL_Rect createRect(int h = 32, int w = 32, int x = 0,int y = 0);
    static void draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dst);
};