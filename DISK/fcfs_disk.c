// FCFS DISK SCHEDULING

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void main()
{
    // input no of request
    int no_requests;
    printf("Enter the number of requests:");
    scanf("%d", &no_requests);
    // input requests
    int request[no_requests];
    printf("Enter the requests:");
    for (int i = 0; i < no_requests; i++)
    {
        scanf("%d", &request[i]);
    }
    // input initial head position
    int initialhead;
    printf("Enter the initial head position:");
    scanf("%d", &initialhead);
    printf("%d->", initialhead);

    //------------------inputting over-----------------------------------------

    int currenthead = initialhead;
    int totalseektime = 0;

    for (int i = 0; i < no_requests; i++)
    {
        if (i == no_requests - 1) // for last request
            printf("%d\n", request[i]);
        else // for rest of requests
            printf("%d->", request[i]);

        totalseektime += abs(request[i] - currenthead);
        currenthead = request[i];
    }
    printf("Seek time:%d", totalseektime);
}