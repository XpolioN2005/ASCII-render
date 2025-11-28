#include "headers/FrameBuffer.h"
#include <stdexcept>

FrameBuffer::FrameBuffer(int w, int h)
    : w(w), h(h),
      lightBuffer(w * h, 0),
      glyphBuffer(w * h, ' ')
{
}

int FrameBuffer::width() const { return w; }
int FrameBuffer::height() const { return h; }

void FrameBuffer::clear(uint8_t value) {
    std::fill(lightBuffer.begin(), lightBuffer.end(), value);
    std::fill(glyphBuffer.begin(), glyphBuffer.end(), ' ');
}

uint8_t& FrameBuffer::light(int x, int y) {
    return lightBuffer[y * w + x];
}

const uint8_t& FrameBuffer::light(int x, int y) const {
    return lightBuffer[y * w + x];
}

char& FrameBuffer::glyph(int x, int y) {
    return glyphBuffer[y * w + x];
}

const char& FrameBuffer::glyph(int x, int y) const {
    return glyphBuffer[y * w + x];
}
