#include <stdio.h>

#include "includes/ft_printf.h"

int main(void)
{
	char *res = ft_strnjoin("Hello", "World", 0, 4);
	printf("%s", res);

	ft_printf("Hello/n");
	return (0);
}
