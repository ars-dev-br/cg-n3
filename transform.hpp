/**
 * @file transform.hpp
 * @brief Transform definition.
 */

#ifndef ARS_TRANSFORM_HPP
#define ARS_TRANSFORM_HPP

namespace ars {

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
    };

}

#endif
