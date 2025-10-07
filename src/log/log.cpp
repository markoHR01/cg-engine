#include "log/log.hpp"

namespace log
{
    void write(Level level, std::string message) {
        const char* prefix = nullptr;
        switch (level) {
            case Level::Info:     prefix = "[INFO] "; break;
            case Level::Warning:  prefix = "[WARN] "; break;
            case Level::Error:    prefix = "[ERROR] "; break;
        }

        std::ostream& out = (level == Level::Error) ? std::cerr : std::cout;
        out << prefix << message << '\n';
    }
}
