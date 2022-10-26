 #include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<stdlib.h>
void recursive(const char *name, int indent);

int main(int argc,char **argv)
 {

   struct dirent **name;
   int n;

   if (argc == 1)
    {
     n=scandir(".",&name,NULL,alphasort);
      while (n--)
       {
         printf("%s\n",name[n]->d_name);
         free(name[n]);
       }
      free(name);
   }


    
   exit(EXIT_SUCCESS);
   }


