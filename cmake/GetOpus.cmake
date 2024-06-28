include(ExternalProject)

set(PREFIX ${CMAKE_BINARY_DIR}/_deps/opus)
set(OPUS_INSTALL_DIR ${PREFIX}/usr)
set(OPUS_INCLUDE_DIR ${OPUS_INSTALL_DIR}/include)
set(OPUS_LIBRARY_SUFFIX a)

ExternalProject_Add(opus
    PREFIX ${PREFIX}
    DOWNLOAD_NO_PROGRESS ON
    URL https://downloads.xiph.org/releases/opus/opus-1.5.2.tar.gz
    URL_HASH SHA256=65c1d2f78b9f2fb20082c38cbe47c951ad5839345876e46941612ee87f9a7ce1
    BUILD_IN_SOURCE ON
    CONFIGURE_COMMAND ./configure --prefix=${OPUS_INSTALL_DIR} --with-pic
    BUILD_COMMAND make
    TEST_EXCLUDE_FROM_MAIN ON
    INSTALL_COMMAND make install
    INSTALL_DIR ${OPUS_INSTALL_DIR}
    BUILD_BYPRODUCTS ${OPUS_INSTALL_DIR}/lib/libopus.${OPUS_LIBRARY_SUFFIX}
)

file(MAKE_DIRECTORY ${OPUS_INCLUDE_DIR})

add_library(Opus::lib STATIC IMPORTED GLOBAL)
set_property(TARGET Opus::lib PROPERTY IMPORTED_LOCATION ${OPUS_INSTALL_DIR}/lib/libopus.${OPUS_LIBRARY_SUFFIX})
set_property(TARGET Opus::lib PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${OPUS_INCLUDE_DIR})
set_property(TARGET Opus::lib PROPERTY INTERFACE_COMPILE_DEFINITIONS HAVE_LIBOPUS)
add_dependencies(Opus::lib opus)

