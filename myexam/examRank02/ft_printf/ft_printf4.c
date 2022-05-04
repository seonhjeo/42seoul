#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct s_info
{
	int		minus;
	int		width;
	int		prec;
	char	conv;
	int		num_sign;
	int		num_base;
}				t_info;

void	init_info(t_info *info)
{
	info->minus = 0;
	info->width = 0;
	info->prec = -1;
	info->conv = '\0';
	info->num_sign = 1;
	info->num_base = 10;
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

int		ft_putstr(char *s, int i)
{
	write (1, s, i);
	return (i);
}

void	ft_check_format(char c, t_info *info)
{
	if (c == '-' && info->width == 0)
		info->minus = 1;
	if (is_digit(c) && info->prec == -1)
		info->width = (info->width * 10) + (c - '0');
	if (c == '.' && info->prec == -1)
		info->prec = 0;
	if (is_digit(c) && info->prec != -1)
		info->prec = (info->prec * 10) + (c - '0');
}

int		ft_print_str(char *str, t_info *info)
{
	int		res;
	int		len;
	int		i;

	if (str == NULL)
		str = "(null)";
	res = 0;
	len = ft_strlen(str);
	if (len > info->prec && info->prec != -1)
		len = info->prec;
	i = 0;
	if (info->width > len && info->minus == 0)
		while (i < info->width - len)
		{
			res += ft_putchar(' ');
			i++;
		}
	res += ft_putstr(str, len);
	i = 0;
	if (info->width > len && info->minus == 1)
		while (i < info->width - len)
		{
			res += ft_putchar(' ');
			i++;
		}
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
		nbr /= info->num_base;
		len++;
	}
	return (len);
}

char	*return_base(int base)
{
	if (base == 10)
		return ("0123456789");
	else if (base == 16)
		return ("0123456789abcedf");
	else
		return ("");
}

int		ft_itoa(char **buf, unsigned int nbr, t_info *info)
{
	int		len;
	int		i;

	len = get_nbr_len(nbr, info);
	if (!(*buf = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	(*buf)[len] = '\0';
	if (nbr == 0 && info->prec != 0)
		(*buf)[0] = '0';
	i = 1;
	while (nbr)
	{
		(*buf)[len - i] = return_base(info->num_base)[nbr % info->num_base];
		nbr /= info->num_base;
		i++;
	}
	return (len);
}

int		ft_print_num(unsigned int nbr, t_info *info)
{
	char	*buf;
	int		len;
	int		res;
	int		i;

	if (info->conv == 'd' && (int)nbr < 0)
	{
		info->num_sign = -1;
		nbr = -nbr;
	}
	len = ft_itoa(&buf, nbr, info);
	res = 0;
	if (info->prec < len)
		info->prec = len;
	if (info->width > info->prec && info->num_sign == -1)
		info->width--;
	i = 0;
	if (info->width > info->prec && info->minus == 0)
		while (i < info->width - info->prec)
		{
			res += ft_putchar(' ');
			i++;
		}
	if (info->prec > len && info->num_sign == -1)
		res += ft_putchar('-');
	i = 0;
	if (info->prec > len)
		while (i < info->prec - len)
		{
			res += ft_putchar('0');
			i++;
		}
	if (info->prec <= len && info->num_sign == -1)
		res += ft_putchar('-');
	res += ft_putstr(buf, len);
	i = 0;
	if (info->width > info->prec && info->minus == 1)
		while (i < info->width - info->prec)
		{
			res += ft_putchar(' ');
			i++;
		}
	free(buf);
	return (res);
}

int		ft_print_format(va_list ap, t_info *info)
{
	int		res;

	if (info->conv == 's')
		res = ft_print_str(va_arg(ap, char *), info);
	else if (info->conv == 'd')
		res = ft_print_num(va_arg(ap, unsigned int), info);
	else if (info->conv == 'x')
	{
		info->num_base = 16;
		res = ft_print_num(va_arg(ap, unsigned int), info);
	}
	else
		res = -1;
	return (res);
}

int		ft_printf_init(const char *str, va_list ap, t_info *info)
{
	int		res;
	int		n;
	int		i;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			init_info(info);
			while (!is_conv(str[i]) && str[i])
				ft_check_format(str[i++], info);
			info->conv = str[i++];
			if ((n = ft_print_format(ap, info)) == -1)
				return (-1);
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
	int	res;

	res = ft_printf("[%10.8d]", -1234);
	printf ("\nlen : %d\n", res);
	res = printf("[%10.8d]", -1234);
	printf ("\nlen : %d\n", res);

	return (0);
}
*/
