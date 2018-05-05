/**
 * @author Hyung-Gyu Ryoo (hyungyu.ryoo@gmail.com)
 * @author Donguk Seo
 *
 */
#pragma once

#include <SFCGAL/GeometryCollection.h>
#include "SFGeometry.h"

class SFGeometryCollection : public SFGeometry {
public:	
	SFGeometryCollection() : SFGeometry(new SFCGAL::GeometryCollection()) { }
	
	//SFGeometryCollection(const SFGeometryCollection& other) : SFGeometry(other.data) { }
	SFGeometryCollection(const SFCGAL::GeometryCollection& other) : SFGeometry(new SFCGAL::GeometryCollection(other)) { }
	//SFGeometryCollection(SFCGAL::GeometryCollection& other) : SFGeometry(new SFCGAL::GeometryCollection(other)) { }
	SFGeometryCollection(SFCGAL::GeometryCollection* other) : SFGeometry(other) { }

	SFGeometryCollection& operator=(const SFGeometryCollection& other) {
		data = other.data;
		
		return *this;
	}
	
	~SFGeometryCollection() { }
	
	
	//--SFCGAL::Geometry
	SFGeometryCollection* clone() const;
	
	std::string geometryType() const;
	
	int geometryTypeId() const;
	
	int dimension() const;
	
	int coordinateDimension() const;

	bool isEmpty() const;

	bool is3D() const;
	
	bool isMeasured() const;

	size_t numGeometries() const;


	const SFGeometry& geometryN(size_t const& n) const;

	SFGeometry& geometryN(size_t const& n);
	
	void addGeometry(SFGeometry* geometry);

	void addGeometry(const SFGeometry& geometry);
	
	// iterator begin() ;
	// iterator end() ;

	//void accept(GeometryVisitor& visitor);
	//void accept(ConstGeometryVisitor& visitor) const ;
};