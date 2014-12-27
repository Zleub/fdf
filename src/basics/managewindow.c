/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managewindow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 04:14:12 by adebray           #+#    #+#             */
/*   Updated: 2014/12/27 17:33:11 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <basics.h>

t_win	*newwindow(int macro, int this_int)
{
	char		*name;
	static int	cmp;
	static int	width;
	static int	height;
	void		*window;

	if (macro == WIDTH)
		width = this_int;
	else if (macro == HEIGHT)
		height = this_int;
	if (width == 0)
		width = 640;
	if (height == 0)
		height = 480;
	name = ft_itoa(cmp);
	window = mlx_new_window(managemlx(GET), width, height, name);
	free(name);
	cmp += 1;
	return (window);
}

t_win	*managewindow(int macro)
{
	static t_win	*current;

	if (macro == NEW)
	{
		current = newwindow(0, 0);
		managewindowlist(ADD);
	}
	else if (macro == GET)
		return (current);
	else
		ft_printf("Useless call to managewindow\n");
	return (NULL);
}
