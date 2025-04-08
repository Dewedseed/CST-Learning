message(STATUS "Configure LIBXVIDEO: ${LIBXVIDEO}")

################################################################################

# set source file
set(
    xvideoFiles
    fftask.cpp
    xtask_fac.cpp
    xvideo_input.cpp
    test_class.cpp
)

# set install include file
set(
    xvideoIncludeInstall
    xtask.h
)

################################################################################

# compile shared library
add_library(${LIBXVIDEO} SHARED ${xvideoFiles})

# include path
target_include_directories(${LIBXVIDEO} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../xlog>
    $<INSTALL_INTERFACE:include>
)

# dependent library
target_link_libraries(${LIBXVIDEO} PRIVATE
                      ${LIBXLOG}
)

# install lib
install(TARGETS ${LIBXVIDEO}
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)

# install include
# install(FILES ${xvideoIncludeInstall} DESTINATION include)
