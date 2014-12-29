/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manageenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 08:15:56 by adebray           #+#    #+#             */
/*   Updated: 2014/12/28 20:42:30 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>

void	manageenvnew(t_env *env)
{
	if (env->argc < 2 || env->argc > 3)
		env->ch = '?';
	else
	{
		if (!ft_strcmp(env->format, "!file"))
		{
			env->ch = '!';
			env->str = env->argv[1];
		}
	}
}

t_env	*manageenv(int macro)
{
	static t_env	env;

	if (macro == GET)
		return (&env);
	else if (macro == NEW)
		manageenvnew(&env);
	else if (macro == PRINT)
	{
		ft_printf("%d\n", env.argc);
		ft_printf("%p\n", env.argv);
		ft_printf("%s\n", env.format);
		ft_printf("%d\n", env.ch);
		ft_printf("%s\n", env.str);
	}
	else
		ft_printf("Useless call to manageenv\n");
	return (NULL);
}
