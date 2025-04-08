# compile dynamic library xlog
set(LIBXLOG xlog)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/${LIBXLOG})

# compile dynamic library xvideo
set(LIBXVIDEO xvideo_edit)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/${LIBXVIDEO})

# compile module test_xlog
set(TESTXVIDEO test_xvideo)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/${TESTXVIDEO})
