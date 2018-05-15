/**
 * @author Hyung-Gyu Ryoo (hyungyu.ryoo@gmail.com)
 *
 */

#pragma once

#include <string>
#include <cmath>

namespace SFxxCGAL {

    class BoundingBox {
    private:
        double xmin;
        double ymin;
        double zmin;
        double xmax;
        double ymax;
        double zmax;
    public:
        SFXBoundingBox(
                const double xmin, const double xmax,
                const double ymin, const double ymax,
                const double zmin, const double zmax) {
            this->xmin = xmin;
            this->ymin = ymin;
            this->zmin = zmin;
            this->xmax = xmax;
            this->ymax = ymax;
            this->zmax = zmax;
        }

        ~SFXBoundingBox() {}

        const double xMin() const;

        const double yMin() const;

        const double zMin() const;

        const double xMax() const;

        const double yMax() const;

        const double zMax() const;
    };
}