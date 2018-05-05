/**
 * @author Hyung-Gyu Ryoo (hyungyu.ryoo@gmail.com)
 * @author Donguk Seo
 *
 */
#pragma once

#include <SFCGAL/Envelope.h>
#include "SFCoordinate.h"

class SFLineString ;
class SFPolygon ;
class SFSolid ;
class SFPolyhedralSurface ;

class SFEnvelope {
	SFCGAL::Envelope data;
public:
	const SFCGAL::Envelope& get_data() const;
	SFCGAL::Envelope& get_data();

	SFEnvelope() : data() { }
	SFEnvelope(
			const double& xmin, const double& xmax,
			const double& ymin, const double& ymax) : data(xmin, xmax, ymin, ymax) { }
	SFEnvelope(
			const double& xmin, const double& xmax,
			const double& ymin, const double& ymax,
			const double& zmin, const double& zmax) : data(xmin, xmax, ymin, ymax, zmin, zmax) { }
	SFEnvelope(const SFCoordinate& p) : data(p.get_data()) { }
	SFEnvelope(const SFCoordinate& p1, const SFCoordinate& p2) : data(p1.get_data(), p2.get_data()) { }
	SFEnvelope(const SFEnvelope& other) : data(other.data) { }
	SFEnvelope(const SFCGAL::Envelope& other) : data(other) { }

	~SFEnvelope() { }

	SFEnvelope& operator=(const SFEnvelope& other);

	bool isEmpty() const;

	bool is3D() const;

	void expandToInclude(const SFCoordinate& coordinate);

	const double& xMin() const;

	const double& yMin() const;

	const double& zMin() const;

	const double& xMax() const;

	const double& yMax() const;

	const double& zMax() const;

	static bool contains(const SFEnvelope& a, const SFEnvelope& b) {
		return SFCGAL::Envelope::contains(a.data, b.data);
	}

	static bool overlaps(const SFEnvelope& a, const SFEnvelope& b) {
		return SFCGAL::Envelope::overlaps(a.data, b.data);
	}
	SFLineString& toRing() const;

	SFPolygon& toPolygon() const;

	SFSolid& toSolid() const;

	bool operator==(const SFEnvelope& other);
};