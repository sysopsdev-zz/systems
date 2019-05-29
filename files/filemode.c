#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int file;

    file = open("new.txt", O_RDWR | O_CREAT, 0755);

    if(file < 0) {
        printf("Error!\n");
        exit(1);
    }

    int x;

    x = close(file);

    if(x < 0) {
        printf("Error!\n");
        exit(1);
    }

    int y;

    y = remove("nw.txt");

    if(y < 0) {
        printf("Error!\n");
        exit(1);
    }

    return 0;
}
