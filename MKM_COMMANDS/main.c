#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char** argv)
{
	if(argc<=1)
	{
		system("make clean");
		system("clear");
		system("make");
	}
	else if(argc == 2)
	{
		if(!strcmp(argv[1], "c"))
		{
			system("clear");
		}
		else if(!strcmp(argv[1], "o"))
		{
			system("make clean");
			system("clear");
		}

		else if( !strcmp(argv[1], "r"))
		{
			system("clear");
			system("make run");
		}
		
		else
		{
			printf("\nUnknown parameter\n");
		}
	}
	return 0;
}
