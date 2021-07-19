#pragma once
#include <Windows.h>

class Window
{
public:
	Window();
	~Window();

	// Initialize Window
	bool init();

	// Release Window
	bool release();

protected:
	HWND m_hwnd;

private:
};

