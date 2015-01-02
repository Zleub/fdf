/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manageimage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 19:42:06 by adebray           #+#    #+#             */
/*   Updated: 2015/01/02 00:06:19 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <basics.h>

void		imagenew(t_image *image)
{
	if ((image->width <= 0) || (image->height <= 0))
	{
		ft_printf("new image too small\n");
		return ;
	}
	image->mlximg = mlx_new_image(managemlx(GET), image->width, image->height);
}

void		geometryprint(t_geometry *geometry)
{
	ft_printf("%p\n", geometry);
	ft_printf("geometry->x1: %d\n", geometry->x1);
	ft_printf("geometry->y1: %d\n", geometry->y1);
	ft_printf("geometry->x2: %d\n", geometry->x2);
	ft_printf("geometry->y2: %d\n", geometry->y2);
	ft_printf("geometry->radius: %d\n", geometry->radius);
}

void		imageprint(t_image *image)
{
	ft_printf("%p\n", image);
	ft_printf("image->color: %d\n", image->color);
	ft_printf("image->x: %d\n", image->x);
	ft_printf("image->y: %d\n", image->y);
	ft_printf("image->width: %d\n", image->width);
	ft_printf("image->height: %d\n", image->height);
	ft_printf("image->put: %d\n", image->put);
	ft_printf("image->mlximg: %p\n", image->mlximg);
	ft_printf("image->geometry: %p\n", image->geometry);
	geometryprint(&image->geometry);
}

t_image		*manageimage(int macro)
{
	static t_image	current;

	if (macro == GET)
		return (&current);
	else if (macro == PRINT)
		imageprint(&current);
	else if (macro == NEW)
	{
		imagenew(&current);
		manageimagelist(ADD);
		current.put = 1;
	}
	else if (macro == PUT)
	{
		mlx_put_image_to_window(managemlx(GET), managewindow(GET),
			current.mlximg, current.x, current.y);
		current.put = 0;
	}
	else if (macro >= -10 && macro <= -8)
		imagedraw(macro, &current);
	else
		ft_printf("Useless call to manageimage\n");
	return (NULL);
}
