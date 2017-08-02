#include "global.h"
#include "RageLog.h"

#include "WindowManager.h"

WindowManager* WINDOWMAN = NULL;

WindowManager::WindowManager()
{
	LOG->Trace( "WindowManager::WindowManager()" );
}

WindowManager::~WindowManager()
{

}


#include "LuaBinding.h"

template<class T>
class LunaWindowManager : public Luna<T>
{
public:
	LunaWindowManager() { LUA->Register( Register ); }

	static int GetUsedAPI( T* p, lua_State *L )
	{
		lua_pushstring( L, p->GetUsedAPI() );
		return 1;
	}

	static void Register(lua_State *L)
	{
		ADD_METHOD( GetUsedAPI )
		Luna<T>::Register( L );

		if( WINDOWMAN )
		{
			lua_pushstring(L, "WINDOWMAN");
			WINDOWMAN->PushSelf( L );
			lua_settable(L, LUA_GLOBALSINDEX);
		}
	}
};

LUA_REGISTER_CLASS( WindowManager )
