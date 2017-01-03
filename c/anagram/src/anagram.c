#include <stdio.h>
#include <stdlib.h>
#include "./anagram.h"

// pointer version
void xor_chars(char *word, int *xord) {
    int i = 0;
    while (word[i++] != '\0') {
        *xord ^= word[i];
        printf("%i\n", *xord);
    }
}

// invoked like so:
//int xord = 0;
//xor_chars("xoa", &xord);
//printf("xord: %i\n", xord);

struct Vector anagrams_for(char *word, struct Vector vec) {
    int xord = 0;
    xor_chars(word, &xord);

    for (int i = 0; i < vec.size; i++) {
    }
}

int main(void) {
    int xord = 0;
    xor_chars("xoa", &xord);
    printf("xord: %i\n", xord);
    xor_chars("xoa", &xord);
    printf("xord: %i\n", xord);
    char words[][MAX_STR_LEN] = {
        "banana", "boa", "sup"
    };
    struct Vector vec = {
        words,
        3
    };
    anagrams_for("oab", vec);
}
