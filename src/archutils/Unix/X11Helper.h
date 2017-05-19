/* Manages our X connection and window. */
#ifndef X11_HELPER_H
#define X11_HELPER_H

#include <X11/Xlib.h>		// Window

#include "RageDisplay.h"	// RageDisplay
#include <vector>           // std::vector
#include <GL/glx.h>         // GLXContext

namespace X11Helper
{
	// All functions in here that return a bool return true on success, and
	// false on failure.

	// Create the connection, if necessary; otherwise do some important
	// internal session-tracking stuff (so you should call this anyway).
	bool Go();

	// Shitty getters because "undefined reference to" is annoying me
	Display *GetDpy();
	std::vector<Window> GetWins();
	std::vector<GLXContext> GetCtxs();

	// The current Display (connection). Initialized by the first call to
	// Go().
	extern Display *Dpy;

	// A vector containing active windows.
	extern std::vector<Window> Wins;

	// A vector containing active GLX contexts.
	extern std::vector<GLXContext> Ctxs;

	// Set current GL Viewport
	void SetViewport(int shift_left, int shift_down);

	// Set current GLX Context
	bool SetCurrentContext(unsigned int i);

	// Destroy a specific window by its index.
	void DestroyWindow(unsigned int i);

	// Destroy a specific window.
	void DestroyWindow(Window w);

	// (Re)create the window on the screen of this number with this depth,
	// this visual type, this width (optional -- you can resize the window
	// in your callback later), and this height (optional).
	bool MakeWindow(int screenNum, int depth, Visual *visual,
					int width=32, int height=32,
					bool bOverrideRedirect = false);

	// Unmask one X event type mask thingy (XSelectInput() arg 3) on the
	// current window. Masked/unmasked events will carry between windows.
	bool OpenMask(long mask);

	// (Re)mask one X event type mask thingy (XSelectInput() arg 3) on the
	// current window. Masked/unmasked events will carry between windows.
	bool CloseMask(long mask);

	// Destroy the connection, if appropriate; otherwise do some important
	// internal session-tracking stuff (so you should call it anyway).
	void Stop();
};


namespace H
{
	namespace X11Helper
	{
		// Shitty getters because "undefined reference to" is annoying me
		Display *GetDpy();
		std::vector<Window> GetWins();
		std::vector<GLXContext> GetCtxs();

		// Set current GL Viewport
		void SetViewport(int shift_left, int shift_down);

		// Set current GLX Context
		bool SetCurrentContext(unsigned int i);

		// Destroy a specific window by its index.
		void DestroyWindow(unsigned int i);

		// Destroy a specific window.
		void DestroyWindow(Window w);
	}
}

#endif

/*
 * (c) 2005 Ben Anderson
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, and/or sell copies of the Software, and to permit persons to
 * whom the Software is furnished to do so, provided that the above
 * copyright notice(s) and this permission notice appear in all copies of
 * the Software and that both the above copyright notice(s) and this
 * permission notice appear in supporting documentation.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF
 * THIRD PARTY RIGHTS. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR HOLDERS
 * INCLUDED IN THIS NOTICE BE LIABLE FOR ANY CLAIM, OR ANY SPECIAL INDIRECT
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */
