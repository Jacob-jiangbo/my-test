#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
/*
waitpid(�ӽ���pid�������������״̬�ı����ĵ�ַ��0����WNOHANG)
��������ָ��pid�ӽ�����Դ��pidΪ-1��ʾ��ָ���ӽ���pid��
0��ʾ�����ȴ��ӽ��̽����ŷ��أ�����ֵΪ�������ӽ���pid
WNOHANG��ʾ�������ȴ�������ӽ��̽����˾ͷ����ӽ���pid��û���ӽ��̽����ͷ���0��
��������-1��
*/
int main()
{
	int i=0;
	int ret = fork();
	if(ret==0)
	{//�ӽ��������������
		for(i=0; i<5; i++){
			printf("i=%d, ret=%d, �ҵĽ���id%d,�ϰ�%d\n", 
				i, ret,	getpid(),getppid());
			sleep(1);
		}
	}
	else
	{//�����̣�Ҳ����ԭ���Ǹ�����
		for(i=50; i<65; i++)
		{
			printf("ret=%d,���Ǹ�����%d\n", ret,getpid());
			sleep(1);
			printf("*****%d*****\n",waitpid(-1, NULL, WNOHANG));
		}
	}
	return 0;
}
