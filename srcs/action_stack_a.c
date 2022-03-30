/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:19:18 by mabid             #+#    #+#             */
/*   Updated: 2022/03/15 15:36:04 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Va faire un swap et remplacer le 1er element en haut 
 * de la stack par le second.
 * 
 * @param stack_a 
 * @return t_stack* 
 */
t_stack	*swap_a(t_stack *stack_a)
{
	if (stack_a->nbr && stack_a->next->nbr)
		ft_swap(&(stack_a->nbr), &(stack_a->next->nbr));
	ft_putstr("sa\n");
	return (stack_a);
}

/**
 * @brief Va chercher dans la stack_b en haut, 
 * pour la placer de la stack_a en haut. 
 * Toujours utiliser del_nbr_head apres un push.
 * 
 * @param stack_a 
 * @param stack_b 
 * @return t_stack* 
 */
t_stack	*push_a(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a)
	stack_a = new_element(stack_b->nbr);
	else
	stack_a = ft_stack_front(stack_a, stack_b->nbr);
	ft_putstr("pa\n");
	return (stack_a);
}

/**
 * @brief Dans une meme pile le chiffre du haut et deplacer en bas.
 * Le chiffre suivant devient celui en tete. 
 * 
 * @param stack_a 
 * @return t_stack* 
 */
t_stack	*rotate_a(t_stack *stack_a)
{
	int			stay;
	t_stack		*nextnbr;

	if (len_list(stack_a) == 1)
		return (stack_a);
	stay = stack_a->nbr;
	nextnbr = stack_a->next;
	ft_stack_back(nextnbr, stay);
	stack_a = del_nbr_head(stack_a);
	ft_putstr("ra\n");
	return (nextnbr);
}

/**
 * @brief C'est un reverse de rotate_a.
 * Il fait la meme chose a l'envers 
 * soit le dernier nombre de la pile devient le premier. 
 * 
 * @param stack_a 
 * @return t_stack* 
 */
t_stack	*rrotate_a(t_stack *stack_a)
{
	t_stack		*last;
	t_stack		*avant_last;

	avant_last = stack_a;
	last = ft_lstlast(stack_a);
	if (len_list(stack_a) == 1)
		return (stack_a);
	else
		while (avant_last->next->next)
			avant_last = avant_last->next;
	last->next = stack_a;
	avant_last->next = NULL;
	ft_putstr("rra\n");
	return (last);
}
