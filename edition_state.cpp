#include "edition_state.hpp"

#include "color.hpp"
#include "world.hpp"

namespace ars {

    EditionState::EditionState(World& world)
        : base(world), currentObject(nullptr), currentPoint(nullptr) { }

    void EditionState::keyboard(unsigned char key, const Point& point) {
        switch (key) {
        case 'c':
            if (currentObject != nullptr) {
                currentObject->setColor(Color::random());
            }
            break;

        case 'd':
            if (currentPoint != nullptr) {
                currentObject->removePoint(*currentPoint);
                currentPoint = nullptr;
            }
            break;

        case '\b':
            if (currentObject != nullptr) {
                world.removeObject(*currentObject);
                currentObject = nullptr;
                currentPoint = nullptr;
            }
            break;

        case ' ':
            if (currentObject != nullptr) {
                currentObject->toggleOpenClosed();
            }
            break;

        case '\033': // esc
            if (currentObject != nullptr) {
                currentPoint = nullptr;
                currentObject->updateBBox();
                currentObject->deselect();
                currentObject = nullptr;
            }
            break;

        default:
            base::keyboard(key, point);
            break;
        }
    }

    void EditionState::mouse(int button, int state, const Point& point) {
        if (state != GLUT_DOWN) {
            return;
        }

        if (button == GLUT_LEFT_BUTTON && currentPoint == nullptr) {
            if (currentObject != nullptr) {
                currentObject->deselect();
            }

            currentObject = world.objectUnder(point);
            if (currentObject != nullptr) {
                currentObject->select();
                currentPoint = currentObject->pointNear(point);
            }
        } else if (button == GLUT_RIGHT_BUTTON) {
            if (currentPoint != nullptr) {
                currentObject->updateBBox();
                currentPoint = nullptr;
            }
        }
    }

    void EditionState::passiveMotion(const Point& point) {
        if (currentPoint != nullptr) {
            *currentPoint = point;
        }
    }

    void EditionState::special(int key, const Point& point) {

    }

}
