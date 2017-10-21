# set target name
set(TARGET_NAME rild)

include_directories(BEFORE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(SOURCE_FILES rild.c)

add_definitions( -DHAVE_ANDROID_OS )
add_definitions( -DRIL_SHLIB )

add_executable (${TARGET_NAME} ${SOURCE_FILES})
target_link_libraries(${TARGET_NAME} rilutils ril dl log cutils ${GLIB_LIBRARIES})

install ( TARGETS ${TARGET_NAME}
          RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
          ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
          LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} )

