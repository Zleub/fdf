/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/29 11:39:02 by adebray           #+#    #+#             */
/*   Updated: 2014/12/28 23:16:54 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASICS_H
# define BASICS_H

# include <libft.h>
# include <ft_printf.h>
# include <mlx.h>
# include <math.h>
# include <enum.h>

typedef void			t_win;

typedef struct			s_win_list
{
	t_win				*window;
	struct s_win_list	*next;
}						t_win_list;

typedef void			t_mlximg;

typedef struct			s_image
{
	int					width;
	int					height;
	int					color;
	int					x;
	int					y;
	int					radius;
	t_mlximg			*mlximg;
}						t_image;

typedef struct			s_image_list
{
	t_mlximg			*image;
	struct s_image_list	*next;
}						t_image_list;

void					*managemlx(int macro);
void					*managewindow(int macro);
void					*managewindowlist(int macro);
t_image					*manageimage(int macro);
t_image_list			*manageimagelist(int macro);

#endif
