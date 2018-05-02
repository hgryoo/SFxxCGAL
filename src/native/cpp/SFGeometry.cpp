/**
 * @author Hyung-Gyu Ryoo (hyungyu.ryoo@gmail.com)
 * @author Donguk Seo
 *
 */
#include "SFGeometry.h"

const SFCGAL::Geometry* SFGeometry::get_data() const { return data; }
SFCGAL::Geometry* SFGeometry::get_data() { return data; }

//--SFCGAL::Geometry
SFGeometry* SFGeometry::clone() const {
    if(data == NULL) return NULL;

    return new SFGeometry(data->clone());
}

std::string SFGeometry::geometryType() const {
    if(data == NULL) return "";

    return data->geometryType();
}

int SFGeometry::geometryTypeId() const {
    if(data == NULL) return -1;

    return data->geometryTypeId();
}

int SFGeometry::dimension() const {
    if(data == NULL) return -1;

    return data->dimension();
}

int SFGeometry::coordinateDimension() const {
    if(data == NULL) return -1;

    return data->coordinateDimension();
}

bool SFGeometry::isEmpty() const {
    if(data == NULL) return false;

    return data->isEmpty();
}


bool SFGeometry::is3D() const {
    if(data == NULL) return false;

    return data->is3D();
}

bool SFGeometry::isMeasured() const {
    if(data == NULL) return false;

    return data->isMeasured();
}

std::string SFGeometry::asText(const int& numDecimals) const {
    if(data == NULL) return "";

    return data->asText(numDecimals);
}

SFEnvelope& SFGeometry::envelope() const {
    return *(new SFEnvelope(data->envelope()));
}

SFGeometry& SFGeometry::boundary() const {	//virtual std::auto_ptr<Geometry> boundary() const;
    //if(data == NULL) return NULL;
    std::auto_ptr<SFCGAL::Geometry> p = data->boundary();

    SFGeometry *geometry = new SFGeometry(p.release());

    return *geometry;
}

double SFGeometry::distance(const SFGeometry& other) const {
    if(data == NULL) return -1;

    return data->distance(*(other.get_data()));
}

double SFGeometry::distance3D(const SFGeometry& other) const {
    if(data == NULL) return -1;

    return data->distance3D(*(other.get_data()));
}

void SFGeometry::round(const long& scale) {
    if(data == NULL) return ;

    data->round(scale);
}

size_t SFGeometry::numGeometries() const {
    //if(data == NULL) return -1;

    return data->numGeometries();
}

const SFGeometry& SFGeometry::geometryN(size_t const& n) const {
    return *(new SFGeometry(data->geometryN(n)));
}

SFGeometry& SFGeometry::geometryN(size_t const &n) {
    return *(new SFGeometry(data->geometryN(n)));
}

bool SFGeometry::operator==(const SFGeometry& other){
    return ( *data == *(other.data) );
}