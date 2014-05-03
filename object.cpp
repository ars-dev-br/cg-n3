#include "object.hpp"
#include "free_functions.hpp"

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

    Object::Object()
        : isSelected(false) { }

    void Object::render() const {
        glPushMatrix();
        glMultMatrixd(transform.getData());

        glColor3fv(color.getData());

        glLineWidth(1);
        glBegin(GL_LINES);
        {
            for(auto it = std::begin(points); it != std::end(points); ++it) {
                glVertex3d(it->x, it->y, it->z);
            }
        }
        glEnd();

        for(auto it = std::begin(children); it != std::end(children); ++it) {
            it->render();
        }

        if (isSelected) {
            Object bboxObject = boundingBoxToObject(bbox);
            bboxObject.render();
        }

        glPopMatrix();
    }

    void Object::addPoint(const Point& point) {
        points.push_back(point);
    }

    void Object::addChild(const Object& child) {
        children.push_back(child);
    }

    void Object::setColor(const Color& color) {
        this->color = color;
    }

    void Object::select() {
        isSelected = true;
    }

    void Object::deselect() {
        isSelected = false;
    }

    void Object::resetTransform() {
        transform = Transform();
    }

    void Object::applyTransform(const Transform& transform) {
        this->transform = transform * this->transform;
    }
}
