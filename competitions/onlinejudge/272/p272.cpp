#include <iostream>
#include <stdio.h>

using namespace std;


int main(int argc, char **argv) {
    int ch;
    bool flag = false;
    while(true) {
        ch = getchar();
        if(ch == EOF) break;
        if(ch == '"' && flag == true) {
            putchar('\'');
            putchar('\'');
            flag = false;
        } else if(ch == '"' && flag == false) {
            putchar('`');
            putchar('`');
            flag = true;
        } else {
            putchar(ch);
        }
    }

    return 0;
}
