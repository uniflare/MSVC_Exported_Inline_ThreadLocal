#pragma once

#ifdef DLL_Library_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

struct ThreadLocalData
{
	int i = 0;
};

class DLL_API ExportedClass
{
public:
	inline void TestFunc(); // <- inline here will bring the static data in the function with it
};