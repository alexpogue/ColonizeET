#include "SDL2/SDL.h"

#ifdef EMSCRIPTEN
#include "emscripten.h"
#endif

#include "Graphics.h"

static const int SCREEN_WIDTH = 640;
static const int SCREEN_HEIGHT = 480;

static Graphics g("Colonize E.T.", SCREEN_WIDTH, SCREEN_HEIGHT);

void renderFrame() {
    g.clear(0xFF, 0xFF, 0xFF);
    g.rectangle(0, 0, 100, 100, 0xFF, 0x00, 0x00);
    g.flip();
}

int main(void) {
#ifdef EMSCRIPTEN
    emscripten_set_main_loop(renderFrame, 0, 1);
#else
    while(true) {
        renderFrame();
    }
#endif

    return 0;
}
