// C program to find if two strings are anagrams or not.

#include <stdio.h>
#include <string.h>

int isAnagram(char str1[], char str2[])
{
    int f1[26] = {0}, f2[26] = {0};

    for (int i = 0; str1[i] != '\0'; i++)
    {
        if (str1[i] >= 'a' && str1[i] <= 'z')
        {
            f1[str1[i] - 'a']++;
        }
    }

    for (int i = 0; str2[i] != '\0'; i++)
    {
        if (str2[i] >= 'a' && str2[i] <= 'z')
        {
            f2[str2[i] - 'a']++;
        }
    }

    if (strlen(str1) != strlen(str2))
    {
        return 0;
    }

    for (int i = 0; i < 26; i++)
    {
        if (f1[i] != f2[i])
        {
            return 0;
        }
    }

    return 1;
}

void main()
{
    char str1[100], str2[100];
    scanf("%[^\n]%*c\n", str1);
    scanf("%[^\n]%*c", str2);
    if (isAnagram(str1, str2))
    {
        printf("Strings are anagrams.\n");
    }
    else
    {
        printf("Strings are not anagrams.\n");
    }
}