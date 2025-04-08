message(STATUS "Configure LIBXLOG: ${LIBXLOG}")

################################################################################

# set source file
set(
    xlogFiles
    xlog_format.cpp
    log_xml_format.cpp
    log_console_output.cpp
    log_file_output.cpp
    logger.cpp
    xconfig.cpp
    x_exec.cpp
    user_input.cpp
    xdir.cpp
    log_fac.cpp
    test_class_in.cpp
)

# set install include file
set(
    xlogIncludeInstall
    xlog.h
    user_input.h
    xdir.h
    test_class_in.h
)

################################################################################

# compile shared library
add_library(${LIBXLOG} SHARED ${xlogFiles})

target_compile_definitions(${LIBXLOG} PRIVATE XLOG_EXPORTS)

# include path
target_include_directories(${LIBXLOG} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

# dependent file
target_link_libraries(${LIBXLOG} PRIVATE

)

# install lib
install(TARGETS ${LIBXLOG}
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)

# install include
install(FILES ${xlogIncludeInstall} DESTINATION include)
