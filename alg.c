#include "alg.h"
#include <stdio.h>

	//СЧИТЫВАНИЕ ПУТИ//

void input(char *str, char *delim) {
	FILE *file;
	file = fopen("way.txt", "r");

	fscanf(file, "%s", delim);
	printf("\ndelim:%s\n\n", delim);

	fscanf(file, "%s", str);
	printf("str:%s\n\n", str);

	fclose(file);
}

	//ПРОВЕРКИ//

int check_win(char *ptr, int r) {
	int x = 0;
	// for(int i = 0; i < rez; i++) {
        if(schr(ptr,'|') != -1) {
            printf("Error!banned symbol (|)\nptr incorrect\n");
            x = -1;
        }
        if(schr(ptr,'>') != -1) {
            printf("Error!banned symbol (>)\nptr incorrect\n");
            x = -1;
        }
        if(schr(ptr,'<') != -1) {
            printf("Error!banned symbol (<)\nptr incorrect\n");
            x = -1;
        }
        if(schr(ptr,'?') != -1) {
            printf("Error!banned symbol (?)\nptr incorrect\n");
            x = -1;
        }
        if(schr(ptr,'*') != -1) {
            printf("Error!banned symbol (*)\nptr incorrect\n");
            x = -1;
        }
        if(schr(ptr, '\\') != -1) {
            printf("Error!banned symbol (\\)\nptr incorrect\n");
            x = -1;
        }
        // if(((ptr[12]  != 'W') && (ptr[12] != 'D')) || ((ptr[13] != 'W') && (ptr[13] != 'D'))) {
        // printf("Error!incorrect number symbol! \nptr incorrect\n");
        // printf("\n");
        // 	x = -1;
        // }
        // printf("Cимвол0:%c\n", ptr[0]);
        // printf("Cимвол1:%c\n", ptr[1]);
        // printf("Cимвол2:%c\n", ptr[2]);
        // printf("Cимвол3:%c\n", ptr[3]);
        // printf("Cимвол4:%c\n", ptr[4]);
        // printf("Cимвол5:%c\n", ptr[5]);
        // printf("Cимвол6:%c\n", ptr[6]);
        // printf("Cимвол7:%c\n", ptr[7]);
        // printf("Cимвол8:%c\n", ptr[8]);
        // printf("Cимвол9:%c\n", ptr[9]);
        // printf("Cимвол10:%c\n", ptr[10]);
        // printf("Cимвол11:%c\n", ptr[11]);
        // printf("Cимвол12:%c\n", ptr[12]);
        // printf("Cимвол13:%c\n", ptr[13]);
        // printf("Cимвол14:%c\n", ptr[14]);
        // printf("Cимвол15:%c\n", ptr[15]);
        // printf("Cимвол16:%c\n", ptr[16]);
        // printf("Cимвол17:%c\n", ptr[17]);
        // printf("Cимвол18:%c\n", ptr[18]);
         if(ptr[12] == '/') { 
        	printf("Correct way\n");
        }else{
        	if(ptr[11] == '/') { 
        	printf("Correct way\n");
        	}else{	
        		printf("Error!incorrect number symbol! \nptr incorrect\n");
        		x = -1;
         	 }	
		 }      
        // if(ptr[schr(ptr,'D') - 2] != 'e') {
        // 	printf("Error!incorrect nuber symbol! \nptr incorrect\n");
        	// x = -1;
       	// }	
        return x;
}

int check_unix(char *ptr) {
	int x = 0;
	// for(int i = 0; i < rez; i++) {
        if(schr(ptr,'|') != -1) {
            printf("Error!banned symbol (|)\nptr incorrect\n");
            x = -1;
        }
        if(schr(ptr,'>') != -1) {
            printf("Error!banned symbol (>)\nptr incorrect\n");
            x = -1;
        }
        if(schr(ptr,'<') != -1) {
            printf("Error!banned symbol (<)\nptr incorrect\n");
            x = -1;
        }
        if(schr(ptr,'?') != -1) {
            printf("Error!banned symbol (?)\nptr incorrect\n");
            x = -1;
        }
        if(schr(ptr,'*') != -1) {
            printf("Error!banned symbol (*)\nptr incorrect\n");
            x = -1;
        }
        if(schr(ptr, '\\') != -1) {
            printf("Error!banned symbol (\\)\nptr incorrect\n");
            x = -1;
        }
        return x;
}    

	

		//ПРОЦЕСС//

char* procces(char *str, char delim, char *buf) {
	int i;

	// char check = 'c';
	// check = toUpperCase(check);
	// printf("Пися=%c\n", check);
	int index = 0;
	char simb = ':'	;
	char buff[len];
	char *new = buff;
	char *ptr[20];
	char *p = "/cygdrive/"; //Удаляемая часть строки
	int r = slen(p); //Длинна ненужной части
	printf("Lenght Cygdrive=%d\n\n",r);
	int rez;
	// int chec1 = check(str);
	// printf("Проверка=%d\n\n", chec1);
	
		//ПРЕОБРАЗОВАНИЕ ПОЛЕЙ В СТРОКУ//

	rez = stok(str, delim, ptr);
	printf("Rez=%d\n",rez);
	for(int i = 0; i < rez; i++) {
		printf("ptr[%d] = %s\n\n",i, ptr[i]);
	}
	for(int i = 0; i < rez; i++) {
		if(s_str(ptr[i], p) != -1) {
			printf("БУФЕР:%s\n", ptr[i] + 11);
			printf("БУФЕР:%s\n", ptr[i] + 10);
			printf("БУФЕР:%s\n", ptr[i] + 9);
			if(check_win(ptr[i], r) == 0) {
			// printf("123123\n");
			concat(buff, ptr[i] + r);
			index = schr(new, '/');
			inSimbols(new, simb, index);
			simbchange(buff, '/', '\\');
			new[0] = toUpperCase(new[0]);
			//printf("Буф=%s\n\n", buff);
				printf("Буф=%s\n\n", buff);
				concat(buff, "+");
				ptr[i] -= 1;
				new += slen(ptr[i] + r) + 1;				
			}else{
				// printf("Error!banned symbol");
					return -1;
			 }		
		}else{
			if(check_unix(ptr[i]) == 0) {
				concat(buff, ptr[i]);	
			}else{
				// printf("Error!banned symbol");
				return -1;
			 }
		}	
	}
	printf("Correct Way:%s\n", buff);
	return 0;	
}			
	
// }			
	
