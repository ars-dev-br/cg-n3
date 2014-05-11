#include "world.hpp"
#include "free_functions.hpp"

#include <vector>

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

    World::World()
        : minX(-250), minY(-250), maxX(250), maxY(250),
          canvasW(500), canvasH(500), sketch(nullptr),
          referenceAxes(ars::referenceAxes()) { }

    void World::zoomIn() {
        if (width() > 20) {
            minX += 2.5;
            minY += 2.5;

            maxX -= 2.5;
            maxY -= 2.5;
        }
    }

    void World::zoomOut() {
        minX -= 2.5;
        minY -= 2.5;

        maxX += 2.5;
        maxY += 2.5;
    }

    void World::render() const {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(minX, maxX, minY, maxY);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        referenceAxes.render();

        for(auto it = std::begin(objects); it != std::end(objects); ++it) {
            it->render();
        }

        if(sketch != nullptr) {
            sketch->render();
        }

        glutSwapBuffers();
    }

    double World::height() const {
        return maxY - minY;
    }

    double World::width() const {
        return maxX - minX;
    }

    Point World::normalize(int xx, int yy) {
        double x = minX + (xx / static_cast<double>(canvasW)) * width();
        double y = minY + (yy / static_cast<double>(canvasH)) * height();

        return Point(x, -y);
    }

    Object* World::sketchObject() {
        sketch = new Object();
        return sketch;
    }

    void World::addSketchObject() {
        objects.push_back(*sketch);
        delete sketch;
        sketch = nullptr;
    }
}
