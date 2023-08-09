
#include <imgui.h>
#include <backends/imgui_impl_sdl2.h>
#include <backends/imgui_impl_sdlrenderer2.h>
#include <cmath>

#include "Application.h"

#include "Core/Log.h"

// const int mapX  8      //map width
// const int mapY  8      //map height
// const int mapS 64      //map cube size
// const int map[]=           //the map array. Edit to change level but keep the outer walls
// {
//  1,1,1,1,1,1,1,1,
//  1,0,1,0,0,0,0,1,
//  1,0,1,0,0,0,0,1,
//  1,0,1,0,0,0,0,1,
//  1,0,0,0,0,0,0,1,
//  1,0,0,0,0,1,0,1,
//  1,0,0,0,0,0,0,1,
//  1,1,1,1,1,1,1,1,	
// };

float deg_to_rad(int angle) { return (float)angle *(float)M_PI/180.0F;}
int clamp_angle(int angle){ if(angle>359){ angle-=360;} if(angle<0){ angle+=360;} return angle;}

namespace App {

Application::Application() {
  const unsigned int init_flags{SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER};

  if (SDL_Init(init_flags) != 0) {
    APP_ERROR("Error: %s\n", SDL_GetError());
    m_exit_status = 1;
  }

  m_window = std::make_unique<Window>(
    Window::Settings {
      "Application",
      1024,
      510
    }
  );
}

Application::~Application() {
  ImGui_ImplSDLRenderer2_Shutdown();
  ImGui_ImplSDL2_Shutdown();
  ImGui::DestroyContext();

  SDL_Quit();
}

int App::Application::run() {
  if (m_exit_status == 1) {
    return m_exit_status;
  }

  // Setup ImGui
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO &io { ImGui::GetIO() };

  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
  io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

  ImGui_ImplSDL2_InitForSDLRenderer(
    m_window->get_native_window(),
    m_window->get_native_renderer()
  );

  ImGui_ImplSDLRenderer2_Init(m_window->get_native_renderer());

  m_running = true;
  while (m_running) {

    //TODO: Move to polling function
    SDL_Event event {};
    while (SDL_PollEvent(&event) == 1) {
      ImGui_ImplSDL2_ProcessEvent(&event);

      if (event.type == SDL_QUIT) {
        stop();
      }
    }
    
    // Start the Dear ImGui frame
    ImGui_ImplSDLRenderer2_NewFrame();
    ImGui_ImplSDL2_NewFrame();

    ImGui::NewFrame();
    ImGui::DockSpaceOverViewport(nullptr, ImGuiDockNodeFlags_PassthruCentralNode);

        // Render "some panel".
    if (m_show_panel) {
      ImGui::Begin("Some panel", &m_show_panel);
      ImGui::Text("Hello World");
      ImGui::End();
    }

    // Rendering
    ImGui::Render();

    SDL_SetRenderDrawColor(
      m_window->get_native_renderer(),
      // Gray clear color (rgba)
      100, 100, 100, 255
    );
    SDL_RenderClear(m_window->get_native_renderer());

    const int px = 200;
    const int py = 100;
    const int psz = 8;
    const SDL_Rect player_rect {
      px - (psz / 2),
      py - (psz / 2),
      psz, psz
    };

    SDL_SetRenderDrawColor(
      m_window->get_native_renderer(),
      255, 0, 0, 255
    );
    SDL_RenderFillRect(m_window->get_native_renderer(), &player_rect);

    // Render data through the SDL renderer
    ImGui_ImplSDLRenderer2_RenderDrawData(
      ImGui::GetDrawData()
    );

    SDL_RenderPresent(m_window->get_native_renderer());
  }

  m_window->shutdown();

  return m_exit_status;
}

void App::Application::stop() {
  m_running = false;
}

}  // namespace App