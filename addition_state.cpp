#include "addition_state.hpp"

#include "world.hpp"
#include "color.hpp"

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#elif WIN32
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#elif __linux__
#include <GL/gl.h>
#include <GL/glut.h>
#endif

namespace ars {

    AdditionState::AdditionState(World& world)
        : base(world), currentObject(nullptr) { }

    void AdditionState::keyboard(unsigned char key, const Point& point) {
        switch (key) {
        case 'c':
            if (currentObject != nullptr) {
                currentObject->setColor(Color::random());
            }
            break;

        case ' ':
            if (currentObject != nullptr) {
                currentObject->toggleOpenClosed();
            }
            break;

        default:
            base::keyboard(key, point);
            break;
        }
    }

    void AdditionState::mouse(int button, int state, const Point& point) {
        if (state != GLUT_DOWN) {
            return;
        }

        if (button == GLUT_LEFT_BUTTON) {
            if (currentObject == nullptr) {
                currentObject = world.sketchObject();
            }

            currentObject->addPoint(point);
        } else if (button == GLUT_RIGHT_BUTTON) {
            if (currentObject != nullptr) {
                currentObject->removeFakePoint();
                world.addSketchObject();
                currentObject = nullptr;
            }
        }
    }

    void AdditionState::passiveMotion(const Point& point) {
        if (currentObject != nullptr) {
            currentObject->fakePoint(point);
        }
    }

    void AdditionState::special(int key, const Point& point) {
    }

}
