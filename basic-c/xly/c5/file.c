#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd = open("file", O_WRONLY|O_CREAT|O_APPEND, 0600);
	if(fd<0)
	{
		printf("�޷����ļ�file\n");
		return 1;
	}
	write(fd, "ABCDEFG", 7);
	if(fork()==0)
	{
//		close(fd);
		sleep(5);
		write(fd, "abcdefg", 7);
		printf("�ӽ���д���\n");
	}
	else{
		lseek(fd, 4, SEEK_SET);
		write(fd, "12345678", 8);
		printf("������д���\n");
	}
	close(fd);
	return 0;
}
