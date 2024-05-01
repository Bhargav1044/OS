#include <stdio.h>
#include <math.h>

int wait[10], tat[10];

struct process
{
    int id;
    int priority;
    int bt;
};

void priority(struct process p[], int n)
{
    int i, j, pos, temp;
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (p[pos].priority > p[j].priority)
            {
                pos = j;
            }
        }
        if (i != pos)
        {
            temp = p[i].id;
            p[i].id = p[pos].id;
            p[pos].id = temp;

            temp = p[i].priority;
            p[i].priority = p[pos].priority;
            p[pos].priority = temp;

            temp = p[i].bt;
            p[i].bt = p[pos].bt;
            p[pos].bt = temp;
        }
    }
}

void wt(struct process p[], int n)
{
    int total_wt = 0, i;
    wait[0] = 0;
    for (i = 1; i < n; i++)
    {
        wait[i] = wait[i - 1] + p[i - 1].bt;
        total_wt += wait[i];
    }
    printf("\nTotal wt:\t%d", total_wt);
    printf("\nAvg wt:\t%f", (float)total_wt / n);
}
void TAT(struct process p[], int n)
{
    int total_tat = 0, i;
    tat[0] = 0;
    for (i = 0; i < n; i++)
    {
        tat[i] = p[i].bt + wait[i];
        total_tat += tat[i];
    }
    printf("\nTotal wt:\t%d", total_tat);
    printf("\nAvg wt:\t%f", (float)total_tat / n);
}

int main()
{
    int n, i;
    struct process p[10];
    printf("\nEnter no of process:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter process id for process %d:\t", i + 1);
        scanf("%d", &p[i].id);
        printf("Enter process priority for process %d:\t", i + 1);
        scanf("%d", &p[i].priority);
        printf("Enter process Brust time for process %d:\t", i + 1);
        scanf("%d", &p[i].bt);
    }
    priority(p, n);
    wt(p, n);
    TAT(p, n);
    printf("\nprocess ID\tpriority\tbrust time\twait time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].priority, p[i].bt, wait[i]);
    }
    return 0;
}
