/*
 * Copyright (c) 2022 Martin Helmut Fieber <info@martin-fieber.se>
 */

#include "Core/Application.h"
#include "Core/Log.h"
#include "Core/Debug/Instrumentor.h"

int main() {

  App::Application app { /* "App" */ };
  return app.run();
}
