#include "substring.h"
#include <string.h>

/**
 * check_word - Checks if a word from the list is in the substring.
 * @s: The substring.
 * @words: The list of words.
 * @nb_words: Number of words.
 *
 * Return: 1 if all words are found, otherwise 0.
 */
int check_word(char const *s, word_t *words, int nb_words)
{
	int i, j;
	char *substr;

	for (i = 0; i < nb_words; i++)
		words[i].used = 0;

	for (i = 0; i < nb_words; i++)
	{
		for (j = 0; j < nb_words; j++)
		{
			substr = strndup(s + i * words[j].len, words[j].len);
			if (!words[j].used && strcmp(substr, words[j].word) == 0)
			{
				words[j].used = 1;
				free(substr);
				break;
			}
			free(substr);
		}
		if (j == nb_words)
			return (0);
	}
	return (1);
}

/**
 * find_substring - Finds all the possible substrings
 * containing a list of words.
 * @s: The string to search in.
 * @words: The array of words.
 * @nb_words: Number of words.
 * @n: Pointer to store the number of substrings found.
 *
 * Return: An array of starting indices of substrings, or NULL.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *indices, len_s, len_w, i;
	word_t *word_list;

	if (!s || !words || nb_words == 0 || !n)
		return (NULL);
	len_s = strlen(s);
	len_w = strlen(words[0]);
	*n = 0;
	word_list = malloc(sizeof(word_t) * nb_words);
	if (!word_list)
		return (NULL);

	for (i = 0; i < nb_words; i++)
	{
		word_list[i].word = (char *)words[i];
		word_list[i].len = len_w;
		word_list[i].used = 0;
	}
	indices = malloc(sizeof(int) * len_s);
	if (!indices)
	{
		free(word_list);
		return (NULL);
	}
	for (i = 0; i <= len_s - nb_words * len_w; i++)
	{
		if (check_word(s + i, word_list, nb_words))
		{
			indices[*n] = i;
			(*n)++;
		}
	}

	free(word_list);
	if (*n == 0)
	{
		free(indices);
		return (NULL);
	}
	return (indices);
}
