cmake_minimum_required(VERSION 3.16)
get_filename_component(name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${name})
find_package(SWIG 4.0 COMPONENTS python java)
find_package(Python COMPONENTS Development Interpreter)
find_package(JNI)
file(GLOB src _common/*.cxx)
add_library(wrap ${src})
target_include_directories(wrap PUBLIC _common)
target_link_libraries(wrap tinySIP tinyDAV tinySMS tinyXCAP)

if(SWIG_FOUND)
    include(${SWIG_USE_FILE})
    set_property(SOURCE _common/tinyWRAP.i PROPERTY CPLUSPLUS ON)

    if(Python_Development_FOUND)
        swig_add_library(pyWRAP LANGUAGE python OUTPUT_DIR python SOURCES _common/tinyWRAP.i)
        target_include_directories(pyWRAP PUBLIC ${Python_INCLUDE_DIRS})
        set_target_properties(pyWRAP PROPERTIES LIBRARY_OUTPUT_DIRECTORY python)
        target_link_libraries(pyWRAP wrap)

        # Create setup.py
        file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/python/setup.py [[
from setuptools import setup
setup(name='tinyWRAP',
    version='1.0',
    py_modules=['tinyWRAP'],
    packages=[''],
    package_dir={'': '.'},
    package_data={'': ['_pyWRAP.so']},
)
]])

        # Add wheel creation as part of the main build
        add_custom_command(
            TARGET pyWRAP POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/python/dist
            COMMAND ${Python_EXECUTABLE} -m pip wheel --no-deps -w dist .
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/python
        )

        # Modify installation to use the wheel
        install(CODE "
            if(EXISTS \"${CMAKE_CURRENT_BINARY_DIR}/python/dist/tinyWRAP-1.0-py3-none-any.whl\")
                execute_process(
                    COMMAND ${Python_EXECUTABLE} -m pip install --force-reinstall \"${CMAKE_CURRENT_BINARY_DIR}/python/dist/tinyWRAP-1.0-py3-none-any.whl\"
                    RESULT_VARIABLE pip_result
                )
                if(NOT pip_result EQUAL 0)
                    message(FATAL_ERROR \"Failed to install wheel package\")
                endif()
            else()
                message(FATAL_ERROR \"Wheel file not found at ${CMAKE_CURRENT_BINARY_DIR}/python/dist/tinyWRAP-1.0-py3-none-any.whl\")
            endif()
        ")
        
        # Add installation of the wheel file
        install(
            FILES ${CMAKE_CURRENT_BINARY_DIR}/python/dist/tinyWRAP-1.0-py3-none-any.whl
            DESTINATION wheels
            COMPONENT python
            OPTIONAL
        )
    endif()

    if(JNI_FOUND)
        swig_add_library(jWRAP LANGUAGE java SOURCES *common/tinyWRAP.i OUTPUT*DIR java)
        target_include_directories(jWRAP PUBLIC ${JNI_INCLUDE_DIRS})
        set_target_properties(jWRAP PROPERTIES LIBRARY_OUTPUT_DIRECTORY java)
        target_link_libraries(jWRAP wrap)
    endif()
endif()