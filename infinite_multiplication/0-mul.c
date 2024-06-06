#include "holberton.h"
#include <stdlib.h>


/**
 * print_error - prints error message and exits with status 98
 */
void print_error(void) {
    char *error_msg = "Error\n";
    while (*error_msg) {
        _putchar(*error_msg++);
    }
    exit(98);
}

/**
 * is_digit - checks if a string is composed only of digits
 * @str: the string to check
 * 
 * Return: 1 if str is only digits, 0 otherwise
 */
int is_digit(char *str) {
    while (*str) {
        if (*str < '0' || *str > '9') {
            return (0);
        }
        str++;
    }
    return (1);
}

/**
 * multiply - multiplies two numbers represented as strings
 * @num1: the first number
 * @num2: the second number
 * 
 * Return: a pointer to the result string
 */
char *multiply(char *num1, char *num2) {
    int len1 = 0, len2 = 0, len_result, i, j, carry, prod;
    char *result;

    while (num1[len1]) len1++;
    while (num2[len2]) len2++;
    len_result = len1 + len2;

    result = malloc(len_result);
    if (!result) {
        print_error();
    }
    for (i = 0; i < len_result; i++) {
        result[i] = 0;
    }

    for (i = len1 - 1; i >= 0; i--) {
        for (j = len2 - 1; j >= 0; j--) {
            prod = (num1[i] - '0') * (num2[j] - '0');
            carry = (result[i + j + 1] + prod) / 10;
            result[i + j + 1] = (result[i + j + 1] + prod) % 10;
            result[i + j] += carry;
        }
    }

    i = 0;
    while (i < len_result && result[i] == 0) {
        i++;
    }

    if (i == len_result) {
        _putchar('0');
    } else {
        for (; i < len_result; i++) {
            _putchar(result[i] + '0');
        }
    }

    _putchar('\n');
    free(result);
    return result;
}

/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * 
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_error();
    }

    if (!is_digit(argv[1]) || !is_digit(argv[2])) {
        print_error();
    }

    multiply(argv[1], argv[2]);

    return (0);
}
