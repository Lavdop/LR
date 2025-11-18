#include <stdio.h>
#include <locale.h>
void PrintUnicode(char* c){
    printf("%s", c);
    printf("\n");
}
int main(){

    unsigned char c = getchar();
    printf("%u ", c);
    c = getchar();
    printf("%u ", c);
}