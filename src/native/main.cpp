/**
 *   SFCGAL
 *
 *   Copyright (C) 2012-2013 Oslandia <infos@oslandia.com>
 *   Copyright (C) 2012-2013 IGN (http://www.ign.fr)
 *
 *   This library is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU Library General Public
 *   License as published by the Free Software Foundation; either
 *   version 2 of the License, or (at your option) any later version.
 *
 *   This library is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *   Library General Public License for more details.

 *   You should have received a copy of the GNU Library General Public
 *   License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */
#include <SFCGAL/MultiPolygon.h>
#include <SFCGAL/MultiPoint.h>
#include <SFCGAL/Coordinate.h>
#include <SFCGAL/Solid.h>

#include <SFCGAL/io/wkt.h>
#include <SFCGAL/algorithm/offset.h>

#include <string>

#include <stxxl/vector>
#include <stxxl/random>
#include <stxxl/sort>
#include <stxxl/io>
#include <stxxl/vector>
#include <stxxl/stream>

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

#include "cpp/SFCoordinate.h"
#include "cpp/SFPoint.h"
#include "cpp/SFSolid.h"
#include "cpp/SFAlgorithm.h"

using namespace SFCGAL;

typedef stxxl::VECTOR_GENERATOR< boost::shared_ptr<Geometry> >::result vector;
typedef stxxl::vector< std::string > wktVector;

class IndoorSpace {
private:
    std::string id;
    std::string geom;
public:
    IndoorSpace(std::string id, std::string solid) {
        this->id = id;
        this->geom = solid;
    }

    std::string getID() const {
        return id;
    }

    std::string getGeometry() const {
        return geom;
    }
};

class SolidUtil {
public:
    SFSolid* makeSolidbyEnvelope(SFPoint *l, SFPoint *u) {
        SFPoint *p1 = new SFPoint(l->x(), u->y(), l->z());
        SFPoint *p2 = new SFPoint(l->x(), l->y(), l->z());
        SFPoint *p3 = new SFPoint(u->x(), l->y(), l->z());
        SFPoint *p4 = new SFPoint(u->x(), u->y(), l->z());
        SFPoint *p5 = new SFPoint(l->x(), u->y(), u->z());
        SFPoint *p6 = new SFPoint(l->x(), l->y(), u->z());
        SFPoint *p7 = new SFPoint(u->x(), l->y(), u->z());
        SFPoint *p8 = new SFPoint(u->x(), u->y(), u->z());

        std::vector<void *> *dps1 = new std::vector<void *>();
        dps1->push_back(p1);
        dps1->push_back(p4);
        dps1->push_back(p3);
        dps1->push_back(p2);
        dps1->push_back(p1);

        std::vector<void *> *dps2 = new std::vector<void *>();
        dps2->push_back(p3);
        dps2->push_back(p4);
        dps2->push_back(p8);
        dps2->push_back(p7);
        dps2->push_back(p3);

        std::vector<void *> *dps3 = new std::vector<void *>();
        dps3->push_back(p5);
        dps3->push_back(p6);
        dps3->push_back(p7);
        dps3->push_back(p8);
        dps3->push_back(p5);

        std::vector<void *> *dps4 = new std::vector<void *>();
        dps4->push_back(p6);
        dps4->push_back(p5);
        dps4->push_back(p1);
        dps4->push_back(p2);
        dps4->push_back(p6);
        
        std::vector<void *> *dps5 = new std::vector<void *>();
        dps5->push_back(p2);
        dps5->push_back(p3);
        dps5->push_back(p7);
        dps5->push_back(p6);
        dps5->push_back(p2);

        std::vector<void *> *dps6 = new std::vector<void *>();
        dps6->push_back(p1);
        dps6->push_back(p5);
        dps6->push_back(p8);
        dps6->push_back(p4);
        dps6->push_back(p1);

        SFLineString *line1 = new SFLineString(*dps1);
        SFLineString *line2 = new SFLineString(*dps2);
        SFLineString *line3 = new SFLineString(*dps3);
        SFLineString *line4 = new SFLineString(*dps4);
        SFLineString *line5 = new SFLineString(*dps5);
        SFLineString *line6 = new SFLineString(*dps6);

        SFPolygon *poly1 = new SFPolygon(*line1);
        SFPolygon *poly2 = new SFPolygon(*line2);
        SFPolygon *poly3 = new SFPolygon(*line3);
        SFPolygon *poly4 = new SFPolygon(*line4);
        SFPolygon *poly5 = new SFPolygon(*line5);
        SFPolygon *poly6 = new SFPolygon(*line6);

        std::vector<void *> *surfaces = new std::vector<void *>();
        surfaces->push_back(poly1);
        surfaces->push_back(poly2);
        surfaces->push_back(poly3);
        surfaces->push_back(poly4);
        surfaces->push_back(poly5);
        surfaces->push_back(poly6);

        SFPolyhedralSurface *exteriorShell = new SFPolyhedralSurface(*surfaces);
        SFSolid *solid = new SFSolid(*exteriorShell);
        return solid;
    }
};

