#include "strings.h"
#include <stdio.h>

int slen(char *str) {
	int i = 0;
	while(*str) {
		i++;
		str++;
	}
	return i;
}

int stok(char *str, char delim, char *ptr[]) {
	char *suf = str;
	ptr[0] = str; // первое поле – начало str
	int i, j = 1; // j – счетчик полей
	while( ( i = schr(suf, delim) ) >= 0 ){
		suf[i] = '\0';
		suf = suf + i + 1;
		ptr[j] = suf;
		j++;
	}
	return j;
}
int sspn(char *str, char *sym) {
    int i;
    for( i = 0; str[i] != '\0' ; i++) {
        if( schr(sym, str[i] ) < 0 ) {
        break;
        }
    }
    return i;
}
int scmp(char *str, char *str1) {
    int i, flg = 0;
    for( i = 0; (str[i]==str1[i]) && str[i]!='\0' && str1[i]!='\0'; i++);
        if( str[i] < str1[i] ) 
            flg = -1; // если строки
        else if( str[i] > str1[i] ) 
            flg = 1;// разной длины
    return flg;
}

void scopy(char *str, char *str1) {
    while(*str1++ = *str++);
}

int schr(char *str, char ch) {
    int i, index = -1;
    for(i = 0; (str[i] != '\0') && (str[i] != ch); i++);
        if( str[i] == ch )
        index = i;

    return index;
}

int s_str(char *str, char *p) {
    char *suf = str;
    int len = slen(p);
    int i, pos = -1;
    while( ( ( i = schr(suf,p[0]) ) >= 0) && (pos < 0) ){
        char tmp;
        suf = suf + i;
        tmp = suf[len];
        suf[len] = '\0';
        if( sequal(suf, p) ) { // посимвольное сравнение строк
            pos = suf - str; // разность указателей = индекс
        }
        suf[len] = tmp;
        suf++;
    }
    return pos;
}

int sequal(char *str, char *str1) {
    int i, flg = 1;
        for(i = 0; flg && (str[i]!='\0' || str1[i]!='\0');i++) {
            if( str[i]!=str1[i] ) flg = 0;
        }
    return flg;
}


void concat(char *str, char* str1) {
    while(*str) {
        str++;
    }
    while(*str++ = *str1++);
}

int isLowCase(char ch) {
    if( ch >= 'a' && ch <= 'z') {
        return 1;
    }
    return 0;
}

char toUpperCase(char ch) {
	if(isLowCase(ch)) {
		return ch + ('A' - 'a');
	}
	return ch;
} 

void inSimbols(char *str , char simb, int index) {
	char arr[260];
    int leng = slen(str);
    int i = index;
    int j = 0;
 //    char tmp = str[i + 1];
	// char tmp1 = str[i + 2];
        for(int i = index; i <= leng; i++) {
 			arr[j] = str[i];
 			j++;     
       }
       // printf("Длинна=%d\n", leng);
       // printf("Длина строки=%c\n", str[leng]);
       j = 0;
       for(int i = index + 1; i <= leng + 1; i++) {
		str[i] = arr[j];
       	j++;
       }
    str[index] = simb;
}

void simbchange(char *str, char ch, char ch2) {
	int i;

	while((i = schr(str, ch)) != -1 ) {
		str[i] = ch2;
	}
}

void suntok(char *str, char delim, char *ptr[], int cnt) {
    int i;
    for(i = 1; i < cnt; i++) {
        *(ptr[i] - 1) = delim;
    }
}
