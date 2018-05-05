/**
 * @author Hyung-Gyu Ryoo (hyungyu.ryoo@gmail.com)
 * @author Donguk Seo
 *
 */
#pragma once

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