#include "WindowManager.h"

#ifndef WINDOWMANAGER_OGL_X11_H
#define WINDOWMANAGER_OGL_X11_H

struct lua_State;

class WindowManager_OGL_X11: public WindowManager
{
public:
	WindowManager_OGL_X11();
	~WindowManager_OGL_X11();

	CString GetUsedAPI() { return "OGL_X11"; }

};

#endif