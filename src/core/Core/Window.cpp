
#include "Window.h"
#include "Core/Log.h"

namespace App {

Window::Window(const Settings& settings) {
  auto window_flags{static_cast<SDL_WindowFlags>(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI)};

  m_window = SDL_CreateWindow(settings.title.c_str(),
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      settings.width,
      settings.height,
      window_flags);

  auto renderer_flags{
      static_cast<SDL_RendererFlags>(SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED)};
  m_renderer = SDL_CreateRenderer(m_window, -1, renderer_flags);

  if (m_renderer == nullptr) {
    APP_ERROR("Error creating SDL_Renderer!");
    return;
  }
}

// Window::~Window() = default;

void Window::shutdown() {
  SDL_DestroyRenderer(m_renderer);
  SDL_DestroyWindow(m_window);

  m_renderer = nullptr;
  m_window = nullptr;
}

SDL_Window* Window::get_native_window() const {
  return m_window;
}

SDL_Renderer* Window::get_native_renderer() const {
  return m_renderer;
}

}