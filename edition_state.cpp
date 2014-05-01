#include "edition_state.hpp"

#include "world.hpp"

namespace ars {

    EditionState::EditionState(World& world)
        : base(world) { }

    void EditionState::keyboard(unsigned char key, int x, int y) {
        switch (key) {
        default:
            base::keyboard(key, x, y);
            break;
        }
    }

    void EditionState::mouse(int button, int state, int x, int y) {
    }

    void EditionState::passiveMotion(int x, int y) {
    }

    void EditionState::special(int key, int x, int y) {
    }

}
