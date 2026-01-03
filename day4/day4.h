#ifndef DAY4_H
# define DAY4_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);

char	*get_next_line(int fd);
size_t	ft_len(const char *s);
char	*ft_strchr(const char *s, int c);
void	ft_copy(char *dst, const char *src, size_t size);
void	ft_strlcat(char *dst, const char *src, size_t size);
int		free_all(char **ptr, char **result);


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
# if BUFFER_SIZE <=0
#  error BUFFER SIZE invalid
# endif

#endif
