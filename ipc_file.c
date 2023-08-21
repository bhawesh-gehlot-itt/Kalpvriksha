#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void sort(int len, int *ptr)
{
    int i, j, temp;
    for (i = 0; i < len; i++)
    {
        for (j = i + 1; j < len; j++)
        {
            if (*(ptr + j) < *(ptr + i))
            {
                temp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;
            }
        }
    }
}

void main()
{
    int len;
    pid_t p;

    printf("Enter length of array: ");
    scanf("%d", &len);

    int arr[len];

    for (int i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }

    p = fork();

    if (p < 0)
    {
        printf("Failed to fork");
        return;
    }

    else if (p > 0)
    {
        FILE *file = fopen("testFile.txt", "w");
        if (file == NULL)
        {
            printf("Failed to open file P1");
            return;
        }

        for (int i = 0; i < len; i++)
        {
            fprintf(file, "%d\n", arr[i]);
        }

        fclose(file);

        wait(NULL);

        FILE *file2 = fopen("testFile.txt", "r");

        int sortedArrP1[len];
        for (int i = 0; i < len; i++)
        {
            fscanf(file2, "%d", &sortedArrP1[i]);
        }

        printf("------------------\n");
        for (int i = 0; i < len; i++)
        {
            printf("%d ", sortedArrP1[i]);
        }
        printf("\n");

        fclose(file2);
        exit(0);
    }
    else
    {
        FILE *file = fopen("testFile.txt", "r");
        if (file == NULL)
        {
            printf("Failed to open file P2");
            return;
        }

        int sortedArrP2[len];
        for (int i = 0; i < len; i++)
        {
            fscanf(file, "%d", &sortedArrP2[i]);
        }

        fclose(file);

        sort(len, sortedArrP2);

        FILE *file2 = fopen("testFile.txt", "w");
        for (int i = 0; i < len; i++)
        {
            fprintf(file2, "%d\n", sortedArrP2[i]);
        }

        fclose(file2);
        exit(0);
    }
}
