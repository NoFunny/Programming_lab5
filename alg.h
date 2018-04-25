#ifndef ALG_H
#define ALG_H
#include <stdio.h>

#define len 260

void input(char *str, char *delim);

int check_win(char *ptr, int r);

int check_unix(char *ptr);

char* procces(char *str, char delim, char *buf);

int last_check(char *ptr);
// int output();

#endif