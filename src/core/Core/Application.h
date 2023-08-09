#pragma once

#include <memory>

#include <SDL.h>

#include "Window.h"

namespace App {

class Application {
 public:
  Application();
  ~Application();

  int run();
  void stop();

 private:
  int m_exit_status { 0 };
  bool m_running { true };
  bool m_show_panel = true;

  std::unique_ptr<Window> m_window{nullptr};
};

}