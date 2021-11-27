//ZIP: Extending vars.buddy*, a buddy change system

#include "Hooks_Buddy.h"
#include "spdlog/spdlog.h"
#include "MinHook/MinHook.h"
#include "HookMacros.h"
#include "hooks/mgsvtpp_func_typedefs.h"

namespace IHHook {
	extern std::shared_ptr<spdlog::logger> luaLog;

	namespace Hooks_Buddy {
		bool overrideBuddySystem = false;
		struct Buddy {
			uint buddyType = 255;
			std::string horseFpkPath = "";
			std::string dogFpkPath = "";
			std::string quietFpkPath = "";
			std::string walkerGearFpkPath = "";
		};//Buddy
		Buddy buddy;

		int l_SetOverrideBuddySystem(lua_State* L) {
			overrideBuddySystem = lua_toboolean(L, -1);

			spdlog::debug("l_SetOverrideBuddySystem override:{}, ", overrideBuddySystem);

			return 0;
		}//l_SetOverrideBuddySystem
		int l_SetBuddyTypeForPartsType(lua_State* L) {
			buddy.buddyType = (uint)lua_tointeger(L, -1);

			spdlog::debug("l_SetBuddyTypeForPartsType buddyType:{}, ", buddy.buddyType);

			return 0;
		}//l_SetBuddyTypeForPartsType

		/*
			SetBuddy*PartsFpkPath
		*/
		int l_SetBuddyDogPartsFpkPath(lua_State* L) {
			const char* filePath = lua_tostring(L, -1);
			if (filePath == NULL) {
				filePath = "";
			}
			spdlog::debug("l_SetBuddyDogPartsFpkPath {}, ", filePath);
			buddy.dogFpkPath = filePath;

			return 0;
		}//l_SetBuddyDogPartsFpkPath
		int l_SetBuddyHorsePartsFpkPath(lua_State* L) {
			const char* filePath = lua_tostring(L, -1);
			if (filePath == NULL) {
				filePath = "";
			}
			spdlog::debug("l_SetBuddyHorsePartsFpkPath {}, ", filePath);
			buddy.horseFpkPath = filePath;

			return 0;
		}//l_SetBuddyHorsePartsFpkPath
		int l_SetBuddyQuietPartsFpkPath(lua_State* L) {
			const char* filePath = lua_tostring(L, -1);
			if (filePath == NULL) {
				filePath = "";
			}
			spdlog::debug("l_SetBuddyQuietPartsFpkPath {}, ", filePath);
			buddy.quietFpkPath = filePath;

			return 0;
		}//l_SetBuddyQuietPartsFpkPath
		int l_SetBuddyWalkerGearPartsFpkPath(lua_State* L) {
			const char* filePath = lua_tostring(L, -1);
			if (filePath == NULL) {
				filePath = "";
			}
			spdlog::debug("l_SetBuddyWalkerGearPartsFpkPath {}, ", filePath);
			buddy.walkerGearFpkPath = filePath;

			return 0;
		}//l_SetBuddyWalkerGearPartsFpkPath

		/*
			Vanilla FPK paths

		std::string buddyHorsePartsFpksDefault[]{
			"/Assets/tpp/pack/buddy/horse/buddy_horse2_00.fpk",
			"/Assets/tpp/pack/buddy/horse/buddy_horse2_03.fpk",
			"/Assets/tpp/pack/buddy/horse/buddy_horse2_02_0.fpk",
			"/Assets/tpp/pack/buddy/horse/buddy_horse2_02_1.fpk",
			"/Assets/tpp/pack/buddy/horse/buddy_horse2_02_2.fpk",
			"/Assets/tpp/pack/buddy/horse/buddy_horse2_05.fpk",
			"/Assets/tpp/pack/buddy/horse/buddy_horse2_04.fpk",
		};
		std::string buddyDogPartsFpksDefault[]{
			"/Assets/tpp/pack/buddy/dog/buddy_dog2_00.fpk",
			"/Assets/tpp/pack/buddy/dog/buddy_dog2_01.fpk",
			"/Assets/tpp/pack/buddy/dog/buddy_dog2_02.fpk",
			"/Assets/tpp/pack/buddy/dog/buddy_dog2_03.fpk",
			"/Assets/tpp/pack/buddy/dog/buddy_dog2_04.fpk",
		};
		std::string buddyQuietPartsFpksDefault[]{
			"/Assets/tpp/pack/buddy/quiet/buddy_quiet2_00.fpk",
			"/Assets/tpp/pack/buddy/quiet/buddy_quiet2_01.fpk",
			"/Assets/tpp/pack/buddy/quiet/buddy_quiet2_02.fpk",
			"/Assets/tpp/pack/buddy/quiet/buddy_quiet2_03.fpk",
			"/Assets/tpp/pack/buddy/quiet/buddy_quiet2_04.fpk",
			"/Assets/tpp/pack/buddy/quiet/buddy_quiet2_05.fpk",
		};
		std::string buddyWalkerGearPartsFpksDefault[]{
			"/Assets/tpp/pack/buddy/walkergear/buddy_wg2_00.fpk",
		};
		*/
		
