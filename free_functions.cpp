#include "free_functions.hpp"

namespace ars {

    Object boundingBoxToObject(const BoundingBox& bbox) {
        Object obj;

        obj.addPoint(bbox.min);
        obj.addPoint(Point(bbox.min.x, bbox.max.y));
        obj.addPoint(bbox.max);
        obj.addPoint(Point(bbox.max.x, bbox.min.y));
        obj.addPoint(bbox.min);

        obj.setColor(YELLOW);

        return obj;
    }

    Object referenceAxes() {
        Object xAxis, yAxis;

        xAxis.addPoint(Point(-100, 0));
        xAxis.addPoint(Point(100, 0));
        xAxis.setColor(RED);

        yAxis.addPoint(Point(0, -100));
        yAxis.addPoint(Point(0, 100));
        yAxis.setColor(GREEN);

        Object axes;
        axes.addChild(yAxis);
        axes.addChild(xAxis);

        return axes;
    }

}
