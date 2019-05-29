#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <resolv.h>
#include <unistd.h>

#define PORT_TIME	13
#define PORT_FTP	21
#define SERVER_ADDR	"127.0.0.1"
#define MAXBUF		1024

int main()
{
	int sockfd;
	struct sockaddr_in dest;
	char buffer[MAXBUF];

	if ( (sockfd = socket(AF_INET, SOCK_STREAM,0) ) < 0 )
	{
		perror("Socket");
		exit(errno);
	}

	bzero(&dest, sizeof(dest));
	dest.sin_family = AF_INET;
	dest.sin_port = htons(PORT_FTP);
	if ( inet_aton(SERVER_ADDR, &dest.sin_addr.s_addr) == 0 )
	{
		perror(SERVER_ADDR);
		exit(errno);
	}

	if ( connect(sockfd, (struct sockaddr*)&dest, sizeof(dest)) != 0 )
	{
		perror("Connect ");
		exit(errno);
	}

	bzero(buffer, MAXBUF);
	recv(sockfd, buffer, sizeof(buffer), 0);
	printf("%s", buffer);

	close(sockfd);
	return 0;
}










