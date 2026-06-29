cmake_minimum_required(VERSION 3.16)
project(gex2_decomp C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Warnings — keep this strict to catch decomp mistakes early
if(MSVC)
    add_compile_options(/W3)
else()
    add_compile_options(-Wall -Wextra -Wno-unused-parameter -Wno-unused-variable)
endif()

# Core game library (decompiled C)
add_library(gex2_game STATIC
    src/core/bigfile.c
    src/core/script_exec.c
    src/core/utils.c
    src/game/object.c
    src/game/camera.c
    # TODO: add as decompiled
    # src/game/level.c
    # src/game/player.c
    # src/game/physics.c
    # src/audio/dnsc.c
    # src/render/a8aa.c
    # src/render/vram.c
    # src/render/gpu_ps1.c
    # src/port/gte.c
    # src/port/spu.c
)

target_include_directories(gex2_game PUBLIC include)

# Global definitions for known PS1 address values (documentation only —
# on PC these become regular globals defined in globals.c)
target_compile_definitions(gex2_game PRIVATE
    GEX2_PS1_BUILD=0
    GEX2_VERSION_STRING="SLUS-00598"
)

# Test harness — exercises confirmed decompiled functions
add_executable(gex2_tests
    tests/test_bigfile_hash.c
    tests/test_script_exec.c
)
target_link_libraries(gex2_tests gex2_game)
target_include_directories(gex2_tests PRIVATE include)

# Eventually: LUS integration target
# add_subdirectory(libultraship)
# add_executable(gex2 src/main.cpp ...)
# target_link_libraries(gex2 gex2_game libultraship ...)
