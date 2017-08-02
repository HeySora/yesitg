#include "WindowManager.h"

#ifndef WINDOWMANAGER_OGL_WIN32_H
#define WINDOWMANAGER_OGL_WIN32_H

struct lua_State;

class WindowManager_OGL_Win32: public WindowManager
{
public:
	WindowManager_OGL_Win32();
	~WindowManager_OGL_Win32();

	CString GetUsedAPI() { return "OGL_Win32" }

};

#endif