#include <stdio.h>
#include <stdbool.h>

int main() {
    long long a;
    bool b = 1;
    while (scanf("%lld", &a) > 0) {
        b = 1;
        if (a < 0) {
            a = -a;
        }
        while (a > 0) {
            if (a % 10 == (a / 10) % 10) {
                b = 0;
                break;
            } 
            a = a / 10;
        }
        printf("%d\n", b);
    }
    return 0;
}
// stepan loh