set(NAME "Core")

include(${PROJECT_SOURCE_DIR}/cmake/StaticAnalyzers.cmake)

add_library(${NAME} STATIC
  Core/Log.cpp
  Core/Log.h
  Core/Application.cpp
  Core/Application.h
  Core/Window.cpp
  Core/Window.h

  Core/Debug/Instrumentor.h
)

target_include_directories(${NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(${NAME} PRIVATE cxx_std_20)
target_link_libraries(${NAME} 
  PRIVATE
    project_warnings
  PUBLIC 
    fmt
    spdlog
    SDL2::SDL2
    imgui
)
