/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/29 11:39:02 by adebray           #+#    #+#             */
/*   Updated: 2014/12/27 08:22:01 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASICS_H
# define BASICS_H

# include <libft.h>
# include <ft_printf.h>
# include <mlx.h>
# include <math.h>

# include <enum.h>

typedef void	t_win;

typedef struct			s_win_list
{
	t_win				*window;
	struct s_win_list	*next;
}						t_win_list;


void *managewindowlist(int macro);
void *managewindow(int macro);
void *managemlx(int macro);

#endif
