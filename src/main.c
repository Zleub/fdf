/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 14:43:26 by adebray           #+#    #+#             */
/*   Updated: 2015/04/23 22:01:52 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <env.h>
#include <basics.h>

#include <stdio.h>

void		ft_getfile(int fd)
{
	while (get_next_line(fd, (char**)managefile(SET)) > 0)
		managefile(ADD);
}

int			ft_getopt(int argc, char **argv)
{
	int		fd;
	t_env	*env;

	env = manageenv(GET);
	env->format = "!file";
	env->argc = argc;
	env->argv = argv;
	manageenv(NEW);
	if (env->ch == '?')
	{
		ft_printf("USAGE PUTE\n");
		return (-1);
	}
	else
	{
		if ((fd = open(env->str, O_RDONLY)) == -1)
		{
			ft_printf("USAGE PUTE\n");
			return (-1);
		}
		else
			ft_getfile(fd);
	}
	return (0);
}

int		key_hook(int keycode, void *param)
{
	(void)param;
	printf("-> %d\n", keycode);
	if (keycode == 53)
		exit(-1);
	return (0);
}

void		drawLine(int x1, int y1, int x2, int y2)
{
	ft_printf("drawLine\n");
	ft_printf("%d, %d, %d, %d\n", x1, y1, x2, y2);
	ft_printf("%d, %d\n", x2 - x1, y2 - y1);

	int x_vector = x2 - x1;
	int y_vector = y2 - y1;

	// int coeff = x_vector / y_vector;
	// int rest = x_vector % y_vector;

	ft_printf("x_vector / y_vector : %d\n", x_vector / y_vector);
	ft_printf("x_vector %% y_vector : %d\n", x_vector % y_vector);
	ft_printf("y_vector / x_vector : %d\n", y_vector / x_vector);
	ft_printf("y_vector %% x_vector : %d\n", y_vector % x_vector);

	// int tmp;
	// while (y_vector)
	// {
	// 	tmp = coeff;
	// 	if (x_vector)
	// 	{
	// 		mlx_pixel_put(managemlx(GET), managewindow(GET), x1 + x_vector, y1 + y_vector, 0xee4477);
	// 		tmp -= 1;
	// 		x_vector -= 1;
	// 	}
	// 	y_vector -= 1;
	// }

	mlx_pixel_put(managemlx(GET), managewindow(GET), x1 , y1 , 0x44ee77);
	mlx_pixel_put(managemlx(GET), managewindow(GET), x2 , y2 , 0x44ee77);

}

int			main(int argc, char **argv)
{
	// t_image *image;

	if (ft_getopt(argc, argv) == -1)
		return (0);
	if (!(managemlx(NEW)))
		return (0);
	managewindow(NEW);

	mlx_key_hook(managewindow(GET),key_hook, NULL);

	managefile(PRINT);
	// manageimagelist(PRINT);

	// [x1, y1 ; x2, y2]
	// [ 0,  0 ; 10, 10]
	// [ 10, 10 ; 0,  0]
	// [ 10, 0 ; 10,  0]

	// int i = 0;
	// int j = 0;

	drawLine(100, 100, 200, 120);
	drawLine(100, 100, 120, 200);
	drawLine(35, 50, 100, 100);
	drawLine(50, 35, 100, 100);

	mlx_loop(managemlx(GET));
	return (0);
}
