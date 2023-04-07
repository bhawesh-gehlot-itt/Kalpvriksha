// C program to trim leading and trailing spaces from a string.

#include <stdio.h>
#include <string.h>

char *trimSpaces(char str[])
{
    int i, j, len;
    len = strlen(str);

    // removing leading spaces
    for (i = 0; str[i] == ' '; i++)
        ;
    for (j = 0; i < len; i++, j++)
    {
        str[j] = str[i];
    }
    str[j] = '\0';

    len = strlen(str);

    // removing trailing spaces
    for (i = len - 1; i >= 0 && str[i] == ' '; i--)
        ;
    str[i + 1] = '\0';

    return (str);
}

void main()
{
    char sentence[100];
    scanf("%[^\n]%*c\n", sentence);
    printf("%s", trimSpaces(sentence));
}