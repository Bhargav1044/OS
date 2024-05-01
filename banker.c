#include <stdio.h>

int main() {
    int n, m;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    // Initialize arrays
    int need[n][m], max[n][m], allocate[n][m], available[m], work[m];

    // Input allocation and maximum matrices
    printf("Enter allocation matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &allocate[i][j]);
        }
    }

    printf("Enter max matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Input available resources
    printf("Enter available resources:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &available[i]);
        work[i] = available[i];
    }

    // Calculate need matrix
    printf("Need matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocate[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    // Safety algorithm
    int finish[n];
    for (int i = 0; i < n; i++) {
        finish[i] = 0;
    }

    int count = 0;
    int safeSequence[n];
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j])
                        break;
                }
                if (j == m) {
                    for (int k = 0; k < m; k++) {
                        work[k] += allocate[i][k];
                    }
                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (found == 0) {
            printf("System is not in safe state!\n");
            return -1;
        }
    }

    printf("System is in safe state.\nSafe sequence is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", safeSequence[i]);
    }
    printf("\n");
  return 0;
}