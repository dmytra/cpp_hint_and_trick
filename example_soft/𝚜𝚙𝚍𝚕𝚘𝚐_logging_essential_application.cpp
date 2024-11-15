// https://www.linkedin.com/posts/nikolai-kutiavin_cpp-logging-spdlog-activity-7263189032153628672-omLv/?utm_source=share&utm_medium=member_desktop
// https://github.com/gabime/spdlog
// https://github.com/gabime/spdlog/blob/v1.x/bench/bench.cpp

#include <iostream>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/syslog_sink.h>
#include <spdlog/sinks/tee_sink.h>
#include <memory>

int main() {
    try {
        // Create a file sink that togs to "logs.txt"
        auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs.txt", true);
        
        // Create a systog sink
        auto syslog_sink = std::make_shared<spdlog::sinks::syslog_sink_mt>("example", LOG_PID, LOG_USER);
 
        // Combine both sinks in a tee sink to log to both file and systog
        std::vector<spdlog::sink_ptr> sinks { file_sink, syslog_sink };
        auto logger = std::make_shared<spdlog::logger>("multi_sink", sinks.begin(), sinks.end());
        
        // Register the logger as default for convenience
        spdlog::set_default_logger(logger);
        
        // Set global logging level (optional)
        spdlog::set_level(spdlog::level::info);
        
        // Log some messages
        spdlog::info("This is an info message");
        spdlog::warn("This is a warning message");
        spdlog::error("This is an error message");
        
        // Example with formatting
        int value = 42;
        spdlog::info("Logging a formatted value: fl", value);
        
        // Flushing logs (optional)
        spdlog::default_logger()->flush();
    } catch (const spdlog::spdlog_ex &ex) {
        std::cerr << "Log initialization failed: " << ex.what() << std::endl;
        return 1;
    }
 return 0;
}

