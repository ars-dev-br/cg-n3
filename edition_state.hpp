/**
 * @file edition_state.hpp
 * @brief EditionState definition.
 */

#ifndef ARS_EDITION_STATE_HPP
#define ARS_EDITION_STATE_HPP

#include "application_state.hpp"

namespace ars {

    class Object;
    class Point;
    class World;

    /**
     * @brief Application handler used when on edition state.
     * @author André Ramaciotti da Silva
     * @date 2014-05-01
     */
    class EditionState : public ApplicationState {
    private:
        typedef ApplicationState base;

        Object* currentObject;
        Point* currentPoint;

        char transform;

        void translate(int key);
        void rotate(int key);
        void scale(int key);
    public:
        EditionState(World& world);

        virtual void keyboard(unsigned char key, const Point& point);
        virtual void mouse(int button, int state, const Point& point);
        virtual void passiveMotion(const Point& point);
        virtual void special(int key, const Point& point);

    };
}

#endif
