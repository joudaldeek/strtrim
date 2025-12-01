#include <stdio.h>
#include <stdlib.h>
int inset(char const *set, char c)
{
	int i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
int ft_strlen(const char *s)
{
	int i=0; 
	while (s[i] != '\0')
		i++;
	return (i);
}
char *ft_strtrim(char const *s1, char const *set)
{
	char *p;
	int start; 
	int end;
	int i;
	int size;

	i = 0;
	size = ft_strlen(s1);
	start = 0;
	end = size - 1;
	while (s1[i] != '\0')
	{
		if(inset(set,s1[i]))
			start = i+1;
		else 
			break;
		i++;
	}
	i = size - 1;
	while (i > 0) 
	{
		if (inset(set, s1[i]))
			end = i-1;
		else 
			break;
		i--;
	}
	p = malloc ((end - start + 2) * 1) ;
	i = 0;
	while (start <= end)
	{
		p[i] = s1[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}

int main ()
{
	char s[] = "*&(jude---";
	char s2[] = "*&";
	char *p = ft_strtrim(s, s2);
	printf("%s" , p);
	return (0);
}





