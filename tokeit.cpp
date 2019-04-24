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
#include <sys/types.h>
using namespace std;

int main()
{
	//char line[512];
	string command;
	getline(cin, command);
	char* strArray[11];
	char *token;
	token = strtok(&command[0], " ");
	int num = 0;
	while (token != NULL)
	{
		//cout << token << endl;
		strArray[num++] = token;
		token = strtok(NULL, " ");
	}
	for(int i =0; i < 10; i++)
	{
		if(i >= num)
		{
			strArray[i] = NULL;
		}
	}
	int forkVal = fork();
	int status;
	if(forkVal != 0)
	{
		cout << "done parsing" << endl;
		cout << "num args: " << num << endl;
		for(int i =0; i < num; i++)
		{
			cout << strArray[i] << endl;
		}
		wait(&status);
	}
	else
	{
		execvp(strArray[0], strArray);
		perror("error exec\'ing");
		return 1;

	}
	return 0;
}
