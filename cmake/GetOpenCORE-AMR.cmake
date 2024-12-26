include(ExternalProject)

set(PREFIX ${CMAKE_BINARY_DIR}/_deps/amr)
set(INSTALL_DIR ${PREFIX}/usr)
set(INCLUDE_DIR ${INSTALL_DIR}/include)
set(LIBRARY_SUFFIX a)

ExternalProject_Add(opencore-amr
    PREFIX ${PREFIX}
    DOWNLOAD_NO_PROGRESS ON
    URL https://downloads.sourceforge.net/project/opencore-amr/opencore-amr/opencore-amr-0.1.6.tar.gz
    URL_HASH SHA1=3c2c618a5a38757a530034f80aa5356789589bcc
    BUILD_IN_SOURCE ON
    CONFIGURE_COMMAND ./configure --prefix=${INSTALL_DIR} --with-pic
    BUILD_COMMAND make
    TEST_EXCLUDE_FROM_MAIN ON
    INSTALL_COMMAND make install
    INSTALL_DIR ${INSTALL_DIR}
    BUILD_BYPRODUCTS
        ${INSTALL_DIR}/lib/libopencore-amrnb.${LIBRARY_SUFFIX}
        ${INSTALL_DIR}/lib/libopencore-amrwb.${LIBRARY_SUFFIX}
)

file(MAKE_DIRECTORY ${INCLUDE_DIR})

# Create imported target for NB
add_library(AMR::libNB STATIC IMPORTED GLOBAL)
set_property(TARGET AMR::libNB PROPERTY IMPORTED_LOCATION
    ${INSTALL_DIR}/lib/libopencore-amrnb.${LIBRARY_SUFFIX})
set_property(TARGET AMR::libNB PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${INCLUDE_DIR})
set_property(TARGET AMR::libNB PROPERTY INTERFACE_COMPILE_DEFINITIONS HAVE_OPENCORE_AMR)
add_dependencies(AMR::libNB opencore-amr)

# Create imported target for WB
add_library(AMR::libWB STATIC IMPORTED GLOBAL)
set_property(TARGET AMR::libWB PROPERTY IMPORTED_LOCATION
    ${INSTALL_DIR}/lib/libopencore-amrwb.${LIBRARY_SUFFIX})
set_property(TARGET AMR::libWB PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${INCLUDE_DIR})
set_property(TARGET AMR::libWB PROPERTY INTERFACE_COMPILE_DEFINITIONS HAVE_OPENCORE_AMR)
add_dependencies(AMR::libWB opencore-amr)

# Optionally create a single 'AMR' INTERFACE target that links to both NB and WB
add_library(AMR_lib INTERFACE)
target_link_libraries(AMR_lib INTERFACE AMR::libNB AMR::libWB)
target_include_directories(AMR_lib INTERFACE ${INCLUDE_DIR})
target_compile_definitions(AMR_lib INTERFACE HAVE_OPENCORE_AMR)
add_dependencies(AMR_lib opencore-amr)
add_library(AMR::lib ALIAS AMR_lib)