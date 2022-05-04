#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct s_info
{
	int		minus;
	int		width;
	int		prec;
	char	conv;
	int		nbr_base;
	int		nbr_sign;
}				t_info;

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
	write (1, &c, 1);
	return (1);
}

int		ft_putchar_n(char c, int num)
{
	int		i;

	i = 0;
	while (i < num)
	{
		write (1, &c, 1);
		i++;
	}
	return (num);
}

int		ft_putstr(char *s, int	i)
{
	write (1, s, i);
	return (i);
}

int		is_conv(char c)
{
	if (c == 's' || c == 'x' || c == 'd')
		return (1);
	return (0);
}

int		is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	init_info(t_info *info)
{
	info->minus = 0;
	info->width = 0;
	info->prec = -1;
	info->conv = '\0';
	info->nbr_base = 10;
	info->nbr_sign = 1;
}

void	check_format(char c, t_info *info)
{
	if (c == '-' && info->width == 0)
		info->minus = 1;
	if (is_digit(c) && info->prec == -1)
		info->width = (info->width * 10) + (c - '0');
	if (c == '.' && info->prec == -1)
		info->prec = 0;
	if (is_digit(c) && info->prec > -1)
		info->prec = (info->prec * 10) + (c - '0');
}

int		ft_print_str(char *str, t_info *info)
{
	int		res;
	int		len;

	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	res = 0;
	if (info->prec < len && info->prec != -1)
		len = info->prec;
	if (info->width > len && info->minus == 0)
		res += ft_putchar_n(' ', info->width - len);
	res += ft_putstr(str, len);
	if (info->width > len && info->minus == 1)
		res += ft_putchar_n(' ', info->width - len);
	return (res);
}

int		get_nbr_len(unsigned int nbr, t_info *info)
{
	int		len;

	if (nbr == 0 && info->prec != 0)
		return (1);
	len = 0;
	while (nbr)
	{
		nbr /= info->nbr_base;
		len++;
	}
	return (len);
}

char	*return_base(int base)
{
	if (base == 10)
		return ("0123456789");
	return ("0123456789abcdef");
}

int		ft_itoa(char **buf, unsigned int nbr, t_info *info)
{
	int		len;
	int		i;

	len = get_nbr_len(nbr, info);
	if (!(*buf = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	if (nbr == 0 && info->prec != 0)
		(*buf)[0] = '0';
	(*buf)[len] = '\0';
	i = 1;
	while (nbr)
	{
		(*buf)[len - i] = return_base(info->nbr_base)[nbr % info->nbr_base];
		nbr /= info->nbr_base;
		i++;
	}
	return (len);
}

int		ft_print_nbr(unsigned int nbr, t_info *info)
{
	int		res;
	char	*buf;
	int		len;

	if (info->nbr_base == 10 && (int)nbr < 0)
	{
		info->nbr_sign = -1;
		nbr = -nbr;
	}
	res = 0;
	len = ft_itoa(&buf, nbr, info);
	if (info->prec < len)
		info->prec = len;
	if (info->width > info->prec && info->nbr_sign == -1)
		info->width--;
	if (info->width > info->prec && info->minus == 0)
		res += ft_putchar_n(' ', info->width - info->prec);
	if (info->prec > len && info->nbr_sign == -1)
		res += ft_putchar('-');
	if (info->prec > len)
		res += ft_putchar_n('0', info->prec - len);
	if (info->prec <= len && info->nbr_sign == -1)
		res += ft_putchar('-');
	res += ft_putstr(buf, len);
	if (info->width > info->prec && info->minus == 1)
		res += ft_putchar_n(' ', info->width - info->prec);
	return (res);
}

int		ft_print_format(va_list ap, t_info *info)
{
	int		res;

	if (info->conv == 's')
		res = ft_print_str(va_arg(ap, char *), info);
	else if (info->conv == 'd')
		res = ft_print_nbr(va_arg(ap, unsigned int), info);
	else if (info->conv == 'x')
	{
		info->nbr_base = 16;
		res = ft_print_nbr(va_arg(ap, unsigned int), info);
	}
	else
		res = -1;
	return (res);
}

int		ft_printf_init(const char *str, va_list ap, t_info *info)
{
	int		res;
	int		i;
	int		n;

	if (!str)
		return (-1);
	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			init_info(info);
			while (!is_conv(str[i]) && str[i])
				check_format(str[i++], info);
			info->conv = str[i++];
			if ((n = ft_print_format(ap, info)) == -1)
				return (n);
			res += n;
		}
		else
			res += ft_putchar(str[i++]);
	}
	return (res);
}

int		ft_printf(const char *str, ...)
{
	int		res;
	va_list	ap;
	t_info	*info;

	va_start(ap, str);
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (-1);
	res = ft_printf_init(str, ap, info);
	va_end(ap);
	free(info);
	return (res);
}

/*
#include <stdio.h>
int		main(void)
{
	int		res;
	res = ft_printf("Hello World! [%-10.6s], [%12.9d], [%3.8x]", "Printf!", -123456, 34567);
	printf("\nlen : %d\n", res);
	res = printf("Hello World! [%-10.6s], [%12.9d], [%3.8x]", "Printf!", -123456, 34567);
	printf("\nlen : %d\n", res);
	return (0);
}
*/
