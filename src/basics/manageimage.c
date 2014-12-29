/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manageimage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 19:42:06 by adebray           #+#    #+#             */
/*   Updated: 2014/12/28 23:19:54 by adebray          ###   ########.fr       */
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

void		imagesquare(t_image *image)
{
	int i;
	int j;
	char *img;
	int vars[3];

	img = mlx_get_data_addr(image->mlximg, &(vars[0]), &(vars[1]), &(vars[2]));
	i = 0;
	j = 0;
	while (i < vars[1])
	{
		*(int*)(img + i + (j * vars[1])) = image->color;
		i += 4;
		if (j < image->height && i >= image->width * 4)
		{
			i = 0;
			j += 1;
		}
	}
}

void		imagecircle(t_image *image)
{
	int i;
	int j;
	char *img;
	int vars[3];

	img = mlx_get_data_addr(image->mlximg, &(vars[0]), &(vars[1]), &(vars[2]));
	i = -image->radius;
	j = -image->radius;
	while (i < image->radius * 4)
	{
		if (i * i + j * j <= image->radius * image->radius + image->radius * 0.8)
			*(int*)(img + (i * 4 + (image->width * 2)) + ((j + image->height / 2) * vars[1])) = image->color;
		i += 1;
		if (j < image->radius && i >= image->radius  * 4)
		{
			i = -image->radius;
			j += 1;
		}
	}
}

t_image		*manageimage(int macro)
{
	static t_image	current;

	if (macro == GET)
		return (&current);
	else if (macro == NEW)
	{
		imagenew(&current);
		manageimagelist(ADD);
	}
	else if (macro == PUT)
		mlx_put_image_to_window(managemlx(GET), managewindow(GET),
			current.mlximg, current.x, current.y);
	else if (macro == SQR)
		imagesquare(&current);
	else if (macro == CIR)
		imagecircle(&current);
	else
		ft_printf("Useless call to manageimage\n");
	return (NULL);
}
