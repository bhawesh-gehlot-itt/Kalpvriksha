// C program to remove non-alphanumeric characters from a string.

#include <stdio.h>

int isAlphaNumeric(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void removeNonAlphaNumeric(char str[], char new_str[])
{
    int i, j = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (isAlphaNumeric(str[i]))
        {
            new_str[j] = str[i];
            j++;
        }
    }
    new_str[j] = '\0';
}

void main()
{
    char str[100], new_str[100];
    scanf("%[^\n]%*c", str);
    removeNonAlphaNumeric(str, new_str);
    printf("\n%s", new_str);
}