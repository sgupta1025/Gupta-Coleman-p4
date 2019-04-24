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
	if(fork() ==0)
	{
		cout << "in child" << endl;
		execlp(command.c_str(), command.c_str(), (char *) NULL);
	}
	else
	{
		int status;
		int childID = wait(&status);
		cout << "Waiting on child: " << childID << endl;
		if(WIFEXITED(status) == true)
		{
			cout << "termination by exit" << endl;
			cout << "exit code:" <<WEXITSTATUS(status) << endl;


		}
	if(WIFSIGNALED(status) == true)
		{
			cout << "termination by signal" << endl;
			cout << "signal: " << WTERMSIG(status) << "--" << strsignal(status) << endl;
		}
	}
	return 0;
}
