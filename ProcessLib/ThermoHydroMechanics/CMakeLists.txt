append_source_files(SOURCES)

add_library(ThermoHydroMechanics ${SOURCES})
if(BUILD_SHARED_LIBS)
    install(TARGETS ThermoHydroMechanics
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
endif()
target_link_libraries(ThermoHydroMechanics
                      PUBLIC ProcessLib
                      PRIVATE ParameterLib)

if(BUILD_TESTING)
    include(Tests.cmake)
endif()
