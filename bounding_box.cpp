#include "bounding_box.hpp"

#include "point.hpp"

#include <vector>

namespace ars {

    Point BoundingBox::center() const {
        double x = (min.x + max.x) / 2;
        double y = (min.y + max.y) / 2;

        return Point(x, y);
    }

    void BoundingBox::update(const std::vector<Point>& points) {
        min = points.front();
        max = points.front();

        for (auto it = std::begin(points); it != std::end(points); ++it) {
            min.x = std::min(min.x, it->x);
            min.y = std::min(min.y, it->y);

            max.x = std::max(max.x, it->x);
            max.y = std::max(max.y, it->y);
        }
    }

    bool BoundingBox::contains(const Point& point) const {
        return point.x >= min.x && point.x <= max.x
            && point.y >= min.y && point.y <= max.y;
    }

    bool operator ==(const BoundingBox& lhs, const BoundingBox& rhs) {
        return lhs.min == rhs.min && lhs.max == rhs.max;
    }

}
