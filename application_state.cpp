#include "application_state.hpp"

#include "point.hpp"
#include "world.hpp"

namespace ars {

    ApplicationState::ApplicationState(World& world)
        : world(world) { }

    ApplicationState::~ApplicationState() { }

    void ApplicationState::reshape(int width, int height) {
    }

    void ApplicationState::display() {
        world.render();
    }

    void ApplicationState::keyboard(unsigned char key, const Point& point) {
        switch (key) {
        case '-':
            world.zoomOut();
            break;

        case '+':
        case '=':
            world.zoomIn();
            break;
        }
    }
}
