/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 14:43:26 by adebray           #+#    #+#             */
/*   Updated: 2015/01/01 08:32:33 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <env.h>
#include <basics.h>

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

int			main(int argc, char **argv)
{
	t_image *image;

	if (ft_getopt(argc, argv) == -1)
		return (0);
	if (!(managemlx(NEW)))
		return (0);
	managewindow(NEW);

	image = manageimage(GET);
	// image->width = 640;
	// image->height = 480;
	// manageimage(NEW);

	image->x = 100;
	image->y = 250;
	image->xto = 20;
	image->yto = 400;
	image->color = 0xff0000;
	manageimage(LIN);
	manageimage(PUT);

	image->y = 100;
	image->x = 250;
	image->yto = 20;
	image->xto = 400;
	image->color = 0x0000ff;
	manageimage(LIN);
	manageimage(PUT);

	image->x = 200;
	image->y = 210;
	image->xto = 201;
	image->yto = 300;
	image->color = 0x00ff00;
	manageimage(LIN);
	manageimage(PUT);

	image->x = 300;
	image->y = 100;
	image->xto = 500;
	image->yto = 250;
	image->color = 0xffffff;
	manageimage(LIN);
	manageimage(PUT);

	// t_file *file = managefile(GET);
	// int i;
	// while (file)
	// {
	// 	i = 0;
	// 	while (file->str[i])
	// 	{
	// 		while (ft_isspace(file->str[i]))
	// 			i += 1;
	// 		ft_printf("%d\n", ft_atoi(&file->str[i]));
	// 		mlx_pixel_put(managemlx(GET), manageimage(GET), 10, 10, 0xff0000);
	// 		i += 1;
	// 	}
	// 	file = file->next;
	// }
	// manageimage(PUT);

	manageimagelist(PRINT);
	mlx_loop(managemlx(GET));
	return (0);
}
