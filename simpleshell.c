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

void parseInput();
void changeDirectories();
void executeCommand();

int main(){
    char cwd[MAX];
    //getcwd(cwd,MAX);
    //printf("igavlovskyi:%s$",cwd);

    char input[MAX];
    char splitCommands[MAX][MAX];

    while(true){
        printf("works");
    }


    return 0;
}

void parseInput(){

} 

void changeDirectories(){

}

void executeCommand(){
    
}