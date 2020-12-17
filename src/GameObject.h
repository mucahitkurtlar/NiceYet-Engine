#pragma once
#include "Game.h"

class GameObject
{
private:
    int xpos;
    int ypos;
    SDL_Texture *texture;
    SDL_Rect srcRect, dstRect;
    SDL_Renderer *renderer;
public:
    GameObject(const char *filename, SDL_Renderer *rend, SDL_Rect src, SDL_Rect dst);
    ~GameObject();
    void update();
    void render();
};
