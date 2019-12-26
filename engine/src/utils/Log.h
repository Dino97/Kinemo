#pragma once

#include <memory>

#include "spdlog/spdlog.h"

namespace Kinemo
{
	class Log
	{
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	};
}

// Core log macros
#define KM_CORE_TRACE(...)		::Kinemo::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define KM_CORE_INFO(...)		::Kinemo::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KM_CORE_WARNING(...)	::Kinemo::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KM_CORE_ERROR(...)		::Kinemo::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KM_CORE_FATAL(...)		::Kinemo::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define KM_TRACE(...)			::Kinemo::Log::GetClientLogger()->trace(__VA_ARGS__)
#define KM_INFO(...)			::Kinemo::Log::GetClientLogger()->info(__VA_ARGS__)
#define KM_WARNING(...)			::Kinemo::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KM_ERROR(...)			::Kinemo::Log::GetClientLogger()->error(__VA_ARGS__)
#define KM_FATAL(...)			::Kinemo::Log::GetClientLogger()->fatal(__VA_ARGS__)