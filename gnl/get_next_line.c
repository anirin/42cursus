char *get_newline(save, fd)
{
    char buf[BUFFER_SIZE + 1];
    long check;

    while (1)
    {
        check = read(fd, buf, BUFFER_SIZE);
        if (check != BUFFER_SIZE || ft_strchr(save, '\n'))
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