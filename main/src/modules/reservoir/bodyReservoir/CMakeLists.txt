# Copyright: (C) 2015 WYSIWYD Consortium
# Authors: Grégoire Pointeau
# CopyPolicy: Released under the terms of the GNU GPL v2.0.

set(PROJECTNAME bodyReservoir)
project(${PROJECTNAME})


file(GLOB folder_source src/*.cpp src/*.cc src/*.c)
file(GLOB folder_header include/*.h  )
set(doc_files ${PROJECTNAME}.xml)


source_group("Header Files" FILES ${folder_header})
source_group("Source Files" FILES ${folder_source})
source_group("DOC Files"    FILES ${doc_files})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${wrdac_INCLUDE_DIRS} ${YARP_INCLUDE_DIRS})

add_executable(${PROJECTNAME} ${folder_header} ${folder_source} ${doc_files})
target_link_libraries(${PROJECTNAME} wrdac ${YARP_LIBRARIES})
set_target_properties(${PROJECTNAME} PROPERTIES FOLDER tools)
install(TARGETS ${PROJECTNAME} DESTINATION bin)
yarp_install(FILES ${doc_files} DESTINATION ${WYSIWYD_MODULES_INSTALL_DIR})

