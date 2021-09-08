#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int get(unsigned int n){
    return (n & (1<<9) );
}
void set(unsigned int *n){
    *n = (*n | (1<<9));
}

void clear(unsigned int *n){
    *n = (*n & ~(1<<9));
}

void inverse(unsigned int *n){
    *n = (*n^ (1<<9));
}


int main()
{

    char s[1000];
    scanf("%[^\n]%*c", &s);
    int i=0;
    while(i<1000 && s[i]!='\0') {
        printf("%c", *(s+i));
        i++;
    }
    return 0;
}


