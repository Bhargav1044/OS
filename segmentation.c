#include <stdio.h>
#define MAX_PARTITIONS 10
int main()
{
    int n;
    printf("Enter the total number of partitions (maximum %d): ", MAX_PARTITIONS);
    scanf("%d", &n);
    if (n > MAX_PARTITIONS)
    {
        printf("ERROR..(max partition allowed: 10)");
        return 1;
    }
    int total[MAX_PARTITIONS], process[MAX_PARTITIONS], internal[MAX_PARTITIONS];
    int total_internal = 0, os_size;
    printf("Enter the size of os: ");
    scanf("%d", &os_size);
    for (int i = 0; i < n; i++)
    {
        printf("Enter sixe of partition %d : ", i + 1);
        scanf("%d", &total[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter sixe of process %d : ", i + 1);
        scanf("%d", &process[i]);
        internal[i] = total[i] - process[i];
        total_internal += internal[i];
    }
    int total_used_memory = 0;
    for (int i = 0; i < n; i++)
    {
        total_used_memory += process[i];
    }
    int total_ext_fragmentation = 0;
    if (total_internal < total_used_memory)
    {
        total_ext_fragmentation = total_used_memory - total_internal;
    }
    printf("\npartition\tTotal_size\tProcess_size\tInternal Fragmentation\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, total[i], process[i], internal[i]);
    }
    printf("Total Used memory: %d\n", total_used_memory);
    printf("Total Internal Fragmentation: %d", total_internal);
    printf("Total External Fragmentation: %d", total_ext_fragmentation);
    return 0;
}