/**
 * @author Hyung-Gyu Ryoo (hyungyu.ryoo@gmail.com)
 *
 */

#pragma once

#include <stxxl/io>
#include <stxxl/vector>

#include "SFXBoundingBox.hpp"

namespace SFxxCGAL {

    class RandomGenerator {
    public:
        static void generatePoints
                (std::string path, SFXBoundingBox lower, SFXBoundingBox upper) {
            stxxl::syscall_file f(path, stxxl::file::DIRECT | stxxl::file::RDWR);
        }
        static void generateLines
                (std::string path, SFXBoundingBox lower, SFXBoundingBox upper) {
            stxxl::syscall_file f(path, stxxl::file::DIRECT | stxxl::file::RDWR);
        }
        static void generatePolygons
                (std::string path, SFXBoundingBox lower, SFXBoundingBox upper) {
            stxxl::syscall_file f(path, stxxl::file::DIRECT | stxxl::file::RDWR);
        }
        static void generateLines
                (std::string path, SFXBoundingBox lower, SFXBoundingBox upper) {
            stxxl::syscall_file f(path, stxxl::file::DIRECT | stxxl::file::RDWR);
        }
    private:

    };

}