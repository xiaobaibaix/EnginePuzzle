#pragma once

#include "puzzle/Core.h"
#include "pzpch.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Puzzle {

	class PUZZLE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };

	private:
		static std::shared_ptr <spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}
//core logger
#define PZ_CORE_TRACE(...)		::Puzzle::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PZ_CORE_INFO(...)		::Puzzle::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PZ_CORE_WAEN(...)		::Puzzle::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PZ_CORE_ERROR(...)		::Puzzle::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PZ_CORE_FATAL(...)		::Puzzle::Log::GetCoreLogger()->fatal(__VA_ARGS__)
//client logger
#define PZ_TRACE(...)			::Puzzle::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PZ_INFO(...)			::Puzzle::Log::GetClientLogger()->info(__VA_ARGS__)
#define PZ_WAEN(...)			::Puzzle::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PZ_ERROR(...)			::Puzzle::Log::GetClientLogger()->error(__VA_ARGS__)
#define PZ_FATAL(...)			::Puzzle::Log::GetClientLogger()->fatal(__VA_ARGS__)