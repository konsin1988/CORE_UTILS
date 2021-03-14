#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <err.h>
#include <sys/user.h>
#include <sys/ptrace.h>
#include <syscall.h>
#include <dirent.h>

int in_param(int argc, char** argv);
int my_getch();
int yes_or_no();
