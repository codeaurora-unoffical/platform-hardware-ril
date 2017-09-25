# set target name
set(TARGET_NAME ril)

include_directories(BEFORE
    ${CMAKE_SOURCE_DIR}/ril/include
    ${CMAKE_SOURCE_DIR}/ril/librilutils
    ${CMAKE_CURRENT_SOURCE_DIR}
)

macro(SYSR_INCLUDE_DIR subdir)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I =/usr/include/${subdir}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I =/usr/include/${subdir}")
endmacro()

SYSR_INCLUDE_DIR(hardware/ril/librilutils)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

## begin the tooling support for strlcpy() and strlcat()
    SYSR_INCLUDE_DIR(glib-2.0/include)
    SYSR_INCLUDE_DIR(glib-2.0)

    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I =/usr/lib/glib-2.0/include")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -include glib.h")

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I =/usr/lib/glib-2.0/include")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -include glib.h")

    add_definitions( -Dstrlcpy=g_strlcpy )
    add_definitions( -Dstrlcat=g_strlcat )
## end the support for strlcpy() and strlcat()

set(SOURCE_FILES ril.cpp ril_event.cpp RilSocket.cpp RilSapSocket.cpp)

add_library (${TARGET_NAME} SHARED ${SOURCE_FILES})
target_link_libraries(${TARGET_NAME} rilutils)
set_target_properties(${TARGET_NAME} PROPERTIES LINK_FLAGS 
"-Wl,-z,defs -lbinder -lprotobuf-nanopb -lpthread -llog -lcutils -lutils -lglib-2.0")

install ( TARGETS ${TARGET_NAME}
          RUNTIME DESTINATION bin
          ARCHIVE DESTINATION bin
          LIBRARY DESTINATION lib )

