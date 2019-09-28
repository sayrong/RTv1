/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:08:50 by cschoen           #+#    #+#             */
/*   Updated: 2018/12/18 15:52:01 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new_str;
	char	*res;

	new_str = NULL;
	res = NULL;
	if (s == NULL)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if ((new_str = ft_strnew(ft_strlen(s))) != NULL)
	{
		ft_strcpy(new_str, s);
		new_str = ft_strrev(new_str);
		if (new_str == NULL)
			return (NULL);
		while (*new_str == ' ' || *new_str == '\n' || *new_str == '\t')
			new_str++;
		res = ft_strnew(ft_strlen(new_str));
		if (res != NULL)
		{
			ft_strcpy(res, new_str);
			res = ft_strrev(res);
		}
	}
	return (res);
}
