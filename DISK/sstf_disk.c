// SSTF DISK SCHEDULING
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    // inputting requests
    int no_request;
    printf("Enter the number of requests:");
    scanf("%d", &no_request);
    int requests[no_request];
    bool completed[no_request];
    printf("Enter the requests:");
    for (int i = 0; i < no_request; i++)
    {
        scanf("%d", &requests[i]);
        completed[i] = false;
    }

    // inputting head position
    int initialhead;
    printf("Enter the initial head position:");
    scanf("%d", &initialhead);
    printf("%d->", initialhead);

    int currenthead = initialhead;
    int totalseektime = 0;
    int totalcompleted = 0;

    while (totalcompleted < no_request)
    {
        int shortestdistance = 1e9; // initialising shortest distance to 10^9, a large value
        int nextrequestindex = -1;
        for (int i = 0; i < no_request; i++)
        {
            if (!completed[i])
            {
                int distance = abs(requests[i] - currenthead);
                if (distance < shortestdistance)
                {
                    shortestdistance = distance;
                    nextrequestindex = i;
                }
            }
        }
        if (nextrequestindex != -1)
        { // if a valid request having shortest seek time is found
            completed[nextrequestindex] = true;
            totalseektime += abs(requests[nextrequestindex] - currenthead);
            currenthead = requests[nextrequestindex];
            totalcompleted++;
        }
        if (totalcompleted == no_request)
        {
            printf("%d\n", requests[nextrequestindex]);
        }
        else
        {
            printf("%d->", requests[nextrequestindex]);
        }
    }
    printf("Seek Time:%d\n", totalseektime);
}