#include "transform.hpp"

#include "point.hpp"

#include <cmath>

namespace ars {

    Transform::Transform() {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                matrix[i][j] = 0.0;
            }
        }

        matrix[0][0] = matrix[1][1] = matrix[2][2] = matrix[3][3] = 1.0;
    }

    const double* Transform::getData() const {
        return reinterpret_cast<const double*>(matrix);
    }

    Point Transform::operator *(const Point& rhs) const {
        double x = rhs.x * matrix[0][0]
            + rhs.y * matrix[0][1]
            + rhs.z * matrix[0][2]
            + rhs.w * matrix[0][3];

        double y = rhs.x * matrix[1][0]
            + rhs.y * matrix[1][1]
            + rhs.z * matrix[1][2]
            + rhs.w * matrix[1][3];

        double z = rhs.x * matrix[2][0]
            + rhs.y * matrix[2][1]
            + rhs.z * matrix[2][2]
            + rhs.w * matrix[2][3];

        double w = rhs.x * matrix[3][0]
            + rhs.y * matrix[3][1]
            + rhs.z * matrix[3][2]
            + rhs.w * matrix[3][3];

        return Point(x, y, z, w);
    }

    Transform Transform::operator *(const Transform& r) const {
        const Transform& l = *this;

        Transform t;

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                double sum = 0.0;

                for(int k = 0; k < 4; k++) {
                    sum += l.matrix[i][k] * r.matrix[k][j];
                }

                t.matrix[i][j] = sum;
            }
        }

        return t;
    }

    Transform Transform::translation(const Point& translation) {
        Transform t;

        t.matrix[3][0] = translation.x;
        t.matrix[3][1] = translation.y;
        t.matrix[3][2] = translation.z;

        return t;
    }

    Transform Transform::scale(double xfactor, double yfactor, double zfactor) {
        Transform t;

        t.matrix[0][0] = xfactor;
        t.matrix[1][1] = yfactor;
        t.matrix[2][2] = zfactor;

        return t;
    }

    Transform Transform::xRotation(double rad) {
        Transform t;

        t.matrix[1][1] = std::cos(rad);
        t.matrix[2][1] = -1 * std::sin(rad);
        t.matrix[1][2] = std::sin(rad);
        t.matrix[2][2] = std::cos(rad);

        return t;
    }

    Transform Transform::yRotation(double rad) {
        Transform t;

        t.matrix[0][0] = std::cos(rad);
        t.matrix[2][0] = std::sin(rad);
        t.matrix[0][2] = -1 * std::sin(rad);
        t.matrix[2][2] = std::cos(rad);

        return t;
    }

    Transform Transform::zRotation(double rad) {
        Transform t;

        t.matrix[0][0] = std::cos(rad);
        t.matrix[1][0] = -1 * std::sin(rad);
        t.matrix[0][1] = std::sin(rad);
        t.matrix[1][1] = std::cos(rad);

        return t;
    }
}
