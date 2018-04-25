#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>


int slen(char *str);

int stok(char *str, char delim, char *ptr[]);

int sequal(char *str, char *str1);

int s_str(char *str, char *p);

int sspn(char *str, char *sym);

int scmp(char *str, char *str1);

void scopy(char *str, char *str1);

int schr(char *str, char ch);

void concat(char *str, char *str1); 

int isLowCase(char ch);

void inSimbols(char *str , char simb, int index);

char toUpperCase(char ch);

void simbchange(char *str, char ch, char ch2);

void suntok(char *str, char delim, char *ptr[], int cnt);

#endif