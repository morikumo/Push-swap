/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:05:52 by mabid             #+#    #+#             */
/*   Updated: 2022/03/15 16:44:03 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*free_stack(t_stack *stack_a)
{
	t_stack	*nbr;

	while (stack_a)
	{
		nbr = stack_a;
		stack_a = stack_a->next;
		free(nbr);
	}
	return (stack_a);
}

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			size;

	stack_a = NULL;
	stack_b = NULL;
	if (ac <= 1 || ac > 2)
		return (0);
	stack_a = init(av);
	if (stack_a)
	{
		size = len_list(stack_a);
		if (size == 2)
			stack_a = tri_for_2(stack_a);
		else if (size == 3)
			stack_a = tri_for_3(stack_a);
		else if (size == 5)
			stack_a = tri_for_5(stack_a, stack_b);
		else
			stack_a = push_by_group(stack_a, stack_b, size);
	}
	free_stack(stack_a);
	return (0);
}
