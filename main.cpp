// App filter - High Level Code
// Engine filter - Low Level Code

#include "AppWindow.h"

int main() 
{

	AppWindow app;
	if (app.init()) 
	{

		while (app.isRun() == true) 
		{
			app.broadcast();

		}
	}

	return 0;
}