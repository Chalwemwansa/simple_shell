#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>
#include <fcntl.h>

int _putchar(char c);
void shell(char *arg[], char *argv[]);
int check(char *str);
void do1(char **str1);

#endif
