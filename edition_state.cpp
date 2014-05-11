#include "edition_state.hpp"

#include "world.hpp"

namespace ars {

    EditionState::EditionState(World& world)
        : base(world) { }

    void EditionState::keyboard(unsigned char key, const Point& point) {
        switch (key) {
        default:
            base::keyboard(key, point);
            break;
        }
    }

    void EditionState::mouse(int button, int state, const Point& point) {
    }

    void EditionState::passiveMotion(const Point& point) {
    }

    void EditionState::special(int key, const Point& point) {
    }

}
