#include <stdio.h>
#include <stdlib.h>

#define N 5
int buffer[N];
int in = 0;
int out = 0;

void printbuffer()
{
    printf("BUFFER:");
    for (int i = out; i != in; i = (i + 1) % N)
    {
        printf("%d ", buffer[i]);
    }
    printf("\n");
}

void produce(int value)
{
    if ((in + 1) % N == out)
    {
        printf("Buffer is full!");
    }
    else
    {
        buffer[in] = value;
        in = (in + 1) % N;
        printbuffer();
    }
}

int consume()
{
    if (in == out)
    {
        printf("Buffer is empty!");
        return -1;
    }
    else
    {
        int value = buffer[out];
        out = (out + 1) % N;
        printf("Value consumed:%d", value);
        return value;
    }
}

void main()
{
    int ch, value;
    while (1)
    {
        printf("MENU:\n1.PRODUCE\n2.CONSUME\n3.DISPLAY\n4.EXIT\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value you wish to produce:");
            scanf("%d", &value);
            produce(value);
            break;
        case 2:
            consume();
            printbuffer();
            break;
        case 3:
            printbuffer();
            break;
        case 4:
            exit(0);
        }
        printf("");
    }
}
