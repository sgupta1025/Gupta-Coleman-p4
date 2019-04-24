#include<dirent.h>
#include<stdio.h>
#include <stdlib.h>
#include<string.h> 
#include<unistd.h> 
#include<fcntl.h> 
#include <iostream> 
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
using namespace std;



int main(){
     char  line[512];
     char *argv[];
     //get commmand line string
     gets(line);

     //parse through string
     // Returns first token  
     char *token = strtok(line, " "); 
     
     // Keep printing tokens while one of the 
     // delimiters present in str[].
     int num = 0;
     while (token != NULL) 
       { 
	 printf("%s\n", token);
	 argv[num] = token;
	 token = strtok(NULL, " ");
	 num++;
       }

     //start fork
     int forkVal = fork();

     if(forkVal == 0){
       execvp(argv[0], argv);
       perror("execvp error");///shouldn't get here if execvp works
       exit(2);
     }//if
     else if(forkVal < 0){
       perrror("fork");
       exit(2);
     }//else if
     else{
       waitpid(frokVal, NULL)
     }//else
     

     return 0;
}//end
