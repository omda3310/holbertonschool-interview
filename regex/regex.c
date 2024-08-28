#include "regex.h"

/**
 * regex_match - checks if a given pattern matches a string
 * @str: the string to be scanned
 * @pattern: the regular expression pattern
 *
 * Return: 1 if the pattern matches the string, 0 otherwise
 */
int regex_match(const char *str, const char *pattern)
{
	if (*pattern == '\0')
		return (*str == '\0');

	int matched = (*str != '\0' && (*str == *pattern || *pattern == '.'));

	if (*(pattern + 1) == '*')
	{
		return (regex_match(str, pattern + 2) ||
			(matched && regex_match(str + 1, pattern)));
	}
	else
	{
		return (matched && regex_match(str + 1, pattern + 1));
	}
}
