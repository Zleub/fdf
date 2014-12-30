/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 14:43:26 by adebray           #+#    #+#             */
/*   Updated: 2014/12/30 11:56:18 by adebray          ###   ########.fr       */
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
	image->color = 0xff0000;
	image->width = 500;
	image->height = 500;
	image->radius = 250;
	image->x = 0;
	manageimage(CIR);
	manageimage(PUT);

	image->x = 100;
	image->y = 100;
	image->width = 100;
	image->height = 100;
	image->color = 0x00ffee;
	manageimage(SQR);
	image->color = 0xeeff00;
	image->radius = 25;
	manageimage(CIR);
	manageimage(PUT);

	image->x = 300;
	image->y = 100;
	image->xto = 50;
	image->yto = 250;
	image->color = 0xeeffee;
	manageimage(LIN);
	manageimage(PUT);

	manageimagelist(PRINT);
	mlx_loop(managemlx(GET));
	return (0);
}
