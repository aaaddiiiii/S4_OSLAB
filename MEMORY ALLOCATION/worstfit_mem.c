#include <stdio.h>
#include <stdlib.h>
void main()
{

    // inputting process
    int no_processes;
    printf("Enter the number of processes:");
    scanf("%d", &no_processes);
    int process[no_processes], allocated[no_processes];
    printf("Enter the size of each process:\n");
    for (int i = 0; i < no_processes; i++)
    {
        printf("Enter the size of process %d:", i + 1);
        scanf("%d", &process[i]);
        allocated[i] = -1;
    }

    // inputting blocks
    int no_blocks;
    printf("Enter the number of blocks:");
    scanf("%d", &no_blocks);
    int block[no_blocks];
    printf("Enter the size of each process:\n");
    for (int i = 0; i < no_blocks; i++)
    {
        printf("Enter the size of block %d:", i + 1);
        scanf("%d", &block[i]);
    }

    for (int i = 0; i < no_processes; i++)
    {
        int worst = -1;
        for (int j = 0; j < no_blocks; j++)
        {
            if (block[j] >= process[j] && allocated[i] == -1)
            {
                if (worst == -1 || block[j] >= block[worst])
                {
                    worst = j;
                }
            }
        }
        if (worst != -1)
        {
            allocated[i] = worst;
            block[worst] = block[worst] - process[i];
        }
    }

    printf("0 indicated not allocated!\n");
    printf("PROCESS NO.\tPROCESS SIZE\tBLOCK NO.\n");
    for (int i = 0; i < no_processes; i++)
    {
        printf("%d\t\t%d\t\t%d\n", i + 1, process[i], allocated[i] + 1);
    }
}