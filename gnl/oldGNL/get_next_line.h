#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <ctype.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
//utils
size_t	ft_strlen(const char *str);
void	*ft_memset(void *buf, int ch, size_t n);
void	*ft_calloc(size_t num, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcat(char *dest, const char *src, size_t size);

//gnl
char	*ft_gnljoin(char const *s1, char const *s2, int check);
char	*get_newline(char *save, int fd);
char	*get_next_line(int fd);

#endif
