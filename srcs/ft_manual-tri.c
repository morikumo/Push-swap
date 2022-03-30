/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manual-tri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:54:44 by mabid             #+#    #+#             */
/*   Updated: 2022/03/15 15:59:53 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Tri manuel pour 5 element.
 *  Si le 1er element est plus grand que le second 
 *  on swap sinon on retourne directement stack_a.
 * 
 * @param stack_a 
 * @return t_stack* 
 */
t_stack	*tri_for_2(t_stack *stack_a)
{
	if (stack_a->nbr > stack_a->next->nbr)
		stack_a = swap_a(stack_a);
	return (stack_a);
}

/**
 * @brief C'est la suite de tri_for_3 ...
 * 
 * @param stack_a 
 * @return t_stack* 
 */
t_stack	*tri_3_plus_de_25_lignes(t_stack *stack_a)
{
	if (stack_a->nbr > stack_a->next->nbr
		&& stack_a->next->nbr < stack_a->next->next->nbr)
	{
		stack_a = rotate_a(stack_a);
		return (stack_a);
	}
	else if (stack_a->nbr < stack_a->next->nbr
		&& stack_a->nbr < stack_a->next->next->nbr
		&&stack_a->next->nbr > stack_a->next->next->nbr)
	{
		stack_a = swap_a(stack_a);
		stack_a = rotate_a(stack_a);
		return (stack_a);
	}
	else if (stack_a->nbr < stack_a->next->nbr
		&& stack_a->next->nbr > stack_a->next->next->nbr)
	{
		stack_a = rrotate_a(stack_a);
		return (stack_a);
	}
	return (stack_a);
}

/**
 * @brief Tri manuel pour 3 elements. 
 * Si le 1er elements est plus grand que le second, 
 * et que le 3eme elements est plus grand que le 1er,
 * on fait un swap des 2 premiers elements.
 * Si le 1er elements est plus grand que le second 
 * et que le second element est plus grand que le 3eme.
 * On fait un swap des 2 premier elements et on fait un reverse rotate,
 * soit le dernier element devient le premier.
 * 
 * @param stack_a 
 * @return t_stack* 
 */
t_stack	*tri_for_3(t_stack *stack_a)
{
	if (stack_a->nbr > stack_a->next->nbr
		&& stack_a->next->next->nbr > stack_a->nbr)
	{
		stack_a = swap_a(stack_a);
		return (stack_a);
	}
	else if (stack_a->nbr > stack_a->next->nbr
		&& stack_a->next->nbr > stack_a->next->next->nbr)
	{
		stack_a = swap_a(stack_a);
		stack_a = rrotate_a(stack_a);
		return (stack_a);
	}
	stack_a = tri_3_plus_de_25_lignes(stack_a);
	return (stack_a);
}

/**
 * @brief Tri manuel pour 5 element
 * Plus petit en stack b, puis plus grand en stack b,
 * tri pour 3 on mets le plus grand en stack a, 
 * puis rotate a pour que le plus grand finisse dernier
 * puis push_a,et tout est dans l'ordre.
 * 
 * @param stack_a 
 * @param stack_b 
 * @return t_stack* 
 */
t_stack	*tri_for_5(t_stack *stack_a, t_stack *stack_b)
{
	stack_a = min_up_list(stack_a);
	stack_b = push_b(stack_a, stack_b);
	stack_a = del_nbr_head(stack_a);
	stack_a = max_up_list(stack_a);
	stack_b = push_b(stack_a, stack_b);
	stack_a = del_nbr_head(stack_a);
	stack_a = tri_for_3(stack_a);
	stack_a = push_a(stack_a, stack_b);
	stack_b = del_nbr_head(stack_b);
	stack_a = rotate_a(stack_a);
	stack_a = push_a(stack_a, stack_b);
	stack_b = del_nbr_head(stack_b);
	return (stack_a);
}
