#include "Graphics.h"

#include "SDL2/SDL.h"
#include <stdexcept>

Graphics::Graphics(std::string title, int width, int height) {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw std::runtime_error(std::string("SDL failed to initialize. SDL error = ") + SDL_GetError());
    }
    if(SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer) == -1) {
        SDL_Quit();
        throw std::runtime_error(std::string("SDL Couldn't create window and renderer. SDL error = ") + SDL_GetError());
    }
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
}

Graphics::~Graphics() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Graphics::rectangle(int x, int y, int width, int height, int r, int g, int b) {
    SDL_Rect dstRect = {x, y, width, height};
    SDL_SetRenderDrawColor(renderer, r, g, b, 0xFF);
    SDL_RenderFillRect(renderer, &dstRect);
}

void Graphics::clear(int r, int g, int b) {
    SDL_SetRenderDrawColor(renderer, r, g, b, 0xFF);
    SDL_RenderClear(renderer);
}

void Graphics::flip() {
    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0xFF, 0xFF);
    // for emscripten, don't call SDL_RenderClear here: WebGL ignores the
    // SDL_RenderPresent and flips automatically after emscripten's main loop.
    // Instead, call Graphics::clear at beginning of main loop.
}
