#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

static int va1(int res, va_list ap)
{
	res += va_arg(ap, int);
	return (res);
}

static int va_test(int count, ...)
{
	int res = 0;
	va_list ap;

	va_start(ap, count);
	for (int i = 0; i < count; i++)
	{
		res = va1(res, ap);
		//res += va_arg(ap, int);
	}
	va_end(ap);

	va_start(ap, count);
	for (int i = 0; i < count; i++)
	{
		res = va1(res, ap);
		//res += va_arg(ap, int);
	}
	va_end(ap);

	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!res)
		return (0);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	if (!src || !dst)
		return (0);
	len = ft_strlen(src);
	i = 0;
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && src[i] != 0)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

void	ft_strncat(char *restrict dst, const char *restrict src,
	size_t start, size_t end)
{
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(src);
	i = ft_strlen(dst);
	j = start;
	while (src[j] != '\0' && j < end)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
}

char	*ft_strnjoin_test(char *res, const char *str, size_t start, size_t end)
{
	char		*temp;
	size_t		len1;

	if (!res || !str)
		return (0);
	len1 = ft_strlen(res);
	if (end > ft_strlen(str))
		end = ft_strlen(str);
	else if (start > end)
		return (0);
	if (str[end + 1] == '\0')
		end++;
	if (!(temp = (char *)malloc(sizeof(char) * (len1 + (end - start) + 1))))
		return (0);
	ft_strlcpy(temp, res, len1 + 1);
	ft_strncat(temp + len1, str, start, end);
	free(res);
	return (temp);
}

static char	*ft_make_final_test(const char *str)
{
	char	*res;
	size_t	i;
	size_t	start;

	if (!(res = ft_strdup("")))
		return (0);
	i = 0;
	start = 0;
	while (str[i])
	{
		if (str[i] == '%' || str[i + 1] == '\0')
		{
			res = ft_strnjoin_test(res, str, start, i++);
			start = i;
		}
		i++;
	}
	return (res);
}

void	i_plus_3(int i)
{
	i = i + 3;
}

int main(void)
{
	char *ans = ft_make_final_test("Hi% %my name% is %kim\n");
	printf("%s", ans);
	free (ans);
	printf("%s\n", "test");

	printf("%d", va_test(5, 1, 2, 3, 4, 5));

	return (0);
}
