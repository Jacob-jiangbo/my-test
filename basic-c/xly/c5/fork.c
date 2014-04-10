#include <stdio.h>
#include <unistd.h>

int main()
{
	int i=0;
	int ret = fork();
	if(ret==0)
	{//子进程满足这个条件
		for(i=0; i<10; i++){
			printf("i=%d, ret=%d, 我的进程id%d,老爸%d\n", 
				i, ret,	getpid(),getppid());
			sleep(1);
		}
	}
	else{//父进程，也就是原来那个进程
		for(i=50; i<55; i++)
		{
			printf("ret=%d,我是父进程%d\n", ret,getpid());
			sleep(1);
		}
	}
	return 0;
}

