/**
 * @author Hyung-Gyu Ryoo (hyungyu.ryoo@gmail.com)
 * @author Donguk Seo
 *
 */

#include "SFEnvelope.h"

#include "SFLineString.h"
#include "SFPolygon.h"
#include "SFSolid.h"
#include "SFPolyhedralSurface.h"
const SFCGAL::Envelope& SFEnvelope::get_data() const { return data; }
SFCGAL::Envelope& SFEnvelope::get_data() { return data; }

SFEnvelope& SFEnvelope::operator=(const SFEnvelope& other) {
    data = other.data;

    return *this;
}

bool SFEnvelope::isEmpty() const {
    return data.isEmpty();
}

bool SFEnvelope::is3D() const {
    return data.is3D();
}

void SFEnvelope::expandToInclude(const SFCoordinate& coordinate) {
    data.expandToInclude(coordinate.get_data());
}

const double& SFEnvelope::xMin() const {
    return data.xMin();
}

const double& SFEnvelope::yMin() const {
    return data.yMin();
}

const double& SFEnvelope::zMin() const {
    return data.zMin();
}

const double& SFEnvelope::xMax() const {
    return data.xMax();
}

const double& SFEnvelope::yMax() const {
    return data.yMax();
}

const double& SFEnvelope::zMax() const {
    return data.zMax();
}

SFLineString& SFEnvelope::toRing() const {
    std::auto_ptr<SFCGAL::LineString> p = data.toRing();

    SFLineString *lineString = new SFLineString(p.release());

    return *lineString;
}

SFPolygon& SFEnvelope::toPolygon() const {
    std::auto_ptr<SFCGAL::Polygon> p = data.toPolygon();

    SFPolygon *polygon = new SFPolygon(p.release());

    return *polygon;
}

SFSolid& SFEnvelope::toSolid() const {
    std::auto_ptr<SFCGAL::Solid> p = data.toSolid();

    SFSolid *solid = new SFSolid(p.release());

    return *solid;
}

bool SFEnvelope::operator==(const SFEnvelope& other) {
    return (this->data == other.data);
}