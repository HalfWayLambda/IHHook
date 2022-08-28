#include "Hooks_WWise.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "IHHook.h"
#include "MinHook/MinHook.h"
#include "HookMacros.h"
#include "hooks/mgsvtpp_func_typedefs.h"

namespace IHHook {
	namespace Hooks_WWise {
		const std::wstring logName{ L"wwise_log.txt" };
		std::shared_ptr<spdlog::logger> log;

		ulong PostEventHook(ulong eventID, ulong64 param_2, ulong UIRegNotification,
			void* CallBackTypeFuncPtr,
			void* param_5, ulong param_6, AkExternalSourceInfo* param_7, ulong param_8)
		{
			log->info("PostEvent with ID: {} and register notification: {}", eventID,
				UIRegNotification);
			if (param_7)
			{
				//spdlog::info("PostEvent from file: {} with ID: {}", param_7->szFile,
				//	param_7->idFile);
				log->info(L"PostEvent from file: {}", param_7->szFile);
				log->info("PostEvent from file ID: {}", param_7->idFile);
			}
			return PostEvent(eventID, param_2, UIRegNotification, CallBackTypeFuncPtr,
				param_5, param_6, param_7, param_8);
		}

		void CreateHooks()
		{
			spdlog::debug(__func__);
			if (!config.enableWWiseHooks)
			{
				spdlog::debug("!enableWWiseHooks, returning");
				return;
			}

			log = spdlog::basic_logger_mt("wwise", logName);
			log->set_pattern("%M:%S:%f | %l\t | %v");

			if (addressSet["PostEvent"] == NULL)
			{
				spdlog::warn("PostEvent == NULL");
				return;
			}

			CREATE_HOOK(PostEvent);
			ENABLEHOOK(PostEvent);
		}
	}
}