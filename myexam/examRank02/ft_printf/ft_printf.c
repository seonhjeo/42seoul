#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct	s_info
{
	int			minus;
	int			prec;
	int			width;
	char		conv;
	int			nbr_sign;
	int			nbr_base;
}				t_info;

int		is_conv(char c)
{
	if (c == 's' || c == 'd' || c == 'x')
		return (1);
	return (0);
}

int		is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putstr(char *s)
{
	int		len;
	
	len = ft_strlen(s);
	write (1, &s, len);
	return (len);
}

char	*ft_strdup(char *s)
{
	char	*res;
	int 	len;
	int		i;
	
	len = ft_strlen(s);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	init_info(t_info *info)
{
	info->minus = 0;
	info->prec = -1;
	info->width = 0;
	info->conv = 0;
	info->nbr_sign = 1;
	info->nbr_base = 10;
}

void	check_info(t_info *info, char c)
{
	if (c == '-' && info->width == 0 && info->prec == -1)
		info->minus = 1;
	if (info->prec == -1 && is_digit(c))
		info->width = info->width * 10 + (c - '0');
	if (c == '.')
		info->prec = 0;
	if (info->prec == 0 && is_digit(c))
		info->prec = info->prec * 10 + (c - '0');
}

char	*get_base_str(t_info *info)
{
	if (info->nbr_base == 10)
		return ("0123456789");
	else if (info->nbr_base == 16)
		return ("0123456789abcdef");
	else
		return (NULL);
}

int		get_nbr_length(unsigned int n, t_info *info)
{
	int 	res;

	res = 0;
	if (n == 0)
		res = 1;
	else
	{
		while (n > 0)
		{
			n /= info->nbr_base;
			res++;
		}
	}
	return (res);
}

int		add_prec_nbr(char **nbr, t_info *info)
{
	char		*temp;
	int 		len;
	int			i;
	int			j;
	
	len = ft_strlen(nbr);
	if (info->prec > len)
	{
		if (!(temp == (char *)malloc(sizeof(char) * (info->prec + 1))))
			return (NULL);
		i = 0;
		while (i < info->prec - len)
			temp[i++] = '0';
		j = 0;
		while (nbr[j])
			temp[i++] = nbr[j++];
		temp[i] = '\0';
		len = info->prec;
		free(*nbr);
		return (temp);
	}
	return (nbr);
}

int		add_width_nbr(char **nbr, t_info *info)
{
	char		*temp;
	int			len;
	int			i;
	int			j;

	len = ft_strlen(nbr);
	if (info->width > len)
	{
		if (!(temp = (char *)malloc(sizeof(char) * (info->width + 1))))
			return (NULL);
		i = 0;
		j = 0;
		if (info->minus == 0)
		{
			while (i < info->width - len)
				temp[i++] = ' ';
			while (nbr[j])
				temp[i++] = nbr[j++];
		}
		else if (info->minus == 1)
		{
			while (nbr[j])
				temp[i++] = nbr[j++];
			while (i < info->width)
				temp[i++] = ' ';
		}
		else
			return (NULL);
		temp[i] = '\0';
		printf("temp : [%s]\n", temp);
		len = info->width;
		free(*nbr);
		return (temp);
	}
	return (nbr);
}

int		print_nbr(int n, t_info *info)
{
	char			*res;
	int				len;
	unsigned int	num;
	int				i;

	len = 0;
	if (n < 0)
	{
		info->nbr_sign = -1;
		num = n * -1;
		len += 1;
	}
	else
		num = n;
	len += get_nbr_length(num, info);
	res = (char *)malloc(sizeof(char) * (len + 1));
	res[len] = '\0';
	i = len - 1;
	while (num > 0)
	{
		res[i] = get_base_str(info)[num % info->nbr_base];
		num /= info->nbr_base;
		i--;
	}
	if (info->nbr_sign == -1)
		res[0] = '-';
	printf("semic : %s\n", res);
	res = add_prec_nbr(res, info);
	res = add_width_nbr(res, info);
	len = ft_putstr(res);
	return (len);
}

int		print_str(char *str, t_info *info)
{
	return (0);
}

int		ft_print_ap(va_list ap, t_info *info)
{
	int		res;

	res = 0;
	if (info->conv == 'd')
		res += print_nbr(va_arg(ap, int), info);
	else if (info->conv == 'x')
	{
		info->nbr_base = 16;
		res += print_nbr(va_arg(ap, int), info);
	}
	else if (info->conv == 's')
		res += print_str(va_arg(ap, char *), info);
	else
		return (-1);
	return (res);
}

int		ft_printf_init(const char *str, va_list ap)
{
	t_info	*info;
	int		res;
	int		i;

	if (!str)
		return (-1);
	info = (t_info*)malloc(sizeof(t_info));
	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			init_info(info);
			while (!is_conv(str[i]) && str[i])
			{
				check_info(info, str[i]);
				i++;
			}
			if (str[i] == '\0')
				return (-1);
			else
				info->conv = str[i];
			res += ft_print_ap(ap, info);
		}
		else
			res += ft_putchar(str[i]);
		i++;
	}
	return (res);
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	int			res;

	if (!str)
		return (-1);
	va_start(ap, str);
	res = ft_printf_init(str, ap);
	va_end(ap);
	return (res);
}
