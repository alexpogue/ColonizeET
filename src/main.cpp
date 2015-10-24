#include "SDL2/SDL.h"

#include "Graphics.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(void) {
    Graphics g("Colonize E.T.", SCREEN_WIDTH, SCREEN_HEIGHT);
    g.rectangle(0, 0, 100, 100, 0xFF, 0x00, 0x00);
    g.flip();
    SDL_Delay(2000);

    return 0;
}
