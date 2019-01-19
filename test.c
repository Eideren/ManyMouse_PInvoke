#include <stdio.h>
#include "manymouse.h"

void main()
{
	printf("Begin ManyMouse\n");
	
	const int available_mice = ManyMouse_Init();

	if (available_mice < 0)
		printf("ManyMouse failed to initialize!\n");
	else if (available_mice == 0)
		printf("No mice detected!\n");
	else
	{
		int i;
		printf("ManyMouse driver: %s\n", ManyMouse_DriverName());
		for (i = 0; i < available_mice; i++)
			printf("#%d: %s\n", i, ManyMouse_DeviceName(i));
	}
    printf("Reading mouse input ...\n");

	ManyMouseEvent e;
	while (1)
	{
		while (ManyMouse_PollEvent(&e))
		{
			printf("%i\n", e.value);
		}
	}
	ManyMouse_Quit();
}