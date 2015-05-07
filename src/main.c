/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 14:43:26 by adebray           #+#    #+#             */
/*   Updated: 2015/05/07 08:41:46 by adebray          ###   ########.fr       */
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

int		isPos(int i)
{
	return (i > 0);
}

void		normalLine(int x1, int y1, int x2, int y2)
{
	printf("%d, %d, %d, %d\n", x1, y1, x2, y2);
	printf("%d, %d\n", (x2 - x1), (y2 - y1));
	int		inc = (x2 - x1) / (y2 - y1);
	printf("inc: %d\n", inc);
	int		i = x1;
	int		j = y1;

	while (i < x2)
	{
		mlx_pixel_put(managemlx(GET), managewindow(GET), i, j , 0x44ee77);
		if (i % inc == 0)
		{
			j += 1;
		}
		i += 1;
		printf("%d:%d\n", i, j);
	}
}

void		drawLine(int x1, int y1, int x2, int y2)
{
	ft_printf("drawLine\n");
	ft_printf("%d, %d, %d, %d\n", x1, y1, x2, y2);
	ft_printf("x_vector: %d, y_vector: %d\n", x2 - x1, y2 - y1);

	int x_vector = x2 - x1;
	int y_vector = y2 - y1;

	// int coeff = x_vector / y_vector;
	// int rest = x_vector % y_vector;

	ft_printf("x_vector / y_vector : %d\n", x_vector / y_vector);
	ft_printf("x_vector %% y_vector : %d\n", x_vector % y_vector);
	ft_printf("y_vector / x_vector : %d\n", y_vector / x_vector);
	ft_printf("y_vector %% x_vector : %d\n", y_vector % x_vector);

	mlx_pixel_put(managemlx(GET), managewindow(GET), x1 , y1 , 0x44ee77);
	mlx_pixel_put(managemlx(GET), managewindow(GET), x2 , y2 , 0x4477ee);

	if (x_vector > y_vector)
	{
		// ft_printf("x_vector / y_vector : %d\n", x_vector / y_vector);
		printf("x_vector > y_vector\n");
		if (x1 <= x2)
		{
			printf("x1 <= x2 && y1 <= y2\n");
			normalLine(x1, y1, x2, y2);
		}
		else
		{
			printf("else\n");
			normalLine(x2, y2, x1, y1);
		}
	}
	else
	{
			printf("y_vector > x_vector\n");
		// ft_printf("y_vector / x_vector : %d\n", y_vector / x_vector);
		// normalLine(y1, x1, y2, x2);
	}


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

	// managefile(PRINT);
	// manageimagelist(PRINT);

	// [x1, y1 ; x2, y2]
	// [ 0 ,  0; 10, 10]
	// [ 10, 10;  0,  0]
	// [ 10, 0 ; 10,  0]

	// int i = 0;
	// int j = 0;

	drawLine(100, 100, 200, 120);
	drawLine(100, 100, 120, 200);
	// drawLine(35, 50, 100, 100);
	// drawLine(50, 35, 100, 100);
	drawLine(100, 100, 35, 50);
	drawLine(100, 100, 50, 35);

	mlx_loop(managemlx(GET));
	return (0);
}
