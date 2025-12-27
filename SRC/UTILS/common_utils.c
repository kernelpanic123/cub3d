/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:23:37 by abtouait          #+#    #+#             */
/*   Updated: 2025/12/26 11:49:42 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	strlen_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

static int	nbr_mots(char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char *s, char c)
{
	char	**new_str;
	size_t	i;
	size_t	j;
	size_t	wordcount;
	size_t	wordlen;

	wordcount = nbr_mots(s, c);
	new_str = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < wordcount)
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		wordlen = 0;
		while (s[j + wordlen] != '\0' && s[j + wordlen] != c)
			wordlen++;
		new_str[i] = ft_substr(s, j, wordlen);
		i++;
		j = j + wordlen;
	}
	new_str[i] = NULL;
	return (new_str);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*str;
	int		i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*byte;
	size_t			i;

	byte = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		byte[i] = c;
		i++;
	}
	return (s);
}
