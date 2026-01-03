#include "day5.h"

char	*ft_strdup(const char *s)
{
	unsigned char	*ch;
	size_t			size;
	size_t			i;
	unsigned char	*ptr;

	size = 0;
	i = 0;
	ch = (unsigned char *)s;
	while (ch[i] != '\0')
		i++;
	size = i + 1;
	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = ch[i];
		i++;
	}
	return ((char *)ptr);
}
