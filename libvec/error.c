/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 02:55:01 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/29 15:53:58 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	error(char *str)
{
	perror(str);
	exit(1);
}

void	null_error(void)
{
	write(1, "NULL pointer exception\n", 23);
	exit(1);
}
