#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main() {

    int fd; 
    char buffer[100];


    fd = open("random_text.txt", O_RDONLY, 0777);

    if(fd < 0) {
        printf("Error\n");
        exit(1);
    }
    
    int read_count;
    read_count = read(fd, buffer, 100);

    if(read_count < 0) {
        printf("Error!\n");
        exit(1);
    } else {
        printf("%.*s\n", read_count, buffer);
    }
    return 0;
}
