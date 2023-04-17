// C program to find the largest word in the given sentence.

#include <stdio.h>
#include <string.h>

char *getLargestWord(char sentence[], char largestWord[])
{
    int senLen = strlen(sentence);
    int maxLen = 0;
    char currentWord[100] = {0};

    for (int i = 0; i < senLen; i++)
    {
        int j = 0;
        while (sentence[i] != ' ' && i < senLen)
        {
            currentWord[j++] = sentence[i++];
        }
        currentWord[j] = '\0';

        if (strlen(currentWord) > maxLen)
        {
            maxLen = strlen(currentWord);
            for (int k = 0; k < maxLen; k++)
            {
                largestWord[k] = currentWord[k];
            }
        }
    }
    return largestWord;
}

void main()
{
    char sentence[100];
    char largestWord[100] = {0};
    scanf("%[^\n]%*c", sentence);
    printf("\n%s", getLargestWord(sentence, largestWord));
}