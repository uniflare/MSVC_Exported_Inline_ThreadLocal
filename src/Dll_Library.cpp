#include "Dll_Library.h"

void ExportedClass::TestFunc()
{
	static thread_local ThreadLocalData data; // <- If this item is exported with latest v143 toolset, it will create a LNK1161: invalid export specification
	data.i += 1;
}