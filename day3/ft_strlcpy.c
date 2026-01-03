# include "day3.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = 0;
	while (src[i] != '\0')
		i++;
	len_src = i;
	if (size == 0)
		return (len_src);
	i = 0;
	while (i < size - 1 && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	i = 0;
	return (len_src);
}
