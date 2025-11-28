#include "headers/Engine.h"

Engine::Engine(int w, int h) 
    : fb(w, h)
{
}

void Engine::run() {
    fb.clear(0);

    // simple demo: draw a box
    for (int x = 0; x < fb.width(); x++) {
        fb.glyph(x, 0) = '#';
        fb.glyph(x, fb.height() - 1) = '#';
    }
    for (int y = 0; y < fb.height(); y++) {
        fb.glyph(0, y) = '#';
        fb.glyph(fb.width() - 1, y) = '#';
    }

    // place a glyph inside
    fb.glyph(fb.width() / 2, fb.height() / 2) = '@';

    Renderer::render(fb);
}
