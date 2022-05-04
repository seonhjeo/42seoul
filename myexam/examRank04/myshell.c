#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define STDIN 0
#define STDOUT 1
#define STDERR 2

#define T_END 3
#define T_PIPE 4
#define T_BREAK 5

#define ERR_CD1 "error: cd: bad arguments\n"
#define ERR_CD2 "error: cd: cannot change directory to "
#define ERR_FATAL "error: fatal\n"
#define ERR_EXE "error: cannot execute "

typedef struct s_data
{
	int	size;
	int	type;
	int	fd[2];
	char **av;
	struct s_data *prev;
	struct s_data *next;
}				t_data;

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strdup(char *str)
{
	char *temp;
	int	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	temp[len] = '\0';
	while (--len >= 0)
		temp[len] = str[len];
	return (temp);
}

void	exit_fatal(void)
{
	write(STDERR, ERR_FATAL, ft_strlen(ERR_FATAL));
	exit(EXIT_FAILURE);
}

void	exit_exe(char *str)
{
	write(STDERR, ERR_EXE, ft_strlen(ERR_EXE));
	write(STDERR, str, ft_strlen(str));
	write(STDERR, "\n", 1);
	exit(EXIT_FAILURE);
}

int		exit_cd1(void)
{
	write(STDERR, ERR_CD1, ft_strlen(ERR_FATAL));
	return (EXIT_FAILURE);
}

int		exit_cd2(char *str)
{
	write(STDERR, ERR_CD2, ft_strlen(ERR_CD2));
	write(STDERR, str, ft_strlen(str));
	write(STDERR, "\n", 1);
	exit(EXIT_FAILURE);
}

int	get_size(char **av)
{
	int	i;

	i = 0;
	while (av[i] && strcmp(av[i], ";") != 0 && strcmp(av[i], "|") != 0)
		i++;
	return (i);
}

int	get_type(char *av)
{
	if (!av)
		return (T_END);
	if (strcmp(av, "|") == 0)
		return (T_PIPE);
	if (strcmp(av, ";") == 0)
		return (T_BREAK);
	return (0);
}

void	ft_lstadd_back(t_data **data, t_data *new)
{
	t_data *temp;
	
	if (!(*data))
		*data = new;
	else
	{
		temp = *data;
		while (temp->next)
			temp = temp->next;
		new->prev = temp;
		temp->next = new;
	}
}

int	parse(t_data **data, char **av)
{
	t_data	*new;
	int	size;

	new = (t_data *)malloc(sizeof(t_data));
	if (!new)
		exit_fatal();
	size = get_size(av);
	new->size = size;
	new->prev = NULL;
	new->next = NULL;
	new->type = get_type(av[size]);
	new->av = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new->av)
		exit_fatal();
	new->av[size] = NULL;
	while(--size >= 0)
		new->av[size] = ft_strdup(av[size]);
	ft_lstadd_back(data, new);
	return (new->size);
}

void	exec_cmd(t_data *data, char **env)
{
	pid_t pid;
	int status;
	int	pipe_open;

	pipe_open = 0;
	if (data->type == T_PIPE || (data->prev && data->prev->type == T_PIPE))
	{
		pipe_open = 1;
		if (pipe(data->fd))
			exit_fatal();
	}
	pid = fork();
	if (pid < 0)
		exit_fatal();
	else if (pid == 0)
	{
		if (data->type == T_PIPE && dup2(data->fd[1], STDOUT) < 0)
			exit_fatal();
		if (data->prev && data->prev->type == T_PIPE && dup2(data->prev->fd[0], STDIN) < 0)
			exit_fatal();
		if ((execve(data->av[0], data->av, env)) < 0)
			exit_exe(data->av[0]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (pipe_open)
		{
			close(data->fd[1]);
			if (!data->next && data->next->type != T_PIPE)
				close(data->fd[0]);
		}
		if (data->prev && data->prev->type == T_PIPE)
			close(data->prev->fd[0]);
	}
}

void	exec_cmds(t_data *data, char **env)
{
	t_data *temp;

	temp = data;
	while (temp)
	{
		if (strcmp("cd", temp->av[0]) == 0)
		{
			if (temp->size < 2 )
				exit_cd1();
			else if (chdir(temp->av[1]))
				exit_cd2(temp->av[1]);
		}
		else
			exec_cmd(data, env);
		temp = temp->next;		
	}
}

void	free_all(t_data *data)
{
	t_data *temp;
	int		i;

	while (data)
	{
		i = 0;
		temp = data->next;
		while (i < data->size)
			free(data->av[i++]);
		free(data->av);
		free(data);
		data = temp;
	}
	data = NULL;
}

#include <stdio.h>

int	main(int ac, char **av, char **env)
{
	t_data *data;
	int	i;

	data = NULL;
	i = 1;
	if (ac > 1)
	{
		while (av[i])
		{
			if (strcmp(av[i], ";") == 0)
			{
				i++;
				continue ;
			}
			i += parse(&data, &av[i]);
			if (!av[i])
				break ;
			else
				i++;
		}
		t_data *ptr = data;
		while (ptr)
	{
		
		printf("=================\n");
		for (i = 0; i < ptr->size; i++)
			printf("%s\n", ptr->av[i]);
		printf("TYPE: %d\n", ptr->type);
		printf("SIZE: %d\n", ptr->size);
		printf("=================\n");
		ptr = ptr->next;
	}
	(void)**env;
	printf("END\n");
		if (data)
			exec_cmds(data, env);
		free_all(data);
	}
	return (0);
}