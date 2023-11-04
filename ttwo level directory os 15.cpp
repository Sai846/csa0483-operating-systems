#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIRECTORIES 100
#define MAX_FILES_PER_DIRECTORY 50
#define MAX_FILENAME_LENGTH 50

struct File {
    char name[MAX_FILENAME_LENGTH];
};

struct Directory {
    char name[MAX_FILENAME_LENGTH];
    struct File files[MAX_FILES_PER_DIRECTORY];
    int fileCount;
};

struct Directory directories[MAX_DIRECTORIES];
int directoryCount = 0;

void createDirectory(const char *dirname) {
    if (directoryCount < MAX_DIRECTORIES) {
        strcpy(directories[directoryCount].name, dirname);
        directories[directoryCount].fileCount = 0;
        directoryCount++;
        printf("Directory '%s' created successfully.\n", dirname);
    } else {
        printf("Cannot create directory '%s'. Too many directories.\n", dirname);
    }
}

void createFile(const char *dirname, const char *filename) {
    int dirIndex = -1;
    for (int i = 0; i < directoryCount; ++i) {
        if (strcmp(directories[i].name, dirname) == 0) {
            dirIndex = i;
            break;
        }
    }

    if (dirIndex != -1) {
        if (directories[dirIndex].fileCount < MAX_FILES_PER_DIRECTORY) {
            strcpy(directories[dirIndex].files[directories[dirIndex].fileCount].name, filename);
            directories[dirIndex].fileCount++;
            printf("File '%s' created successfully in directory '%s'.\n", filename, dirname);
        } else {
            printf("Cannot create file '%s' in directory '%s'. Too many files in the directory.\n", filename, dirname);
        }
    } else {
        printf("Directory '%s' not found.\n", dirname);
    }
}

void deleteFile(const char *dirname, const char *filename) {
    int dirIndex = -1;
    for (int i = 0; i < directoryCount; ++i) {
        if (strcmp(directories[i].name, dirname) == 0) {
            dirIndex = i;
            break;
        }
    }

    if (dirIndex != -1) {
        int found = 0;
        for (int i = 0; i < directories[dirIndex].fileCount; ++i) {
            if (strcmp(directories[dirIndex].files[i].name, filename) == 0) {
                found = 1;
                for (int j = i; j < directories[dirIndex].fileCount - 1; ++j) {
                    strcpy(directories[dirIndex].files[j].name, directories[dirIndex].files[j + 1].name);
                }
                directories[dirIndex].fileCount--;
                printf("File '%s' deleted successfully from directory '%s'.\n", filename, dirname);
                break;
            }
        }
        if (!found) {
            printf("File '%s' not found in directory '%s'.\n", filename, dirname);
        }
    } else {
        printf("Directory '%s' not found.\n", dirname);
    }
}

void listDirectoryContents(const char *dirname) {
    int dirIndex = -1;
    for (int i = 0; i < directoryCount; ++i) {
        if (strcmp(directories[i].name, dirname) == 0) {
            dirIndex = i;
            break;
        }
    }

    if (dirIndex != -1) {
        printf("Files in directory '%s':\n", dirname);
        for (int i = 0; i < directories[dirIndex].fileCount; ++i) {
            printf("%s\n", directories[dirIndex].files[i].name);
        }
    } else {
        printf("Directory '%s' not found.\n", dirname);
    }
}

int main() {
    int choice;
    char dirname[MAX_FILENAME_LENGTH];
    char filename[MAX_FILENAME_LENGTH];

    do {
        printf("\nMenu:\n");
        printf("1. Create Directory\n");
        printf("2. Create File\n");
        printf("3. Delete File\n");
        printf("4. List Directory Contents\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter directory name: ");
                scanf("%s", dirname);
                createDirectory(dirname);
                break;
            case 2:
                printf("Enter directory name: ");
                scanf("%s", dirname);
                printf("Enter filename: ");
                scanf("%s", filename);
                createFile(dirname, filename);
                break;
            case 3:
                printf("Enter directory name: ");
                scanf("%s", dirname);
                printf("Enter filename to delete: ");
                scanf("%s", filename);
                deleteFile(dirname, filename);
                break;
            case 4:
                printf("Enter directory name: ");
                scanf("%s", dirname);
                listDirectoryContents(dirname);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
