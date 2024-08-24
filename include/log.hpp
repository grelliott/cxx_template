/*
 * Filename: /home/grant/src/test_c++/include/log.hpp
 * Path: /home/grant/src/test_c++/include
 * Created Date: Saturday, August 24th 2024, 6:15:13 am
 * Author: Grant Elliott
 *
 * Copyright (c) 2024 Grant Elliott
 */

#pragma once

#include "fmt/format.h"
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"

namespace ca::grantelliott::log {

void initialize();

struct location_and_format {
    constexpr location_and_format(char const* _format,
                                  char const* _file_name = __builtin_FILE(),
                                  unsigned _line = __builtin_LINE()) noexcept
        : format{_format}, file_name{_file_name}, line{_line} {}

    char const* format;
    char const* file_name;
    unsigned line;
};

template <typename... Targs>
inline auto msg(location_and_format format,
                Targs const&... args) -> std::string_view {
    return {fmt::format("{}:{}: ", format.file_name, format.line) +
            fmt::vformat(
                format.format,
                fmt::make_format_args(std::forward<Targs const&>(args)...))};
}

template <typename... Targs>
inline void trace(location_and_format format, Targs const&... args) {
    SPDLOG_TRACE(msg(format, std::forward<Targs const&>(args)...));
}

template <typename... Targs>
inline void debug(location_and_format format, Targs const&... args) {
    SPDLOG_DEBUG(msg(format, std::forward<Targs const&>(args)...));
}

template <typename... Targs>
inline void info(location_and_format format, Targs const&... args) {
    SPDLOG_INFO(msg(format, std::forward<Targs const&>(args)...));
}

template <typename... Targs>
inline void warn(location_and_format format, Targs const&... args) {
    SPDLOG_WARN(msg(format, std::forward<Targs const&>(args)...));
}

template <typename... Targs>
inline void error(location_and_format format, Targs const&... args) {
    SPDLOG_ERROR(msg(format, std::forward<Targs const&>(args)...));
}

template <typename... Targs>
inline void critical(location_and_format format, Targs const&... args) {
    SPDLOG_CRITICAL(msg(format, std::forward<Targs const&>(args)...));
}

}  // namespace ca::grantelliott::log
