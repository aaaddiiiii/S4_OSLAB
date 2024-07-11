#include <stdio.h>

void main()
{
    int f, r, pr[100], i, j, k;
    printf("Enter the number of frames: ");
    scanf("%d", &f);
    printf("Enter the number of requests: ");
    scanf("%d", &r);
    printf("Enter the request string: ");
    for (i = 0; i < r; i++)
    {
        scanf("%d", &pr[i]);
    }

    printf("LRU page replacement:\n");
    printf("Pages\n");
    for (i = 0; i < r; i++)
    {
        printf("%d ", pr[i]);
    }
    printf("\n");

    int frame[f], time[f];
    for (i = 0; i < f; i++)
    {
        frame[i] = -1; // Initialize the frame with -1 indicating empty slots
        time[i] = 0;   // Initialize time tracking for LRU
    }

    int miss = 0, hit = 0, counter = 0;

    for (i = 0; i < r; i++)
    {
        int symbol = pr[i];
        int flag = 0;

        for (j = 0; j < f; j++)
        {
            if (frame[j] == symbol)
            {
                flag = 1;
                time[j] = ++counter; // Update the time of use for the page
                break;
            }
        }

        if (flag == 1)
        { // Page hit
            hit++;
        }
        else
        { // Page miss
            int min_time = time[0], min_index = 0;
            for (j = 1; j < f; j++)
            {
                if (time[j] < min_time)
                {
                    min_time = time[j];
                    min_index = j;
                }
            }
            frame[min_index] = symbol;
            time[min_index] = ++counter;
            miss++;
        }

        // Print the current state of the frame
        for (k = 0; k < f; k++)
        {
            if (frame[k] != -1)
            {
                printf("%d ", frame[k]);
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