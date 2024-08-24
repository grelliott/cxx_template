
#include "application.hpp"
#include "log.hpp"

using namespace ca::grantelliott;

int main(int argc, char *argv[]) {
    // initialize logging
    log::initialize();

    log::trace("Trace");
    log::debug("Debug");
    log::info("Info");
    log::warn("Warn");
    log::error("Error");
    log::critical("Critical");

    // read args and log to file or console
    log::info("Starting program");

    ca::grantelliott::testapp::Application app{};
    app.init();

    app.start();

    log::info("Terminating program");
    app.terminate();
}