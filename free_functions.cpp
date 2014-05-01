#include "free_functions.hpp"

namespace ars {

    Object boundingBoxToObject(const BoundingBox& bbox) {
        return Object();
    }

    Object referenceAxes() {
        Object xAxis, yAxis;

        xAxis.addPoint(Point(0, -100));
        xAxis.addPoint(Point(0, 100));
        xAxis.setColor(RED);

        yAxis.addPoint(Point(-100, 0));
        yAxis.addPoint(Point(100, 0));
        yAxis.setColor(GREEN);

        Object axes;
        axes.addChild(xAxis);
        axes.addChild(yAxis);

        return axes;
    }

}
