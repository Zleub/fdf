/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managewindowlist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 07:16:24 by adebray           #+#    #+#             */
/*   Updated: 2014/12/27 17:34:32 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <basics.h>

t_win_list				*windowlistnew(t_win *window)
{
	t_win_list	*new;

	if (!(new = (t_win_list*)malloc(sizeof(t_win_list))))
		return (NULL);
	new->window = window;
	new->next = NULL;
	return (new);
}

t_win_list				*windowlistadd(t_win_list *head, t_win *window)
{
	t_win_list			*tmp;

	if (head == NULL)
		head = windowlistnew(window);
	else
	{
		tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = windowlistnew(window);
	}
	return (head);
}

void					windowlistprint(t_win_list *head)
{
	if (head)
	{
		ft_printf("head: %p\n", head);
		ft_printf("\thead->window: %p\n", head->window);
		ft_printf("\thead->next: %p\n", head->next);
		windowlistprint(head->next);
	}
}

void					*managewindowlist(int macro)
{
	static t_win_list	*head;

	if (macro == ADD)
		head = windowlistadd(head, managewindow(GET));
	else if (macro == GET)
		return (head);
	else if (macro == PRINT)
		windowlistprint(head);
	else
		ft_printf("Useless call to managewindowlist\n");
	return (NULL);
}
