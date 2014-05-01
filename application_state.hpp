/**
 * @file application_state.hpp
 * @brief ApplicationState definition.
 */

#ifndef ARS_APPLICATION_STATE_HPP
#define ARS_APPLICATION_STATE_HPP

#include "world.hpp"

namespace ars {

    /**
     * @brief Abstract class for application handlers that depend on state.
     * @author André Ramaciotti da Silva
     * @date 2014-05-01
     *
     * @see ars::AdditionState
     * @see ars::EditionState
     */
    class ApplicationState {
    protected:
        World& world;

    public:
        /**
         * Creates an application state to edit a graphical world.
         */
        ApplicationState(World& world);

        /**
         * Destroys an application state.
         */
        virtual ~ApplicationState();

        /**
         * Displays the scene and renders the world.
         */
        virtual void display();

        /**
         * Handles a "normal" keypress.
         * @see special
         */
        virtual void keyboard(unsigned char key, int x, int y);

        /**
         * Handles a mouse event.
         */
        virtual void mouse(int button, int state, int x, int y) = 0;

        /**
         * Handles mouse movement.
         */
        virtual void passiveMotion(int x, int y) = 0;

        /**
         * Handles a window resize.
         */
        virtual void reshape(int width, int height);

        /**
         * Handles special keypresses.
         */
        virtual void special(int key, int x, int y) = 0;

    private:
        // Don't let copies be made.
        ApplicationState(const ApplicationState& src) = delete;
        ApplicationState& operator=(const ApplicationState& src) = delete;
    };

}

#endif
