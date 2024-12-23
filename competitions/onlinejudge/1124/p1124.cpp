#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


int main() {
    size_t len, nread = 0; 
    char *s = NULL;
    while((nread = getline(&s, &len, stdin)) != -1) {
        fwrite(s, nread, 1, stdout);
    }
    free(s);

    // char ch;
    // while(true) {
    //     ch = getchar();
    //     if(ch == EOF) break;
    //     putchar(ch);
    // }

    return 0;
}