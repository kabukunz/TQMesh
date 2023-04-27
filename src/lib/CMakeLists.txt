set( TQMESH_LIB TQMeshLib )

add_library( ${TQMESH_LIB}
    main.cpp
)

target_link_libraries( ${TQMESH_LIB}
  util
  algorithm
  extern_libs
)

install( TARGETS ${TQMESH_LIB} RUNTIME DESTINATION ${BIN} )
