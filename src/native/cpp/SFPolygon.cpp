/**
 * @author Hyung-Gyu Ryoo (hyungyu.ryoo@gmail.com)
 * @author Donguk Seo
 *
 */

#include "SFPolygon.h"

SFPolygon& SFPolygon::operator=(const SFPolygon& other) {
    data = other.data;

    return *this;
}



//--SFCGAL::Geometry
SFPolygon* SFPolygon::clone() const {
    return new SFPolygon(*this);
}

std::string SFPolygon::geometryType() const {
    return data->geometryType();
}

int SFPolygon::geometryTypeId() const {
    return data->geometryTypeId();
}

int SFPolygon::dimension() const {
    return data->dimension();
}

int SFPolygon::coordinateDimension() const {
    return data->coordinateDimension();
}

bool SFPolygon::isEmpty() const {
    return data->isEmpty();
}

bool SFPolygon::is3D() const {
    return data->is3D();
}

bool SFPolygon::isMeasured() const {
    return data->isMeasured();
}



bool SFPolygon::isCounterClockWiseOriented() {
    return ((SFCGAL::Polygon *)data)->isCounterClockWiseOriented();
}

void SFPolygon::reverse() {
    ((SFCGAL::Polygon *)data)->reverse();
}


SFLineString& SFPolygon::exteriorRing() const { // not used
    return *(new SFLineString(((SFCGAL::Polygon *)data)->exteriorRing()));
}

SFLineString& SFPolygon::exteriorRing() {
    return *(new SFLineString(((SFCGAL::Polygon *)data)->exteriorRing()));
}

void SFPolygon::setExteriorRing(const SFLineString& ring) {
    ((SFCGAL::Polygon *)data)->setExteriorRing(*(SFCGAL::LineString *)(ring.get_data()));
}
//void setExteriorRing(const SFCGAL::LineString& ring);

bool SFPolygon::hasInteriorRings() const {
    return ((SFCGAL::Polygon *)data)->hasInteriorRings();
}

size_t SFPolygon::numInteriorRings() const {
    return ((SFCGAL::Polygon *)data)->numInteriorRings();
}

const SFLineString& SFPolygon::interiorRingN(const size_t& n) const {
    return *(new SFLineString(((SFCGAL::Polygon *)data)->interiorRingN(n)));
}

SFLineString& SFPolygon::interiorRingN(const size_t& n) {
    return *(new SFLineString(((SFCGAL::Polygon *)data)->interiorRingN(n)));
}

size_t SFPolygon::numRings() const {
    return ((SFCGAL::Polygon *)data)->numRings();
}

const SFLineString& SFPolygon::ringN( size_t const & n) const {
    return *(new SFLineString(((SFCGAL::Polygon *)data)->ringN(n)));
}

SFLineString& SFPolygon::ringN( size_t const & n) {
    return *(new SFLineString(((SFCGAL::Polygon *)data)->ringN(n)));
}


void SFPolygon::addInteriorRing(const SFLineString& ls){
    ((SFCGAL::Polygon *)data)->addInteriorRing(*(SFCGAL::LineString *)(ls.get_data()));
}

void SFPolygon::addInteriorRing(SFLineString* ls){
    ((SFCGAL::Polygon *)data)->addInteriorRing(*(SFCGAL::LineString *)(ls->get_data()));
}
//void addInteriorRing(SFCGAL::LineString* ls);

void SFPolygon::addRing( const SFLineString& ls ) {
    ((SFCGAL::Polygon *)data)->addRing(*(SFCGAL::LineString *)(ls.get_data()));
}

void SFPolygon::addRing( SFLineString* ls ) {
    ((SFCGAL::Polygon *)data)->addRing(*(SFCGAL::LineString *)(ls->get_data()));
}