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

#ifndef JAVACPP_SFCGAL_Point_H
#define JAVACPP_SFCGAL_Point_H

#include <SFCGAL/Point.h>

#include "SFGeometry.h"
#include "SFCoordinate.h"

class SFPoint : public SFGeometry {
public:

    SFPoint() : SFGeometry(new SFCGAL::Point()) { }
    SFPoint(SFCoordinate& coordinate) : SFGeometry(new SFCGAL::Point(coordinate.get_data())) { }
    SFPoint(double x, double y) : SFGeometry(new SFCGAL::Point(x, y)) { }
    SFPoint(double x, double y, double z) : SFGeometry(new SFCGAL::Point(x, y, z)) { }
    SFPoint(double x, double y, double z, double m) : SFGeometry(new SFCGAL::Point(x, y, z, m)) { }
    SFPoint(const SFPoint& other) : SFGeometry(other.data) { }
    SFPoint(const SFCGAL::Point& other) : SFGeometry(new SFCGAL::Point(other)) { }
    SFPoint(SFCGAL::Point* other) : SFGeometry(other) { }

    ~SFPoint() { }

	SFPoint& operator=(const SFPoint& other);



    //--SFCGAL::Geometry
	SFPoint* clone() const;
	
	std::string geometryType() const;
	
	int geometryTypeId() const;
	
	int dimension() const;
	
	int coordinateDimension() const;

	bool isEmpty() const;

	bool is3D() const;
	
	bool isMeasured() const;

	double x() const;

	double y() const;

	double z() const;

	double m() const;
	
	void setM(const double& m);

	bool operator<(const SFPoint& other) const;

	bool operator==(const SFPoint& other) const;

	bool operator!=(const SFPoint& other) const;

	SFCoordinate& coordinate();
	
	SFCoordinate& coordinate() const;
};

#endif
