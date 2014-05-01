/**
 * @file edition_state.hpp
 * @brief EditionState definition.
 */

#ifndef ARS_EDITION_STATE_HPP
#define ARS_EDITION_STATE_HPP

#include "application_state.hpp"

namespace ars {

    /**
     * @brief Application handler used when on edition state.
     * @author André Ramaciotti da Silva
     * @date 2014-05-01
     */
    class EditionState : public ApplicationState {
    private:
        typedef ApplicationState base;

    public:
        EditionState(World& world);

        virtual void keyboard(unsigned char key, int x, int y);
        virtual void mouse(int button, int state, int x, int y);
        virtual void passiveMotion(int x, int y);
        virtual void special(int key, int x, int y);

    };
}

#endif
