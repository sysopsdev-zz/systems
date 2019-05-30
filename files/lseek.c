#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main() {
    
    int fd = open("random_text.txt", O_RDWR | O_CREAT, 0755);

    if(fd < 0) {
        printf("Error reading from file.\n");
    }

    char *write_this = "\nGoodbye, Linux!";
    printf(" %s\n", write_this);

    lseek(fd, 10, SEEK_END);

    write(fd, write_this, strlen(write_this));
    return 0;
}
