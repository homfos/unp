#include "unp.h"

int Select(int nfds, fd_set *readfds, fd_set *writefds,
		fd_set *exceptfds, struct timeval *timeout)
{
	int		retval;

	if ((retval = select(nfds, readfds, writefds, exceptfds, timeout)) == -1)
	{
		err_sys("select error\n");
	}

	return (retval);
}

int Socket(int family, int type, int protocol)
{
	int		n;

	if ((n = socket(family, type, protocol)) == -1)
	{
		err_sys("socket error\n");
	}

	return (n);
}

void Fputs(const char *s, FILE *stream)
{
	int		n;
	if ((n = fputs(s, stream)) == -1)
	{
		err_sys("fputs error\n");
	}
}

char *Fgets(char *s, int size, FILE *stream)
{
	if (fgets(s, size, stream) == NULL)
	{
		err_sys("fgets error\n");
	}

	return (s);
}

void
Writen(int fd, void *ptr, size_t nbytes)
{
	if (writen(fd, ptr, nbytes) != nbytes)
		err_sys("writen error");
}

void Connect(int sockfd, const struct sockaddr *serv_addr, socklen_t len)
{
	if (connect(sockfd, serv_addr, len) == -1)
	{
		err_sys("connect error\n");
	}
}

void Inet_pton(int af, const char *src, void *des)
{
	if (inet_pton(af, src, des) <= 0)
	{
		err_sys("inet error\n");
	}
}

void Bind(int sockfd, const struct sockaddr *my_addr, socklen_t addrlen)
{
	if (bind(sockfd, my_addr, addrlen) == -1)
	{
		err_sys("bind error\n");
	}
}

void Listen(int sockfd, int backlog)
{
	if (listen(sockfd, backlog) == -1)
		err_sys("listen error\n");
}

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
	int		n;
	if ((n = accept(sockfd, addr, addrlen)) == -1)
		err_sys("accept errror\n");

	return (n);
}

pid_t Fork(void)
{
	pid_t	pid;
	if ((pid = fork()) == -1)
		err_sys("");

	return (pid);
}

void Close(int sockfd)
{
	if (close(sockfd) == -1)
		err_sys("close error\n");
}

ssize_t Recvfrom(int s, void *buf, size_t len, int flags,
		struct sockaddr *from, socklen_t *fromlen)
{
	ssize_t		n;

	if ((n = recvfrom(s, buf, len, flags,
			from, fromlen)) == -1)
		err_sys("recv error\n");

	return	n;
}

void Sendto(int s, const void *buf, size_t len, int flags, 
		const struct sockaddr *to, socklen_t tolen)
{
	if (sendto(s, buf, len, flags, 
				to, tolen) == -1)
		err_sys("send to error\n");
}
