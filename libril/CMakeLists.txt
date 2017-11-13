# set target name
set(TARGET_NAME ril)

include_directories(BEFORE
    ${CMAKE_SOURCE_DIR}/ril/include
    ${CMAKE_SOURCE_DIR}/ril/librilutils
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ril.cpp ril_event.cpp RilSocket.cpp RilSapSocket.cpp)

add_library (${TARGET_NAME} SHARED ${SOURCE_FILES})
target_link_libraries(${TARGET_NAME} rilutils)
target_link_libraries(${TARGET_NAME} binder protobuf-nanopb pthread
    log cutils utils ${GLIB_LIBRARIES})
set_target_properties(${TARGET_NAME} PROPERTIES
                      LINK_FLAGS "-Wl,-z,defs"
                      VERSION 1.0.0
                      SOVERSION 1)

install ( TARGETS ${TARGET_NAME}
          RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
          ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
          LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} )
