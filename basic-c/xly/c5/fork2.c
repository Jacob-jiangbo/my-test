#include <stdio.h>
#include <unistd.h>
int main()
{
	if ( fork()>0&&fork()>0&&fork()>0 )
		printf( "hello\n" );
	printf( "world\n" );
	return 0;
}
