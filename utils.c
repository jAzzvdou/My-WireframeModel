/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 01:46:58 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/11 19:06:53 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	nb;
	int	mult;

	nb = 0;
	mult = 1;
	while ((*nptr > 8 && *nptr < 14) || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
		mult = -mult;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = (nb * 10) + (*nptr - '0');
		nptr++;
	}
	return (nb * mult);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = c;
	while (*s && *s != ch)
		s++;
	if (*s == ch)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*final;

	final = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!final)
		return (NULL);
	i = -1;
	while (s[++i])
		final[i] = s[i];
	final[i] = '\0';
	return (final);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*new_s;

	if (!s1 && !s2)
		return (NULL);
	new_s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_s)
		return (NULL);
	i = 0;
	while (s1 && *s1)
		new_s[i++] = *s1++;
	while (s2 && *s2)
		new_s[i++] = *s2++;
	new_s[i] = '\0';
	return (new_s);
}
