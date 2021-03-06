#include <stdio.h>
#include "stdlib.h"
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>   
#include <netdb.h>       

int main (int argc,char *argv[])
{
   	int sock, val, cnt;          
   	struct sockaddr_in myname; 
   	struct sockaddr_in *nptr;  
   	char buf[80];   
   	struct hostent *hp;

   	if ( argc < 3 ) 
	{
      		printf("network client failure: required parameters");
      		printf(" missing from the command line\n");
      		printf("network client: usage");
      		printf("[executable-name] [host name] [port number]\n");
      		exit(1);
   	}

   	if (( sock = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) 
	{
      		printf("network client socket failure %d\n", errno);
      		perror("network client");
      		exit(2);
   	}
   	myname.sin_port = htons( atoi(argv[2]) ); /* 服务器端口号 */
   	myname.sin_family = AF_INET; 

   	/* 获取主机信息.  */
   	hp = gethostbyname ( argv[1] );
   	if ( hp == NULL ) 
	{
      		printf("network client gethostbyname failure %d\n", errno);
      		perror("network client");
      		close ( sock );
      		exit(3);
   	}
	bcopy ( hp -> h_addr_list[0], &myname.sin_addr.s_addr, hp -> h_length );//bcopy和memcpy是不同支持版本
   
   	printf("\nInformation provided in client's");
   	printf(" connect request\n");
   	printf("\tRemote host address is %lx\n", ntohl ( myname.sin_addr.s_addr ) );
   	printf("\tPort number supplied is %d\n", ntohs ( myname.sin_port ) );
   	printf("\tInternet family ID is %d\n", myname.sin_family);
   	printf("\tsin_zero character string is: %s\n", myname.sin_zero);
 
   	if ( ( connect ( sock, &myname, sizeof(myname) ) ) < 0 ) 
	{
         	printf("network client %s connect failure %d\n", argv[0], errno);// 显示错误号
         	perror("network client");//显示错误原因
         	close (sock);
         	exit(4);
      	}
 
   	/*  与客户端交 换数据。首先清空缓冲区 */
   	memset  (buf,0,sizeof(buf));  /* 清空缓冲区 */
   	strcpy ( buf, "Message from client to server" );
   	write ( sock, buf, sizeof(buf) );
   	if ( ( cnt = read (sock, buf, sizeof(buf) ) ) < 0 ) 
	{
      		printf("network client socket read failure &d\n", errno);
      		perror("network client");
      		close(sock);
      		exit(5);
   	}
   	else
   	printf("network client received the message %s\n", buf);

   	memset  (buf,0,sizeof(buf));  /* 清空缓冲区 */
   	write ( sock, buf, 0 );
   	close (sock);
   	exit(0);
}  
