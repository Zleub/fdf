/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 08:15:08 by adebray           #+#    #+#             */
/*   Updated: 2014/12/27 17:30:57 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <enum.h>
# include <ft_printf.h>
# include <libft.h>

/*
** CLASSIC OPTGET STRING FORMAT: "x:y:" | "abc:"
*/

/*
** SPECIAL FORMAT "!file" expect a single filename, caught by env.ch == '!'
*/

typedef struct	s_env
{
	int			argc;
	char		**argv;
	char		*format;
	char		ch;
	char		*str;
}				t_env;

t_env			*manageenv(int macro);

typedef struct	s_file
{
	char		*str;
	void		*next;
}				t_file;

void			*managefile(int macro);

#endif
