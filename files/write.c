#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main() {
    // User Group Other
    // R: 4 W: 2 X: 1
    int file;

    file = open("file.txt", O_RDWR | O_CREAT, 0755);

    if(file < 0) {
        printf("Error creating/opening file\n");
    }

    char *msg = "Hello, Linux! Isn't C awesome?\n";
    int write_size;

    write_size = write(file, msg, strlen(msg));
    
    if(write_size < 0) {
        printf("Error writing to file.\n");
    }

    if(close(file) < 0) {
        printf("Error closing file.\n");
    }

    return 0;
}
