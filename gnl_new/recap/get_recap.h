#ifndef GET_RECAP_H
# define GET_RECAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "unistd.h"
# include "fcntl.h"
# include "stdlib.h"


/* FUNCTIONS */
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
void	*ft_memmove(void *dest, const void *src, size_t n);

#endif