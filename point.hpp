/**
 * @file point.hpp
 * @brief Point definition.
 */

#ifndef ARS_PONTO_HPP
#define ARS_PONTO_HPP

namespace ars {

    /**
     * @brief A 4D point.
     * @author André Ramaciotti da Silva
     * @date 2014-05-01
     *
     * This class represents a point with four dimensions.  The last one (w) is
     * always 1.
     */
    class Point {
    public:
        double x, y, z, w;

        /**
         * Creates a new point with coordinates (0, 0, 0, 1).
         */
        Point();

        /**
         * Creates a new point with coordinates (x, y, 0, 1).
         */
        Point(double x, double y);

        /**
         * Creates a new point with coordinates (x, y, z, 1).
         */
        Point(double x, double y, double z);

        /**
         * Creates a new point with coordinates (x, y, z, w).
         */
        Point(double x, double y, double z, double w);
    };

    /**
     * Compares two points for equality.
     */
    bool operator ==(const Point& lhs, const Point& rhs);
}

#endif
