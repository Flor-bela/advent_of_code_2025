
#ifndef DAY2_H
# define DAY2_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

long long		ft_atol(const char *nptr);
char			**ft_split(char const *s, char c);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_ltoa(long long nbr);

// get_next_line:
char	*get_next_line(int fd);
size_t	ft_len(const char *s);
char	*ft_strchr(const char *s, int c);
void	ft_copy(char *dst, const char *src, size_t size);
void	ft_strlcat(char *dst, const char *src, size_t size);
int		free_all(char **ptr, char **result);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif
# if BUFFER_SIZE <=0
#  error BUFFER SIZE invalid
# endif

#endif
