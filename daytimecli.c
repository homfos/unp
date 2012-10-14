#include "unp.h"

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
	while ( (n = read(sockfd, buf, MAXLINE)) > 0) 
	{
			buf[n] = 0;	/* null terminate */
			if (fputs(buf, stdout) == EOF)
				perror("fputs error");
				exit(-1);
		}
}
