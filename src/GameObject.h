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
    GameObject(const char *filename, SDL_Renderer *rend);
    ~GameObject();
    void update();
    void render();
};
