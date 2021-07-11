cmake_minimum_required(VERSION 3.14)

set(CUR_TARGET SubStudio)

SET(CMAKE_MODULE_PATH
	${CMAKE_SOURCE_DIR}/cmake
)

if (WIN32)
    project(${CUR_TARGET} LANGUAGES CXX)
elseif (UNIX)
    project(${CUR_TARGET})
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets Multimedia MultimediaWidgets REQUIRED)

# libvlc
include_directories(${LIBVLC_INCLUDE_DIR})
find_package(LIBVLC REQUIRED)

# libvlc
include_directories(${PROJECT_SOURCE_DIR}/lib/libvlcpp)

set(source_dir ${PROJECT_SOURCE_DIR}/src)
set(forms_dir ${PROJECT_SOURCE_DIR}/forms)

file(GLOB source_files 
	${source_dir}/*.cpp
)
file(GLOB header_files 
	${source_dir}/*.h
	${source_dir}/*.hpp
)
file(GLOB form_files
	${forms_dir}/*.ui
)

qt5_add_resources(RESOURCE_ADDED ${PROJECT_SOURCE_DIR}/Resources.qrc)

if (WIN32)
	list(APPEND source_files ${source_dir}/version.h)
endif()

source_group("Source Files" FILES ${source_files})
source_group("Header Files" FILES ${header_files})
source_group("Form Files" FILES ${form_files})

add_executable(${CUR_TARGET} WIN32 MACOSX_BUNDLE ${RESOURCE_ADDED} ${source_files} ${header_files} ${form_files})
target_link_libraries(${CUR_TARGET} Qt5::Widgets Qt5::Multimedia Qt5::MultimediaWidgets ${LIBVLC_LIBRARY} ${LIBVLCCORE_LIBRARY})

if (APPLE)
	configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/assets/MacOSXBundleInfo.plist.in
        ${CMAKE_CURRENT_BINARY_DIR}/assets/MacOSXBundleInfo.plist
    )

    set_target_properties(${CUR_TARGET} PROPERTIES
        MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_BINARY_DIR}/assets/MacOSXBundleInfo.plist
    )
endif()
