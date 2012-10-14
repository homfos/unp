#include "unp.h"
#include <time.h>

#define MAX 100

int main(int argc, char **argv)
{
	int listenfd, connfd;
	socklen_t len;
	struct sockaddr_in servaddr, cliaddr;
	char	buff[MAX];
	pid_t	pid;

	listenfd = socket(AF_INET, SOCK_STREAM, 0 );
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(13);
	
	if (bind(listenfd, (struct servaddr *)&servaddr, sizeof(servaddr)) == -1)
	{
		perror("bind error");
		exit(-1);
	}

	if (listen(listenfd, 5) == -1)
	{
		perror("listen");
		exit(-1);
	}

	for ( ; ; )
	{
		len = sizeof(cliaddr);
		if ((connfd  = accept(listenfd, (struct servaddr *)&cliaddr, &len)) == -1)
		{
			perror("accept");
			exit(-1);
		}

		printf("connection from %s, port %d\n", inet_ntop(AF_INET, &cliaddr.sin_addr, buff, sizeof(buff)),
				ntohs(cliaddr.sin_port));
		
		if ((pid = fork()) < 0)
		{
			perror("fork error");
			exit(-1);
		}
		else if (pid == 0)
		{
			if (close(listenfd) == -1)
			{
				perror("close listenfd error");
				exit(-1);
			}
			str_echo(connfd);
			exit(0);
		}

		if (close(connfd) == -1)
		{
			perror("close socket");
			exit(-1);
		}
	}
}
