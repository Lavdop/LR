#include <stdio.h>
 void PrintChar(char* c){
    for(int i = 0; c[i] != '\0'; ++i){
        printf("%d ",c[i]);
    } 

}
int main(){
    char *c;
    int* a;
    long long t;
    int i = 0;
    while(scanf("%lld",&t) > 0){
        a[i] = t;
        i ++;
    }
    for(int k = 0;k < 10;k++){
        c[k] = (char)a[k];
    }
    printf("%s\n",c);
//    PrintChar(c);     

}