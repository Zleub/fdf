/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/29 11:39:02 by adebray           #+#    #+#             */
/*   Updated: 2014/12/28 17:12:51 by Arno             ###   ########.fr       */
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

typedef struct			s_image_list
{
	void				*image;
	struct s_image_list	*next;
}						t_image_list;

void					*managemlx(int macro);
void					*managewindow(int macro);
void					*managewindowlist(int macro);
void					*manageimagelist(int macro);

#endif
