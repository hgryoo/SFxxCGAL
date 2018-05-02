/**
 * @author Hyung-Gyu Ryoo (hyungyu.ryoo@gmail.com)
 * @author Donguk Seo
 *
 */

#ifndef JAVACPP_SFCGAL_Coordinate_H
#define JAVACPP_SFCGAL_Coordinate_H

#include <SFCGAL/Coordinate.h>

class SFCoordinate{
	SFCGAL::Coordinate data;
public:
	const SFCGAL::Coordinate& get_data() const;
	SFCGAL::Coordinate& get_data();

	SFCoordinate() : data() { }
	SFCoordinate(double x, double y) : data(x, y) { }
	SFCoordinate(double x, double y, double z) : data(x, y, z) { }
	SFCoordinate(const SFCoordinate& other) : data(other.data) { }
	SFCoordinate(const SFCGAL::Coordinate& other) : data(other) { }
	
	SFCoordinate& operator=(const SFCoordinate& other);

	~SFCoordinate() { }
	
	int coordinateDimension() const;
	bool isEmpty() const;

	bool is3D() const;

	double x() const;

	double y() const;

	double z() const;

	SFCoordinate& round(const long& scaleFactor = 1);

	bool operator<(const SFCoordinate& other) const;

	bool operator==(const SFCoordinate& other) const;

	bool operator!=(const SFCoordinate& other) const;
};

#endif
