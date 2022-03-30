/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_stack_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:36:13 by mabid             #+#    #+#             */
/*   Updated: 2022/03/15 15:45:40 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Voir action_stack_a
 * 
 * @param stack_b 
 * @return t_stack* 
 */
t_stack	*swap_b(t_stack *stack_b)
{
	if (stack_b->nbr && stack_b->next->nbr)
		ft_swap(&(stack_b->nbr), &(stack_b->next->nbr));
	ft_putstr("sb\n");
	return (stack_b);
}

/**
 * @brief Voir action_stack_a
 * 
 * @param stack_b 
 * @param stack_a 
 * @return t_stack* 
 */
t_stack	*push_b(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_b)
		stack_b = new_element(stack_a->nbr);
	else
		stack_b = ft_stack_front(stack_b, stack_a->nbr);
	ft_putstr("pb\n");
	return (stack_b);
}

/**
 * @brief Voir action_stack_a 
 * 
 * @param stack_b 
 * @return t_stack* 
 */
t_stack	*rotate_b(t_stack *stack_b)
{
	int			stay;
	t_stack		*nextnbr;

	if (len_list(stack_b) == 1)
		return (stack_b);
	stay = stack_b->nbr;
	nextnbr = stack_b->next;
	ft_stack_back(nextnbr, stay);
	stack_b = del_nbr_head(stack_b);
	ft_putstr("rb\n");
	return (nextnbr);
}

/**
 * @brief Voir action_stack_a 
 * 
 * @param stack_b 
 * @return t_stack* 
 */
t_stack	*rrotate_b(t_stack *stack_b)
{
	t_stack		*last;
	t_stack		*avant_last;

	avant_last = stack_b;
	last = ft_lstlast(stack_b);
	if (len_list(stack_b) == 1)
		return (stack_b);
	else
		while (avant_last->next->next)
			avant_last = avant_last->next;
	last->next = stack_b;
	avant_last->next = NULL;
	ft_putstr("rrb\n");
	return (last);
}
