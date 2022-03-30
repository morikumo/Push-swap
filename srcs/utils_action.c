/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:56:57 by mabid             #+#    #+#             */
/*   Updated: 2022/03/15 16:58:49 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Va creer un nouveau element a la liste. 
 * Equivalent de lstnew dans libft.
 * 
 * @param nbr 
 * @return t_stack* 
 */
t_stack	*new_element(int nbr)
{
	t_stack	*element;

	element = malloc(sizeof(t_stack));
	element->nbr = nbr;
	element->next = NULL;
	return (element);
}

/**
 * @brief Va creer un element et le donner à push pour faire un echange. 
 * Equivalent de lstadd_front.
 * 
 * @param start 
 * @param data 
 * @return t_stack* 
 */
t_stack	*ft_stack_front(t_stack *start, int data)
{
	t_stack	*push;

	push = NULL;
	if (start)
	{
		push = new_element(data);
		push->next = start;
		start = push;
	}
	return (push);
}

/**
 * @brief Va parcourir la liste et juste avant le dernier element 
 * qui pointe sur null on va ajouter un maillont. Ici nbr. 
 * Equivalent de lstadd_back un peu remixer quand meme.
 * 
 * @param stack_a 
 * @param nbr 
 * @return t_stack* 
 */
t_stack	*ft_stack_back(t_stack *stack_a, int nbr)
{
	t_stack	*list;

	list = stack_a;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = new_element(nbr);
	}
	return (list);
}

/**
 * @brief Va supprimer uniquement le premier element. 
 * Equivalent de lstdelone, mais uniquement pour le premier element.
 * 
 * @param stack_a 
 * @return t_stack* 
 */
t_stack	*del_nbr_head(t_stack *stack_a)
{
	t_stack	*new_stack;

	if (stack_a != NULL)
	{
		new_stack = stack_a->next;
		free(stack_a);
		return (new_stack);
	}
	else
	{
		return (NULL);
	}
}

/**
 * @brief Va retourner le dernier element de la liste.
 * 
 * @param lst 
 * @return t_stack* 
 */
t_stack	*ft_lstlast(t_stack *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}
