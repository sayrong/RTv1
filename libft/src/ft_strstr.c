/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 21:15:27 by cschoen           #+#    #+#             */
/*   Updated: 2018/12/31 15:10:03 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	len_haystack;
	size_t	len_needle;
	size_t	i;

	i = 0;
	len_haystack = ft_strlen(haystack);
	len_needle = ft_strlen(needle);
	while (i + len_needle <= len_haystack)
	{
		if (ft_strncmp(haystack, needle, len_needle) == 0)
			return ((char *)haystack);
		i++;
		haystack++;
	}
	return (NULL);
}
