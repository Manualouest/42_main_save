char	*ft_strcpy(char *dest, char *src)
{
	int	pos;

	pos = 0;
	while (src[pos])
	{
		dest[pos] = src[pos];
		pos++;
	}
	dest[pos] = 0;
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i ++;
	}
	return (i);
}
