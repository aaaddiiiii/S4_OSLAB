// INDEXED FILE ALLOCATION

#include <stdio.h>

void main()
{
    int nof, alloc = 0, index_block_no, nob, length, allocated_blocks[50], allocated[50][3], indexblocks[30];

    // indexblocks[] contains the blocks in which a file is allocated
    // allocated[50][3] has columns fileno, index block no, length

    printf("Enter the number of files:");
    scanf("%d", &nof);
    for (int i = 0; i < 50; i++)
    {
        allocated_blocks[i] = 0;
    }
    for (int i = 0; i < nof; i++)
    {
        printf("Enter the index block:");
        scanf("%d", &index_block_no);
        if (allocated_blocks[index_block_no] == 0)
        {
            printf("Enter the total no of blocks in which file is allocated:");
            scanf("%d", &nob);
        }
        else
        {
            printf("Index block %d is already allocated!\n", index_block_no);
            continue;
        }
        printf("Enter the blocks occupied by the file:");
        for (int j = 0; j < nob; j++)
        {
            scanf("%d", &indexblocks[j]);
            if (allocated_blocks[indexblocks[j]] == 0)
            {
                length++;
            }
        }
        if (length == nob)
        {
            for (int j = 0; j < nob; j++)
            {
                allocated_blocks[indexblocks[j]] = 1;
            }
            printf("Allocated!\n");
            allocated[alloc][0] = i + 1;
            allocated[alloc][1] = index_block_no;
            allocated[alloc][2] = length;
            alloc++;
        }
        else
            printf("Index is already allocated!");
    }
    printf("\nFile\tIndex\tLength\n");
    for (int i = 0; i < alloc; i++)
        printf("%d\t%d\t%d\n", allocated[i][0], allocated[i][1], allocated[i][2]);
}