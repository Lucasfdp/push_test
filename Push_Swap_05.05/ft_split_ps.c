#include "push_swap.h"

size_t	ft_count_subs_ps(const char *s, char c)
{
	size_t	num_subs;

	num_subs = 0;
	while (*s)
	{
		if (*s != c)
		{
			num_subs++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (num_subs);
}

void	ft_free_all_ps(char **result, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (result[i])
			free(result[i]);
		i++;
	}
	free(result);
}

char	**dosplit_ps(const char *s, char c, char **result)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				s++;
			result[i] = ft_substr(s - len, 0, len);
			if (!result)
			{
				ft_free_all_ps(result, i);
				return (0);
			}
			i++;
		}
		else
			s++;
	}
	result[i] = 0;
	return (result);
}

char	**ft_split_ps(const char *s, char c)
{
	char	**result;

	if (!s)
		return (0);
	result = malloc(sizeof(char *) * (ft_count_subs_ps(s, c) + 1));
	if (!result)
		return (0);
	result = dosplit_ps(s, c, result);
	return (result);
}