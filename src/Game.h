#ifndef Game_h
#define Game_h

#include <iostream>
#include "SDL.h"

class Game {
private:
    Uint32 startingtick;
    bool isrunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
public:
    //Game();
    //~Game();
    void init(const char *title, int pos_x, int pos_y, int w, int h, bool isfullscreen);
    void handleevents();
    void update();
    void render();
    void clean();
    bool running();
    void setsetartingtick();
    void fitfps(int fpslimit);

};

#endif