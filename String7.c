// C program to capitalize the first letter of each word of a string.

#include <stdio.h>

char *capitalizeFirstLetter(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (i == 0 || str[i - 1] == ' ')
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] = str[i] - 32;
            }
        }
    }
    return str;
}

void main()
{
    char str[100];
    scanf("%[^\n]%*c", str);
    printf("\n%s", capitalizeFirstLetter(str));
}