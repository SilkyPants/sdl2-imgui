include(FetchContent)

FetchContent_Declare(
  doctest
  GIT_REPOSITORY "https://github.com/onqtam/doctest.git"
  GIT_TAG v2.4.10
)
add_subdirectory(doctest)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY "https://github.com/fmtlib/fmt.git"
  GIT_TAG 9.1.0
)
add_subdirectory(fmt)

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
  GIT_TAG v1.11.0
)
add_subdirectory(spdlog)

# vendor/IMGui
FetchContent_Declare(
  imgui
  GIT_REPOSITORY "https://github.com/ocornut/imgui.git"
  GIT_TAG f8704cd085c4347f835c21dc12a3951924143872 #v1.89.8 (docking branch)
)
add_subdirectory(imgui)

# SDL 2
FetchContent_Declare(
  SDL2
  GIT_REPOSITORY "https://github.com/libsdl-org/SDL.git"
  GIT_TAG release-2.28.2
)
add_subdirectory(sdl)