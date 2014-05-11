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

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#elif WIN32
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#elif __linux__
#include <GL/gl.h>
#include <GL/glut.h>
#endif

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
        GLenum primitive;

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
         * Adds point to object.
         */
        void addPoint(const Point& point);

        /**
         * Adds a fake point to this object (so the user can see what'll
         * happen when it inserts this point).
         */
        void fakePoint(const Point& point);

        /**
         * Removes the last (and fake) point.
         */
        void removeFakePoint();

        /**
         * Adds child object to object.
         */
        void addChild(const Object& object);

        /**
         * Sets this object color.
         */
        void setColor(const Color& color);

        /**
         * Sets this object as selected (shows the BBox).
         */
        void select();

        /**
         * Deselects this object.
         */
        void deselect();

        /**
         * Resets this object transform back to identity.
         */
        void resetTransform();

        /**
         * Applies a transform to object (accumulates with existing transforms).
         */
        void applyTransform(const Transform& transform);

        /**
         * Toggles if it should be an open or closed polygon.
         */
        void toggleOpenClosed();
    };

}

#endif
