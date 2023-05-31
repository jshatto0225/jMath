# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later:
file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${ModernCMakeExample_SOURCE_DIR}/include/modern/*.h")
# set(HEADER_LIST "${ModernCMakeExample_SOURCE_DIR}./include/jMath/jMath.h")

# Make an automatic library - will be static or dynamic based on user setting
add_library(jMath jMath.cpp ${HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(jMath PUBLIC ../include)

# This depends on (header only) boost
target_link_libraries(jMath PRIVATE Boost::boost)

# All users of this library will need at least C++17
target_compile_features(jMath PUBLIC cxx_std_17)

# IDEs should put the headers in a nice place
source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})

