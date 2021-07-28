// App filter - High Level Code
// Engine filter - Low Level Code

#include "Window.h"

Window* window = nullptr;

Window::Window()
{

}

Window::~Window()
{

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) 
{
	switch (msg)
	{

	case WM_CREATE:
	{
		// Event fired when the window will be created
		window->onCreate();

		break;
	}

	case WM_DESTROY:
	{
		// Event fired when the window will be destroyed
		window->onDestroy();

		::PostQuitMessage(0);

		break;
	}

	default:
	{
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
	}

	}

	return NULL;
}

bool Window::init()
{
	WNDCLASSEXW wc;	// Contains the window class attributes registered by RegisterClassEX

	wc.cbClsExtra = 0;	// The number of extra bytes to allocate following the window-class structure, normally initialized by the system to 0

	wc.cbSize = sizeof(WNDCLASSEXW);	// The size of the class in bytes

	wc.cbWndExtra = 0;	// The number of extra bytes to allocate following the window instance, normally initialized by system to 0

	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;	// A handle to the class background brush
	
	wc.hCursor = LoadCursorW(NULL, IDC_ARROW); // A handle to the class cursor, set to load standard arrow

	wc.hIcon = LoadIconW(NULL, IDI_APPLICATION); // Handles to the class icon, set to load default application icon
	wc.hIconSm = LoadIconW(0, IDI_APPLICATION);

	wc.hInstance = NULL;	// A handle to the instance that contains the window procedure for the class

	wc.lpszClassName = L"MyWindowClass";	// A pointer to a null-terminated 256 character-max string literal specifying the class name

	wc.lpszMenuName = L"";	// A pointer to a null-terminated character string literal specifying the resource name of the class menu

	wc.style = NULL;	// The class style

	wc.lpfnWndProc = &WndProc;	// A pointer to the window procedure. You must use the CallWindowProc function to call the window procedure

	// Win32 function to register a class that defines the style and properties of the window to be created
	// returns false if registration fails
	if (!::RegisterClassExW(&wc)) { return false; }

	if (window == nullptr) { window = this; }

	// Create the window, or return false if it fails
	m_hwnd = ::CreateWindowExW(WS_EX_OVERLAPPEDWINDOW, L"MyWindowClass", L"DirectX Application", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768, NULL, NULL, NULL, NULL);

	if (m_hwnd == NULL) { return false; }

	// Show the window
	::ShowWindow(m_hwnd, SW_SHOW);
	::UpdateWindow(m_hwnd);

	// Indicate that window is intialized and running
	m_is_run = true;

	return true;
}

bool Window::release() 
{

	// Destroy the window
	if (::DestroyWindow(m_hwnd) == false) { return false; }

	return true;
}

bool Window::isRun()
{
	return m_is_run;
}

bool Window::broadcast()
{
	MSG msg;

	while (::PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}

	window->onUpdate();

	Sleep(0);

	return true;
}

void Window::onDestroy()
{
	// Indicate window is about to be destroyed
	m_is_run = false;

	return;
}

