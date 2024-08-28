#include "palindrome.h"

int is_palindrome(unsigned long n)
{
    unsigned long reversed = 0, original = n, mod_n;

    while (n != 0)
    {
        mod_n = n % 10;
        reversed = reversed * 10 + mod_n;
        n /= 10;
    }

    if (original == reversed)
        return 1;
    else
        return 0;
}
