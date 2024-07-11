// CSCAN DISK SCHEDULING
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

    // sorting the requests
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

    printf("%d->", initialhead);

    int totalseektime = 0;
    int currenthead = initialhead;
    for (int i = pos + 1; i < no_request + 2; i++)
    { // for requests in right
        printf("%d->", requests[i]);
        totalseektime += abs(requests[i] - currenthead);
        currenthead = requests[i];
    }

    // moving to the very end
    totalseektime += abs(requests[no_request + 1] - currenthead);
    // moving to the beginning,i.e.,0
    totalseektime += abs(requests[no_request + 1] - 0);
    printf("0->");
    currenthead = 0;

    // for the requests again towards the right
    for (int i = 0; i < pos; i++)
    {
        if (i == pos - 1)
            printf("%d\n", requests[i]);
        else
            printf("%d->", requests[i]);
        totalseektime += abs(requests[i] - currenthead);
        currenthead = requests[i];
    }
    printf("Total Seek Time:%d", totalseektime);
}