/* WindowManager - Handles multi-windows */

#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

struct lua_State;

class WindowManager
{
public:
	WindowManager();
	virtual ~WindowManager() = 0;

	virtual CString GetUsedAPI() = 0;

	// Lua
	void PushSelf( lua_State *L );
};

extern WindowManager* WINDOWMAN;

#endif