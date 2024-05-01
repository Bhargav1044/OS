#include <stdio.h>
#include <stdlib.h>

#include <string.h>
int main()
{
    char dirname[100];
    printf("Enter directory name: ");
    scanf("%s", dirname);
    int num_files;
    printf("Enter number of files to create: ");
    scanf("%d", &num_files);
    char filenames[num_files][100];
    for (int i = 0; i < num_files; i++)
    {
        printf("Enter name for file %d: ", i + 1);
        scanf("%s", filenames[i]);
    }
    char new_filename[100];
    char choice;
    do
    {
        printf("Do you want to create a new file? (y/n): ");
        scanf("%c", &choice);
        if (choice == 'y' || choice == 'Y')
        {
            printf("Enter new file name: ");
            scanf("%s", new_filename);
            int exists = 0;
            for (int i = 0; i < num_files; i++)
            {
                if (strcmp(new_filename, filenames[i]) == 0)
                {
                    exists = 1;
                    break;
                }
            }
            if (exists)
            {
                printf("File already exists.\n");
            }
            else
            {
                printf("File '%s' has been created.\n", new_filename);
            }
        }

    } while (choice == 'y' || choice == 'Y');
    return 0;
}