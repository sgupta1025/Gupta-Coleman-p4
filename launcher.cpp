#include <iostream>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstring>
using namespace std;

int main()
{
	string command;
	cin >> command;
	int forkVal = fork();
	if(forkVal == -1)
	{
		perror("error fork");
		return 1;
	}
	if(forkVal !=0)
	{

		int status;
		cout << "Waiting on child: " << forkVal << endl;
		wait(&status);
		if(WIFEXITED(status) == true)
		{
			cout << "termination by exit" << endl;
			cout << "exit code:" <<WEXITSTATUS(status) << endl;


		}
		if(WIFSIGNALED(status) == true)
		{
			cout << "termination by signal" << endl;
			cout << "signal: " << WTERMSIG(status) << " -- " << strsignal(WTERMSIG(status)) << endl;
		}
	}
	else
	{
		execlp(command.c_str(), command.c_str(), (char *) NULL);
	}
	return 0;
}
