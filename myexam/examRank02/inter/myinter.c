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
	{
		ft_putchar('\n');
	}
	else
	{
		i = 0;
		while (argv[1][i] != '\0')
		{
			j = 0;
			flag = 0;
			while (argv[2][j] != '\0')
			{
				if (argv[1][i] == argv[2][j])
				{
					flag = 1;
					break ;
				}
				j++;
			}
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
		ft_putchar('\n');
	}
	return (0);
}
