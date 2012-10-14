#include "unp.h"

void str_cli(FILE *fp, int sockfd);

int main(int argc, char **argv)
{
	int		sockfd, n;
	char	buf[MAXLINE + 1];
	struct	sockaddr_in	servaddr;

	if (argc != 2)
	{
		perror("use age:a.out <IPaddress>");
		exit(-1);
	}

	if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror(" socket error");
		exit(-1);
	}

	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(13);
	if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) < 0)
	{
		perror("inet_pton error");
		exit(-1);
	}

	if (connect(sockfd,(struct sockaddr *) &servaddr, sizeof(servaddr)) == -1)
	{
		perror("conect error");
		exit(-1);
	}

	str_cli(stdin, sockfd);

	if (close(sockfd) == -1)
	{
		perror("close error");
		exit(-1);
	}
}

void str_cli(FILE *fp, int sockfd)
{
	char	sendline[MAXLINE], recvline[MAXLINE];

	while (fgets(sendline, MAXLINE, fp) != NULL)
	{
		if (write(fd, sendline, strlen(sendline)) == -1)
		{
			perror("send error");
			exit(-1);
		}


	}
}
