
# Standard cmake version requirement
cmake_minimum_required(VERSION 2.6)

# Inform user
MESSAGE("Configuring nonlinear solver library.")

# Project (fortran must be enabled for OpenCMISS compatibility)
PROJECT( nas LANGUAGES C CXX Fortran )

# Add all the local source files from the folder "src" to the makefile
file(GLOB_RECURSE NAS_CPP_SRC_LIBRARY
	"*.hpp"
	"*.cpp"
)

#---- external packages ----#
# 1. MPI
find_package( MPI REQUIRED  ) 
include_directories(${MPI_INCLUDE_PATH})

#---- local packages ----#
# 2. Add the paths to the utility function lib and include
find_library(UTILITYFUNCTION_LIBRARY_PATH utilityFunctionLibrary HINTS "${UtilityFunctionLibrary_INSTALL_DIR}/lib")
# link_directories( ${UtilityFunctionLibrary_INSTALL_DIR}/lib )
include_directories( ${UtilityFunctionLibrary_INSTALL_DIR}/include )

# Add the execubale using the source files in (src)
add_library(nas SHARED
	${NAS_CPP_SRC_LIBRARY}
)

# Set version
set_target_properties(nas PROPERTIES SOVERSION 1)

# Link the local and external libraries to the executable
target_link_libraries( 
  nas
  mpi
  mpi_cxx
  ${MPI_LIBRARIES}
  ${UTILITYFUNCTION_LIBRARY_PATH}
)

# Set the install location
install(TARGETS nas
	LIBRARY DESTINATION lib
)
   
# Install the header files
INSTALL ( DIRECTORY ${CMAKE_SOURCE_DIR}/
  DESTINATION ${CMAKE_INSTALL_PREFIX}/include
  FILES_MATCHING PATTERN "*.hpp"
)

# Install the header files
INSTALL ( DIRECTORY ${CMAKE_SOURCE_DIR}/
  DESTINATION ${CMAKE_INSTALL_PREFIX}/include
  FILES_MATCHING PATTERN "*.h"
)




































