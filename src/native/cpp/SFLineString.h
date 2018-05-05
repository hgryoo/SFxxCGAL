/**
 * @author Hyung-Gyu Ryoo (hyungyu.ryoo@gmail.com)
 * @author Donguk Seo
 *
 */
#pragma once

#include <SFCGAL/LineString.h>

#include <vector>

#include "SFGeometry.h"
#include "SFPoint.h"

class SFLineString : public SFGeometry {
public:

	SFLineString() : SFGeometry(new SFCGAL::LineString()) { }

	SFLineString(const std::vector< void * > & points) {
		std::vector<SFCGAL::Point>* cpp_base_points = new std::vector<SFCGAL::Point>();

		for(size_t i=0; i<points.size(); i++){
			cpp_base_points->push_back( *(SFCGAL::Point *)(((SFPoint *)points.at(i))->get_data()) );
		}

		data = new SFCGAL::LineString(*cpp_base_points);
	}

	SFLineString(const SFPoint& startPoint, const SFPoint& endPoint)
			: SFGeometry(new SFCGAL::LineString(	*(SFCGAL::Point *)(startPoint.get_data()),
													*(SFCGAL::Point *)(endPoint.get_data()) )) { }

	SFLineString(const SFCGAL::LineString& other) : SFGeometry(new SFCGAL::LineString(other)) { }

	SFLineString(SFCGAL::LineString* other) : SFGeometry(other) { }

    ~SFLineString() { }

	SFLineString& operator=(const SFLineString& other);


	//--SFCGAL::Geometry
	SFLineString* clone() const;
	std::string geometryType() const;
	
	int geometryTypeId() const;
	
	int dimension() const;
	
	int coordinateDimension() const;

	bool isEmpty() const;

	bool is3D() const;
	
	bool isMeasured() const;

	void clear();
	
	void reverse();

	size_t numPoints() const;

	size_t numSegments() const;

	const SFPoint& pointN( size_t const & n) const;
	
	SFPoint& pointN(size_t const& n);

	const SFPoint& startPoint() const;
	
	SFPoint& startPoint();

	const SFPoint& endPoint() const;

	SFPoint& endPoint();

	void addPoint(const SFPoint& p);

	void addPoint(SFPoint* p);

	bool isClosed() const;
	
	// iterator begin() ;
	// iterator end() ;

	void reserve(const size_t& n);

};