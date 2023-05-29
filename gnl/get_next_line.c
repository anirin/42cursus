char *get_newline(save, fd)
{
    char *buf;
    long check;

    while (1)
    {
        buf = ft_calloc(BUFFER_SIZE + 1);
        if (buf == NULL)
            return (NULL);
        check = read(fd, buf, BUFFER_SIZE);
        if (check == -1)
        {
            retutn (NULL);
        }
        tmp = save;
        save = ft_strjoin(tmp, buf); 
        free(tmp);
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
    if (strchr(save, '\n'))
    {
        return (save);
    }
    tmp = save;
    newline = ft_substr(tmp, 0, strchr(tmp, '\n') - tmp);
    save = ft_substr(tmp, strchr(tmp, '\n') - tmp, ft_strlen(tmp)); 
    free(tmp);
    return (newline);
}