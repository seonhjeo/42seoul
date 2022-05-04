#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int i;
	int j;
	int flag;

	if (argc != 3)
		;
	else
	{
		i = 0;
		while (argv[1][i] != '\0')
		{
			flag = 1;
			j = 0;
			while (j < i)
			{
				if (argv[1][i] == argv[1][j])
				{
					flag = 0;
					break ;
				}
				j++;
			}
			if (flag == 1)
				ft_putchar(argv[1][i]);
			i++;
		}
		i = 0;
		while (argv[2][i] != '\0')
		{
			flag = 1;
			j = 0;
			while (argv[1][j] != '\0')
			{
				if (argv[2][i] == argv[1][j])
				{
					flag = 0;
					break ;
				}
				j++;
			}
			j = 0;
			while (j < i)
			{
				if (argv[2][i] == argv[2][j])
				{
					flag = 0;
					break ;
				}
				j++;
			}
			if (flag == 1)
				ft_putchar(argv[2][i]);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
