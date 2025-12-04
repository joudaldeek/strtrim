#include <stdio.h>
#include <stdlib.h>

int	num_of_words(char const *s, char c) 
{
	int	i;
	int count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if(s[i] != c)
			i++;
		else if ((i != 0) && (s[i] == c) && (s[i-1] != c))
		{
			count++;
			i++;
		}
		else 
			i++;
	}
	if (s[i -1] != c)
		return (count + 1);
	return (count);
}
int	*size_of_each(char *s, char c)
{
	int	i;
	int	j;
	int	size;

	size = 0;
	j = 0;
	i = 0;
	int num = num_of_words (s, c);
	int *p = malloc (num * sizeof(int));
	while((s) && (j < num))
	{
		if(s[i] != c)
			size++;
		if((s[i] == c) && (i != 0) && (s[i - 1] != c))
		{
			p[j++] = size + 1 ;
			size = 0;
		}
		i++;
	}
	if(size != 0) 
		p[j] = size + 1;
	return (p);
}
void copy(char *p, char *s, int *k, int size)
{
	int j = 0;
	while (j < size - 1)
	{
		p[j] = s[*k];
		(*k)++;
		j++;
	}
	p[j] = '\0';
}	
char **put_in_p(char *s, char c, int *sizes, int num)
{
	char **p;
	int	i;
	int	k;

	i = 0;
	k = 0;
	p = NULL;
	p = malloc ((num +1) * sizeof(char *));
	while (i < num)
	{
		p[i] = malloc(sizes[i] * sizeof(char));
		if (s[k] == c)
			k++;
		else
		{
			copy(p[i] , s, &k, sizes[i]);
			i++;
		}
	}
	p[i] = NULL;
	return (p);
}


char **ft_split(char *s, char c)
{
	char **p;
	int	*sizes;
	sizes = size_of_each(s,c);
	int num = num_of_words(s,c);

	p = put_in_p(s , c, sizes, num);
	return (p);
}
int main()
{
	char str[] = "jude sami aldeek ";
	char **p = ft_split(str, ' ');
	int i = 0;
	while (i < num_of_words(str,' '))
	{
		printf("%s\n", p[i] );
		i++;
	}

	return (0);
}
