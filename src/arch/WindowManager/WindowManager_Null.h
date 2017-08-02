#include "WindowManager.h"

#ifndef WINDOWMANAGER_NULL_H
#define WINDOWMANAGER_NULL_H

struct lua_State;

class WindowManager_Null: public WindowManager
{
public:
	WindowManager_Null();
	~WindowManager_Null();

	CString GetUsedAPI() { return "Null"; }

};

#endif