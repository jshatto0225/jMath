set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_BUILTIN_STL_SUPPORT YES)

# Source fiels just in case
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src)

# All Header files
file(GLOB HEADER_FILES ${CMAKE_SOURCE_DIR}/include/jMath)

doxygen_add_docs(docs ${HEADER_FILES} "${CMAKE_CURRENT_SOURCE_DIR}/mainpage.md"
                 WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/include")

