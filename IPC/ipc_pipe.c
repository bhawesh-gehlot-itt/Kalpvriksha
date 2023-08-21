#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int fd1[2];
    int fd2[2];
    int len;
    pid_t p;

    if (pipe(fd1) == -1)
    {
        printf("Failed to Create Pipe 1");
        return;
    }

    if (pipe(fd2) == -1)
    {
        printf("Failed to Create Pipe 2");
        return;
    }

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
        int sortedArrP1[len];

        close(fd1[0]);
        write(fd1[1], arr, sizeof(arr));
        close(fd1[1]);

        wait(NULL);

        close(fd2[1]);
        read(fd2[0], sortedArrP1, 100);

        printf("------------------\n");
        for (int i = 0; i < len; i++)
        {
            printf("%d ", sortedArrP1[i]);
        }
        printf("\n");

        close(fd2[0]);
        exit(0);
    }

    else
    {
        close(fd1[1]);

        int sortedArrP2[len];
        read(fd1[0], sortedArrP2, 100);

        sort(len, sortedArrP2);

        close(fd1[0]);
        close(fd2[0]);

        write(fd2[1], sortedArrP2, 100);
        close(fd2[1]);

        exit(0);
    }
}
