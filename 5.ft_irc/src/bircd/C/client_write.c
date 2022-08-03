
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include "bircd.h"

void	client_write(t_env *e, int cs)
{
<<<<<<< HEAD:src/bircd/client_write.c
<<<<<<< HEAD

}
=======
=======
<<<<<<< HEAD:src/bircd/client_write.c
>>>>>>> 1cbbb3452785983d9bcab4fd7a80491a4233cf54:src/bircd/C/client_write.c
	// int r;
	// int i;

	// r = recv(cs, e->fds[cs].buf_read, BUF_SIZE, 0);
	// if (r <= 0)
	// {
	// 	close(cs);
	// 	clean_fd(&e->fds[cs]);
	// 	printf("client #%d gone away\n", cs);
	// }
	// else
	// {
	// 	i = 0;
	// 	while (i < e->maxfd)
	// 	{
	// 		if ((e->fds[i].type == FD_SERV) &&
	// 			(i != cs))
	// 			send(i, e->fds[cs].buf_read, r, 0);
	// 		i++;
	// 	}
	// }
}
<<<<<<< HEAD:src/bircd/client_write.c
>>>>>>> 60e642e0de101352bfdba7cf37906e747ed85a67
=======
=======

}
>>>>>>> 5590a8ee2634ba63d3476cc7bda2fe255387bc58:src/bircd/C/client_write.c
>>>>>>> 1cbbb3452785983d9bcab4fd7a80491a4233cf54:src/bircd/C/client_write.c
