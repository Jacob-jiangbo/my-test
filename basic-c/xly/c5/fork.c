#include <stdio.h>
#include <unistd.h>

int main()
{
	int i=0;
	int ret = fork();
	if(ret==0)
	{//�ӽ��������������
		for(i=0; i<10; i++){
			printf("i=%d, ret=%d, �ҵĽ���id%d,�ϰ�%d\n", 
				i, ret,	getpid(),getppid());
			sleep(1);
		}
	}
	else{//�����̣�Ҳ����ԭ���Ǹ�����
		for(i=50; i<55; i++)
		{
			printf("ret=%d,���Ǹ�����%d\n", ret,getpid());
			sleep(1);
		}
	}
	return 0;
}
