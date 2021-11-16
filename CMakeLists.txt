cmake_minimum_required(VERSION 3.16)

project(guile-embed-example VERSION 0.0.1)

find_package(PkgConfig)

pkg_check_modules(GUILE guile-3.0 REQUIRED IMPORTED_TARGET)

add_executable(guile-test guile-test.cc)

target_link_libraries(guile-test PkgConfig::GUILE)

target_compile_options(guile-test
    PRIVATE
        $<$<CONFIG:Debug>:-Wall -Wextra -pedantic -Wshadow -Wunused -Wconversion>
)

install(TARGETS guile-test DESTINATION "." RUNTIME DESTINATION bin)
