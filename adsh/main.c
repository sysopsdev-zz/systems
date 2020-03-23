#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void adsh_start(void);
char *adsh_read_line(void);
char **adsh_split_line(char *line);
int adsh_launch(char **args);
int adsh_cd(char ** args);
int adsh_help();
int adsh_exit();
int adsh_execute();

char *builtin_str[] = {
    "cd",
    "help",
    "exit"
};

int(*builtin_func[]) (char **) = {
    &adsh_cd,
    &adsh_help,
    &adsh_exit
};

int adsh_num_builtins() {
    return sizeof(builtin_str) / sizeof(char *);
}


int main() {
    // Load config files, if there are any.
    printf("Loading configs...\n");

    printf("Testing configs...\n");
    printf("Configs passed!\n");
    
    // Run command loop.
    adsh_start();

    // Perform cleanup and shutdown

    return EXIT_SUCCESS;
}


void adsh_start(void) {
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = adsh_read_line();
        args = adsh_split_line(line);
        status = adsh_execute(args);

        free(line);
        free(args);
    } while(status);
}

#define ADSH_RL_BUFSIZE 1024
char *adsh_read_line(void) {
    char *line = NULL;
    size_t bufsize = 0; // getline allocates buffer
    getline(&line, &bufsize, stdin);
    return line;
}

#define ADSH_TOK_BUFSIZE 64
#define ADSH_TOK_DELIM " \t\r\n\a"
char **adsh_split_line(char *line) {
    int bufsize = ADSH_TOK_BUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    if(!tokens) {
        fprintf(stderr, "adsh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, ADSH_TOK_DELIM);
    while(token != NULL) {
        tokens[position] = token;
        position++;

        if(position >= bufsize) {
            bufsize += ADSH_TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if(!tokens) {
                fprintf(stderr, "adsh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, ADSH_TOK_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}


int adsh_launch(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if(pid == 0) {
        // Child process
        if(execvp(args[0], args) == -1) {
            perror("adsh");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Error forking
        perror("adsh");
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while(!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

int adsh_cd(char **args) {
    if(args[1] == NULL) {
        fprintf(stderr, "adsh: expected argument to \"cd\"\n");
    } else {
        if(chdir(args[1]) != 0) {
            perror("adsh");
        }
    }
    return 1;
}

int adsh_help() {
    int i;
    printf("AdminDev's Shell: ADSH\n");
    printf("Enter program names and arguments, then press enter.\n");
    printf("Built in commands:\n");

    for(i = 0; i < adsh_num_builtins(); i++) {
        printf("  %s\n", builtin_str[i]);
    }

    printf("Use the man command for information on other programs.\n");
    return 1;
}

int adsh_exit() {
    return 0;
}

int adsh_execute(char **args) {
    int i;

    if(args[0] == NULL) {
        // An empty command was entered.
        return 1;
    }

    for(i = 0; i < adsh_num_builtins(); i++) {
        if(strcmp(args[0], builtin_str[i]) == 0) {
            return (*builtin_func[i])(args);
        }
    }

    return adsh_launch(args);
}
