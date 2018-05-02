/*
 *    GeoTools - The Open Source Java GIS Toolkit
 *    http://geotools.org
 *
 *    (C) 2015, Open Source Geospatial Foundation (OSGeo)
 *
 *    This library is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation;
 *    version 2.1 of the License.
 *
 *    This library is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 */

/**
 * @author Donguk Seo
 *
 */

#include "SFPoint.h"

SFPoint& SFPoint::operator=(const SFPoint& other) {
    data = other.data;

    return *this;
}

//--SFCGAL::Geometry
SFPoint* SFPoint::clone() const {
    return new SFPoint(*this);
}

std::string SFPoint::geometryType() const {
    return data->geometryType();
}

int SFPoint::geometryTypeId() const {
    return data->geometryTypeId();
}

int SFPoint::dimension() const {
    return data->dimension();
}

int SFPoint::coordinateDimension() const {
    return data->coordinateDimension();
}

bool SFPoint::isEmpty() const {
    return data->isEmpty();
}

bool SFPoint::is3D() const {
    return data->is3D();
}

bool SFPoint::isMeasured() const {
    return data->isMeasured();
}

double SFPoint::x() const {
    return CGAL::to_double(((SFCGAL::Point *)data)->x());
}

double SFPoint::y() const {
    return CGAL::to_double(((SFCGAL::Point *)data)->y());
}

double SFPoint::z() const {
    return CGAL::to_double(((SFCGAL::Point *)data)->z());
}

double SFPoint::m() const {
    return ((SFCGAL::Point *)data)->m();
}

void SFPoint::setM(const double& m) {
    ((SFCGAL::Point *)data)->setM(m);
}

bool SFPoint::operator<(const SFPoint& other) const {
    return ( *((SFCGAL::Point *)data) < *((SFCGAL::Point *)other.data) ) ;
}

bool SFPoint::operator==(const SFPoint& other) const {
    return ( *((SFCGAL::Point *)data) == *((SFCGAL::Point *)other.data) ) ;
}

bool SFPoint::operator!=(const SFPoint& other) const {
    return ( *((SFCGAL::Point *)data) != *((SFCGAL::Point *)other.data) ) ;
}

SFCoordinate& SFPoint::coordinate() {
    return *(new SFCoordinate(((SFCGAL::Point *)data)->coordinate()));
}

SFCoordinate& SFPoint::coordinate() const {
    return *(new SFCoordinate(((SFCGAL::Point *)data)->coordinate()));
}