/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imagedraw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 11:04:18 by adebray           #+#    #+#             */
/*   Updated: 2015/01/01 08:33:12 by adebray          ###   ########.fr       */
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

int		imageline(t_image *image)
{
	int		diagonal = 0;

	if (image->xto != 0)
		image->width = image->xto - image->x;
	if (image->yto != 0)
		image->height = image->yto - image->y;
	if (image->width < 0 && image->height < 0)
	{
		diagonal = 1;
		image->x = image->xto;
		image->y = image->yto;
	}
	else if (image->width < 0 && image->height > 0)
	{
		diagonal = 2;
		image->x = image->xto;
	}
	else if (image->width > 0 && image->height < 0)
	{
		diagonal = 3;
		image->y = image->yto;
	}
	else if (image->width > 0 && image->height > 0)
		diagonal = 4;
	else
		ft_printf("pixel ?? horizontal && vertical\n");
	image->width = ft_abs(image->width);
	image->height = ft_abs(image->height);
	return (diagonal);
}

void		longnormaldiagonal(t_image *image)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	*img;
	int		vars[5];

	ft_printf("long diagonal\n");
	img = mlx_get_data_addr(image->mlximg, &(vars[0]), &(vars[1]), &(vars[2]));
	i = 0;
	j = 0;
	k = 0;
	l = 0;
	vars[3] = image->width / image->height;
	vars[4] = image->width % image->height;
	ft_printf("w:%d | h:%d %d::%d\n", image->width, image->height, vars[3], vars[4]);
	while (i < vars[1])
	{
		*(int*)(img + i + (j * vars[1])) = image->color;
		i += 4;
		k += 1;
		l += vars[4];
		if (l >= image->width)
		{
			k -= 1;
			l -= image->width;
		}
		if (k >= vars[3])
		{
			k = 0;
			j += 1;
		}
	}
}

void		highnormaldiagonal(t_image *image)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	*img;
	int		vars[5];

	ft_printf("high diagonal\n");
	img = mlx_get_data_addr(image->mlximg, &(vars[0]), &(vars[1]), &(vars[2]));
	i = 0;
	j = 0;
	k = 0;
	l = 0;
	vars[3] = image->height / image->width;
	vars[4] = image->height % image->width;
	ft_printf("w:%d | h:%d %d::%d\n", image->width, image->height, vars[3], vars[4]);
	while (i < vars[1])
	{
		*(int*)(img + i + (j * vars[1])) = image->color;
		k += 1;
		j += 1;
		l += vars[4];
		if (l >= image->height)
		{
			k -= 1;
			l -= image->height;
		}
		if (k >= vars[3])
		{
			k = 0;
			i += 4;
		}
	}

}

void		longinvertdiagonal(t_image *image)
{
	ft_printf("long invert diagonal\n");
	int		i;
	int		j;
	int		k;
	int		l;
	char	*img;
	int		vars[5];

	img = mlx_get_data_addr(image->mlximg, &(vars[0]), &(vars[1]), &(vars[2]));
	i = vars[1] - 4;
	j = 0;
	k = 0;
	l = 0;
	vars[3] = image->width / image->height;
	vars[4] = image->width % image->height;
	// *(int*)(img + i + (j * vars[1])) = image->color;
	while (i >= 0)
	{
		*(int*)(img + i + (j * vars[1])) = image->color;
		k += 1;
		l += vars[4];
		i -= 4;
		if (l >= image->width)
		{
			k -= 1;
			l -= image->width;
		}
		if (k >= vars[3])
		{
			k = 0;
			j += 1;
		}
	}
}

void		highinvertdiagonal(t_image *image)
{
	ft_printf("high invert diagonal\n");
	int		i;
	int		j;
	int		k;
	int		l;
	char	*img;
	int		vars[5];

	img = mlx_get_data_addr(image->mlximg, &(vars[0]), &(vars[1]), &(vars[2]));
	i = vars[1] - 4;
	j = 0;
	k = 0;
	l = 0;
	vars[3] = image->height / image->width;
	vars[4] = image->height % image->width;
	ft_printf("w:%d | h:%d %d::%d\n", image->width, image->height, vars[3], vars[4]);
	*(int*)(img + i + (j * vars[1])) = image->color;
	while (i >= 0)
	{
		*(int*)(img + i + (j * vars[1])) = image->color;
		k += 1;
		j += 1;
		l += vars[4];
		if (l >= image->height)
		{
			k -= 1;
			l -= image->height;
		}
		if (k >= vars[3])
		{
			k = 0;
			i -= 4;
		}
	}
}

void		imagediagonal(t_image *image, int diagonal)
{
	ft_printf("diag: %d\n", diagonal);
	if (diagonal == 1)
	{
		if (image->width >= image->height)
			longnormaldiagonal(image);
		else
			highnormaldiagonal(image);
	}
	else if (diagonal == 2)
	{
		if (image->width >= image->height)
			longinvertdiagonal(image);
		else
			highinvertdiagonal(image);
	}
	else if (diagonal == 3)
	{
		if (image->width >= image->height)
			longinvertdiagonal(image);
		else
			highinvertdiagonal(image);
	}
	else if (diagonal == 4)
	{
		if (image->width >= image->height)
			longnormaldiagonal(image);
		else
			highnormaldiagonal(image);
		// normaldiagonal(image);
	}
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
		int diagonal = imageline(current);
		ft_printf("ANANANANAN: %d\n", current->put);
		if (current->put == 0)
			manageimage(NEW);
		// manageimage(SQR);
		// current->color = current->color / 2;
		imagediagonal(current, diagonal);
	}
}
