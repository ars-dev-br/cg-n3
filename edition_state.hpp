/**
 * @file edition_state.hpp
 * @brief EditionState definition.
 */

#ifndef ARS_EDITION_STATE_HPP
#define ARS_EDITION_STATE_HPP

#include "application_state.hpp"
#include "point.hpp"
#include "world.hpp"

namespace ars {

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
    public:
        EditionState(World& world);

        virtual void keyboard(unsigned char key, const Point& point);
        virtual void mouse(int button, int state, const Point& point);
        virtual void passiveMotion(const Point& point);
        virtual void special(int key, const Point& point);

    };
}

#endif
