# set target name
set(TARGET_NAME rild)

include_directories(BEFORE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(SOURCE_FILES rild.c)

add_definitions( -DHAVE_ANDROID_OS )
add_definitions( -DRIL_SHLIB )

add_definitions( -Dstrlcpy=g_strlcpy )
add_definitions( -Dstrlcat=g_strlcat )

add_executable (${TARGET_NAME} ${SOURCE_FILES})
target_link_libraries(${TARGET_NAME} rilutils ril)
set_target_properties(${TARGET_NAME} PROPERTIES LINK_FLAGS "-ldl -llog -lglib-2.0 -lcutils")

install ( TARGETS ${TARGET_NAME}
          RUNTIME DESTINATION bin
          ARCHIVE DESTINATION bin
          LIBRARY DESTINATION lib )

