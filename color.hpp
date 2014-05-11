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

        /**
         * Creates a random RGB color.
         */
        static Color random();
    };

    const Color BLACK(0.0f, 0.0f, 0.0f);
    const Color WHITE(1.0f, 1.0f, 1.0f);

    const Color RED(1.0f, 0.0f, 0.0f);
    const Color GREEN(0.0f, 1.0f, 0.0f);
    const Color BLUE(0.0f, 0.0f, 1.0f);

    const Color YELLOW(1.0f, 1.0f, 0.0f);
    const Color MAGENTA(1.0f, 0.0f, 1.0f);
    const Color CYAN(0.0f, 1.0f, 1.0f);
}

#endif
