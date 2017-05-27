#include "global.h"
#include "Window.h"
#include "ActorUtil.h"
#include "RageDisplay.h"

namespace H
{
	#include "archutils/Unix/X11Helper.h"
}

//REGISTER_ACTOR_CLASS( Window )

Window::Window()
{
	RageDisplay::VideoModeParams p = DISPLAY->GetVideoModeParams();

	m_sWindowTitle = p.sWindowTitle.c_str();
	m_iWidth = p.width;
	m_iHeight = p.height;
	m_iViewportLeft = 0;
	m_iViewportDown = 0;

	m_iWindowsIndex = H::X11Helper::GetWins().size();
}

/*
void Window::RenameWindow()
{
	XChangeProperty( X11Helper::Dpy, X11Helper::Wins[0], XA_WM_NAME, XA_STRING, 8, PropModeReplace,
				reinterpret_cast<unsigned char*>(m_sWindowTitle), strlen(m_sWindowTitle) );
}*/

#include "LuaBinding.h"

template<class T>
class LunaWindow : public Luna<T>
{
public:
	LunaWindow() { LUA->Register( Register ); }

	static int SetTitle( T* p, lua_State *L)        { p->SetTitle(SArg(1)); return 0; }
	static int SetSize( T* p, lua_State *L)         { p->SetSize(IArg(1), IArg(2)); return 0; }
	static int SetWidth( T* p, lua_State *L)        { p->SetWidth(IArg(1)); return 0; }
	static int SetHeight( T* p, lua_State *L)       { p->SetHeight(IArg(1)); return 0; }
	static int SetViewport( T* p, lua_State *L)     { p->SetViewport(IArg(1), IArg(2)); return 0; }
	static int SetViewportLeft( T* p, lua_State *L) { p->SetViewportLeft(IArg(1)); return 0; }
	static int SetViewportDown( T* p, lua_State *L) { p->SetViewportDown(IArg(1)); return 0; }

	static void Register(lua_State *L)
	{

		Luna<T>::Register( L );
	}
};

LUA_REGISTER_CLASS( Window )