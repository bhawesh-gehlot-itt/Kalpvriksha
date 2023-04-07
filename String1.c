// C program to count number of words present in a string.

#include <stdio.h>
#include <string.h>

int countWords(char str[])
{
    if (strlen(str) == 0)
    {
        return 0;
    }
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' || str[i] == '\n')
        {
            count++;
        }
    }
    return count + 1;
}

void main()
{
    char sentence[100];
    scanf("%[^\n]%*c", sentence);
    int wordCount = 0;
    wordCount = countWords(sentence);
    printf("%d", wordCount);
}