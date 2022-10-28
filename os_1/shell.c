#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <libgen.h> 
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include <dirent.h>

#define MAXCOM 1000 
#define MAXLIST 100 

#define clear() printf("\033[H\033[J")

void init_shell()
{
	clear();
	printf("\n\n\n\n*******");
	printf("\n\n\n\t BHAVYA SHELL");
	printf("\n\n\tuse at own risk");
	printf("\n\n\n\n*******");
	char* username = getenv("user");
	printf("\n\n\n user is: @%s", username);
	printf("\n");
	sleep(1);
	clear();
}

int takeInput(char* str)
{	char* buf;

	buf = readline("\n>>> ");
	if (strlen(buf) != 0) {
		add_history(buf);
		strcpy(str, buf);
		return 0;
	} 
	else {
		return 1;
	}
}

void printDir()
{
	char cwd[1024];
	getcwd(cwd, sizeof(cwd));
	printf("\nDir: %s", cwd);
}

void execArgs(char** parsed){
	pid_t pid = fork();

	if (pid == -1) {
		printf("\nFailed forking child..");
		return;
	} 
	else if (pid == 0) {
        if (!strcmp(parsed[0],"date")){
           	execl("./date",parsed[0],parsed[1],NULL);}
			
		else if(!strcmp(parsed[0],"ls")){
			execl("./ls",parsed[0],parsed[1],NULL);}
		
		else if(!strcmp(parsed[0],"cat")){
			execl("./cat",parsed[0],parsed[1],parsed[2],NULL);}

		
		else if(!strcmp(parsed[0],"rm")){
			
			execl("./rm",parsed[0],parsed[1],parsed[2],NULL);}
			
	
		else if(!strcmp(parsed[0],"mkdir")){
			execl("./mkdir", parsed[0],parsed[1],parsed[2],parsed[3], NULL);
			
		}
        else{
            printf("Command not recognized!!");
			exit(0);
        }}
	 
	else {
		wait(NULL);
		return;}
}

int ownCmdHandler(char** parsed)
{
	int NoOfOwnCmds = 4, i, switchOwnArg = 0;
	char* ListOfOwnCmds[NoOfOwnCmds];
	char* username;

	ListOfOwnCmds[0] = "exit";
	ListOfOwnCmds[1] = "cd";
	ListOfOwnCmds[2] = "echo";
	ListOfOwnCmds[3] = "pwd";

	for (i = 0; i < NoOfOwnCmds; i++) {
		if (strcmp(parsed[0], ListOfOwnCmds[i]) == 0) {
			switchOwnArg = i + 1;
			break;
		}
	}

	switch (switchOwnArg) {
	case 1:
		printf("\nGoodbye\n");
		exit(0);
	case 2:
		if(parsed[1]==NULL){
		chdir(parsed[1]);}
		else{
			int check=chdir(parsed[1]);
			char buff[1000];
			char*present_dir=getcwd(buff,sizeof(buff));
			if(check==-1){
				printf("Invalid path\n");
			}
		}

	case 3:
		while (*++parsed) {
        	printf("%s", parsed[0]);
        	if (parsed[1]) printf(" ");
    }
    	printf("\n");
		return 1;
	case 4: 
		execl("/bin/pwd", "pwd", NULL);
		return 1;
	default:
        execArgs(parsed);
		break;
	}
	return 0;
}

void parseSpace(char* str, char** parsed)
{
	int i;

	for (i = 0; i < MAXLIST; i++) {
		parsed[i] = strsep(&str, " ");
		if (parsed[i] == NULL)
			break;
		if (strlen(parsed[i]) == 0)
			i--;
	}
}

void processString(char* str, char** parsed, char** parsedpipe)
{
	char* strpiped[2];
	parseSpace(str, parsed);
	ownCmdHandler(parsed);
}

int main()
{
	char inputString[MAXCOM], *parsedArgs[MAXLIST];
	char* parsedArgsPiped[MAXLIST];
	int execFlag = 0;
	init_shell();

	while (1) {
		printDir();
		if (takeInput(inputString))
			continue;

        processString(inputString,parsedArgs, parsedArgsPiped);
	}
	return 0;
}
