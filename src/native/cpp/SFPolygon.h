/**
 * @author Hyung-Gyu Ryoo (hyungyu.ryoo@gmail.com)
 * @author Donguk Seo
 *
 */

#ifndef JAVACPP_SFCGAL_Polygon_H
#define JAVACPP_SFCGAL_Polygon_H

#include <SFCGAL/Polygon.h>
#include "SFGeometry.h"
#include "SFLineString.h"
#include "SFSurface.h"
#include "SFTriangle.h"

class SFPolygon : public SFSurface {
public:	
	SFPolygon() : SFSurface(new SFCGAL::Polygon()) { }
	SFPolygon(const std::vector< void * > & rings) {
		std::vector<SFCGAL::LineString>* cpp_base_rings = new std::vector<SFCGAL::LineString>();

		for(size_t i=0; i<rings.size(); i++){
			cpp_base_rings->push_back( *(SFCGAL::LineString *)(((SFLineString *)rings.at(i))->get_data()) );
		}

		data = new SFCGAL::Polygon(cpp_base_rings->at(0));
		
		SFCGAL::Polygon* poly = dynamic_cast<SFCGAL::Polygon*>(data);
		if(cpp_base_rings->size() > 1) {
			for(size_t i=1; i<cpp_base_rings->size(); i++)
			poly->addInteriorRing(cpp_base_rings->at(i));
		}
	}
	SFPolygon(const SFLineString& exteriorRing) : SFSurface(new SFCGAL::Polygon(*(SFCGAL::LineString *)(exteriorRing.get_data()))) { }

	SFPolygon(SFTriangle& triangle) : SFSurface(new SFCGAL::Polygon(*(SFCGAL::Triangle *)(triangle.get_data()))) { }

	SFPolygon(const SFCGAL::Polygon& other) : SFSurface(new SFCGAL::Polygon(other)) { }
	SFPolygon(SFCGAL::Polygon* other) : SFSurface(other) { }

	~SFPolygon() { }

	SFPolygon& operator=(const SFPolygon& other);

	
	
	//--SFCGAL::Geometry
	SFPolygon* clone() const;
	
	std::string geometryType() const;
	
	int geometryTypeId() const;
	
	int dimension() const;
	
	int coordinateDimension() const;

	bool isEmpty() const;

	bool is3D() const;
	
	bool isMeasured() const;

	bool isCounterClockWiseOriented();
	
	void reverse();

	
	SFLineString& exteriorRing() const;

	SFLineString& exteriorRing();

	void setExteriorRing(const SFLineString& ring);
	
	bool hasInteriorRings() const;

	size_t numInteriorRings() const;

	const SFLineString& interiorRingN(const size_t& n) const;

	SFLineString& interiorRingN(const size_t& n);

	size_t numRings() const;

	const SFLineString& ringN( size_t const & n) const;
	
	SFLineString& ringN( size_t const & n);
	
	
	void addInteriorRing(const SFLineString& ls);

	void addInteriorRing(SFLineString* ls);

	void addRing( const SFLineString& ls );

	void addRing( SFLineString* ls );
};

#endif
