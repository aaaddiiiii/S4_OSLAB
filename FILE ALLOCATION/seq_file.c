// SEQUENTIAL FILE ALLOCATION
#include <stdio.h>

void main()
{
    int nof, block_no, length, alloc = 0, allocated_blocks[50], allocated[30][3];
    printf("Enter the number of files:");
    scanf("%d", &nof);

    // initialising files as not allocated
    for (int i = 0; i < 50; i++)
        allocated_blocks[i] = 0;

    for (int i = 0; i < nof; i++)
    {
        int flag = 0; // for counting no of free blocks
        printf("Enter the block number and length of the file%d:", i + 1);
        scanf("%d %d", &block_no, &length);
        for (int j = block_no; j < (block_no + length); j++)
        {
            if (allocated_blocks[j] == 0)
            {
                flag++;
            }
        }
        if (flag == length)
        { // i.e, if we have the required free blocks
            for (int k = block_no; k < (block_no + length); k++)
            {
                if (allocated_blocks[k] == 0)
                {
                    allocated_blocks[k] = 1;
                }
            }
            printf("File %d is allocated to the disk.\n", i + 1);
            allocated[alloc][0] = i + 1;
            allocated[alloc][1] = block_no;
            allocated[alloc][2] = length;
            alloc++;
        }
        else
            printf("File %d is not allocated to the disk.\n", i + 1);
    }
    printf("\nFile\tBlock\tLength\n");
    for (int i = 0; i < alloc; i++)
        printf("%d\t%d\t%d\n", allocated[i][0], allocated[i][1], allocated[i][2]);

    // to search for a file
    int search_file, flag = 0;
    printf("\nEnter the file number to be searched: ");
    scanf("%d", &search_file);
    for (int i = 0; i < alloc; i++)
    {
        if (allocated[i][0] == search_file)
        {
            printf("File %d occupies %d space.", i + 1, allocated[i][2]);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("File %d not found!", search_file);
    }
}