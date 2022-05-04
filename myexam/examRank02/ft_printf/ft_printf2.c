#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#include <stdio.h>

typedef struct s_info
{
	int		minus;
	int		width;
	int		prec;
	char	conv;
	int		nbr_sign;
	int		nbr_base;
}				t_info;

int		ft_isconv(char c)
{
	if (c == 's' || c == 'd' || c == 'x')
		return (1);
	return (0);
}

int		ft_isdigit(char c)
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
	int		i;

	i = ft_strlen(s);
	write(1, s, i);
	return (i);
}

void	init_info(t_info *info)
{
	info->minus = 0;
	info->width = 0;
	info->prec = -1;
	info->conv = 'a';
	info->nbr_sign = 1;
	info->nbr_base = 10;
}

void	ft_check_info(char c, t_info *info)
{
	if (c == '-' && info->width == 0 && info->prec == -1)
		info->minus = 1;
	if (ft_isdigit(c) && info->prec == -1)
		info->width = (info->width * 10) + (c - '0');
	if (c == '.')
		info->prec = 0;
	if (ft_isdigit(c) && info->prec != -1)
		info->prec = (info->prec * 10) + (c - '0');
}

int		ft_print_str(char *str, t_info *info)
{
	char	*temp;
	int		len;
	int		flen;
	int		i;
	int		j;

	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (info->prec < len)
		len = info->prec;
	if (info->width > len)
		flen = info->width;
	else
	{
		flen = len;
		info->width = 0;
	}
	temp = (char *)malloc(sizeof(char) * (flen + 1));
	i = 0;
	if (info->minus == 0 && info->width != 0)
	{
		while (i < (flen - len))
			temp[i++] = ' ';
	}
	j = 0;
	while (j < len)
		temp[i++] = str[j++];
	if (info->minus == 1 && info->width != 0)
	{
		while(i < flen)
			temp[i++] = ' ';
	}
	temp[i] = '\0';
	len = ft_putstr(temp);
	free(temp);
	return (len);
}

int		ft_get_num_len(unsigned int nbr, int base, int sign)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= base;
		i++;
	}
	if (base == 16 && sign == -1)
		i = 8;
	return (i);
}

char	*return_char_by_base(int base)
{
	if (base == 10)
		return ("0123456789");
	else if (base == 16)
		return ("0123456789abcdef");
	else
		return (0);
}

int		ft_print_num(unsigned int num, int base, int numlen, int sign)
{
	char	*temp;
	int		i;

	if (base == 16 && sign == -1)
		num = 4294967295 - num + 1;

	temp = (char *)malloc(sizeof(char) * (numlen + 1));
	i = numlen;
	temp[i--] = '\0';
	while (i > -1)
	{
		temp[i--] = return_char_by_base(base)[num % base];
		num /= base;
	}
	//printf(" [%s] ", temp);
	i = ft_putstr(temp);
	free(temp);
	return (i);
}

int		ft_print_nbr(int nbr, t_info *info)
{
	unsigned int	num;
	int				res;
	int				numlen;
	int				plen;
	int				wlen;
	int				i;

	res = 0;
	if(nbr < 0)
	{
		num = nbr * -1;
		info->nbr_sign = -1;
	}
	else
		num = nbr;
	numlen = ft_get_num_len(num, info->nbr_base, info->nbr_sign);
	if (info->prec > numlen)
		plen = info->prec;
	else
		plen = numlen;
	if (info->width > plen && info->nbr_sign == 1)
		wlen = info->width;
	else if (info->width > plen && info->nbr_sign == -1)
		wlen = info->width - 1;
	else
		wlen = plen;
	//printf(" [p : %d, w : %d] ", info->prec, info->width);
	//printf(" [nl : %d, pl : %d, wl : %d] ", numlen, plen, wlen);
	i = 0;
	if (wlen > plen && info->minus == 0)
		while (i < (wlen - plen))
		{
			res += ft_putchar(' ');
			i++;
		}	
	if (info->nbr_sign == -1 && info->nbr_base == 10)
		res += ft_putchar('-');
	i = 0;
	if (plen > numlen)
		while (i < (plen - numlen))
		{
			res += ft_putchar('0');
			i++;
		}
	res += ft_print_num(num, info->nbr_base, numlen, info->nbr_sign);
	i = 0;
	if (wlen > plen && info->minus == 1)
		while (i < (wlen - plen))
		{
			res += ft_putchar(' ');
			i++;
		}
	return (res);
}

int		ft_print_format(va_list ap, t_info *info)
{
	int res;

	if (info->conv == 's')
		res = ft_print_str(va_arg(ap, char *), info);
	else if (info->conv == 'd')
		res = ft_print_nbr(va_arg(ap, int), info);
	else if (info->conv == 'x')
	{
		info->nbr_base = 16;
		res = ft_print_nbr(va_arg(ap, int), info);
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
	while(str[i])
	{
		if (str[i++] == '%')
		{
			init_info(info);
			while (!ft_isconv(str[i]) || str[i])
				ft_check_info(str[i++], info);
			if (ft_isconv(str[i]))
				info->conv = str[i];
			if ((n = ft_print_format(ap, info)) == -1)
				return (-1);
			res += n;
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
	t_info		*info;
	int			res;

	va_start(ap, str);
	info = (t_info *)malloc(sizeof(t_info));
	res = ft_printf_init(str, ap, info);
	free(info);
	va_end(ap);
	return (res);
}
/*
int		main(void)
{
	int res = 0;
	res = printf("Hello [%-10.4s] World! [%d]", "lovely", 0);
	printf("\nlength : %d\n", res);
	res = ft_printf("Hello [%-10.4s] World! [%d]", "lovely", 0);
	printf("\nlength : %d\n", res);
	return (0);
}*/
