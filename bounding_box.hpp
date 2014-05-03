/**
 * @file bounding_box.hpp
 * @brief BoundingBox definition.
 */

#ifndef ARS_BOUNDING_BOX_HPP
#define ARS_BOUNDING_BOX_HPP

#include "point.hpp"

#include <vector>

namespace ars {

    /**
     * @brief A (logical) bounding box.
     * @author André Ramaciotti da Silva
     * @date 2014-05-01
     *
     * A logical bounding box, used to delimit a graphical object.  It's only
     * logical, meaning that it doesn't appear in the world.  If one wants to
     * render it, an object should be made with its coordinates.
     *
     * @see ars::Object
     * @see ars::boundingBoxToObject
     */
    class BoundingBox {
    public:
        Point min, max;

        /**
         * The center point of this bounding box.
         */
        Point center() const;
    };
}

#endif
