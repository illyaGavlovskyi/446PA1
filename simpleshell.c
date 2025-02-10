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
void changeDirectories();
int executeCommand(char * const* enteredCommand, const char* infile, const char* outfile);

int main()
{
    char input[MAX];
    char splitWords[MAX][500];

    while(1)
    {
        char cwd[MAX];
        getcwd(cwd,MAX);
        printf("igavlovskyi:%s$",cwd);

        fgets(input, sizeof(input), stdin);
        int numWords = parseInput(input, splitWords, MAX);
        // for(int i = 0; i < sizeof(splitWords[i]); i++)
        // {
        //     printf( "%s%d\n", splitWords[i], i);

    //    }
        if(strcmp(splitWords[0],"cd") == 0)
        {
            changeDirectories();   
        }
        else if(strcmp(splitWords[0],"exit") == 0)
        {
            break;
        }
        else
        {
            if(strcmp(splitWords[], "<") == 0)
            {

            }
            else if(splitWords[], ">") == 0)
            {

            }
            else
            {
                executeCommand();
            }
        }
    }


    return 0;
}

int parseInput(char * input, char splitWords[][500], int maxWords)
{
    char *token;
    token = strtok(input, " ");
    int num = 0;
    while(token != NULL) {
        printf( "%s\n", token); // TEST

        strcpy (splitWords[num], token);
        token = strtok(NULL, " \n");
        num++;
   }
   return num; 
}

void changeDirectories()
{

}

int executeCommand(char * const* enteredCommand, const char* infile, const char* outfile)
{
    
}