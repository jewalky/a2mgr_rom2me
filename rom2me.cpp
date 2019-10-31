// rom2me25.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "string.h"
#include "stdio.h"


#ifdef _MANAGED
#pragma managed(push, off)
#endif

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
    return TRUE;
}

#ifdef _MANAGED
#pragma managed(pop)
#endif

// exports
//
char aUpdateLst[] = "update.lst";
void __declspec(naked) imp_RemoveResRequirement()
{
	__asm
	{ // 004182A2
		add		esp, 0x14 // there's also this 0x0C in the original code, but we aren't calling fopen there
		push	offset aUpdateLst
		mov		ecx, 0x0042FBC0
		call	ecx
		add		esp, 0x04
		mov		ecx, 0x0041834B
		jmp		ecx
	}
}

void __declspec(naked) imp_RemoveResRequirement2()
{
	__asm
	{ // 004183A0
		// even though I'm removing the piracy check, I still better initialize some values, otherwise it crashes while trying to unitialize
		push	0x0047B154 // offset aSi ; "si"
		lea		ecx, [esp+0x34]
		mov		edx, 0x0044DE1F
		call	edx
		mov		ecx, 0x004184A7
		jmp		ecx
	}
}

void _stdcall AddResFromData(const char* filename, void* result)
{
	/*static char tscp[512];
	sprintf(tscp, "loading RES file %s [%p]", filename, result);
	MessageBoxA(NULL, tscp, "", MB_OK);*/

	FILE* f = fopen("res.log", "a");
	fprintf(f, "loading RES file %s\n", filename);
	fflush(f);
	fclose(f);
}

char aData[] = "data\\";
char aDataPatch[] = "data\\patch\\";
void __declspec(naked) imp_AddResFromData()
{
	__asm
	{ // 004300C0
		push	ebp
		mov		ebp, esp
		sub		esp, 0x10

		push	eax
		push	ebx
		push	ecx
		push	edx
		push	esi
		push	edi

		mov		[ebp-0x04], 0
		mov		[ebp-0x0C], ecx
/*
		push	1
		push	[ebp+0x08]
		call	AddResFromData*/

		// first, try to append data\\patch\\
		// then, try to append data\\
		// then try normal load

		push	0x200
		mov		edx, 0x0043824D
		call	edx // malloc
		add		esp, 0x04
		test	eax, eax
		jz		ret_0
		mov		[ebp-0x08], eax

		push	offset aDataPatch
		push	[ebp-0x08]
		mov		edx, 0x00440F00
		call	edx // strcpy
		add		esp, 0x08

		push	[ebp+0x08]
		push	[ebp-0x08]
		mov		edx, 0x00440F10
		call	edx // strcat
		add		esp, 0x08

		push	[ebp+0x10]
		push	[ebp+0x0C]
		push	[ebp-0x08]
		mov		ecx, [ebp-0x0C]
		call	sub_4300C0
		mov		[ebp-0x04], eax
		test	eax, eax
		jnz		ret_sub

		push	offset aData
		push	[ebp-0x08]
		mov		edx, 0x00440F00
		call	edx // strcpy
		add		esp, 0x08

		push	[ebp+0x08]
		push	[ebp-0x08]
		mov		edx, 0x00440F10
		call	edx // strcat
		add		esp, 0x08

		push	[ebp+0x10]
		push	[ebp+0x0C]
		push	[ebp-0x08]
		mov		ecx, [ebp-0x0C]
		call	sub_4300C0
		mov		[ebp-0x04], eax
		test	eax, eax
		jnz		ret_sub

		push	[ebp+0x10]
		push	[ebp+0x0C]
		push	[ebp+0x08]
		mov		ecx, [ebp-0x0C]
		call	sub_4300C0
		mov		[ebp-0x04], eax

		jmp ret_sub

ret_0:
		mov		[ebp-0x04], 0

ret_sub:

		push	[ebp-0x08]
		mov		edx, 0x00438387
		call	edx // free?
		add		esp, 0x04

		pop		edi
		pop		esi
		pop		edx
		pop		ecx
		pop		ebx
		pop		eax
		mov		eax, [ebp-0x04]
		mov		esp, ebp
		pop		ebp
		retn	0x000C

sub_4300C0:
		push	ebp
		mov		ebp, esp
		push	0xFFFFFFFF
		push	0x00466038
		mov		eax, fs:[0]
		push	eax
		mov		fs:[0], esp
		sub		esp, 0x804
		mov		eax, 0x004300DE
		jmp		eax
	}
}

char aLocaleTextMain[] = "locale\\en\\main.txt";
char aLocaleTextHeropicture[] = "locale\\en\\heropicture.txt";
char aLocaleTextItemserv[] = "locale\\en\\itemserv.txt";
void __declspec(naked) imp_LoadLocaleText()
{
	__asm
	{ // 004184F2
		push	offset aLocaleTextMain
		mov		ecx, 0x0049F260
		mov		eax, 0x0040E980
		call	eax

		push	offset aLocaleTextHeropicture
		mov		ecx, 0x0049F250
		mov		eax, 0x0040E980
		call	eax

		push	offset aLocaleTextItemserv
		mov		ecx, 0x0049F1E0
		mov		eax, 0x0040E980
		call	eax

		mov		eax, 0x0041851F
		jmp		eax
	}
}
