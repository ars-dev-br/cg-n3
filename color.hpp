/**
 * @file color.hpp
 * @brief Color definition.
 */

#ifndef ARS_COLOR_HPP
#define ARS_COLOR_HPP

namespace ars {

    /**
     * @brief A RGB color.
     * @author André Ramaciotti da Silva
     * @date 2014-05-01
     *
     * Represents a color with red, green and blue components.
     */
    class Color {
    public:
        float r, g, b;

        /**
         * Creates a color object representing black (0, 0, 0).
         */
        Color();

        /**
         * Creates a color object with the specified color (r, g, b).
         */
        Color(float r, float g, float b);

        /**
         * Returns the color as an array of floats
         */
        const float* getData() const;
    };

    const Color RED = Color(1.0f, 0.0f, 0.0f);
    const Color GREEN = Color(0.0f, 1.0f, 0.0f);
    const Color BLUE = Color(0.0f, 0.0f, 1.0f);

}

#endif
