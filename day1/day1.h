
#ifndef DAY1_H
# define DAY1_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_list
{
	int				data;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

// get_next_line
char	*get_next_line(int fd);
size_t	ft_len(const char *s);
char	*ft_strchr(const char *s, int c);
void	ft_copy(char *dst, const char *src, size_t size);
void	ft_strlcat(char *dst, const char *src, size_t size);
int		free_all(char **ptr, char **result);

// Lists
t_list	*ft_lstnew(int data);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstlast_circular(t_list *lst);

int	ft_atoi(const char *nptr);


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# if BUFFER_SIZE <=0
#  error BUFFER SIZE invalid
# endif

#endif
