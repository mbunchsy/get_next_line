/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramos-j <mramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 23:33:46 by mramos-j          #+#    #+#             */
/*   Updated: 2019/12/11 17:52:55 by mramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	if (dst == '\0' && src == '\0')
		return (dst);
	while (n--)
		*str1++ = *str2++;
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	void	*dst;

	dst = malloc(ft_strlen(s1) + 1);
	if (dst == 0)
		return (0);
	return ((char *)ft_memcpy(dst, s1, (ft_strlen(s1) + 1)));
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;
	size_t	size;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	size = (ft_strlen(s + start) > len) ? len : ft_strlen(s + start);
	if (!(result = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size && *s)
	{
		result[i] = s[i + start];
		i++;
	}
	result[i] = 0;
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	size1;
	size_t	size2;
	size_t	i;

	if (!(s1 && s2))
		return (0);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!(dest = (char *)malloc(sizeof(char) * (size1 + size2 + 1))))
		return (0);
	i = 0;
	while (i < size1)
	{
		dest[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < size2)
	{
		dest[size1 + i] = s2[i];
		i++;
	}
	dest[size1 + size2] = 0;
	return (dest);
}
