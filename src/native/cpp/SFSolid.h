/**
 * @author Hyung-Gyu Ryoo (hyungyu.ryoo@gmail.com)
 * @author Donguk Seo
 *
 */

#ifndef JAVACPP_SFCGAL_Solid_H
#define JAVACPP_SFCGAL_Solid_H

#include <SFCGAL/Solid.h>
#include "SFPolyhedralSurface.h"

class SFSolid : public SFGeometry {
public:	
	SFSolid() : SFGeometry(new SFCGAL::Solid()) { }
	
	SFSolid(const std::vector< void * > & shells) {
		std::vector<SFCGAL::PolyhedralSurface>* cpp_base_shell = new std::vector<SFCGAL::PolyhedralSurface>();

		for(size_t i=0; i<shells.size(); i++){
			cpp_base_shell->push_back( *(SFCGAL::PolyhedralSurface *)(((SFPolyhedralSurface *)shells.at(i))->get_data()) );
		}

		data = new SFCGAL::Solid(*cpp_base_shell);
	}
    SFSolid(const SFPolyhedralSurface& exteriorShell) {
	    data = new SFCGAL::Solid(*(SFCGAL::PolyhedralSurface *)(exteriorShell.get_data()));
	}

	SFSolid(const SFCGAL::Solid& other) : SFGeometry(new SFCGAL::Solid(other)) { }
	
	SFSolid(SFCGAL::Solid* other) : SFGeometry(other) { }

	~SFSolid() { }

	SFSolid& operator=(const SFSolid& other);

	SFSolid* clone() const;

	std::string geometryType() const;
	int geometryTypeId() const;

	int dimension() const;
	int coordinateDimension() const;
	bool isEmpty() const;
	bool is3D() const;
	bool isMeasured() const;

	SFPolyhedralSurface& exteriorShell() const;

	SFPolyhedralSurface& exteriorShell();

	size_t numInteriorShells() const;

	const SFPolyhedralSurface& interiorShellN( size_t const & n) const;

	SFPolyhedralSurface& interiorShellN( size_t const & n);

	void addInteriorShell( const SFPolyhedralSurface& shell );

	void addInteriorShell( SFPolyhedralSurface* shell );

	size_t numShells() const;

	SFPolyhedralSurface& shellN( size_t const & n) const;

	SFPolyhedralSurface& shellN( size_t const & n);

	//iterator begin();
	//iterator begin() const;
	//iterator end();
	//iterator end() const;	

	//void accept(GeometryVisitor& visitor);
	//void accept(ConstGeometryVisitor& visitor) const ;
};

#endif
