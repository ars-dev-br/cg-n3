/**
 * @file free_functions.hpp
 * @brief Functions definitions that don't belong to this project classes.
 */

#ifndef ARS_FREE_FUNCTIONS_HPP
#define ARS_FREE_FUNCTIONS_HPP

#include "bounding_box.hpp"
#include "object.hpp"

/**
 * Personal namespace for this project.
 */
namespace ars {

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

}

#endif
