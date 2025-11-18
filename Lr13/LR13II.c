#include <stdio.h>
#include <stdbool.h>

unsigned int GetUnicode() {
    int a = getchar();
    int b = 0;
    unsigned int res = 0, t = 0;
    if (a == -1) {
        return -1u;
    }
    for (int i = 7; i > 0; i--) {
        if (((a>>i) & 1) == 1 ) {
            b++;
        } else {
            break;
        }
    }
    if (b == 0) {
        res = a & 127;
    } else {    
        for (int i = 0; i < 7 - b; i++) {
            t = (t << 1) | 1;
        }
        res = a & t;
        for (int i = 0; i < b - 1; i++) {
            a = getchar();
            res = (res << 6) | (a & 63);
        }
    }
    return res;
}
unsigned int ToUnicode(char* s) {
    int b = 0;
    unsigned int res = 0, t = 0;
    for (int i = 7; i > 0; i--) {
        if (((s[0] >> i) & 1) == 1 ) {
            b++;
        } else {
            break;
        }
    }
    if (b == 0) {
            res = s[0] & 127;
        } else {
            for (int i = 0; i < 7 - b;i ++) {
                t = (t << 1) | 1;
            }
            res = s[0] & t;
            for (int i = 0; i < b - 1; i++) {
                res = (res << 6) | (s[i + 1] & 63);
            }
    }
    return res;
} 
long long int Index(unsigned int s) {
    if(ToUnicode("а") <= s && s <= ToUnicode("я")) {
        return (1ll << (s - ToUnicode("а")));
    } else if (ToUnicode("А") <= s && s <= ToUnicode("Я")) {
        return (1ll << (s - ToUnicode("А")));
    } else if (s == ToUnicode("Ё") || s == ToUnicode("ё")) {
        return (1ll << 34);
    } else {
        return -1;
    }
}
int main() {
    long long int a = 0;
    long long int b = Index(ToUnicode("а")) | Index(ToUnicode("о")) | Index(ToUnicode("у")) | Index(ToUnicode("ы")) | Index(ToUnicode("и")) | Index(ToUnicode("э"));
    unsigned int s;
    bool isWordStarted = false;
    bool res = false;
    while (1) {
        s = GetUnicode();
        if (Index(s) != -1) {
            a = a | Index(s);
            isWordStarted = true;
        } else if (isWordStarted) {
            if ((a & (~b)) == 0) {
                res = true;
            }
            isWordStarted = false;
            a = 0;
        }
        if (s == -1u) {
            break;
        }
    }
    if (res == true) {
        printf("YES");
    } else {
        printf("NO");
    } 
}
