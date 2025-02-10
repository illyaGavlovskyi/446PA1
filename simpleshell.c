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
void executeCommand();

int main(){
    char input[MAX];
    char splitWords[MAX][500];

    while(1){
        char cwd[MAX];
        getcwd(cwd,MAX);
        printf("igavlovskyi:%s$",cwd);

        fgets(input, sizeof(input), stdin)

        if(){
            
        }
    }


    return 0;
}

int parseInput(char * input, char splitWords[][500], int maxWords);{
    char *token;
    token = strtok(input, " ");
    int num = 0;
    while(num < maxWords) {
        printf( " %s\n", token);
        strcpy (splitWords[num], token);
        token = strtok(NULL, " ");
        num++;
   }
   return num; 
}

void changeDirectories(){

}

void executeCommand(){
    
}