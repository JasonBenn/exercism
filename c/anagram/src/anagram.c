#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "anagram.h"
#define MAX_STR_LEN 20

enum { TRUE, FALSE };

int *countLetters(char *word) {
    int *ptr;
    ptr = malloc(sizeof(int) * 26);

    int i = 0;
    int lettersCount = 26;

    while (lettersCount--) {
        ptr[lettersCount] = 0;
    }

    while (word[i] != '\0') {
        ptr[word[i] - 'a'] += 1;
        i++;
    }
    return ptr;
}

void printLetterCount(int *letterCount) {
    int i = 0;
    while (i < 26) {
        if (letterCount[i] != 0) {
            printf("%c: %i\n", (char) i + 'a', letterCount[i]);
        }
        i++;
    }
}

int compareLetterCounts(int *a, int *b) {
    int i = 0;
    while (i++ < 26) {
        printf("comparing: %c to %c. %i\n", a[i] + 'a', b[i] + 'a', a[i] == b[i]);
        if (a[i] != b[i])
            return FALSE;
    }
    return TRUE;
}

#define MAX_INPUTS_LENGTH 5


struct Vector anagrams_for(char *word, struct Vector inputs) {
    int *wordLetterCounts = countLetters(word);
    char matchingWords[5][MAX_STR_LEN];
    struct Vector outputs = { matchingWords, 0 };

    for (int i = 0; i < inputs.size; i++) {
        if (compareLetterCounts(wordLetterCounts, countLetters(inputs.vec[i]))) {
            printf("%i", outputs.size);
//            outputs[outputs.size++] = inputs.vec[i];
        }
    }
    return outputs;
}

int main(void) {

//    int x;
    char inputs[][MAX_STR_LEN] = {
            "tan",
            "stand",
            "at"
    };

//    char outputs[][MAX_STR_LEN] = {
//            "tan"
//    };
//    int outputs_len = sizeof(outputs) / MAX_STR_LEN;

    struct Vector vin = {
            inputs,
            sizeof(inputs) / MAX_STR_LEN
    };

    anagrams_for("ant", vin);

//    char *wordA = "ahhhhhhaahello";
//    char *wordB = "ahhhhhhaahlello";
//    int *letterCount = countLetters(wordA);

//    printLetterCount(letterCount);
    // How do I allocate memory for a struct containing an array of pointers to chars (strings)? I guess I have to
    // enforce a max length, don't I.
    // Is it char vec[5][20]?

    // I want to create a struct that maps characters to the count of characters. How do I dynamically add characters
    // and their counts to a list? Would I need to implement a search through a list to find a char, and add only if
    // the char was never found?

    // my goal is to create a mapping from char to count as I encounter chars. Then, by comparing these counts, I'll
    // know if they're anagrams of each other.
    // CharToCount

//    printf("first vec: %s, size: %i", outputs->vec[0], outputs->size);
}
