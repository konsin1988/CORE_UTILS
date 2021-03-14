#include "std.h"

int in_param(int argc, char** argv)
{
	if(argc != 2) {
		printf("\n\t%s requires one parameter\n"
			"Syntax:\n\t%s 'name of the folder'.\n\t"
			"'Name of the folder' - name without full path, "
			"without quotes or any other symbols.\n", 
			argv[0], argv[0]);
	} else {
		return 1;
	}
	return 0;
}