std::ostream& operator << (std::ostream& o, const IndoorSpace& obj)
{
    o << obj.getID() << " => " << std::endl << (obj.getGeometry()) << std::endl;
    return o;
}


void generateRandomBuildings(int x, int y, int z) {
    //const stxxl::internal_size_type block_size = sizeof(s) * 4096;
    typedef stxxl::vector<std::string> vector_type;
    typedef stxxl::VECTOR_GENERATOR<std::string>::result isVec;
    SolidUtil util;

    isVec vec;

    int num = 0;
    for(int i = 0; i < x - 1; i++) {
        for(int j = 0; j < y - 1; j++) {
            for(int k = 0; k < z - 1; k++) {
                std::string id = "C" + std::to_string(num++);
                SFSolid *s = util.makeSolidbyEnvelope(new SFPoint(i, j, k), new SFPoint(i + 1, j + 1, k + 1));
                std::string result = id + "," + s->asText() + "\n";
                delete s;
                //std::cout << result << std::endl;
                vec.push_back(result);
            }
        }
    }

    stxxl::file::unlink("./buildings.csv");
    stxxl::syscall_file out_file("./buildings.csv", stxxl::file::DIRECT | stxxl::file::RDWR | stxxl::file::CREAT);

    vector_type OutputVector(&out_file);
    int i = 0;
    for (isVec::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        if(i < 10) {
            std::cout << *it << std::endl;
        }
        OutputVector.push_back(*it); // add the value pointed by 'it' to OutputVector
    }

    /*
    int size = vec.size();
    for ( size_t i = 0; i < size; ++i ) {
        std::cout << i << std::endl;
        std::auto_ptr< Geometry > buffer( algorithm::offset( *g, 0.2*i ) );
        //std::cout << buffer->asText() << std::endl;
        outputVec.push_back(buffer->asText());
    }
    */
}

int main() {
    SFPoint *p1 = new SFPoint(0, 0, 0);
    SFPoint *p2 = new SFPoint(1, 1, 1);
    SFPoint *p3 = new SFPoint(0.5, 0.5, 0.3);

    SolidUtil util;
    SFSolid *s = util.makeSolidbyEnvelope(p1, p2);
    std::cout << s->asText() << std::endl;

    bool result = intersects3D(*s, *p3);
    std::cout << "intersects = " << result << std::endl;

    bool result2 = covers3D(*s, *p3);
    std::cout << "covers = " << result2 << std::endl;

    generateRandomBuildings(10, 10, 10);
    return 0;
}

/*
int main(){
    using stxxl::file;

    //vector vec;
    stxxl::timer tm(true); // start a timer

    file::unlink("./geom.wkt");
    stxxl::syscall_file output("./geom.wkt", file::RDWR | file::CREAT | file::DIRECT);
    wktVector outputVec(&output);

    std::cout << "Using first method: copying vector elements." << std::endl;

    std::auto_ptr< Geometry > g( io::readWkt("MULTIPOINT(0 0,5 6,3 2,7 1,4 1,3 5,2 9)") );
    for ( size_t i = 1; i < 100; ++i ) {
        std::cout << i << std::endl;
        std::auto_ptr< Geometry > buffer( algorithm::offset( *g, 0.2*i ) );
        //std::cout << buffer->asText() << std::endl;
        outputVec.push_back(buffer->asText());
    }

    std::cout << "Copied in " << tm.seconds() << " at "
              << (double)output.size() / tm.seconds() / 1024 / 1024 << " MiB/s" << std::endl;

    return 0 ;
}
*/