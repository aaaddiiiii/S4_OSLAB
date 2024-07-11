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

    printf("Optimal page replacement:\n");
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

    int miss = 0;
    int hit = 0;

    for (i = 0; i < r; i++)
    {
        int symbol = pr[i];
        int flag = 0;

        for (j = 0; j < f; j++)
        {
            if (frame[j] == symbol)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
        { // Page hit
            hit++;
        }
        else
        { // Page miss
            if (i < f)
            { // If there are still empty frames
                frame[i] = symbol;
            }
            else
            { // Find the page to replace
                int pos = -1, farthest = i + 1;
                for (j = 0; j < f; j++)
                {
                    int k;
                    for (k = i + 1; k < r; k++)
                    {
                        if (frame[j] == pr[k])
                        {
                            if (k > farthest)
                            {
                                farthest = k;
                                pos = j;
                            }
                            break;
                        }
                    }
                    if (k == r)
                    { // If the page is not found in the future
                        pos = j;
                        break;
                    }
                }
                if (pos == -1)
                {
                    pos = 0;
                }
                frame[pos] = symbol;
            }
            miss++;
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