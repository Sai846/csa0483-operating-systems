#include<stdio.h>
#include<unistd.h>
int main(){
	pid_t pid=getpid();
	pid_t parent_pid=getpid();
	printf("current position ID:%d\n",pid);
	printf("parent process ID:%d\n",parent_pid);
	return 0;
}
