
#include "MemoryMgr.h"


int* __cdecl AllocateMemory(int a1)
{
	int v1; // eax@1

	v1 = ((int(__cdecl*)())0x580E30)();

	int* result = ((int* (__thiscall*)(int, int))0x580C30)(v1, a1);

	//Big data can cause a error, just use then the internal malloc
	if (result == 0) {
		return (int*)malloc(a1);
	}

	return result;
}

extern "C"
{
	__declspec(dllexport) void InitializeASI()
	{
		Memory::VP::InjectHook(0x580ED0, AllocateMemory, PATCH_JUMP);
	}
}


