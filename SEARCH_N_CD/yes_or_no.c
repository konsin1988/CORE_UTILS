#include "std.h"

int yes_or_no ()
{
	char key = my_getch();
	do
	{
		if(key=='y') return 1;
		else if(key=='n') return 0;
		else {
			key=my_getch();
		}
	}
	while (1);
}
