/* Quad - A rectangle shaped actor with color. */

#ifndef WINDOW_H
#define WINDOW_H

struct lua_State;

class Window
{
public:
	Window();

	void RenameWindow();
	void Resize();
	void ChangeViewport();

	void SetTitle(const CString &title) { m_sWindowTitle = title; RenameWindow(); }
	void SetSize(int w, int h) { m_iWidth = w; m_iHeight = h; Resize(); }
	void SetWidth(int w)       { m_iWidth = w; Resize(); }
	void SetHeight(int h)      { m_iHeight = h; Resize(); }
	void SetViewport(int l, int d) { m_iViewportLeft = l; m_iViewportDown = d; ChangeViewport(); }
	void SetViewportLeft(int l) { m_iViewportLeft = l; ChangeViewport(); }
	void SetViewportDown(int d) { m_iViewportDown = d; ChangeViewport(); }

	// Lua
	void PushSelf( lua_State *L );

protected:
	CString m_sWindowTitle;
	int m_iWidth;
	int m_iHeight;
	int m_iViewportLeft;
	int m_iViewportDown;
	int m_iWindowsIndex; // Index where the window/GLXContext is located in the vectors. ~Sora
};

#endif
