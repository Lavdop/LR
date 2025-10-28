#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    if (a < 0) {
        a = -a;
    }
    while (a > 0) {
        printf("%d ", a % 10);
        a = a / 10;
    }
}