/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 02:42:24 by adebray           #+#    #+#             */
/*   Updated: 2014/12/27 17:06:17 by adebray          ###   ########.fr       */
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

int		ft_getopt(int argc, char **argv)
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
			return (-1);
		else
			ft_getfile(fd);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	ft_getopt(argc, argv);
	managefile(PRINT);
	managemlx(NEW);
	managewindow(NEW);
	mlx_loop(managemlx(GET));
	return (0);
}
