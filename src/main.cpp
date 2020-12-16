#include "Game.h"

#define FPS_LIMIT 30
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

Game *game = nullptr;

int main(int argc, char const *argv[]) {
    game = new Game();
    game->init("NiceYet Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false);

    Uint32 start_tick;
    while (game->running())
    {
        start_tick = SDL_GetTicks();
        game->handleevents();
        game->update();
        game->render();
        if ((1000 / FPS_LIMIT) > SDL_GetTicks() - start_tick)
        {
            SDL_Delay(1000 /FPS_LIMIT - (SDL_GetTicks() - start_tick));
        }
    }

    game->clean();
    
    return 0;
}
