/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_stack_a_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:06:05 by mabid             #+#    #+#             */
/*   Updated: 2022/03/15 15:19:06 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Va faire un swap_a et swap_b simultanément
 * 
 * @param stack_a_b 
 * @return t_stack* 
 */
t_stack	*swap_a_b(t_stack *stack_a_b)
{
	swap_a(stack_a_b);
	swap_b(stack_a_b);
	ft_putstr("ss\n");
	return (stack_a_b);
}

/**
 * @brief Va faire un rotate_a et rotate_b simultanément
 * 
 * @param stack_a_b 
 * @return t_stack* 
 */
t_stack	*rotate_a_b(t_stack	*stack_a_b)
{
	rotate_a(stack_a_b);
	rotate_b(stack_a_b);
	ft_putstr("rr\n");
	return (stack_a_b);
}

/**
 * @brief Va faire un rrotate_a et rrotate_b simultanément
 * 
 * @param stack_a_b 
 * @return t_stack* 
 */
t_stack	*rrotate_a_b(t_stack *stack_a_b)
{
	rrotate_a(stack_a_b);
	rrotate_b(stack_a_b);
	ft_putstr("rrr\n");
	return (stack_a_b);
}
