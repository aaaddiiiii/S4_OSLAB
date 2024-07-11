// LOOK DISK SCHEDULING -it only goes as far as the last request in each direction before reversing direction, rather than going all the way to the end of the disk.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void main()
{
    // inputting no of request n requests
    int no_request;
    printf("Enter the number of requests");
    scanf("%d", &no_request);
    int requests[no_request + 1];
    printf("Enter the requests:");
    for (int i = 0; i < no_request; i++)
    {
        scanf("%d", &requests[i]);
    }

    // inputting initial head position
    int initialhead;
    printf("Enter the initial head position:");
    scanf("%d", &initialhead);
    requests[no_request] = initialhead; // inserting the initial head position into the array
    printf("%d->", initialhead);

    // sorting the array
    for (int i = 0; i < no_request; i++)
    {
        for (int j = 0; j < no_request - i; j++)
        {
            if (requests[j] > requests[j + 1])
            {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    // find the position of initial head in the sorted array
    int pos;
    for (int i = 0; i < no_request + 1; i++)
    {
        if (requests[i] == initialhead)
        {
            pos = i;
            break;
        }
    }

    // inputting direction of head movement
    int direction;
    printf("Enter the direction(0-right/1-left):");
    scanf("%d", &direction);

    int currenthead = initialhead;
    int totalseektime = 0;
    if (direction == 0)
    { // right
        for (int i = pos + 1; i < no_request + 1; i++)
        { // satisfying requests in right direction
            printf("%d->", requests[i]);
            totalseektime += abs(requests[i] - currenthead);
            currenthead = requests[i];
        }
        for (int i = pos - 1; i >= 0; i--)
        { // satisfying requests while going back
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
        { // satisfying requests in left direction
            printf("%d->", requests[i]);
            totalseektime += abs(requests[i] - currenthead);
            currenthead = requests[i];
        }
        for (int i = pos + 1; i < no_request + 1; i++)
        { // satisfying requests while going back
            if (i == no_request)
                printf("%d\n", requests[i]);
            else
                printf("%d->", requests[i]);
            totalseektime += abs(requests[i] - currenthead);
            currenthead = requests[i];
        }
    }
    printf("Total Seek Time:%d", totalseektime);
}