#pragma once

int in_param( int, char**, int*, char** );
void print_help( char**);
char** search_files (char*, int);
void print_files_to_rm (char**);
void remove_files (char**);
int yes_or_no();
int my_getch();
void print_line();
	
