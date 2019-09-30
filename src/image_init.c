/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:46:12 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/30 02:55:17 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_img	*img_new(int width, int height)
{
	t_img	*new_img;

	if (!(new_img = (t_img*)malloc(sizeof(t_img))))
		error("img_new: ");
//TODO
	return (new_img);
}
