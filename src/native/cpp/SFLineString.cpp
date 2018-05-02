/**
 * @author Hyung-Gyu Ryoo (hyungyu.ryoo@gmail.com)
 * @author Donguk Seo
 *
 */

#include "SFLineString.h"
SFLineString& SFLineString::operator=(const SFLineString& other) {
    data = other.data;

    return *this;
}

//--SFCGAL::Geometry
SFLineString* SFLineString::clone() const {
    return new SFLineString(*this);
}

std::string SFLineString::geometryType() const {
    return data->geometryType();
}

int SFLineString::geometryTypeId() const {
    return data->geometryTypeId();
}

int SFLineString::dimension() const {
    return data->dimension();
}

int SFLineString::coordinateDimension() const {
    return data->coordinateDimension();
}

bool SFLineString::isEmpty() const {
    return data->isEmpty();
}

bool SFLineString::is3D() const {
    return data->is3D();
}

bool SFLineString::isMeasured() const {
    return data->isMeasured();
}



void SFLineString::clear() {
    ((SFCGAL::LineString *)data)->clear();
}

void SFLineString::reverse() {
    ((SFCGAL::LineString *)data)->reverse();
}

size_t SFLineString::numPoints() const {
    return ((SFCGAL::LineString *)data)->numPoints();
}

size_t SFLineString::numSegments() const {
    return ((SFCGAL::LineString *)data)->numSegments();
}

const SFPoint& SFLineString::pointN( size_t const & n) const {
    return *(new SFPoint(((SFCGAL::LineString *)data)->pointN(n)));
}

SFPoint& SFLineString::pointN(size_t const& n) {
    return *(new SFPoint(((SFCGAL::LineString *)data)->pointN(n)));
}


const SFPoint& SFLineString::startPoint() const {
    return *(new SFPoint(((SFCGAL::LineString *)data)->startPoint()));
}

SFPoint& SFLineString::startPoint() {
    return *(new SFPoint(((SFCGAL::LineString *)data)->startPoint()));
}

const SFPoint& SFLineString::endPoint() const {
    return *(new SFPoint(((SFCGAL::LineString *)data)->endPoint()));
}

SFPoint& SFLineString::endPoint() {
    return *(new SFPoint(((SFCGAL::LineString *)data)->endPoint()));
}

void SFLineString::addPoint(const SFPoint& p){
    ((SFCGAL::LineString *)data)->addPoint( *(SFCGAL::Point *)(p.get_data()) );
}

void SFLineString::addPoint(SFPoint* p){
    ((SFCGAL::LineString *)data)->addPoint( *(SFCGAL::Point *)(p->get_data()) );
}

bool SFLineString::isClosed() const {
    return ((SFCGAL::LineString *)data)->isClosed();
}

// iterator begin() ;
// iterator end() ;

void SFLineString::reserve(const size_t& n){
    ((SFCGAL::LineString *)data)->reserve(n);
}