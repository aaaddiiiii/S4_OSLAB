#include <stdio.h>

void main()
{
    int f, r, pr[100], i, j;
    printf("Enter the number of frames: ");
    scanf("%d", &f);
    printf("Enter the number of requests: ");
    scanf("%d", &r);
    printf("Enter the request string: ");
    for (i = 0; i < r; i++)
    {
        scanf("%d", &pr[i]);
    }

    printf("FIFO page replacement:\n");
    printf("Pages\n");
    for (i = 0; i < r; i++)
    {
        printf("%d ", pr[i]);
    }
    printf("\n");

    int frame[f];
    for (i = 0; i < f; i++)
    {
        frame[i] = -1; // Initialize the frame with -1 indicating empty slots
    }

    int index = -1;
    int miss = 0;
    int hit = 0;

    for (i = 0; i < r; i++)
    {
        int symbol = pr[i];
        int flag = 0;

        // Check if the page is already in the frame (hit)
        for (j = 0; j < f; j++)
        {
            if (symbol == frame[j])
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
        { // Page hit
            hit += 1;
        }
        else
        { // Page miss
            index = (index + 1) % f;
            frame[index] = symbol;
            miss += 1;
        }

        // Print the current state of the frame
        for (j = 0; j < f; j++)
        {
            if (frame[j] != -1)
            {
                printf("%d ", frame[j]);
            }
            else
            {
                printf("- ");
            }
        }
        printf("\n");
    }

    printf("Total misses: %d\n", miss);
    printf("Total hits: %d\n", hit);
}