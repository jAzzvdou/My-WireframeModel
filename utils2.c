#include "fdf.h"

int	nmax(int x, int y)
{
	if (x >= y)
		return (x);
	return (y);
}

char	*my_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_size;
	char	*new_s;

	s_size = my_strlen(s);
	if ((size_t)start > s_size)
		return (my_strdup(""));
	s += start;
	s_size -= start;
	if (s_size > len)
		s_size = len;
	new_s = malloc(sizeof(char) * (s_size + 1));
	if (new_s == NULL)
		return (NULL);
	i = -1;
	while (++i < s_size)
		new_s[i] = s[i];
	new_s[i] = '\0';
	return (new_s);
}

static size_t	sub_str(char const *s, char c)
{
	size_t	length;

	length = 0;
	while (*s)
	{
		if (*s != c)
			length++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (length);
}

static void	free_split(char **final)
{
	size_t	i;

	i = -1;
	while (final[++i])
		free(final[i]);
	free(final);
}

char	**my_split(char const *s, char c)
{
	size_t	i;
	size_t	words;
	size_t	wordsize;
	char	**final;

	if (s == NULL)
		return (NULL);
	words = sub_str(s, c);
	final = malloc(sizeof(char *) * (words + 1));
	if (final == NULL)
		return (NULL);
	i = -1;
	while (++i < words)
	{
		while (*s == c)
			s++;
		wordsize = 0;
		while (s[wordsize] && s[wordsize] != c)
			wordsize++;
		final[i] = my_substr(s, 0, wordsize);
		if (final[i] == NULL)
			return (free_split(final), NULL);
		s += wordsize;
	}
	return (final[i] = NULL, final);
}
