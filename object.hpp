/**
 * @file object.hpp
 * @brief Object definition.
 */

#ifndef ARS_OBJECT_HPP
#define ARS_OBJECT_HPP

#include "bounding_box.hpp"
#include "color.hpp"
#include "point.hpp"
#include "transform.hpp"

#include <vector>

namespace ars {

    /**
     * @brief A graphical object.
     * @author André Ramaciotti da Silva
     * @date 2014-05-01
     *
     * A graphical object keeps track of its color, children, transformation
     * matrix and bounding box.
     */
    class Object {
    private:
        Color color;
        Transform transform;
        BoundingBox bbox;

        std::vector<Object> children;
        std::vector<Point> points;

        bool isSelected;

    public:
        /**
         * Creates a new (empty) graphical object.
         */
        Object();

        /**
         * Renders the object and all its children recursivelly.
         */
        void render() const;

        /**
         * Add point to object.
         */
        void addPoint(const Point& point);

        /**
         * Add child object to object.
         */
        void addChild(const Object& object);

        /**
         * Set this object color.
         */
        void setColor(const Color& color);

        /**
         * Set this object as selected (shows the BBox).
         */
        void select();

        /**
         * Deselect this object.
         */
        void deselect();

        /**
         * Reset this object transform back to identity.
         */
        void resetTransform();

        /**
         * Apply a transform to object (accumulates with existing transforms).
         */
        void applyTransform(const Transform& transform);
    };

}

#endif
