message(STATUS "Configure TESTXVIDEO: ${TESTXVIDEO}")

set(EXENAME test_xvideo)

################################################################################

# comile executable
add_executable(${EXENAME} ${EXENAME}.cpp)

# link library
target_link_libraries(${EXENAME} PRIVATE
                      ${LIBXLOG}
                      ${LIBXVIDEO}
)

# intall executable
install(TARGETS ${EXENAME} RUNTIME DESTINATION bin)
