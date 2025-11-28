#pragma once
#include <vector>
#include <cstdint>

class FrameBuffer {
public:
    FrameBuffer(int w, int h);

    int width() const;
    int height() const;

    void clear(uint8_t value);

    uint8_t& light(int x, int y);
    const uint8_t& light(int x, int y) const;

    char& glyph(int x, int y);
    const char& glyph(int x, int y) const;


private:
    int w;
    int h;

    std::vector<uint8_t> lightBuffer; 
    std::vector<char> glyphBuffer;
};
