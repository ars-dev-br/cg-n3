#include "transform.hpp"

namespace ars {

    Transform::Transform() {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                matrix[i][j] = i == j ? 1 : 0;
            }
        }
    }

    const double* Transform::getData() const {
        return reinterpret_cast<const double*>(matrix);
    }
}
