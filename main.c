#include <stdio.h>
#include "strings.h"
#include "alg.h"

#define len 260

int main() {	
	char delim[0];
	char str[len];
	input(str, delim);
	char del = delim[0];
	char buf[len];
	if(procces(str, del, buf) == 0) 
		printf("Correct Terminate\n");
	return 0;
}