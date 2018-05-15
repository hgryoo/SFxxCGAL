/**
 * @author Hyung-Gyu Ryoo (hyungyu.ryoo@gmail.com)
 *
 */

#pragma once

#include <stxxl/bits/common/binary_buffer.h>

namespace SFxxCGAL {

    class StorageManager {
    public:
        int read();
        int write();
        int append();
        int readHeader();
        int writeHeader();
    protected:
        stxxl::binary_buffer;
    };

}