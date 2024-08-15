
#include "application.hpp"
#include "spdlog/spdlog.h"

int main(int argc, char *argv[]) {
    // initialize logging
    spdlog::info("Starting program");

    ca::grantelliott::testapp::Application app {};
    app.init();

    app.start();

    spdlog::info("Terminating program");
    app.terminate();
}