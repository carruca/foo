#include "libft.h"

static size_t	ft_word_count(char const *s, char c)
{
	int		i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			cont++;
			while (s[i] != c)
				i++;
		}
	}
	return (count);
}

static size_t	ft_strnlen(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != c)
	{
		count++;
		s++;
	}
	return (count);
}

static 

char			**ft_split(char const *s, char c)
{
	char	**table;
	int		word;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	word = 0;
	i = 0;
	if (!(table = malloc(sizeof(char*) * (ft_word_count(s, c) + 1))))
		return (NULL);
	while (word < ft_word_count(s, c))
	{
		if (!(table = malloc(sizeof(char) * (ft_strnlen(&s[i], c) + 1))))
			return (NULL);
		j = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			table[word][j++] = s[i];
		table[word++][j] = '\0';
	}
	table[word] = NULL;
	return (table);
}
