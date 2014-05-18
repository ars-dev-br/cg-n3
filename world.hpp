/**
 * @file world.hpp
 * @brief World definition.
 */

#ifndef ARS_WORLD_HPP
#define ARS_WORLD_HPP

#include "object.hpp"

#include <vector>

namespace ars {

    class Point;

    /**
     * @brief The graphical world.
     * @author André Ramaciotti da Silva
     * @date 2014-05-01
     *
     * The graphical world keeps track of all created graphical objects
     * and information about the camera.
     */
    class World {
    private:
        double minX, minY, maxX, maxY;
        std::vector<Object> objects;
        int canvasW, canvasH;

        Object* sketch;
        Object referenceAxes;
    public:
        /**
         * Creates a new graphical world.
         */
        World();

        /**
         * Zooms in the camera.
         */
        void zoomIn();

        /**
         * Zooms out the camera.
         */
        void zoomOut();

        /**
         * Renders all the objects onto the screen.
         */
        void render() const;

        /**
         * The world height in pixels.
         */
        double height() const;

        /**
         * The world width in pixels.
         */
        double width() const;

        /**
         * Normalizes a point according to canvas size and camera zoom.
         */
        Point normalize(int x, int y);

        /**
         * Creates a new sketch object and returns it.
         */
        Object* sketchObject();

        /**
         * Adds sketch object to objects list.
         */
        void addSketchObject();

        /**
         * Returns the object under a given point.  It may return nullptr if
         * no object was selected.
         */
        Object* objectUnder(const Point& point);

        /**
         * Removes a object that equals the parameter.
         */
        void removeObject(const Object& object);
    };

}

#endif
