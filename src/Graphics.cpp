#include "Graphics.h"

#include "SDL2/SDL.h"
#include <stdexcept>

Graphics::Graphics(std::string title, int width, int height) {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw std::runtime_error(std::string("SDL failed to initialize. SDL error = ") + SDL_GetError());
    }
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
    if(window == NULL) {
        SDL_Quit();
        throw std::runtime_error(std::string("SDL failed to initialize. SDL error = ") + SDL_GetError());
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        throw std::runtime_error(std::string("Renderer could not be created! SDL Error: %s\n") + SDL_GetError());
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

void Graphics::flip() {
    SDL_RenderPresent(renderer);
}
