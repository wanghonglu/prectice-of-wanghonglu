#include<cstdio>
#include<sys/socket.h>
#include<cerrno>
#include<cstring>
#include<cstdarg>
#include<ctype.h>
class HTTP
{
	public:
		int creat_sockfd();
		int bind_sockfd();
		int connect();

	private:
		int   sockfd;
}
int main( int argc, char **argv )
{
	return 0;
}
