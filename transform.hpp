/**
 * @file transform.hpp
 * @brief Transform definition.
 */

#ifndef ARS_TRANSFORM_HPP
#define ARS_TRANSFORM_HPP

namespace ars {

    class Point;

    /**
     * @brief A linear transform.
     * @author André Ramaciotti da Silva
     * @date 2014-05-01
     *
     * A linear transform used to translate, rotate or scale a graphical
     * object.
     */
    class Transform {
    private:
        double matrix[4][4];

    public:
        /**
         * Creates an identity transform.
         */
        Transform();

        /**
         * Gets transform data as an array of doubles.
         */
        const double* getData() const;

        /**
         * Applies the transform to a point.
         */
        Point operator *(const Point& rhs) const;

        /**
         * Composes two transforms (this operation is not commutative).
         */
        Transform operator *(const Transform& rhs) const;

        /**
         * Creates a translation transform.
         * @param translation A point P such that OP is the translation vector.
         */
        static Transform translation(const Point& translation);

        /**
         * Creates a scale transform.
         */
        static Transform scale(double xfactor, double yfactor, double zfactor);

        /**
         * Creates a rotation transform around the x axis.
         */
        static Transform xRotation(double rad);

        /**
         * Creates a rotation transform around the y axis.
         */
        static Transform yRotation(double rad);

        /**
         * Creates a rotation transform around the z axis.
         */
        static Transform zRotation(double rad);
    };

}

#endif
