cmake_minimum_required( VERSION 2.8 )
project( SFCGAL )

set( CMAKE_DEBUG_POSTFIX "d" )

#----------------------------------------------------------------------------
# build options
#----------------------------------------------------------------------------
# Set a default build type if none was specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to 'Release' as none was specified.")
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
    # Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "RelWithDebInfo")
endif()

#-- include finders and co
set( CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules;${CMAKE_MODULE_PATH}" )

set( SFCGAL4J_VERSION_MAJOR 1 )
set( SFCGAL4J_VERSION_MINOR 0 )
set( SFCGAL4J_VERSION_PATCH 0 )

set( SFCGAL4J_VERSION "${SFCGAL4J_VERSION_MAJOR}.${SFCGAL4J_VERSION_MINOR}.${SFCGAL4J_VERSION_PATCH}" )

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS " -pthread ")

set( INSTALL_PATH "${CMAKE_SOURCE_DIR}/cppbuild/linux-x86_64" )

set( CGAL_DIR "${INSTALL_PATH}/lib/CGAL")
set( SFCGAL_DIR "${INSTALL_PATH}")
set( CGAL_CORE_PACKAGE_DIR "${INSTALL_PATH}")
set( STXXL_DIR_SEARCH "${INSTALL_PATH}")
set( BOOST_ROOT "${INSTALL_PATH}")
set( SIDX_DIR_SEARCH "${INSTALL_PATH}")

macro(build_tool PROGNAME)
    add_executable(${PROGNAME} ${PROGNAME}.cpp ${ARGN})
    target_link_libraries(${PROGNAME}
            ${SIDX_LIBRARY}
            ${STXXL_LIBRARY}
            ${SFCGAL_LIBRARIES}
            ${CGAL_LIBRARIES}
            ${MPFR_LIBRARIES}
            ${GMP_LIBRARIES}
            ${Boost_LIBRARIES}
            )
endmacro(build_tool)

# Boost and its components
find_package( Boost REQUIRED )
if ( NOT Boost_FOUND )
    message(STATUS "This project requires the Boost library, and will not be compiled.")
    return()
endif()

# CGAL and its components
find_package( CGAL COMPONENTS Core REQUIRED )
if ( NOT CGAL_FOUND )
    message(STATUS "This project requires the CGAL library, and will not be compiled.")
    return()
endif()
# include helper file
include( ${CGAL_USE_FILE} )

find_package( SFCGAL REQUIRED )
if ( NOT SFCGAL_FOUND )
    message(STATUS "This project requires the SFCGAL library, and will not be compiled.")
    return()
endif()

find_package( STXXL REQUIRED )
if ( NOT STXXL_FOUND )
    message(STATUS "This project requires the STXXL library, and will not be compiled.")
    return()
endif()

find_package( SIDX REQUIRED )
if ( NOT SIDX_FOUND )
    message(STATUS "This project requires the SIDX library, and will not be compiled.")
    return()
endif()

add_subdirectory (src/native)

