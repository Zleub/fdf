/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawdiagonals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/01 23:45:42 by adebray           #+#    #+#             */
/*   Updated: 2015/01/01 23:46:16 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <basics.h>

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
