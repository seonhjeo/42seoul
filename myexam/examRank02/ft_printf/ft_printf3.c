#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#include <stdio.h>

// structure for store flags : info
typedef struct s_info
{
	int		minus;
	int		width;
	int		prec;
	char	conv;
	int		nbr_sign;
	int		nbr_base;
}				t_info;

// true if the char is digit
int		is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// true if the char is conv
int		is_conv(char c)
{
	if (c == 's' || c == 'x' || c == 'd')
		return (1);
	return (0);
}

// info initializing function
void	init_info(t_info *info)
{
	info->minus = 0;
	info->width = 0;
	info->prec = -1;
	info->conv = '\0';
	info->nbr_sign = 1;
	info->nbr_base = 10;
}

// check width and precursion
void	check_width_and_prec(char c, t_info *info)
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

// return length of string
int		ft_strlen(char *s)
{
	int		i;
	
	i = 0;
	while (s[i])
		i++;
	return (i);
}

// print 1 character and return 1
int		ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

// print i character in string and return i
int		ft_putstr(char *s, int i)
{
	write (1, s, i);
	return (i);
}

// print string in format
int		ft_print_str(char *str, t_info *info)
{
	int		len;
	int		res;
	int		i;

	if (str == NULL)
		str = "(null)";
	res = 0;
	i = 0;
	len = ft_strlen(str);
	if (len > info->prec && info->prec > -1)
		len = info->prec;
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

// calculate length of number
int		ft_nbr_len(unsigned int nbr, t_info *info)
{
	int		i;

	if (nbr == 0 && info->prec != 0)
		return (1);
	i = 0;
	while (nbr > 0)
	{
		nbr /= info->nbr_base;
		i++;
	}
	return (i);
}

//return base
char	*ft_return_base(int base)
{
	if (base == 10)
		return ("0123456789");
	else if (base == 16)
		return ("0123456789abcdef");
	else
		return ("");
}

// make number to string
int		ft_itoa(char **buf, unsigned int nbr, t_info *info)
{;
	int		len;
	int		i;

	len = ft_nbr_len(nbr, info);
	if(!(*buf = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	i = 1;
	(*buf)[len] = '\0';
	if (nbr == 0 && info->prec != 0)
		(*buf)[len - i] = '0';
	while (nbr)
	{
		(*buf)[len - i] = ft_return_base(info->nbr_base)[nbr % info->nbr_base];
		nbr /= info->nbr_base;
		i++;
	}
	return (len);
}

// print number in format
int		ft_print_nbr(unsigned int nbr, t_info *info)
{
	char	*buf;
	int		len;
	int		res;
	int		i;

	if (info->nbr_base == 10 && (int)nbr < 0)
	{
		info->nbr_sign = -1;
		nbr = -nbr;
	}
	res = 0;
	len = ft_itoa(&buf, nbr, info);
	i = 0;
	if (info->prec < len)
		info->prec = len;
	if (info->width > info->prec && info->nbr_sign == -1)
		info->width--;
	if (info->width > info->prec && info->minus == 0)
		while (i < info->width - info->prec)
		{
			res += ft_putchar(' ');
			i++;
		}
	if (info->prec > len && info->nbr_sign == -1)
		res += ft_putchar('-');
	i = 0;
	if (info->prec > len)
		while (i < info->prec - len)
		{
			res += ft_putchar('0');
			i++;
		}
	if (info->prec <= len && info->nbr_sign == -1)
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

// check conversion and call print_conv function
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

// initializing printing function
int		ft_printf_init(char *str, t_info *info, va_list ap)
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
				check_width_and_prec(str[i++], info);
			info->conv = str[i++];
			if((n = ft_print_format(ap, info)) == -1)
				return (n);
			res += n;
		}
		else
			res += ft_putchar(str[i++]);
	}
	return (res);
}

// main function
// allocate and free info
int		ft_printf(const char *str, ...)
{
	va_list(ap);
	t_info	*info;
	int		res;

	info = (t_info*)malloc(sizeof(t_info));
	va_start(ap, str);
	res = ft_printf_init((char *)str, info, ap);
	va_end(ap);
	free(info);
	return (res);
}


int main(void)
{
	ft_printf("Hello %s![%10.5x]\n", "World", -1234567);
	printf("Hello %s![%10.5x]\n", "World", -1234567);
	return (0);
}

