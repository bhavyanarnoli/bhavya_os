// done

#include <time.h>
#include<string.h>
#include<stdio.h>
void main(int argc, char *c[]){
	time_t Time;
	struct tm *tm;
	time(&Time);
	tm=localtime(&Time);
	char buffer[100];

	if(argc==1){

		time_t Time;
		struct tm *tm;
		time(&Time);
		tm=localtime(&Time);
		char buffer[100];
		strftime(buffer,100,"%a %b %d %X %Z %Y ", tm);
		printf("%s\n", buffer);
	}

	if(strcmp(c[1],"-I")==0){
		strftime(buffer,100,"%Y-%m-%d ", tm);
		printf("%s\n", buffer);
	}
	else if (strcmp(c[1],"-R")==0){
		strftime(buffer,100,"%a, %d %b %Y %X %Z ", tm);
		printf("%s +0530\n", buffer);
	}

}

