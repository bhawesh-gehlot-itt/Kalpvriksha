// C program to remove all the vowels from a string.

#include <stdio.h>

char *removeVowels(char str[])
{
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++)
    {
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' && str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U')
        {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
    return str;
}

void main()
{
    char str[100];
    scanf("%[^\n]%*c", str);
    printf("\n%s", removeVowels(str));
}