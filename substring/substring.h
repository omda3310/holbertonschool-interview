#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <stdlib.h>

/**
 * struct word - Represents a word and its properties.
 * @word: The word string.
 * @len: Length of the word.
 * @used: A flag indicating if the word has been used.
 */
typedef struct word
{
	char *word;
	size_t len;
	int used;
} word_t;

int *find_substring(char const *s, char const **words, int nb_words, int *n);

#endif /* SUBSTRING_H */
