/*
 * Filename: /home/grant/src/test_c++/src/application.cpp
 * Path: /home/grant/src/test_c++/src
 * Created Date: Thursday, August 15th 2024, 2:07:30 am
 * Author: Grant Elliott
 *
 * Copyright (c) 2024 Your Company
 */

#include "application.hpp"

#include <chrono>
#include <thread>

#include "spdlog/spdlog.h"

using namespace std::chrono_literals;

namespace ca::grantelliott::testapp {

static constexpr auto NUMBER_OF_LOOPS = 4 * 10;

Application::Application() : mRun{true} {
    spdlog::info("Creating Application");
}

Application::~Application() { spdlog::info("Destroying Application"); }

void Application::init() { spdlog::info("Application::init"); }

void Application::start() {
    spdlog::info("Application::start");
    std::thread th{[&]() {
        std::size_t i = 0;
        while (++i < NUMBER_OF_LOOPS) {
            spdlog::info(".");
            std::this_thread::sleep_for(250ms);
        }
    }};
    th.join();
}

void Application::terminate() noexcept {
    spdlog::info("Application::terminate");
    mRun.store(false);
}

}  // namespace ca::grantelliott::testapp