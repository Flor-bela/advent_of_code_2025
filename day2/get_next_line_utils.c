#include "day2.h"

size_t	ft_len(const char *s)
{
	size_t	num;

	num = 0;
	if (s == NULL)
		return (0);
	while (*s != '\0')
	{
		num++;
		s++;
	}
	return (num);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;
	int				i;

	if (s == NULL)
		return (NULL);
	ch = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return ((char *)&s[i]);
		i++;
	}
	if (ch == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

void	ft_copy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (src != NULL)
	{
		while (src[i] != '\0')
			i++;
		i = 0;
		while (i < size - 1 && (src[i] != '\0'))
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
}

void	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	z;
	size_t	len_dst;
	size_t	to_append;

	z = 0;
	to_append = 0;
	len_dst = ft_len(dst);
	to_append = size - len_dst - 1;
	while (src[z] != '\0' && to_append > 0)
	{
		dst[len_dst] = src[z];
		len_dst++;
		z++;
		to_append--;
	}
	dst[len_dst] = '\0';
}

int	free_all(char **ptr, char **result)
{
	if (*result != NULL)
		free (*result);
	*result = NULL;
	if (*ptr != NULL)
		free (*ptr);
	*ptr = NULL;
	return (-1);
}
