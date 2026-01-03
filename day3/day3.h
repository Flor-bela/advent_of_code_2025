#ifndef DAY3_H
# define DAY3_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char	**ft_split(char const *s, char c);
int	    ft_atoi(char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);

char	*get_next_line(int fd);
size_t	ft_len(const char *s);
char	*ft_strchr(const char *s, int c);
void	ft_copy(char *dst, const char *src, size_t size);
void	ft_strlcat(char *dst, const char *src, size_t size);
int		free_all(char **ptr, char **result);


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# if BUFFER_SIZE <=0
#  error BUFFER SIZE invalid
# endif

#endif
