#include "std.h"

void print_help( char** argv )
{
	printf(
	"\n* Mrm (\"my rm\") utility. 				*\n"
	"* Deletes all files in the current directory 		*\n"
	"* (including internal directories - the -r flag 	*\n"
	"* in the standard rm utility) starting (the f 		*\n"
	"* parameter) or ending (the l parameter) with 		*\n"
	"* the character sequence specified in the second 	*\n"
	"* parameter. There are many types of execution of 	*\n"
	"* this functionality, but all that I have come 	*\n"
	"* across are too cumbersome, and it was decided 	*\n"
	"* to write a utility \"for myself\".			*\n"
	"\n\nSyntax:\n\t%s l(f) 'substring to find and rm' \n",
		argv[0]);
}


