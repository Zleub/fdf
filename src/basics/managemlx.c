/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managemlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 04:07:28 by adebray           #+#    #+#             */
/*   Updated: 2014/12/27 04:39:25 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <basics.h>

void	*managemlx(int macro)
{
	static void	*current;

	if (macro == NEW)
	{
		if (!(current = mlx_init()))
			ft_printf("mlx init failed\n");
	}
	else if (macro == GET)
		return (current);
	else
		ft_printf("Useless call to managemlx\n");
	return (NULL);
}
