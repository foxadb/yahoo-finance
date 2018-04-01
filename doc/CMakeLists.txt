find_package (Doxygen)
if (NOT DOXYGEN_FOUND)
    message ("Doxygen not found, documentation will not be generate/install")
else ()
    configure_file (doxy.rc Doxyfile)

    set (DOXYGEN_INPUT ${CMAKE_BINARY_DIR}/doc/Doxyfile)
    set (DOXYGEN_OUTPUT ${APIDOC_DIR}/html/index.html)

    add_custom_target (doc ALL
        COMMAND ${CMAKE_COMMAND} -E echo_append "Building documentation..."
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_INPUT} > /dev/null
        COMMAND ${CMAKE_COMMAND} -E echo "Done."
        )

    install (DIRECTORY ${CMAKE_BINARY_DIR}/doc/html
        DESTINATION share/doc/${CMAKE_PROJECT_NAME})

endif ()
