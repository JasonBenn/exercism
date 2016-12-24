#include <stdio.h>
#include <stddef.h>
#include "hello_world.h"

void hello(char *buffer, const char *name) {
    printf("Hello ");
    if (name) {
        for (int i = 0; name[i] != '\0' && i < *buffer; ++i) {
            printf("%c", name[i]);
        }
    } else {
        printf("World");
    }
    printf("!\n");
}

int main(void) {
    char buffer[5];
    hello(buffer, "A");
    hello(buffer, "AB");
    hello(buffer, "ABC");
    hello(buffer, "ABCD");
    hello(buffer, "ABCDE");
    hello(buffer, "ABCDEF");
    hello(buffer, "ABCDEFG");
    hello(buffer, "ABCDEFGH");
    hello(buffer, "ABCDEFGHI");
    hello(buffer, "ABCDEFGHIJ");
    hello(buffer, "ABCDEFGHIJK");
    hello(buffer, "ABCDEFGHIJKL");
    hello(buffer, NULL);
}
