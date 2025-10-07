#pragma once
#include <iostream>
#include <format>
#include <string>
#include <string_view>

namespace log
{
    enum class Level { Info, Warning, Error };

    void write(Level level, std::string message);

    template <typename... Args>
    void info(std::string_view fmt, Args&&... args) {
        write(Level::Info, std::vformat(fmt, std::make_format_args(args...)));
    }

    template <typename... Args>
    void warn(std::string_view fmt, Args&&... args) {
        write(Level::Warning, std::vformat(fmt, std::make_format_args(args...)));
    }

    template <typename... Args>
    void error(std::string_view fmt, Args&&... args) {
        write(Level::Error, std::vformat(fmt, std::make_format_args(args...)));
    }
}
