#ifndef _ANAGRAM_H
#define _ANAGRAM_H

#define MAX_STR_LEN 20

struct Vector {
    // pointers to array[20] of chars
   char (*vec)[MAX_STR_LEN];
   int size;
};

struct Vector anagrams_for(char *, struct Vector);

#endif
