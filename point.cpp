#include "point.hpp"

namespace ars {

    Point::Point()
        : x(0), y(0), z(0), w(1) { }

    Point::Point(double x, double y)
        : x(x), y(y), z(0), w(1) { }

    Point::Point(double x, double y, double z)
        : x(x), y(y), z(z), w(1) { }

    Point::Point(double x, double y, double z, double w)
        : x(x), y(y), z(z), w(w) { }

}
