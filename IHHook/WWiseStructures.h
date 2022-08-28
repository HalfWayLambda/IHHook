#pragma once

typedef unsigned char uchar;
typedef unsigned long ulong;
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned long long undefined8;
typedef unsigned char undefined;
typedef unsigned short ushort;
typedef ulonglong ulong64;

struct AkExternalSourceInfo {
	ulong iExternalSrcCookie;
	ulong idCodec;
	wchar_t* szFile;
	void* pInMemory;
	ulong uiMemorySize;
	ulong idFile;
};

template <typename T>
struct AkListBareLight
{
	T* m_pFirst;
};

struct CAkPropBundle
{
	uchar* m_pProps;
};

struct CAkAction {
	undefined field0_0x0;
	undefined field1_0x1;
	undefined field2_0x2;
	undefined field3_0x3;
	undefined field4_0x4;
	undefined field5_0x5;
	undefined field6_0x6;
	undefined field7_0x7;
	undefined field8_0x8;
	undefined field9_0x9;
	undefined field10_0xa;
	undefined field11_0xb;
	undefined field12_0xc;
	undefined field13_0xd;
	undefined field14_0xe;
	undefined field15_0xf;
	undefined field16_0x10;
	undefined field17_0x11;
	undefined field18_0x12;
	undefined field19_0x13;
	undefined field20_0x14;
	undefined field21_0x15;
	undefined field22_0x16;
	undefined field23_0x17;
	CAkAction* pNextLightItem;
	//struct AkPropBundle<AkPropValue> m_props;
	//struct AkPropBundle<RANGED_MODIFIERS<AkPropValue>_> m_ranges;
	CAkPropBundle m_props;
	CAkPropBundle m_ranges;
	ulong m_ulElementID;
	ushort m_eActionType;
	uchar m_eFadeCurve : 5;
	uchar m_bWasLoadedFromBank : 1;
	uchar m_bIsBusElement : 1;
	undefined field32_0x37;
};

struct CAkEvent {
	undefined field0_0x0;
	undefined field1_0x1;
	undefined field2_0x2;
	undefined field3_0x3;
	undefined field4_0x4;
	undefined field5_0x5;
	undefined field6_0x6;
	undefined field7_0x7;
	undefined field8_0x8;
	undefined field9_0x9;
	undefined field10_0xa;
	undefined field11_0xb;
	undefined field12_0xc;
	undefined field13_0xd;
	undefined field14_0xe;
	undefined field15_0xf;
	undefined field16_0x10;
	undefined field17_0x11;
	undefined field18_0x12;
	undefined field19_0x13;
	undefined field20_0x14;
	undefined field21_0x15;
	undefined field22_0x16;
	undefined field23_0x17;
	//struct AkListBareLight<CAkAction, AkListBareLightNextItem<CAkAction>> m_actions;
	AkListBareLight<CAkAction> m_actions;
	ulong m_iPreparationCount;
	undefined field26_0x24;
	undefined field27_0x25;
	undefined field28_0x26;
	undefined field29_0x27;
};