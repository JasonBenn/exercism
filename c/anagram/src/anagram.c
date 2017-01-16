#include <stdio.h>
#include <stdbool.h>
#include "./anagram.h"

// pointer version
void xor_chars(char *word, int *xord) {
    int i = 0;
    while (word[i++] != '\0') {
        *xord ^= word[i];
//        printf("%i\n", *xord);
    }
}

bool is_anagram(char *a, char *b) {
    printf("is_anagram: %s, %s\n", a, b);
    return true;
}

// invoked like so:
//int xord = 0;
//xor_chars("xoa", &xord);
//printf("xord: %i\n", xord);

struct Vector anagrams_for(char *word, struct Vector vec) {
    int xord = 0;
    xor_chars(word, &xord);

    char (*matching_words)[20] = &vec.vec[0];
    // should be pointer to array[20] of chars
    // matching_words++ should be next matching word in vec.
    // start with first array of chars. if matches, matching_words++ = pointer to next word. if doesn't,
    // matching_words++. This means that the pointer will start at the first match, and pointers will be created for
    // subsequent matches. Right?
    int matching_words_length = 0;
    printf("matching_words: %s\n", *matching_words);

    for (int i = 0; i < vec.size; i++) {
        if (is_anagram(vec.vec[i], word)) {
            matching_words_length++;
            printf("this should be garbage, right? %s\n", *(matching_words + matching_words_length));
            printf("this should be a pointer? but it's prob a char. c: %c\n", **(matching_words +
                    matching_words_length));
            printf("this should be a pointer? but it's prob a char. i: %i\n", **(matching_words +
                    matching_words_length));
//            **(matching_words + matching_words_length) = vec.vec[i];
        } else {
            matching_words++;
        }
    }

//    for (int i = 0; i < vec.size; i++) {
//        printf("in loop! i: %i, vec.vec[i]: %s\n", i, &vec.vec[i][0]);
//        int xord_word = 0;
//        xor_chars(&vec.vec[i][0], &xord_word);
//        printf("xord_word: %i, word: %i\n", xord_word, xord);
//        if (xord_word == xord) {
//            printf("xord_word: %i, xord: %i\n", xord_word, xord);
//            strcpy(matching_words[i], vec.vec[i]);
//            printf("matching_words[i]: %s\n", matching_words[i]);
//            matching_words_length++;
//        }
//    }

    // matching_words is a array of pointers. inner pointers are to chars.
    // how do i declare an array of strings again?
    // char matching_words[vec.size][MAX_STR_LEN]?
    // char *matching_words[vec.size][MAX_STR_LEN]?

    // matching words[i]
    struct Vector matching_words_vector = { matching_words, matching_words_length };
    return matching_words_vector;
}

int main(void) {
    int xord = 0;
    xor_chars("xoa", &xord);
//    printf("xord: %i\n", xord);
    xor_chars("xoa", &xord);
//    printf("xord: %i\n", xord);
    char words[][MAX_STR_LEN] = {
        "banana", "boa", "sup", "oab"
    };
    struct Vector vec = {
        words,
        4
    };
    struct Vector result = anagrams_for("oab", vec);
    printf("result.vec.size: %i, result.vec[0]: %s\n", result.size, result.vec[0]);

}
