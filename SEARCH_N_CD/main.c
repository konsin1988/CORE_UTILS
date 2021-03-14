#define _GNU_SOURCE
#include "std.h"

extern char **environ;

void search_dir(char*, char*, char**);
void print_ls(char*);

int main(int argc, char** argv, char** envp)
{
	if(in_param(argc, argv)) {
		char* searching_path = (char*)malloc(200 * sizeof(char));
		char work_space[] = "/home/konsin1988/C_PROG";
		char* searching_dir_name = argv[1];
		int wsstatus;
		search_dir(work_space, searching_dir_name, &searching_path);
		chdir(searching_path);
		printf("%d %d\n", getppid(), getpid());
		system("clear");
		printf("%s\n", searching_path);
		print_ls(searching_path);
		printf("\n\tDo you want to open new term?\n");
		if (yes_or_no()) {
			execl("/bin/sh", "sh", "-c", 
				"xfce4-terminal", "!!; bash", NULL);
		}
	}
	return 0;
}
	
void search_dir(char* work_space, char* search_file, char** searching_path) {
        FILE *F;
        DIR *D;

        if ((F = fopen(work_space, "rt")) == NULL) {
                return;
        }
        if ((D = fdopendir(fileno(F))) == NULL) {
                fclose(F);
                return; 
        }
        char* op_file = (char*)malloc(300 * sizeof(char));
        struct dirent* file;
        while((file = readdir(D))) {
                strcpy(op_file, work_space);
                strcat(op_file, "/");
                strcat(op_file, (*file).d_name);
                if (!strcmp((*file).d_name, ".") || 
                        !strcmp((*file).d_name, "..")) {
                        continue;
                }
		if(!strcmp((*file).d_name, search_file)) {
			strcpy(*searching_path, op_file);
		}
                search_dir(op_file, search_file, searching_path);
        }
        free(op_file);
        free(file);
        closedir(D);
        fclose(F);
}

void print_ls(char* searching_path) {
	char** file_list = (char**)malloc(100 * sizeof(char*));
	size_t i;
	size_t size = 0;
	FILE *F;
	DIR *D;

	if ((F = fopen(searching_path, "rt")) == NULL) {
		fprintf(stderr, "Unable to open file %s\n", searching_path);
		exit(1);
	}
	if ((D = fdopendir(fileno(F))) == NULL) {
		fprintf(stderr, "Unable to open dir %s\n", searching_path);
		fclose(F);
		exit(1);
	}

	struct dirent* files;
	while(files = readdir(D)) {
		if(!strcmp((*files).d_name, ".") || 
				!strcmp((*files).d_name, "..")) {
			continue;
		}
		//printf("\t%s\n", (*files).d_name);
		file_list[size] = (*files).d_name;
		size++;
	}
	register size_t j;
	char* tmp = malloc(200 * sizeof(char));
	for (i = 1; i < size; ++i) {
		j = i;
		while (j > 0 && (strcmp(file_list[j], file_list[j-1]) < 0)) {
			tmp = file_list[j];
			file_list[j] = file_list[j-1];
			file_list[j-1] = tmp;
			j--;
		}
	}
	for (i = 0; i < size; ++i) {
		printf("\t%0.2d --- %s\n", i+1, file_list[i]);	
	}

	free(file_list);
	free(files);
	closedir(D);
	fclose(F);

}
