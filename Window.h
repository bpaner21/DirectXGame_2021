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

	bool isRun();

	bool broadcast();

	// EVENTS
	virtual void onCreate() = 0;
	virtual void onUpdate() = 0;
	virtual void onDestroy();

protected:
	HWND m_hwnd = nullptr;
	bool m_is_run = false;

private:
};

