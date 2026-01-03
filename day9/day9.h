#ifndef DAY9_H
# define DA9_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

// For get_next_line:


char	*get_next_line(int fd);
size_t	ft_len(const char *s);
char	*ft_strchr(const char *s, int c);
void	ft_copy(char *dst, const char *src, size_t size);
void	ft_strlcat(char *dst, const char *src, size_t size);
int		free_all(char **ptr, char **result);

long	ft_atol(const char *nptr);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# if BUFFER_SIZE <=0
#  error BUFFER SIZE invalid
# endif


#endif
