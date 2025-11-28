#pragma once
#include "FrameBuffer.h"
#include "Renderer.h"

class Engine {
public:
    Engine(int w, int h);

    void run(); // simple single-frame example

private:
    FrameBuffer fb;
};
