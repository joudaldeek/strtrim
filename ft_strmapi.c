int ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
char	*ft_strmapi(char const *s, char (*f)(unsigned int , char))
{
	int	i;
	char *p;
	int	size;


	size = ft_strlen(s);
	i = 0;
	p = malloc((size + 1) * 1);
	if (!p) 
		return (NULL);

	while (s[i] != '\0')
	{
		p[i] = f(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}

