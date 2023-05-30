#include "get_next_line.h"

char	*ft_gnljoin(char const *s1, char const *s2, int check)
{
	char	*result;
	size_t	s1_len;

	if (s1 == NULL)
    {
        s1 = ft_calloc(1, 1);
        if (s1 == NULL)
            return (NULL);
    }
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

char *get_newline(char *save, int fd)
{
    char buf[BUFFER_SIZE + 1];
    long check;
    char *tmp;

    check = 0;
    while (1)
    {
        if (save == NULL || strchr(save, '\n') == NULL)
        {
            check = read(fd, buf, BUFFER_SIZE);
            //printf("check=%ld, buf=%s, save=%s\n",check, buf, save);
            if (check == -1)
                return (NULL);
            buf[check] = '\0';
            tmp = save;
            save = ft_gnljoin(tmp, buf, check); 
            free(tmp);
            if (save == NULL)
                return (NULL);
        }
        if (check != BUFFER_SIZE || ft_strchr(save, '\n') != NULL)
            break;
    }
    return (save);
}

char *get_next_line(int fd)
{
    static char *save;
    char *tmp;
    char *newline;

    save = get_newline(save, fd);
    if (save == NULL)
        return (NULL);
    if (ft_strchr(save, '\n') == NULL) //file end
    {
        newline = ft_substr(save, 0, ft_strlen(save));
        free(save);
        save = NULL;
        return (newline);
    }
    tmp = save;
    newline = ft_substr(tmp, 0, ft_strchr(tmp, '\n') - tmp);
    save = ft_substr(tmp, ft_strchr(tmp, '\n') - tmp + 1, ft_strlen(tmp)); 
    free(tmp);
    return (newline);
}