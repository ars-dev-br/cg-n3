/**
 * @file free_functions.hpp
 * @brief Functions definitions that don't belong to this project classes.
 */

#ifndef ARS_FREE_FUNCTIONS_HPP
#define ARS_FREE_FUNCTIONS_HPP

/**
 * Personal namespace for this project.
 */
namespace ars {

    class BoundingBox;
    class Object;
    class Point;

    /**
     * Creates a graphical representation of a bounding box.
     *
     * @param bbox The bounding box to be converted into a graphical object.
     */
    Object boundingBoxToObject(const BoundingBox& bbox);

    /**
     * Creates a graphical object with the reference axes.
     */
    Object referenceAxes();

    /**
     * Calculates the **squared** distance between two points.
     */
    double dist(const Point& lhs, const Point& rhs);

}

#endif
