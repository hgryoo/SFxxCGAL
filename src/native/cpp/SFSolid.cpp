/**
 * @author Hyung-Gyu Ryoo (hyungyu.ryoo@gmail.com)
 * @author Donguk Seo
 *
 */

#include "SFSolid.h"

SFSolid& SFSolid::operator=(const SFSolid& other) {
    data = other.data;

    return *this;
}

//--SFCGAL::Geometry
SFSolid* SFSolid::clone() const {
    return new SFSolid(*this);
}

std::string SFSolid::geometryType() const {
    return data->geometryType();
}

int SFSolid::geometryTypeId() const {
    return data->geometryTypeId();
}

int SFSolid::dimension() const {
    return data->dimension();
}

int SFSolid::coordinateDimension() const {
    return data->coordinateDimension();
}

bool SFSolid::isEmpty() const {
    return data->isEmpty();
}

bool SFSolid::is3D() const {
    return data->is3D();
}

bool SFSolid::isMeasured() const {
    return data->isMeasured();
}


SFPolyhedralSurface& SFSolid::exteriorShell() const {
    return *(new SFPolyhedralSurface(((SFCGAL::Solid *)data)->exteriorShell()));
}

SFPolyhedralSurface& SFSolid::exteriorShell() {
    return *(new SFPolyhedralSurface(((SFCGAL::Solid *)data)->exteriorShell()));
}

size_t SFSolid::numInteriorShells() const {
    return ((SFCGAL::Solid *)data)->numInteriorShells();
}

const SFPolyhedralSurface& SFSolid::interiorShellN( size_t const & n) const {
    return *(new SFPolyhedralSurface(((SFCGAL::Solid *)data)->interiorShellN(n)));
}

SFPolyhedralSurface& SFSolid::interiorShellN( size_t const & n) {
    return *(new SFPolyhedralSurface(((SFCGAL::Solid *)data)->interiorShellN(n)));
}

void SFSolid::addInteriorShell( const SFPolyhedralSurface& shell ) {
    ((SFCGAL::Solid *)data)->addInteriorShell(*(SFCGAL::PolyhedralSurface *)(shell.get_data()));
}

void SFSolid::addInteriorShell( SFPolyhedralSurface* shell ) {
    ((SFCGAL::Solid *)data)->addInteriorShell(*(SFCGAL::PolyhedralSurface *)(shell->get_data()));
}

size_t SFSolid::numShells() const {
    return ((SFCGAL::Solid *)data)->numShells();
}

SFPolyhedralSurface& SFSolid::shellN( size_t const & n) const {
    return *(new SFPolyhedralSurface(((SFCGAL::Solid *)data)->shellN(n)));
}

SFPolyhedralSurface& SFSolid::shellN( size_t const & n) {
    return *(new SFPolyhedralSurface(((SFCGAL::Solid *)data)->shellN(n)));
}

