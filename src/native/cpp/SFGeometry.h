/**
 * @author Hyung-Gyu Ryoo (hyungyu.ryoo@gmail.com)
 * @author Donguk Seo
 *
 */
#pragma once

#include <SFCGAL/Geometry.h>
#include "SFEnvelope.h"

class SFGeometry {
protected:
	SFCGAL::Geometry* data;
public:
	const SFCGAL::Geometry* get_data() const;
    SFCGAL::Geometry* get_data();
	
	SFGeometry() : data(NULL) { }
	SFGeometry(const SFGeometry& other) : data(other.data) { }
	SFGeometry(SFCGAL::Geometry& other) : data(&other){ }
	SFGeometry(SFCGAL::Geometry* other) : data(other){ }

	~SFGeometry() {
		if(data != NULL) delete data;
	}

	//--SFCGAL::Geometry
	virtual SFGeometry* clone() const;

	virtual std::string geometryType() const;
	
	virtual int geometryTypeId() const;
	
	virtual int dimension() const;
	
	virtual int coordinateDimension() const;

	virtual bool isEmpty() const;


	virtual bool is3D() const;
	
	virtual bool isMeasured() const;

	std::string asText(const int& numDecimals = -1) const;

	SFEnvelope& envelope() const;

	virtual SFGeometry& boundary() const;

	double distance(const SFGeometry& other) const;

	double distance3D(const SFGeometry& other) const;

	void round(const long& scale = 1);

	virtual size_t numGeometries() const;
	
	virtual const SFGeometry& geometryN(size_t const& n) const;

	virtual SFGeometry& geometryN(size_t const &n);

	bool operator==(const SFGeometry& other);
};