#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main() {
    // printf("Hello, Linux!\n");
    
    // Using system calls!
    // write(STDOUT_FILENO, "Hello, Linux!\n", strlen("Hello, Linux!\n"));
    if(mkdir("test_dir", 0755) == -1) {
        fprintf(stderr, "%s", "Directory exists\n");
    } else {
        printf("Directory created\n");
    }

    return 0;
}
