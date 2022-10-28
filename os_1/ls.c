//done
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>



void main(int argc, char *c[]){

	
	DIR *folders;
	struct dirent *file_names;
	folders = opendir(".");
	

	if(argc==1){
		printf("\n");
		if(folders!= NULL){
			while((file_names= readdir(folders)) != NULL){
				if(!(strcmp(file_names->d_name,".")==0 || strcmp(file_names->d_name,"..")==0))
					printf("%s \t",file_names->d_name );
			}
			printf("\n");
		}
		closedir(folders);
	}

	if(strcmp(c[1],"-m")==0){
		printf("\n");
		if(folders!= NULL){
			while((file_names= readdir(folders)) != NULL){
				if(!(strcmp(file_names->d_name,".")==0 || strcmp(file_names->d_name,"..")==0))
					printf("%s,\t",file_names->d_name );
			}
			printf("\n");
		}
		closedir(folders);
	}
	else if(strcmp(c[1],"-1")==0){
		if(folders!= NULL){
			while((file_names= readdir(folders)) != NULL){
				if(!(strcmp(file_names->d_name,".")==0 || strcmp(file_names->d_name,"..")==0))
					printf("%s\n",file_names->d_name );
			}
		}
		closedir(folders);
	}
	
}

