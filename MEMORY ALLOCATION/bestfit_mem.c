// BEST FIT MEMORY ALLOCATION
#include <stdio.h>
#include <stdlib.h>

void main()
{

    // inputting process
    int no_processes;
    printf("Enter the number of processes:");
    scanf("%d", &no_processes);
    int process[no_processes], allocated[no_processes];
    printf("Enter the size of the processes:\n");
    for (int i = 0; i < no_processes; i++)
    {
        printf("Enter size of process %d:", i + 1);
        scanf("%d", &process[i]);
        allocated[i] = -1;
    }

    // inputting block
    int no_blocks;
    printf("Enter the number of blocks:");
    scanf("%d", &no_blocks);
    int block[no_blocks];
    printf("Enter the size of the blocks:\n");
    for (int i = 0; i < no_blocks; i++)
    {
        printf("Enter size of block %d:", i + 1);
        scanf("%d", &block[i]);
    }

    for (int i = 0; i < no_processes; i++)
    {
        int best = -1;
        for (int j = 0; j < no_blocks; j++)
        {
            if (block[j] > process[i])
            {
                if (best == -1 || block[j] <= block[best])
                {
                    best = j;
                }
            }
        }
        if (best != -1)
        {
            allocated[i] = best;
            block[best] = block[best] - process[i];
        }
    }

    printf("\n");
    printf("0 indicates not allocated!\n");
    printf("PROCESS NO\tPROCESS SIZE\tBLOCK NO\n");
    for (int i = 0; i < no_processes; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, process[i]);
        printf("%d\n", allocated[i] + 1);
    }
}