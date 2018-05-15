/**
 * @author Hyung-Gyu Ryoo (hyungyu.ryoo@gmail.com)
 *
 */

#include "SFXBoundingBox.hpp"

using namespace SFxxCGAL;

const double BoundingBox::xMin() const {
    return this->xmin;
}

const double BoundingBox::yMin() const {
    return this->ymin;
}

const double BoundingBox::zMin() const {
    return this->zmin;
}

const double BoundingBox::xMax() const {
    return this->xmax;
}

const double BoundingBox::yMax() const {
    return this->ymax;
}

const double BoundingBox::zMax() const {
    return this->zmax;
}