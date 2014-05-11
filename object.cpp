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
        : isSelected(false), primitive(GL_LINE_STRIP) { }

    void Object::render() const {
        glPushMatrix();
        glMultMatrixd(transform.getData());

        glColor3fv(color.getData());

        glLineWidth(1);
        glBegin(primitive);
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

        if (points.size() == 1) {
            points.push_back(point);
        }
    }

    void Object::fakePoint(const Point& point) {
        if (points.size() == 0) {
            return;
        }

        Point& p = points.back();

        p.x = point.x;
        p.y = point.y;
    }

    void Object::removeFakePoint() {
        points.pop_back();
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

    void Object::toggleOpenClosed() {
        if (primitive == GL_LINE_STRIP) {
            primitive = GL_LINE_LOOP;
        } else {
            primitive = GL_LINE_STRIP;
        }
    }
}
