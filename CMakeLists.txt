cmake_minimum_required(VERSION 3.16.3)

project(IngaSdl)

if (UNIX)
    add_compile_options(-Wall -Wextra -pedantic -Wno-unused-parameter)
endif ()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/SDL2)

set(ERMENTRUD_BUILD False CACHE STRING "Enable this to change output name to Ermentrud")

# find sdl
find_package(SDL2 REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

set(INGA_SDL_SRC
        sources/cJSON.c
        sources/Cursor.c
        sources/Dialog.c
        sources/Element.c
        sources/Fader.c
        sources/Font.c
        sources/Game.c
        sources/Menu.c
        sources/GameConfig.c
        sources/GameState.c
        sources/Global.c
        sources/Image.c
        sources/ImageSet.c
        sources/InventoryBar.c
        sources/Location.c
        sources/NavigationMap.c
        sources/Script.c
        sources/Sequence.c
        sources/SlotList.c
        sources/SoundManager.c
        sources/Thread.c
        sources/Utils.c
        sources/
        sources/main.c
)
add_executable(${PROJECT_NAME}
        ${INGA_SDL_SRC}
)
target_include_directories(${PROJECT_NAME}
        PRIVATE sources
)

if (UNIX)
    message(STATUS "linux build")
    target_link_libraries(${PROJECT_NAME}
            PRIVATE SDL2::Main
            PRIVATE SDL2::Mixer
            PRIVATE SDL2::TTF
            PRIVATE m
    )
elseif (MORPHOS)
    message(STATUS "morphos build")
    target_link_libraries(${PROJECT_NAME}
            PRIVATE SDL2::Core SDL2::Mixer SDL2::TTF GL m
    )
    target_compile_definitions(${PROJECT_NAME}
            PRIVATE MOS_SDL2_WORKAROUND
    )
elseif (WIN32)
    message(STATUS "windows build")
    target_link_libraries(${PROJECT_NAME}
            PRIVATE SDL2::Main
            PRIVATE SDL2::Mixer
            PRIVATE SDL2::TTF
    )
endif ()

if (ERMENTRUD_BUILD)
    set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "Ermentrud")
endif ()
