/**
 * @author Hyung-Gyu Ryoo (hyungyu.ryoo@gmail.com)
 * @author Donguk Seo
 *
 */
#include "SFCoordinate.h"

const SFCGAL::Coordinate& SFCoordinate::get_data() const { return data; }
SFCGAL::Coordinate& SFCoordinate::get_data() { return data; }

SFCoordinate& SFCoordinate::operator=(const SFCoordinate& other) {
    data = other.data;

    return *this;
}

int SFCoordinate::coordinateDimension() const {
    return data.coordinateDimension();
}

bool SFCoordinate::isEmpty() const {
    return data.isEmpty();
}

bool SFCoordinate::is3D() const {
    return data.is3D();
}

double SFCoordinate::x() const {
    return CGAL::to_double(data.x());
}

double SFCoordinate::y() const {
    return CGAL::to_double(data.y());
}

double SFCoordinate::z() const {
    return CGAL::to_double(data.z());
}

SFCoordinate& SFCoordinate::round(const long& scaleFactor) {
    data.round(scaleFactor);

    return *this;
}

bool SFCoordinate::operator<(const SFCoordinate& other) const {
    return ( data < other.data ) ;
}

bool SFCoordinate::operator==(const SFCoordinate& other) const {
    return ( data == other.data ) ;
}

bool SFCoordinate::operator!=(const SFCoordinate& other) const {
    return ( data != other.data ) ;
}