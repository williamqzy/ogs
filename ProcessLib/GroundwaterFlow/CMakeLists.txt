append_source_files(SOURCES)

add_library(GroundwaterFlow ${SOURCES})
if(BUILD_SHARED_LIBS)
    install(TARGETS GroundwaterFlow LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
endif()

target_link_libraries(GroundwaterFlow PUBLIC ProcessLib PRIVATE ParameterLib)

if(BUILD_TESTING)
    include(Tests.cmake)
endif()
