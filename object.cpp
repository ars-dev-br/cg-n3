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

#include <algorithm>

namespace ars {

    const double SELECTION_DISTANCE = 5 * 5;

    Object::Object()
        : isSelected(false), primitive(GL_LINE_STRIP) { }

    void Object::render() const {
        glPushMatrix();
        glMultMatrixd(transform.getData());

        if (isSelected) {
            Object bboxObject = boundingBoxToObject(bbox);
            bboxObject.render();
        }

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

        glPopMatrix();
    }

    void Object::addPoint(const Point& point) {
        points.push_back(point);

        if (points.size() == 1) {
            points.push_back(point);
        }

        updateBBox();
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

    void Object::removePoint(const Point& point) {
        points.erase(std::remove(std::begin(points), std::end(points), point),
                     std::end(points));
        updateBBox();
    }

    void Object::removeChild(const Object& child) {
        for(auto it = std::begin(children); it != std::end(children); ++it) {
            it->removeChild(child);
        }

        children.erase(
            std::remove(std::begin(children), std::end(children), child),
            std::end(children));
    }

    Point* Object::pointNear(const Point& point) {
        for(auto it = std::begin(points); it != std::end(points); ++it) {
            if (dist(*it, point) <= SELECTION_DISTANCE) {
                return &(*it);
            }
        }

        return nullptr;
    }

    void Object::updateBBox() {
        bbox.update(points);
    }

    Object* Object::contains(const Point& point) {
        for(auto it = std::begin(children); it != std::end(children); ++it) {
            Object* obj = it->contains(point);

            if(obj != nullptr) {
                return obj;
            }
        }

        if (!bbox.contains(point)) {
            return nullptr;
        }

        int intersections = 0;
        for(size_t i = 0; i < points.size(); ++i) {
            Point objPointA = points[i];
            Point objPointB = points[(i + 1) % points.size()];

            if (objPointA.y != objPointB.y) {
                double t = (point.y - objPointA.y)
                            / (objPointB.y - objPointA.y);
                Point intersect(objPointA.x + ((objPointB.x - objPointA.x) * t),
                                point.y);

                if (intersect.x == point.x) {
                    return this;
                } else if (intersect.x > point.x && t >= 0 && t <= 1) {
                    ++intersections;
                }
            } else if (objPointA.y == point.y
                       && point.x >= std::min(objPointA.x, objPointB.x)
                       && point.x <= std::max(objPointA.x, objPointB.x)) {
                return this;
            }
        }

        return intersections % 2 != 0 ? this : nullptr;
    }

    // For keeping things fast, we consider two objects to be equal if
    // they have the same bounding box.
    bool Object::operator ==(const Object& rhs) {
        return bbox == rhs.bbox;
    }

    Point Object::center() const {
        return bbox.center();
    }
}
