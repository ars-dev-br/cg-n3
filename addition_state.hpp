/**
 * @file addition_state.hpp
 * @brief AdditionState definition.
 */

#ifndef ARS_ADDITION_STATE_HPP
#define ARS_ADDITION_STATE_HPP

#include "application_state.hpp"

namespace ars {

    class Object;
    class Point;
    class World;

    /**
     * @brief Application handler used when on addition state.
     * @author André Ramaciotti da Silva
     * @date 2014-05-01
     */
    class AdditionState : public ApplicationState {
    private:
        typedef ApplicationState base;

        Object* currentObject;
    public:
        AdditionState(World& world);

        virtual void keyboard(unsigned char key, const Point& point);
        virtual void mouse(int button, int state, const Point& point);
        virtual void passiveMotion(const Point& point);
        virtual void special(int key, const Point& point);
    };

}

#endif