		/*
			Buddy hooks/IHHook setup
		*/
		bool IsBuddyTypeValid(int buddyType) {
			if (buddyType > 4) {
				return false;
			}

			if (buddy.buddyType != buddyType) {
				return false;
			}

			return true;
		}//IsBuddyTypeValid

		uint64_t* LoadBuddyMainFileHook(ulonglong param_1, ulonglong* fileSlotIndex, int buddyType) {
			spdlog::debug("LoadBuddyMainFileHook buddyType:{}", buddyType);

			//ZIP: No override or valid buddy? Fallback
			if (!overrideBuddySystem || !IsBuddyTypeValid(buddyType) ) {
				return LoadBuddyMainFile(param_1, fileSlotIndex, buddyType);
			}

			std::string filePath = "";
			if (buddyType == 1) { //For D-Horse
				if (buddy.horseFpkPath != "") {
					filePath = buddy.horseFpkPath;
					spdlog::debug("horseFpkPath: {}", filePath);
				}
			}
			else if (buddyType == 2) { //For D-Dog
				if (buddy.dogFpkPath != "") {
					filePath = buddy.dogFpkPath;
					spdlog::debug("dogFpkPath: {}", filePath);
				}
			}
			else if (buddyType == 3) { //For Quiet
			   //ZIP: Quiet's costumeType is set to 0 for the mission "A Quiet Exit" ( missionCode 10260 )
				if (buddy.quietFpkPath != "") {
					filePath = buddy.quietFpkPath;
					spdlog::debug("quietFpkPath: {}", filePath);
				}
			}
			else if (buddyType == 4) { //For Walker Gear
				if (buddy.walkerGearFpkPath != "") {
					filePath = buddy.walkerGearFpkPath;
					spdlog::debug("walkerGearFpkPath: {}", filePath);
				}
			}
			
			//ZIP: No file path? Fallback
			if (filePath == "") {
				return LoadBuddyMainFile(param_1, fileSlotIndex, buddyType);
			}

			uint64_t filePath64 = PathCode64(filePath.c_str());
			LoadFile(fileSlotIndex, filePath64);
			return fileSlotIndex;
		}//LoadBuddyMainFileHook

		void CreateHooks() {
			spdlog::debug(__func__);

			CREATE_HOOK(LoadBuddyMainFile)
			ENABLEHOOK(LoadBuddyMainFile)
		}//CreateHooks

		int CreateLibs(lua_State* L) {
			spdlog::debug(__func__);

			luaL_Reg libFuncs[] = {
				{ "SetOverrideBuddySystem", l_SetOverrideBuddySystem },
				{ "SetBuddyTypeForPartsType", l_SetBuddyTypeForPartsType },

				{ "SetBuddyHorsePartsFpkPath", l_SetBuddyHorsePartsFpkPath },
				{ "SetBuddyDogPartsFpkPath", l_SetBuddyDogPartsFpkPath },
				{ "SetBuddyQuietPartsFpkPath", l_SetBuddyQuietPartsFpkPath },
				{ "SetBuddyWalkerGearPartsFpkPath", l_SetBuddyWalkerGearPartsFpkPath },

				{ NULL, NULL }//GOTCHA: crashes without
			};
			luaI_openlib(L, "IHH", libFuncs, 0);
			return 1;
		}//CreateLibs
	}//Hooks_Buddy
}//namespace IHHook