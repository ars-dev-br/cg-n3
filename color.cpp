#include "color.hpp"

namespace ars {

    Color::Color()
        : r(0), g(0), b(0) { }

    Color::Color(float r, float g, float b)
        : r(r), g(g), b(b) { }

    const float* Color::getData() const {
        return reinterpret_cast<const float*>(this);
    }
}
