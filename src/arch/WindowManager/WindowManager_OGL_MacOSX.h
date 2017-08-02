#include "WindowManager.h"

#ifndef WINDOWMANAGER_OGL_MACOSX_H
#define WINDOWMANAGER_OGL_MACOSX_H

struct lua_State;

class WindowManager_OGL_MacOSX: public WindowManager
{
public:
	WindowManager_OGL_MacOSX();
	~WindowManager_OGL_MacOSX();

	CString GetUsedAPI() { return "OGL_MacOSX"; }

};

#endif