#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main() {

    int fd, fd2, num_of_reads;
    char buffer[100];

    fd = open("random_text.txt", O_RDWR | O_CREAT, 0777);
    fd2 = open("modified_text.txt", O_RDWR | O_CREAT, 0777);

    if((fd | fd2) < 0) {
        printf("Error reading from file.\n");
    }

    // While loop to read from random_text.txt and write to modified_text.txt
    
    int read_count = read(fd, buffer, 100);

    while(read_count > 0) {
        // Logic for writing to modified_text.txt
        if(num_of_reads % 2 == 0) {
            write(fd2, "Even Read!\n", 10);
        } else {
            write(fd2, buffer, 100);
            write(fd2, "\n", 1);
        }

        read_count = read(fd, buffer, 100);
        num_of_reads++;
    }

    if((close(fd) | close(fd2)) < 0) {
        printf("Error closing file.\n");
        exit(1);
    }

    return 0;
}
