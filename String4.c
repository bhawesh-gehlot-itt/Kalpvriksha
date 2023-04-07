// C program to get all words from a string.

#include <stdio.h>

void extractWords(char str[])
{
    int start = 0, end = 0;
    while (1)
    {
        if (str[end] == ' ' || str[end] == '\n' || str[end] == '\0')
        {
            int length = end - start;
            char word[length + 1];
            for (int i = 0; i < length; i++)
            {
                word[i] = str[start + i];
            }
            word[length] = '\0';
            printf("%s\n", word);
            start = end + 1;
        }
        if (str[end] == '\0')
        {
            break;
        }
        end++;
    }
}

void main()
{
    char sentence[100];
    scanf("%[^\n]%*c", sentence);
    extractWords(sentence);
}