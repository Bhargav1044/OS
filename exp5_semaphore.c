#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFFERSIZE 8
int full = 0;
int empty = 8;
int mutex = 1;
int in = 0;
int out = 0;
int buffer[BUFFERSIZE];

int down(int x)
{
    x = x - 1;
    return x;
}
int up(int x)
{
    x = x + 1;
    return x;
}

int produce()
{
    mutex = down(mutex);
    empty = down(empty);
    printf("Enter item:\t");
    scanf("%d", &buffer[in]);
    in = (in + 1) % BUFFERSIZE;
    full = up(full);
    mutex = up(mutex);
}

int consume()
{
    mutex = down(mutex);
    full = down(full);
    printf("Item at %d is:\t%d", full, buffer[out]);
    out = (out + 1) % BUFFERSIZE;
    empty = up(empty);
    mutex = up(mutex);
}

int main()
{
    int y;
    printf("1.Produce\n2.Consume\n3.Exit");
    while (1)
    {
        printf("\nEnyter your choice:");
        scanf("%d", &y);
        switch (y)
        {
        case 1:
            if (mutex == 1 && empty != 0)
            {
                produce();
                printf("\nfull: %d\nEmpty: %d\nIn: %d\nOut: %d", full, empty, in, out);
            }
            else
            {
                printf("\nBuffer full");
            }
            break;
        case 2:
            if (mutex == 1 && full != 0)
            {
                consume();
                printf("\nfull: %d\nEmpty: %d\nIn: %d\nOut: %d", full, empty, in, out);
            }
            else
            {
                printf("\nBuffer Empty");
            }
            break;
        case 3:
            exit(0);
        default:
            printf("\nEnter correct choice");
            break;
        }
        }
    return 0;
}