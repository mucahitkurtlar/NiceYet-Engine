#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

SDL_Renderer *Game::renderer = nullptr;

GameObject *backgrnd;
GameObject *enemy;
GameObject *ship;

void Game::init(const char *title, int pos_x, int pos_y, int w, int h, bool isfullscreen) {
    int flags = 0;
    if (isfullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, pos_x, pos_y, w, h, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }
        
        isrunning = true;
    } else
    {
        isrunning = false;
    }


    backgrnd = new GameObject("Assets/backgrounds/desert-backgorund.bmp", TextureManager::createRect(272, 256), TextureManager::createRect(544, 512, 0, 0));
    enemy = new GameObject("Assets/spritesheets/enemy-big.bmp", TextureManager::createRect(), TextureManager::createRect(64, 64, 0, 0));
    ship = new GameObject("Assets/spritesheets/ship.bmp", TextureManager::createRect(24, 16, 0, 0), TextureManager::createRect(24, 16, 10, 70));
    
}
void Game::handleevents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isrunning = false;
        break;
    
    default:
        break;
    }
}
void Game::update() {
    enemy->update();
    ship->update();
}
void Game::render() {
    SDL_RenderClear(renderer);
    backgrnd->render();
    enemy->render();
    ship->render();
    SDL_RenderPresent(renderer);
}
void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
bool Game::running() {
    return isrunning;
}
void Game::setsetartingtick() {
    startingtick = SDL_GetTicks();
}
void Game::fitfps(int fpslimit) {
    if ((1000 / fpslimit) > SDL_GetTicks() - startingtick)
    {
        SDL_Delay(1000 /fpslimit - (SDL_GetTicks() - startingtick));
    }
}