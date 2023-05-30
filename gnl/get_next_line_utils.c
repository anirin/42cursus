#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;

	if (str == NULL)
		return (0); //add
	n = 0;
	while (*str != 0)
	{
		n++;
		str++;
	}
	return (n);
}

void	*ft_memset(void *buf, int ch, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = buf;
	i = 0;
	while (i < n)
	{
		*p++ = (unsigned char)ch;
		i++;
	}
	return (buf);
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*ret;

	if (size != 0 && num > SIZE_MAX / size)
		return (NULL);
	ret = malloc(num * size);
	if (ret == NULL)
		return (NULL);
	ft_memset(ret, 0, num * size);
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (len <= ft_strlen(s))
		substr = ft_calloc(len + 1, 1);
	else
		substr = ft_calloc(ft_strlen(s) + 1, 1);
	if (substr == NULL)
		return (NULL);
	while (len-- && s[i + start] != '\0')
	{
		substr[i] = s[i + start];
		i++;
	}
	return (substr);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	n;

	if (dest == NULL && size == 0)
		return (ft_strlen(src));
	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (size <= d_len)
		return (size + s_len);
	n = size - d_len;
	dest += d_len;
	while (n--)
	{
		if (*src == '\0' || n == 0)
			break ;
		*dest++ = *src++;
	}
	*dest = '\0';
	return (s_len + d_len);
}
