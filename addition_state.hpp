/**
 * @file addition_state.hpp
 * @brief AdditionState definition.
 */

#ifndef ARS_ADDITION_STATE_HPP
#define ARS_ADDITION_STATE_HPP

#include "application_state.hpp"
#include "world.hpp"

namespace ars {

    /**
     * @brief Application handler used when on addition state.
     * @author André Ramaciotti da Silva
     * @date 2014-05-01
     */
    class AdditionState : public ApplicationState {
    private:
        typedef ApplicationState base;

    public:
        AdditionState(World& world);

        virtual void keyboard(unsigned char key, int x, int y);
        virtual void mouse(int button, int state, int x, int y);
        virtual void passiveMotion(int x, int y);
        virtual void special(int key, int x, int y);
    };

}

#endif
