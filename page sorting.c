#include <stdio.h>
int findPageFaults(int pages[], int n, int numFrames)
{
    int frames[numFrames];
    int faults = 0, frameIndex = 0, i, j;
    for (i = 0; i < numFrames; i++)
    {
        frames[i] = -1;
    }
    for (i = 0; i < n; i++)
    {
        int pageFound = 0;
        for (j = 0; j < numFrames; j++)
        {
            if (frames[j] == pages[i])
            {
                pageFound = 1;
                break;
            }
        }
        if (!pageFound)
        {
            faults++;
            frames[frameIndex] = pages[i];
            frameIndex = (frameIndex + 1) % numFrames;
        }
        printf("Page %d -> Frames: ", pages[i]);
        for (j = 0; j < numFrames; j++)
        {
            printf("%d", frames[j]);
        }
        printf("\n");
    }
    return faults;
}

int main()
{
    int n, numFrames;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter the pages: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }
    printf("Enter the number of frames : ");
    scanf("%d", &numFrames);
    int faults = findPageFaults(pages, n, numFrames);
    printf("Total Page Faults: %d\n", faults);
    int hit = n - faults;
    printf("Total Page Hits: %d\n", hit);
    return 0;
}