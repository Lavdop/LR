#include <stdio.h>
#include <locale.h>
void PrintUnicode(char* c){
    printf("%s", c);
    printf("\n");

}
unsigned int GetUnicode(){
	int a = getchar();
	int b = 0;
	unsigned int res = 0;
	for(int i = 7; i > 0; i--){
		if(a >> i == 1){
			b++;
		} else{
			break;
		}
	}
	for (int i = 0; i < b; i++){
		if(i == 0){
			unsigned int t = 0;
			for(int k = 0; k < (7 - b);k++){
				t = t<<1 + 1;}
			res = a & t;
		}
		
		else{
			a = getchar();
			res = res<<6 + (a & 127); 

	}

	}
	return res;
}
int main(){
	printf("%u", GetUnicode()); 
}

