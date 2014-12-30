/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manageimage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 19:42:06 by adebray           #+#    #+#             */
/*   Updated: 2014/12/30 11:04:27 by adebray          ###   ########.fr       */
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

void		imageprint(t_image image)
{
	ft_printf("%p\n", image);
	ft_printf("image.color: %d\n", image.color);
	ft_printf("image.width: %d\n", image.width);
	ft_printf("image.height: %d\n", image.height);
	ft_printf("image.x: %d\n", image.x);
	ft_printf("image.y: %d\n", image.y);
	ft_printf("image.xto: %d\n", image.xto);
	ft_printf("image.yto: %d\n", image.yto);
	ft_printf("image.radius: %d\n", image.radius);
}

t_image		*manageimage(int macro)
{
	static t_image	current;

	if (macro == GET)
		return (&current);
	else if (macro == PRINT)
		imageprint(current);
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
