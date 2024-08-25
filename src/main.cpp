/*
 * Filename: /home/grant/src/test_c++/src/main.cpp
 * Path: /home/grant/src/test_c++/src
 * Created Date: Saturday, August 24th 2024, 5:59:00 am
 * Author: Grant Elliott
 *
 * Copyright (c) 2024 Grant Elliott
 */

#include <argparse/argparse.hpp>

#include "application.hpp"
#include "log.hpp"
#include "version.hpp"

using namespace ca::grantelliott;

int main(int argc, char* argv[]) {
    // initialize logging
    log::initialize();
    argparse::ArgumentParser args("test_app", APP_VERSION);
    args.add_description(APP_DESCRIPTION);

    try {
        args.parse_args(argc, argv);
    } catch (const std::exception& err) {
        log::critical("Failed to parse command-line arguments - {}", err.what());
        return 1;
    }

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
