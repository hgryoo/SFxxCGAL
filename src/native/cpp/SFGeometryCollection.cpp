/**
 * @author Hyung-Gyu Ryoo (hyungyu.ryoo@gmail.com)
 * @author Donguk Seo
 *
 */

#include "SFGeometryCollection.h"

//--SFCGAL::Geometry
SFGeometryCollection* SFGeometryCollection::clone() const {
    return new SFGeometryCollection(*this);
}

std::string SFGeometryCollection::geometryType() const {
    return data->geometryType();
}

int SFGeometryCollection::geometryTypeId() const {
    return data->geometryTypeId();
}

int SFGeometryCollection::dimension() const {
    return data->dimension();
}

int SFGeometryCollection::coordinateDimension() const {
    return data->coordinateDimension();
}

bool SFGeometryCollection::isEmpty() const {
    return data->isEmpty();
}

bool SFGeometryCollection::is3D() const {
    return data->is3D();
}

bool SFGeometryCollection::isMeasured() const {
    return data->isMeasured();
}

size_t SFGeometryCollection::numGeometries() const {
    return data->numGeometries();
}


const SFGeometry& SFGeometryCollection::geometryN(size_t const& n) const {
    return *(new SFGeometry( ((SFCGAL::GeometryCollection *)data)->geometryN(n) ));
}

SFGeometry& SFGeometryCollection::geometryN(size_t const& n) {
    return *(new SFGeometry( ((SFCGAL::GeometryCollection *)data)->geometryN(n) ));
}

void SFGeometryCollection::addGeometry(SFGeometry* geometry) {
    ((SFCGAL::GeometryCollection *)data)->addGeometry(geometry->get_data());
}

void SFGeometryCollection::addGeometry(const SFGeometry& geometry){
    ((SFCGAL::GeometryCollection *)data)->addGeometry(*geometry.get_data());
}
