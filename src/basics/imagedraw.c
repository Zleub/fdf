/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imagedraw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 11:04:18 by adebray           #+#    #+#             */
/*   Updated: 2015/01/02 00:02:25 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <basics.h>

void		imagesquare(t_image *image)
{
	int		i;
	int		j;
	char	*img;
	int		vars[3];

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

void		imageprint(t_image *image);


void		imagecircle(t_image *image)
{
	int		i;
	int		j;
	char	*img;
	int		vars[3];

	imageprint(image);

	img = mlx_get_data_addr(image->mlximg, &(vars[0]), &(vars[1]), &(vars[2]));
	i = -image->geometry.radius;
	j = -image->geometry.radius;
	while (i < image->geometry.radius * 4)
	{
		if (i * i + j * j <= image->geometry.radius * image->geometry.radius + image->geometry.radius)
			*(int*)(img + (i * 4 + (image->width * 2))
			+ ((j + image->height / 2) * vars[1])) = image->color;
		i += 1;
		if (j < image->geometry.radius && i >= image->geometry.radius * 4)
		{
			i = -image->geometry.radius;
			j += 1;
		}
	}
}

// int		imageline(t_image *image)
// {
// 	int		diagonal = 0;

// 	if (image->xto != 0)
// 		image->width = image->xto - image->x;
// 	if (image->yto != 0)
// 		image->height = image->yto - image->y;
// 	if (image->width < 0 && image->height < 0)
// 	{
// 		diagonal = 1;
// 		image->x = image->xto;
// 		image->y = image->yto;
// 	}
// 	else if (image->width < 0 && image->height > 0)
// 	{
// 		diagonal = 2;
// 		image->x = image->xto;
// 	}
// 	else if (image->width > 0 && image->height < 0)
// 	{
// 		diagonal = 3;
// 		image->y = image->yto;
// 	}
// 	else if (image->width > 0 && image->height > 0)
// 		diagonal = 4;
// 	else
// 		ft_printf("pixel ?? horizontal && vertical\n");
// 	image->width = ft_abs(image->width);
// 	image->height = ft_abs(image->height);
// 	return (diagonal);
// }

void		imagedraw(int macro, t_image *current)
{
	if (macro == SQR)
	{
		if (current->put == 0)
			manageimage(NEW);
		imagesquare(current);
	}
	else if (macro == CIR)
	{
		if (current->put == 0)
			manageimage(NEW);
		imagecircle(current);
	}
	// else if (macro == LIN)
	// {
	// 	int diagonal = imageline(current);
	// 	ft_printf("ANANANANAN: %d\n", current->put);
	// 	if (current->put == 0)
	// 		manageimage(NEW);
	// 	// manageimage(SQR);
	// 	// current->color = current->color / 2;
	// 	imagediagonal(current, diagonal);
	// }
}
