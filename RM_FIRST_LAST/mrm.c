#include "std.h"

int strcmp_last(const char*, const char*);

/**************** SEARCH_FILES ******************/
/* Input: substring to find;
 * Return: array of file pointer to rm */
char** search_files (char* substr, int flag) {
	char* cwd_dir = (char*)malloc(512 * sizeof(char));
	char** file_list = (char**)malloc(100 * sizeof(char*));
	size_t list_size = 0;
	size_t substr_len = strlen(substr);
	FILE *F;
	DIR *D;

	getcwd(cwd_dir, 512);
	cwd_dir = (char*)realloc(cwd_dir, strlen(cwd_dir) * 
			sizeof(char));
	if ((F = fopen(cwd_dir, "rt")) == NULL) {
		fprintf(stderr, "Unable to open file %s\n", 
				cwd_dir);
	}
	if ((D = fdopendir(fileno(F))) == NULL) {
		fprintf(stderr, "Unable to open dir %s\n", 
				cwd_dir);
	}

	struct dirent* file;
	while((file = readdir(D))) {
		if(flag == 0 && !strncmp((*file).d_name, 
				substr, substr_len)) {
			file_list[list_size] = (*file).d_name;
			list_size++;
		} else if (flag == 1 && !strcmp_last((*file).d_name,
				substr)) {
			file_list[list_size] = (*file).d_name;
			list_size++;
		}
	}
	if (list_size) {
		return file_list;
	}
}

int strcmp_last (const char* str, const char* substr) {
	size_t substr_len = strlen(substr);
	size_t str_len = strlen(str);
	while (substr_len > 0 && substr[substr_len-1] == str[str_len-1]) {
		str_len--;
		substr_len--;
	}
	if (substr_len == 0) {
		return 0;
	}
	return 1;
}
/*_______________________________________________________*/
//
/************* PRINT_FILES_TO_RM ************************/
/* IN: list of string pointers
 * RETURN: void */
void print_files_to_rm (char** file_list) {
	size_t size = 0;
	while (file_list[size]) {
		printf("*   %zu. %-32s*\n", size+1, file_list[size]);
		size++;
	}
}
/*_______________________________________________________*/
//
/***************** REMOVE_FILES **************************/
/* IN:		list of file pointers
 * RETURN:	void 					 */
void remove_files (char** file_list) {
	size_t size = 0;
	DIR *D;

	while (file_list[size]) {
		char comand[100] = "rm ";
		if ((D = opendir(file_list[size])) != NULL) {
			strcat(comand, "-r ");
		}
		strcat(comand, file_list[size]);
		system(comand);
		size++;
	}
}
/*______________________________________________________*/
//
/******************* PRINT_LINE ************************/
void print_line() {
	for(size_t i = 0; i < 40; ++i) {
		printf("*");
	}
	printf("\n");
}
