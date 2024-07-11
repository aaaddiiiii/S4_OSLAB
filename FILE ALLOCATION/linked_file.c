// LINKED FILE ALLOCATION
#include <stdio.h>
#include <stdlib.h>

struct linked
{
    char file_name[50];
    int start_block, block_size;
    int allocated_block_nos[50]; // to store the block no that is allocated to the file
} files[50];

void main()
{
    int nof, st, nob, block_no, alloc = 0, allocated_blocks[50];
    printf("Enter the number of files:");
    scanf("%d", &nof);

    // initialising block as not allocated
    for (int i = 0; i < 50; i++)
    {
        allocated_blocks[i] = 0; // to indicate whether the block is allocated or not
    }

    for (int i = 0; i < nof; i++)
    {
        printf("Enter the file name:");
        scanf("%s", files[alloc].file_name);
        printf("Enter the starting block:");
        scanf("%d", &st);
        allocated_blocks[st] = 1;
        printf("Enter the number of blocks:");
        scanf("%d", &nob);
        printf("Enter the block numbers in which each file is allocated:"); // since this is linked allocation, the file will be stored in scattered blocks.
        for (int j = 0; j < nob; j++)
        {
            scanf("%d", &block_no);
            allocated_blocks[block_no] = 1;
            files[alloc].allocated_block_nos[j] = block_no;
        }
        files[alloc].start_block = st;
        files[alloc].block_size = nob;
        alloc++;
    }
    printf("\nFile\tStart\tSize\tBlock\n");
    for (int i = 0; i < alloc; i++)
    {
        printf("%s\t%d\t%d\t", files[i].file_name, files[i].start_block, files[i].block_size);
        printf("%d ", files[i].allocated_block_nos[0]);
        for (int j = 1; j < files[i].block_size; j++)
            printf("--> %d ", files[i].allocated_block_nos[j]); // to print the allocated block nos of a file
        printf("\n");
    }
}