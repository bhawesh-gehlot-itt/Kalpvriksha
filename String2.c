// C program to count number of occurrences of an alphabet in a string.

#include <stdio.h>
#include <ctype.h>

int noOfOccurrences(char str[], char alphabet)
{
    int occurrences = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (tolower(str[i]) == tolower(alphabet))
            occurrences++;
    }
    return (occurrences);
}

void main()
{
    char sentence[100], alphabet;
    scanf("%[^\n]%*c\n", sentence);
    scanf("%c", &alphabet);
    int occurrences = 0;
    occurrences = noOfOccurrences(sentence, alphabet);
    printf("%d", occurrences);
}