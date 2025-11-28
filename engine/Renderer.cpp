#include "headers/Renderer.h"
#include <iostream>

void Renderer::render(const FrameBuffer& fb) {
    for (int y = 0; y < fb.height(); y++) {
        for (int x = 0; x < fb.width(); x++) {
            std::cout << fb.glyph(x, y);
        }
        std::cout << "\n";
    }
}
