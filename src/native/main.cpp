#include <SFCGAL/Geometry.h>
#include <SFCGAL/MultiPolygon.h>
#include <SFCGAL/MultiPoint.h>
#include <SFCGAL/Coordinate.h>
#include <SFCGAL/Solid.h>

#include <SFCGAL/io/wkt.h>
#include <SFCGAL/io/GeometryStreams.h>
#include <SFCGAL/io/vtk.h>
#include <SFCGAL/detail/io/Serialization.h>
#include <SFCGAL/algorithm/offset.h>
#include <SFCGAL/io/osg.h>

#include <string>

#include <stxxl/vector>
#include <stxxl/random>
#include <stxxl/sort>
#include <stxxl/io>
#include <stxxl/vector>
#include <stxxl/stream>
#include <stxxl/bits/common/binary_buffer.h>
#include <stxxl/bits/common/rand.h>

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

#include "cpp/SFCoordinate.h"
#include "cpp/SFPoint.h"
#include "cpp/SFSolid.h"
#include "cpp/SFAlgorithm.h"
#include "cpp/SFEnvelope.h"

#include "include/Experiments.hpp"

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

    stxxl::binary_buffer buffer;
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

void generateBuildings(int x, int y, int z) {
    std::auto_ptr< GeometryCollection > result( new GeometryCollection() );

    typedef stxxl::VECTOR_GENERATOR<char>::result Byte;
    stxxl::syscall_file* input_file = NULL, * output_file = NULL;

    Byte vec;

    SolidUtil util;
    std::cout << "Random Building Generator in " << x << " * " << y << " * " << z << std::endl;
    for(int i = 0; i < x; i=i+2) {
        for (int j = 0; j < y; j=j+2) {
            stxxl::binary_buffer buffer;
            for (int k = 0; k < z; k=k+2) {
                SFSolid *s = util.makeSolidbyEnvelope(new SFPoint(i, j, k), new SFPoint(i + 1, j + 1, k + 1));
                buffer.put_string(io::writeBinaryGeometry(*(s->get_data())));
                delete s;
                //result->addGeometry(s->get_data());
            }

            stxxl::binary_reader br(buffer);
            std::string ss = br.get_string();
            //vec.push_back(ss.get_string());

        }
    }

    output_file = new stxxl::syscall_file("./buildings", stxxl::file::RDWR | stxxl::file::CREAT | stxxl::file::DIRECT);


    std::cout << "generating finished" << std::endl;

    //std::cout << buffer.size() << std::endl;

    //io::osgWriteFile( *result, "./building.osg" );

    std::cout << "writing osg file finished" << std::endl;
}

int main() {
    StatsPair stats = createNewStats();

    SFPoint *p1 = new SFPoint(0, 0, 0);
    SFPoint *p2 = new SFPoint(1, 1, 1);
    SFPoint *p3 = new SFPoint(0.5, 0.5, 0.3);

    /*
    SolidUtil util;
    SFSolid *s = util.makeSolidbyEnvelope(p1, p2);
    std::cout << s->asText() << std::endl;

    bool result = intersects3D(*s, *p3);
    std::cout << "intersects = " << result << std::endl;

    bool result2 = covers3D(*s, *p3);
    std::cout << "covers = " << result2 << std::endl;
    */
    testGeneratingBuildings(100, 100, 100);

    printStats(stats);

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