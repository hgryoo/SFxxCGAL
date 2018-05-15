/**
 * @author Hyung-Gyu Ryoo (hyungyu.ryoo@gmail.com)
 *
 */
#pragma once

#include <SFCGAL/detail/generator/disc.h>
#include <SFCGAL/detail/generator/building.h>

typedef std::pair<stxxl::stats*, stxxl::stats_data*> StatsPair;
StatsPair createNewStats() {
    // generate stats instance
    stxxl::stats * stats = stxxl::stats::get_instance();

    // start measurement here
    stxxl::stats_data *stats_begin = new stxxl::stats_data(*stats);
    return StatsPair(stats, stats_begin);
}

void printStats(StatsPair& stats) {
    // some computation ...
    // substract current stats from stats at the beginning of the measurement
    std::cout << (stxxl::stats_data(*(stats.first)) - (*(stats.second)));
}

class SolidUtil {
public:
    SFSolid* makeSolidbyEnvelope(SFPoint *l, SFPoint *u) {
        SFEnvelope* env = new SFEnvelope(l->x(), u->x(), l->y(), u->y(), l->z(), u->z());
        SFSolid* solid = new SFSolid(env->toSolid());
        return solid;
    }
};

Geometry* generateRandomDisc(Point& p, double radius, int nQuadrantSegments = 8U, double wallHeight = 1.0, double roofSlope = 1.0) {
    std::auto_ptr< Polygon > randPoly = generator::disc(p, radius, nQuadrantSegments);
    std::auto_ptr< Geometry > building = generator::building(*(randPoly.release()), wallHeight, roofSlope);
    return building.release();
}

void testGeneratingBuildings(int x, int y, int z) {
    std::auto_ptr< GeometryCollection > result( new GeometryCollection() );
    for(int i = 0; i < x * 2; i=i+2) {
        for (int j = 0; j < y * 2; j=j+2) {
            stxxl::binary_buffer buffer;
            for (int k = 0; k < z * 2; k=k+2) {
                Point p(x, y, z);
                Geometry *g = generateRandomDisc(p, 1);
                result->addGeometry(*g);
                delete g;
            }
        }
    }
    io::osgWriteFile( *result, "./test.osg" );
}

//Test 1 : Robustness Test using STL
void robustness_stl_test() {
    std::cout << "===================================" << std::endl;
    std::cout << "TEST1 => Robustness Test using STL" << std::endl;
    std::cout << "===================================" << std::endl;
}

//Test 2 : Robustness Test using STxxL
void robustness_stxxl_test() {
    std::cout << "====================================" << std::endl;
    std::cout << "TEST2 => Robustness Test using STxxL" << std::endl;
    std::cout << "====================================" << std::endl;
}

//Test 3 : Improvement 1 : Spatial Indexing -> Sorting by x, y, z
void improvement_one_test() {
    std::cout << "====================================" << std::endl;
    std::cout << "TEST3 => Improvement Sorting by Axis" << std::endl;
    std::cout << "====================================" << std::endl;
}

//Test 4 : Improvement 2 : Hilbert Curve
void improvement_two_test() {
    std::cout << "===========================================" << std::endl;
    std::cout << "TEST4 => Improvement Sorting by HilberCurve" << std::endl;
    std::cout << "===========================================" << std::endl;
}

