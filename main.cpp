/**
 * @file main.cpp
 * @brief Initialization file
 * @author André Ramaciotti da Silva
 * @date 2014-05-01
 */

#include "world.hpp"
#include "application_state.hpp"
#include "addition_state.hpp"
#include "edition_state.hpp"
#include "point.hpp"

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

#include <string>

ars::World world;

ars::AdditionState additionState(world);
ars::EditionState editionState(world);

ars::ApplicationState* currentState;

/**
 * Function called by GLUT to render the scene.
 */
void display();

/**
 * Function called by GLUT to handle keypresses
 */
void keyboard(unsigned char key, int x, int y);

/**
 * Function called by GLUT when a mouse button is pressed.
 */
void mouse(int button, int state, int x, int y);

/**
 * Function called by GLUT when the mouse pointer moves.
 */
void passiveMotion(int x, int y);

/**
 * Function called by GLUT when the window is resized.
 */
void reshape(int width, int height);

/**
 * Function called by GLUT when a special key is pressed.
 */
void special(int key, int x, int y);

int main(int argc, char* argv[]) {
    currentState = &additionState;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(300, 250);
    glutInitWindowSize(world.width(), world.height());
    glutCreateWindow("Andre Ramaciotti - N3");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutPassiveMotionFunc(passiveMotion);
    glutReshapeFunc(reshape);
    glutSpecialFunc(special);

    glutMainLoop();

    return 0;
}

void display() {
    currentState->display();
}

void keyboard(unsigned char key, int x, int y) {
    key = std::tolower(key);
    ars::Point point = world.normalize(x, y);

    switch (key) {
    case 'e':
        currentState = &editionState;
        break;

    case 'a':
        currentState = &additionState;
        break;

    default:
        currentState->keyboard(key, point);
        break;
    }

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    ars::Point point = world.normalize(x, y);

    currentState->mouse(button, state, point);
    glutPostRedisplay();
}

void passiveMotion(int x, int y) {
    ars::Point point = world.normalize(x, y);

    currentState->passiveMotion(point);
    glutPostRedisplay();
}

void reshape(int width, int height) {
    currentState->reshape(width, height);
    glutPostRedisplay();
}

void special(int key, int x, int y) {
    ars::Point point = world.normalize(x, y);

    currentState->special(key, point);
    glutPostRedisplay();
}
