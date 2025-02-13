//Illya Gavlovskyi
//CS 446
//PA1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

#define MAX 100

int parseInput(char * input, char splitWords[][500], int maxWords);
void changeDirectories(const char *path);
int executeCommand(char * const* enteredCommand, const char* infile, const char* outfile);

int main()
{
    while(1)
    {
        char input[MAX];
        char splitWords[MAX][500];

        char cwd[MAX];
        getcwd(cwd,MAX);
        printf("igavlovskyi: %s$",cwd);

        fgets(input, sizeof(input), stdin);
        int numWords = parseInput(input, splitWords, MAX);
        if(strcmp(splitWords[0],"cd") == 0)
        {
            changeDirectories(splitWords[1]);   
        }
        else if(strcmp(splitWords[0],"exit") == 0)
        {
            return 0;
            break;
        }
        else
        {   
            char *infile = NULL;
            char *outfile = NULL;
            
            int tempCount = 0;
            char *temp[numWords + 1];

            for(int i = 0; i < numWords; i++)
            {
                if(strcmp(splitWords[i], "<") == 0)
                {
                    infile = splitWords[i + 1];
                }
                else if(strcmp(splitWords[i], ">") == 0)
                {
                    outfile = splitWords[i + 1];
                }
                else
                {
                    temp[tempCount] = splitWords[i];
                    tempCount++;
                }
                temp[tempCount] = NULL;
                executeCommand(temp, infile, outfile);
            }
        }
    }
    return 0;
}

int parseInput(char * input, char splitWords[][500], int maxWords)
{
    char *token;
    token = strtok(input, " \n");
    int num = 0;
    while(token != NULL) {
        // printf( "%s\n", token); // TEST

        strcpy (splitWords[num], token);
        token = strtok(NULL, " \n");
        num++;
   }
   return num; 
}

void changeDirectories(const char *path)
{
    int check = chdir(path);
    if(check == -1)
    {
        printf("chdir Failed: %s\n", strerror(errno));
    }
}

int executeCommand(char * const* enteredCommand, const char* infile, const char* outfile)
{
    pid_t pid = fork();
    if(pid == -1)
    {
        printf("fork Failed: %s\n", strerror(errno));
        return 1;
    }
    else if(pid == 0)
    {
        if(infile != NULL)
        {
            int fd = open(infile, O_RDONLY, 0666);
            dup2(fd, STDIN_FILENO);
            close(fd);
        }
        else if(outfile != NULL)
        {
            int fd = open(outfile, O_WRONLY|O_CREAT|O_TRUNC, 0666);
            dup2(fd, STDOUT_FILENO);
            close(fd);
        }
        
        if(execvp(enteredCommand[0], enteredCommand) == -1)
        {
            printf("execvp Failed: %s\n", strerror(errno));
            _exit(1);
        }

    }
    else
    {
        int status;
        wait(&status);
        if(status != 0)
        {
            printf("Child finished with error status: %d\n", status);
        }
    }
    return 0;
}