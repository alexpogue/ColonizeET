#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
private:
    // don't copy window or renderer pointers.
    SDL_Window* window;
    SDL_Renderer* renderer;
    Graphics(const Graphics& other);
    Graphics& operator=(const Graphics&);

public:
    Graphics(std::string, int, int);
    ~Graphics();
    void rectangle(int x, int y, int width, int height, int r, int g, int b);
    void clear(int r, int g, int b);
    void flip();
};

#endif
