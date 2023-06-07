#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int n,fd;
	char data[100];
	int pipeds[2],returnstatus,pid;
	char writemsgs[200],readmsgs[200];
	if(returnstatus == -1)
	{
		printf("UNABLE TO CREATE PIPE\n");
		return 1;
	}
	pid = fork();
	fd = open("abc.txt",O_RDONLY|O_CREAT,0644);
	n = read(fd,data,1000);
	if(pid == 0)
	{
		read(pipeds[0],readmsgs,sizeof(readmsgs));
		printf("Child process reading from pipe-msg-1 is %s\n",readmsgs);
	}
	else
	{
		printf("Parebt process writing to pipe-msg-1 is %s\n",data);
		write(pipeds[1],data,sizeof(data));
	}
	return 0;
}
