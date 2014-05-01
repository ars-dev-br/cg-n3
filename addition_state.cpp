#include "addition_state.hpp"

#include "world.hpp"

namespace ars {

    AdditionState::AdditionState(World& world)
        : base(world) { }

    void AdditionState::keyboard(unsigned char key, int x, int y) {
        switch (key) {
        default:
            base::keyboard(key, x, y);
            break;
        }
    }

    void AdditionState::mouse(int button, int state, int x, int y) {
    }

    void AdditionState::passiveMotion(int x, int y) {
    }

    void AdditionState::special(int key, int x, int y) {
    }

}
