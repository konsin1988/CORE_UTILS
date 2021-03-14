#include "std.h"

int in_param(int argc, char** argv, int* flag, char** substr)
{
	if(argc<=1) {
		printf("\n\t%s requires more parameters.\n"
			"\tSee '--help' for more information.\n", 
			argv[0]);
	}
	else if(!strcmp(argv[1], "--help")) {
		print_help(argv);
	}
	else if(!strcmp(argv[1], "f") || !strcmp(argv[1], "l")) {
		if(argc != 3) {
			printf("\n\t%s %s requires one argument: "
				"'substring to find'\n", argv[0], argv[1]);
		} else if (!strcmp(argv[1], "f")) {
			(*flag) = 0;
			strcpy((*substr), argv[2]);
			return 1;
		} else if (!strcmp(argv[1], "l")) {
			(*flag) = 1;
			strcpy((*substr), argv[2]);
			return 1;
		}
	}
	else {
		printf("\n\tUnknown parameter.\n\t"
			"See '--help' for more information.\n");
	}
	return 0;
}

