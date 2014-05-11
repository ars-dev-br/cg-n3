#include "edition_state.hpp"

#include "color.hpp"
#include "world.hpp"

namespace ars {

    const double TRANSLATION = 2.0;
    const double SCALE = 1.1;
    const double ROTATE = 0.1;

    EditionState::EditionState(World& world)
        : base(world), currentObject(nullptr), currentPoint(nullptr),
          transform('t') { }

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

        case 't':
        case 'r':
        case 's':
            transform = key;
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
        if (currentObject == nullptr || currentPoint != nullptr) {
            return;
        }

        if (key == GLUT_KEY_HOME) {
            currentObject->resetTransform();
        }

        switch(transform) {
        case 't':
            translate(key);
            break;
        case 'r':
            rotate(key);
            break;
        case 's':
            scale(key);
            break;
        }
    }

    void EditionState::translate(int key) {
        switch(key) {
        case GLUT_KEY_UP:
            currentObject->applyTransform(
                Transform::translation(Point(0, TRANSLATION)));
            break;

        case GLUT_KEY_RIGHT:
            currentObject->applyTransform(
                Transform::translation(Point(TRANSLATION, 0)));
            break;

        case GLUT_KEY_DOWN:
            currentObject->applyTransform(
                Transform::translation(Point(0, -TRANSLATION)));
            break;

        case GLUT_KEY_LEFT:
            currentObject->applyTransform(
                Transform::translation(Point(-TRANSLATION, 0)));
            break;
        }
    }

    void EditionState::rotate(int key) {
        switch(key) {
        case GLUT_KEY_RIGHT:
            {
                currentObject->applyTransform(Transform::translation(currentObject->center()));
                currentObject->applyTransform(Transform::zRotation(-ROTATE));
                currentObject->applyTransform(Transform::translation(-currentObject->center()));
            }
            break;

        case GLUT_KEY_LEFT:
            {
                currentObject->applyTransform(Transform::translation(currentObject->center()));
                currentObject->applyTransform(Transform::zRotation(ROTATE));
                currentObject->applyTransform(Transform::translation(-currentObject->center()));
            }
            break;
        }
    }

    void EditionState::scale(int key) {
        switch(key) {
        case GLUT_KEY_UP:
            {
                currentObject->applyTransform(Transform::translation(currentObject->center()));
                currentObject->applyTransform(Transform::scale(1, SCALE, 1));
                currentObject->applyTransform(Transform::translation(-currentObject->center()));
            }
            break;

        case GLUT_KEY_RIGHT:
            {
                currentObject->applyTransform(Transform::translation(currentObject->center()));
                currentObject->applyTransform(Transform::scale(SCALE, 1, 1));
                currentObject->applyTransform(Transform::translation(-currentObject->center()));
            }
            break;

        case GLUT_KEY_DOWN:
            {
                currentObject->applyTransform(Transform::translation(currentObject->center()));
                currentObject->applyTransform(Transform::scale(1, 1/SCALE, 1));
                currentObject->applyTransform(Transform::translation(-currentObject->center()));
            }
            break;

        case GLUT_KEY_LEFT:
            {
                currentObject->applyTransform(Transform::translation(currentObject->center()));
                currentObject->applyTransform(Transform::scale(1/SCALE, 1, 1));
                currentObject->applyTransform(Transform::translation(-currentObject->center()));
            }
            break;
        }
    }

}
