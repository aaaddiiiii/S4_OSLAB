#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

int main()
{
    int i, j, no_of_requests, initial_head, direction;
    printf("Enter the number of requests: ");
    scanf("%d", &no_of_requests);
    int request[no_of_requests + 1]; // +1 for the initial head position

    printf("Enter the requests: ");
    for (i = 0; i < no_of_requests; ++i)
    {
        scanf("%d", &request[i]);
    }

    printf("Enter initial position of R/W head: ");
    scanf("%d", &initial_head);
    request[no_of_requests] = initial_head; // Add initial head position to the requests array

    printf("Enter the direction (0 for left, 1 for right): ");
    scanf("%d", &direction);

    // Sort the requests array
    for (i = 0; i < no_of_requests + 1; ++i)
    {
        for (j = i + 1; j < no_of_requests + 1; ++j)
        {
            if (request[i] > request[j])
            {
                int temp = request[i];
                request[i] = request[j];
                request[j] = temp;
            }
        }
    }

    // Find the position of the initial head in the sorted array
    int pos;
    for (i = 0; i < no_of_requests + 1; ++i)
    {
        if (request[i] == initial_head)
        {
            pos = i;
            break;
        }
    }

    int seek_time = 0;
    int current_head = initial_head;

    printf("%d -> ", initial_head);

    if (direction == 1)
    { // Move right
        // Serve requests to the right of the initial head
        for (i = pos + 1; i < no_of_requests + 1; ++i)
        {
            printf("%d -> ", request[i]);
            seek_time += abs(request[i] - current_head);
            current_head = request[i];
        }
        // Jump to the first request and continue serving
        if (pos != 0)
        {
            seek_time += abs(request[no_of_requests] - current_head);
            seek_time += abs(request[no_of_requests] - request[0]); // Move to the highest request
            current_head = request[0];
            printf("%d -> ", request[0]);
        }
        for (i = 1; i < pos; ++i)
        {
            if (i == pos - 1)
            {
                printf("%d\n", request[i]);
            }
            else
            {
                printf("%d -> ", request[i]);
            }
            seek_time += abs(request[i] - current_head);
            current_head = request[i];
        }
    }
    else
    { // Move left
        // Serve requests to the left of the initial head
        for (i = pos - 1; i >= 0; --i)
        {
            printf("%d -> ", request[i]);
            seek_time += abs(request[i] - current_head);
            current_head = request[i];
        }
        // Jump to the last request and continue serving
        if (pos != no_of_requests)
        {
            seek_time += abs(current_head - request[0]); // Move to the lowest request
            current_head = request[no_of_requests];
            printf("%d -> ", request[no_of_requests]);
        }
        for (i = no_of_requests - 1; i > pos; --i)
        {
            if (i == pos + 1)
            {
                printf("%d\n", request[i]);
            }
            else
            {
                printf("%d -> ", request[i]);
            }
            seek_time += abs(request[i] - current_head);
            current_head = request[i];
        }
    }

    printf("Seek Time: %d\n", seek_time);

    return 0;
}