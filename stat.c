#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat fileStat;
    char filename[] = "/home/ilwin/Documents/csapp/CSAPP/test.txt";

    if (stat(filename, &fileStat) == 0) {
        printf("File Permissions: %o\n", fileStat.st_mode);
        printf("Number of Hard Links: %ld\n", fileStat.st_nlink);
        printf("User ID of Owner: %d\n", fileStat.st_uid);
        printf("Group ID of Owner: %d\n", fileStat.st_gid);
        printf("File Size in Bytes: %ld\n", fileStat.st_size);
        printf("Last Access Time: %ld\n", fileStat.st_atime);
        printf("Last Modification Time: %ld\n", fileStat.st_mtime);
        printf("Last Status Change Time: %ld\n", fileStat.st_ctime);
    } else {
        printf("Failed to get file status.\n");
    }

    return 0;
}
