#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int pid, pid2, y, z;
    char *arg[5] = {"gcc", "-o", "hello_linux", "hello_linux.c", 0};
    char *arg2[1] = {0};

    pid = fork();

    if(pid == 0) {
        printf("Child Process\n");
        execv("/usr/bin/gcc", arg);
    }


    y = wait(&z);
    exit(0);
}
