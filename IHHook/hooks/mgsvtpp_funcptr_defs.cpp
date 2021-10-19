//GENERATED: by ghidra script ExportHooksToHeader.py
//via WriteFuncPtrDefsFile
//declares function pointers of exported functions

// NOT_FOUND - default for a lapi we want to use, and should actually have found the address in prior exes, but aren't in the current exported address list
// NO_USE - something we dont really want to use for whatever reason
// USING_CODE - using the default lapi code implementation instead of hooking

#include "mgsvtpp_func_typedefs.h"

StrCode64Func* StrCode64;
PathCode64Func* PathCode64;
FNVHash32Func* FNVHash32;
GetFreeRoamLangIdFunc* GetFreeRoamLangId;
UpdateFOVLerpFunc* UpdateFOVLerp;
UnkPrintFuncStubbedOutFunc* UnkPrintFuncStubbedOut;
l_StubbedOutFunc* l_StubbedOut;
nullsub_2Func* nullsub_2;
LoadFileSubFunc* LoadFileSub;
LoadFileFunc* LoadFile;
LoadPlayerPartsFpkFunc* LoadPlayerPartsFpk;
LoadPlayerPartsPartsFunc* LoadPlayerPartsParts;
LoadPlayerCamoFpkFunc* LoadPlayerCamoFpk;
LoadPlayerCamoFv2Func* LoadPlayerCamoFv2;
LoadPlayerFacialMotionFpkFunc* LoadPlayerFacialMotionFpk;
LoadPlayerFacialMotionMtarFunc* LoadPlayerFacialMotionMtar;
LoadPlayerBionicArmFpkFunc* LoadPlayerBionicArmFpk;
LoadPlayerBionicArmFv2Func* LoadPlayerBionicArmFv2;
CheckPlayerPartsIfShouldApplySkinToneFv2Func* CheckPlayerPartsIfShouldApplySkinToneFv2;
LoadPlayerPartsSkinToneFv2Func* LoadPlayerPartsSkinToneFv2;
IsHeadNeededForPartsTypeFunc* IsHeadNeededForPartsType;
IsHeadNeededForPartsTypeAndAvatarFunc* IsHeadNeededForPartsTypeAndAvatar;
LoadPlayerSnakeFaceFpkFunc* LoadPlayerSnakeFaceFpk;
LoadPlayerSnakeFaceFv2Func* LoadPlayerSnakeFaceFv2;
LoadAvatarOgreHornFpkFunc* LoadAvatarOgreHornFpk;
LoadAvatarOgreHornFv2Func* LoadAvatarOgreHornFv2;
lua_newstateFunc* lua_newstate;
lua_closeFunc* lua_close;
lua_newthreadFunc* lua_newthread;
lua_atpanicFunc* lua_atpanic;
//lua_gettopFunc* lua_gettop;//USING_CODE
lua_settopFunc* lua_settop;
lua_pushvalueFunc* lua_pushvalue;
lua_removeFunc* lua_remove;
lua_insertFunc* lua_insert;
lua_replaceFunc* lua_replace;
lua_checkstackFunc* lua_checkstack;
lua_xmoveFunc* lua_xmove;
lua_isnumberFunc* lua_isnumber;
lua_isstringFunc* lua_isstring;
lua_iscfunctionFunc* lua_iscfunction;
//lua_isuserdataFunc* lua_isuserdata;//USING_CODE
lua_typeFunc* lua_type;
//lua_typenameFunc* lua_typename;//USING_CODE
//lua_equalFunc* lua_equal;//NOT_FOUND
lua_rawequalFunc* lua_rawequal;
lua_lessthanFunc* lua_lessthan;
lua_tonumberFunc* lua_tonumber;
lua_tointegerFunc* lua_tointeger;
lua_tobooleanFunc* lua_toboolean;
lua_tolstringFunc* lua_tolstring;
lua_objlenFunc* lua_objlen;
lua_tocfunctionFunc* lua_tocfunction;
lua_touserdataFunc* lua_touserdata;
lua_tothreadFunc* lua_tothread;
lua_topointerFunc* lua_topointer;
lua_pushnilFunc* lua_pushnil;
lua_pushnumberFunc* lua_pushnumber;
lua_pushintegerFunc* lua_pushinteger;
lua_pushlstringFunc* lua_pushlstring;
lua_pushstringFunc* lua_pushstring;
lua_pushvfstringFunc* lua_pushvfstring;
lua_pushfstringFunc* lua_pushfstring;
lua_pushcclosureFunc* lua_pushcclosure;
lua_pushbooleanFunc* lua_pushboolean;
lua_pushlightuserdataFunc* lua_pushlightuserdata;
lua_pushthreadFunc* lua_pushthread;
lua_gettableFunc* lua_gettable;
lua_getfieldFunc* lua_getfield;
lua_rawgetFunc* lua_rawget;
lua_rawgetiFunc* lua_rawgeti;
lua_createtableFunc* lua_createtable;
lua_newuserdataFunc* lua_newuserdata;
lua_getmetatableFunc* lua_getmetatable;
lua_getfenvFunc* lua_getfenv;
lua_settableFunc* lua_settable;
lua_setfieldFunc* lua_setfield;
lua_rawsetFunc* lua_rawset;
lua_rawsetiFunc* lua_rawseti;
lua_setmetatableFunc* lua_setmetatable;
lua_setfenvFunc* lua_setfenv;
lua_callFunc* lua_call;
lua_pcallFunc* lua_pcall;
lua_cpcallFunc* lua_cpcall;
lua_loadFunc* lua_load;
lua_dumpFunc* lua_dump;
//lua_yieldFunc* lua_yield;//USING_CODE
lua_resumeFunc* lua_resume;
//lua_statusFunc* lua_status;//USING_CODE
lua_gcFunc* lua_gc;
lua_errorFunc* lua_error;
lua_nextFunc* lua_next;
lua_concatFunc* lua_concat;
//lua_getallocfFunc* lua_getallocf;//NO_USE
//lua_setallocfFunc* lua_setallocf;//NO_USE
//lua_setlevelFunc* lua_setlevel;//NO_USE
lua_getstackFunc* lua_getstack;
lua_getinfoFunc* lua_getinfo;
lua_getlocalFunc* lua_getlocal;
lua_setlocalFunc* lua_setlocal;
lua_getupvalueFunc* lua_getupvalue;
lua_setupvalueFunc* lua_setupvalue;
lua_sethookFunc* lua_sethook;
//lua_gethookFunc* lua_gethook;//USING_CODE
//lua_gethookmaskFunc* lua_gethookmask;//USING_CODE
//lua_gethookcountFunc* lua_gethookcount;//USING_CODE
luaI_openlibFunc* luaI_openlib;
//luaL_registerFunc* luaL_register;//USING_CODE
luaL_getmetafieldFunc* luaL_getmetafield;
luaL_callmetaFunc* luaL_callmeta;
luaL_typerrorFunc* luaL_typerror;
luaL_argerrorFunc* luaL_argerror;
luaL_checklstringFunc* luaL_checklstring;
luaL_optlstringFunc* luaL_optlstring;
luaL_checknumberFunc* luaL_checknumber;
//luaL_optnumberFunc* luaL_optnumber;//USING_CODE
luaL_checkintegerFunc* luaL_checkinteger;
luaL_optintegerFunc* luaL_optinteger;
luaL_checkstackFunc* luaL_checkstack;
luaL_checktypeFunc* luaL_checktype;
luaL_checkanyFunc* luaL_checkany;
luaL_newmetatableFunc* luaL_newmetatable;
luaL_checkudataFunc* luaL_checkudata;
luaL_whereFunc* luaL_where;
luaL_errorFunc* luaL_error;
luaL_checkoptionFunc* luaL_checkoption;
//luaL_refFunc* luaL_ref;//USING_CODE
//luaL_unrefFunc* luaL_unref;//USING_CODE
luaL_loadfileFunc* luaL_loadfile;
luaL_loadbufferFunc* luaL_loadbuffer;
//luaL_loadstringFunc* luaL_loadstring;//USING_CODE
luaL_newstateFunc* luaL_newstate;
luaL_gsubFunc* luaL_gsub;
luaL_findtableFunc* luaL_findtable;
//luaL_buffinitFunc* luaL_buffinit;//USING_CODE
luaL_prepbufferFunc* luaL_prepbuffer;
luaL_addlstringFunc* luaL_addlstring;
//luaL_addstringFunc* luaL_addstring;//USING_CODE
luaL_addvalueFunc* luaL_addvalue;
luaL_pushresultFunc* luaL_pushresult;
luaopen_baseFunc* luaopen_base;
luaopen_tableFunc* luaopen_table;
luaopen_ioFunc* luaopen_io;
luaopen_osFunc* luaopen_os;
luaopen_stringFunc* luaopen_string;
luaopen_mathFunc* luaopen_math;
luaopen_debugFunc* luaopen_debug;
luaopen_packageFunc* luaopen_package;
luaL_openlibsFunc* luaL_openlibs;
