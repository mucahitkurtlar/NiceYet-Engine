#include "Game.h"
#include "Components.h"

SDL_Renderer *Game::renderer = nullptr;


Manager manager;
auto& enemy(manager.addEntity());

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
 
    enemy.addComponent<PositionComponent>();
    enemy.addComponent<SpriteComponent>("Assets/spritesheets/enemy-big.bmp");
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
    manager.refresh();
    manager.update();
}
void Game::render() {
    SDL_RenderClear(renderer);
    manager.draw();
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