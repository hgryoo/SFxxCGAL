# Locate SIDX library
# This module defines
#  SIDX_FOUND, if false, do not try to link to libstxxl
#  SIDX_LIBRARY
#  SIDX_INCLUDE_DIR
#
IF( NOT SIDX_FIND_QUIETLY )
    MESSAGE(STATUS "Looking for SIDX...")
ENDIF()

FIND_PATH(SIDX_INCLUDE_DIR SpatialIndex.h
        HINTS
        $ENV{SIDX_DIR}
        ${SIDX_DIR_SEARCH}
        PATH_SUFFIXES libspatialindex libspatialindex/include/spatialindex include/spatialindex spatialindex
        )

FIND_LIBRARY(SIDX_LIBRARY
        NAMES spatialindex spatialindex_c
        HINTS
        $ENV{SIDX_DIR}
        ${SIDX_DIR_SEARCH}
        PATH_SUFFIXES bin libspatialindex/bin
        )

FIND_LIBRARY(SIDX_LIBRARY_C
        NAMES spatialindex_c
        HINTS
        $ENV{SIDX_DIR}
        ${SIDX_DIR_SEARCH}
        PATH_SUFFIXES bin libspatialindex/bin
        )

INCLUDE(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set SIDX_FOUND to TRUE if
# all listed variables are TRUE
FIND_PACKAGE_HANDLE_STANDARD_ARGS(SIDX  DEFAULT_MSG  SIDX_LIBRARY SIDX_LIBRARY_C SIDX_INCLUDE_DIR)

IF( NOT SIDX_FIND_QUIETLY )
    IF( SIDX_FOUND )
        MESSAGE(STATUS "Found SIDX: ${SIDX_LIBRARY}" )
    ENDIF()
ENDIF()

MARK_AS_ADVANCED(SIDX_INCLUDE_DIR SIDX_LIBRARY SIDX_LIBRARY_C)