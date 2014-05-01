/**
 * @file world.hpp
 * @brief World definition.
 */

#ifndef ARS_WORLD_HPP
#define ARS_WORLD_HPP

#include "object.hpp"
#include "free_functions.hpp"

#include <vector>

namespace ars {

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
    };

}

#endif
