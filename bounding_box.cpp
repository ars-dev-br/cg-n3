#include "bounding_box.hpp"

#include "point.hpp"

namespace ars {

    Point BoundingBox::center() const {
        double x = (min.x + max.x) / 2;
        double y = (min.y + max.y) / 2;

        return Point(x, y);
    }

}
