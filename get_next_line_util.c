#include "get_next_line.h"

int	found_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0)
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((!dest) && (!src))
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	s1_len;
	int	s2_len;
	char	*dst;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dst = (char *)malloc(s1_len + s2_len + 1);
	if (!dst)
		return (NULL);
	ft_memcpy(dst, s1, s1_len + 1);
	ft_memcpy(dst + s1_len, s2, s2_len + 1);
	return (dst);
}