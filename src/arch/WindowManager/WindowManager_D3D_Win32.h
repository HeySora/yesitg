#include "WindowManager.h"

#ifndef WINDOWMANAGER_D3D_WIN32_H
#define WINDOWMANAGER_D3D_WIN32_H

struct lua_State;

class WindowManager_D3D_Win32: public WindowManager
{
public:
	WindowManager_D3D_Win32();
	~WindowManager_D3D_Win32();

	CString GetUsedAPI() { return "D3D_Win32"; }

};

#endif