
add_executable(who who.c utmpentry.c)

target_link_libraries(who PRIVATE compat)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    target_compile_definitions(who PRIVATE -DSUPPORT_UTMP)
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    target_compile_definitions(who PRIVATE -DSUPPORT_UTMPX)
endif()

INSTALL(TARGETS who DESTINATION ${CMAKE_INSTALL_BINDIR})

if(PROGRAM_PREFIX)
set_target_properties(who PROPERTIES PREFIX ${PROGRAM_PREFIX})
endif()

FILE(GLOB MAN1_FILES *.1)
IF(MAN1_FILES)
    INSTALL(FILES ${MAN1_FILES} DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)