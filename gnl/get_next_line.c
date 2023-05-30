#include "get_next_line.h"

char	*ft_gnljoin(char const *s1, char const *s2, int check)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL)
		s1_len = 0;
	else
		s1_len = ft_strlen(s1);
	if (s2 == NULL)
		check = 0;
	if (s1_len == 0 && check == 0)
		return (NULL);
	result = ft_calloc(s1_len + check + 1, 1);
	if (result == NULL)
		return (NULL);
	ft_strlcat(result, (char *)s1, s1_len + 1);
	ft_strlcat(result, (char *)s2, s1_len + check + 1);
	return (result);
}

char *get_newline(save, fd)
{
    char buf[BUFFER_SIZE + 1];
    long check;

    while (1)
    {
        check = read(fd, buf, BUFFER_SIZE);
        if (check == -1)
            retutn (NULL);
        tmp = save;
        save = ft_gnljoin(tmp, buf, check); 
        free(tmp);
        if (save == NULL)
            return (NULL);
        if (check != BUFFER_SIZE || ft_strchr(save, '\n') != NULL)
            break;
    }
    return (save);
}

char *get_next_line(int fd)
{
    static char *save;
    char *tmp;

    save = get_newline(save, fd);
    if (ft_strchr(save, '\n'))
    {
        return (save);
    }
    tmp = save;
    newline = ft_substr(tmp, 0, ft_strchr(tmp, '\n') - tmp);
    save = ft_substr(tmp, ft_strchr(tmp, '\n') - tmp, ft_strlen(tmp)); 
    free(tmp);
    return (newline);
}