/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imagedraw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 11:04:18 by adebray           #+#    #+#             */
/*   Updated: 2014/12/30 11:57:42 by adebray          ###   ########.fr       */
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

void		imagecircle(t_image *image)
{
	int		i;
	int		j;
	char	*img;
	int		vars[3];

	img = mlx_get_data_addr(image->mlximg, &(vars[0]), &(vars[1]), &(vars[2]));
	i = -image->radius;
	j = -image->radius;
	while (i < image->radius * 4)
	{
		if (i * i + j * j <= image->radius * image->radius + image->radius)
			*(int*)(img + (i * 4 + (image->width * 2))
			+ ((j + image->height / 2) * vars[1])) = image->color;
		i += 1;
		if (j < image->radius && i >= image->radius * 4)
		{
			i = -image->radius;
			j += 1;
		}
	}
}

void		imageline(t_image *image)
{
	if (image->xto != 0)
		image->width = image->xto - image->x;
	if (image->yto != 0)
		image->height = image->yto - image->y;
	if (image->width < 0 && image->height < 0)
	{
		ft_printf("left top\n");
		image->x = image->xto;
		image->y = image->yto;
	}
	else if (image->width < 0 && image->height > 0)
	{
		ft_printf("left down\n");
		image->x = image->xto;
	}
	else if (image->width > 0 && image->height < 0)
	{
		ft_printf("left down\n");
		image->y = image->yto;
	}
	else if (image->width > 0 && image->height > 0)
		ft_printf("right down\n");
	else
		ft_printf("pixel ?? horizontal && vertical\n");
	image->width = ft_abs(image->width);
	image->height = ft_abs(image->height);
}

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
	else if (macro == LIN)
	{
		imageline(current);
		if (current->put == 0)
			manageimage(NEW);
		// manageimage(SQR);
	}
}
