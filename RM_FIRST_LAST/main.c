#include "std.h"

int flag;		/* specify whether to check file names 
		   	from the beginning or from the end */
char* substr;	/* substring to find */

int main(int argc, char** argv)
{
	substr = (char*)malloc(20 * sizeof(char));
	if(in_param(argc, argv, &flag, &substr)) {
		char **file_list = search_files(substr, flag);
		//system("clear");
		print_line();
	       	if (file_list == NULL) {
			printf("*   There is no such files in dir!     *\n*");
			goto end_free;
		}
		printf("* Are you sure to delete these files?  *\n");
		print_files_to_rm(file_list);
		printf("\n");
		print_line();
		printf(" ..Press 'y' or 'n' for an answer...\n");
		if (yes_or_no()) {
			remove_files(file_list);
			printf("\n\t--> Successfully remove! <--\n");
		} else {
			printf("\n\t--> Deletion rejected! <--\n");
		}
		free(file_list);
	}
	end_free:
	free(substr);
	printf("\n*\tPress any key to continue...   *\n");
	print_line();
	my_getch();
	system("clear");
	return 0;
}
	


