#include "minishell.h"

static size_t		ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

static size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			index;

	index = 0;
	if (!dst || !src)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while ((index < dstsize - 1) && src[index])
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (ft_strlen(src));
}

static char			**ft_free(char **array)
{
	size_t			idx;

	idx = 0;
	while (array[idx])
	{
		free(array[idx]);
		idx++;
	}
	free(array);
	return (NULL);
}

static size_t		ft_s_l(const char *str, char c)
{
	size_t			idx;
	size_t			ret;

	idx = 0;
	ret = 1;
	if (!*str)
		return (0);
	while (str[idx] == c)
		idx++;
	while (str[idx])
	{
		if ((str[idx] == c) && str[idx - 1] != c)
			ret++;
		idx++;
	}
	return (ret);
}

static size_t		ft_wordlen(const char *str, char c)
{
	size_t			idx;

	idx = 0;
	while (str[idx] != c && str[idx])
		idx++;
	return (idx);
}

char				**ft_split(const char *s, char c)
{
	char			**ret;
	size_t			idx;
	size_t			w_l;
	size_t			str_len;

	idx = 0;
	str_len = 0;
	if (!s || !(ret = (char **)malloc(sizeof(char *) * (ft_s_l(s, c) + 1))))
		return (NULL);
	while (s[idx])
	{
		if (s[idx] != c)
		{
			w_l = ft_wordlen(s + idx, c);
			if (!(ret[str_len] = (char *)malloc(w_l + 1)))
				return (ft_free(ret));
			ft_strlcpy(ret[str_len], &s[idx], w_l + 1);
			str_len++;
			idx = idx + w_l;
		}
		while (s[idx] && s[idx] == c)
			idx++;
	}
	ret[str_len] = NULL;
	return (ret);
}

