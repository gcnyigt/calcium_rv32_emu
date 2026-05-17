cmake_minimum_required(VERSION 3.10)
project(calcium C)
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -g)
include_directories(.)
add_custom_target(RunBootromScript ALL
    COMMAND chmod +x build_bootrom.sh
    COMMAND ./build_bootrom.sh
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/bootrom
)

add_executable(calcium 
    main.c 
    include/decoder.c
    include/addr_space.c
    include/terminal.c
)
add_dependencies(calcium RunBootromScript)
target_include_directories(calcium PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
