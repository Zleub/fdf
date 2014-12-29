/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manageimagelist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 19:27:44 by adebray           #+#    #+#             */
/*   Updated: 2014/12/28 23:16:59 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <basics.h>

t_image_list		*imagelistnew(t_image *window)
{
	t_image_list	*new;

	if (!(new = (t_image_list*)malloc(sizeof(t_image_list))))
		return (NULL);
	new->image = window->mlximg;
	new->next = NULL;
	return (new);
}

t_image_list		*imagelistadd(t_image_list *head, t_image *window)
{
	t_image_list	*tmp;

	if (head == NULL)
		head = imagelistnew(window);
	else
	{
		tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = imagelistnew(window);
	}
	return (head);
}

void				imagelistprint(t_image_list *head)
{
	if (head)
	{
		ft_printf("head: %p\n", head);
		ft_printf("\thead->image: %p\n", head->image);
		ft_printf("\thead->next: %p\n", head->next);
		imagelistprint(head->next);
	}
}

t_image_list		*manageimagelist(int macro)
{
	static t_image_list	*head;

	if (macro == ADD)
		head = imagelistadd(head, manageimage(GET));
	else if (macro == PRINT)
		imagelistprint(head);
	else
		ft_printf("Useless call to manageimagelist\n");
	return (NULL);
}
