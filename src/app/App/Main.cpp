/*
 * Copyright (c) 2022 Martin Helmut Fieber <info@martin-fieber.se>
 */

// We are handling our own main function
#define SDL_MAIN_HANDLED

#include "Core/Application.h"
#include "Core/Log.h"
#include "Core/Debug/Instrumentor.h"

int main() {
  App::Application app { /* "App" */ };
  return app.run();
}
