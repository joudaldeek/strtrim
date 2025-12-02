#include <stdio.h>
#include <stdlib.h>

int ft_len(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		count++;
		n= n / 10;
	}
	return (count);
}
char  *ft_itoa(int n)
{
	char *p;
	int	i;
	int	j;

	j = 0;
	i = ft_len(n) - 1;
	p = malloc ((ft_len(n) + 1) * 1);
	if (n == 0)
		p[0] = '0';
	if (n < 0)
	{
		p[0] ='-'; 
		n = -n;
		j++;
	}
	while ( i >= j)
	{
		p[i] = n % 10 + '0';
		n = n/10;
		i--;
	}
	return (p);
}
int main()
{
	char *p = ft_itoa(0);
	printf("%s" , p);

	return (0);
}

