// SCAN DISK SCHEDULING
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void main()
{
    int no_request;
    printf("Enter the number of requests:");
    scanf("%d", &no_request);
    int requests[no_request + 2]; //+2 for storing initial head position & disk width
    printf("Enter the requests:");
    for (int i = 0; i < no_request; i++)
    {
        scanf("%d", &requests[i]);
    }

    int initialhead;
    printf("Enter the initial head position:");
    scanf("%d", &initialhead);
    requests[no_request] = initialhead;
    printf("Enter the disk width:");
    scanf("%d", &requests[no_request + 1]);

    // bubble sorting the requests
    for (int i = 0; i < no_request + 1; i++)
    {
        for (int j = 0; j < no_request + 1 - i; j++)
        {
            if (requests[j] > requests[j + 1])
            {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    // to find the position of disk head in the sorted array
    int pos;
    for (int i = 0; i < no_request + 2; i++)
    {
        if (requests[i] == initialhead)
        {
            pos = i;
            break;
        }
    }

    // to input the direction of head movement
    int direction;
    printf("Enter the direction of head movement:(0-right/1-left):");
    scanf("%d", &direction);

    printf("%d->", initialhead);

    int totalseektime = 0;
    int currenthead = initialhead;
    if (direction == 0)
    { // right
        for (int i = pos + 1; i < no_request + 2; i++)
        { // moving in right direction
            printf("%d->", requests[i]);
            totalseektime += abs(requests[i] - currenthead);
            currenthead = requests[i];
        }

        for (int i = pos - 1; i >= 0; i--)
        { // moving in the opposite direction
            if (i == 0)
                printf("%d\n", requests[i]);
            else
                printf("%d->", requests[i]);
            totalseektime += abs(requests[i] - currenthead);
            currenthead = requests[i];
        }
    }
    if (direction == 1)
    { // left
        for (int i = pos - 1; i >= 0; i--)
        { // moving in left direction
            printf("%d->", requests[i]);
            totalseektime += abs(requests[i] - currenthead);
            currenthead = requests[i];
        }

        for (int i = pos + 1; i < no_request + 2; i++)
        { // moving in the opposite direction
            if (i == no_request + 1)
                printf("%d\n", requests[i]);
            else
                printf("%d->", requests[i]);
            totalseektime += abs(requests[i] - currenthead);
            currenthead = requests[i];
        }
    }
    printf("Total Seek Time:%d", totalseektime);
}