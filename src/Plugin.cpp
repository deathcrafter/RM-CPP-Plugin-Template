#include "Plugin.h"
#include "Measure.h"

HINSTANCE MODULE_INSTANCE;

/*
* Entry point to Dll, run once at dll load
* Use it to store the dll instance, in case you need it for hooks and other stuff
*/
BOOL WINAPI DllMain(
	HINSTANCE hinstDLL,  // handle to DLL module
	DWORD fdwReason,     // reason for calling function
	LPVOID lpvReserved)  // reserved
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		MODULE_INSTANCE = hinstDLL;
		DisableThreadLibraryCalls(hinstDLL); // disable thread library calls, for performance improvement
	default:
		break;
	}
}

/*
* Called once, at skin load or refresh
* Read any options that need to be constant here
*/
PLUGIN_EXPORT void Initialize(void** data, void* rm)
{
	Measure* measure = new Measure(rm);
	*data = measure;
}

/*
* Called once after Initialize
* Called before every Update if DynamicVariables=1 is defined
* Read options that can require dynamic variables here
*/
PLUGIN_EXPORT void Reload(void* data, void* rm, double* maxValue)
{
	Measure* measure = (Measure*)data;
}

/*
* Called at every measure update
* Update your values here
*/
PLUGIN_EXPORT double Update(void* data)
{
	Measure* measure = (Measure*)data;
	return 0.0;
}


/* 
* Called everytime a [MeasureThisPlugin] is resolved
* DO NOT do any lengthy operations here, use Update for that
* Should only be used if you want the string value to be different than the numeric value
*/
/*PLUGIN_EXPORT LPCWSTR GetString(void* data)
{
	Measure* measure = (Measure*)data;
	return nullptr;
}*/


/*
* Called once, at skin unload (a skin is unloaded when you Refresh it)
* Perform any necessary cleanups here
*/
PLUGIN_EXPORT void Finalize(void* data)
{
	Measure* measure = (Measure*)data;
	delete measure;
}
