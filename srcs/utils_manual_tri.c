/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_manual_tri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:21:57 by mabid             #+#    #+#             */
/*   Updated: 2022/03/15 17:23:40 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Ici stock aura la valeur du plus grand nombre. 
 * On va mettre i a la position dans la liste 
 * pour identifier le nombre en question.
 * Soit la plus grande valeur ici.
 * 
 * @param stack_a 
 * @return int 
 */
int	max_pos(t_stack *stack_a)
{
	t_stack		*tmp;
	int			i;
	int			stock;

	i = 1;
	tmp = stack_a;
	stock = stack_a->nbr;
	while (stack_a)
	{
		if (stack_a->nbr > stock)
		{
			stock = stack_a->nbr;
		}
		stack_a = stack_a->next;
	}
	while (tmp->nbr != stock)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

/**
 * @brief Va chercher la position du nombre le plus petit de la liste.
 * 
 * @param stack_a 
 * @return int 
 */
int	min_pos(t_stack *stack_a)
{
	t_stack	*tmp;
	int		i;
	int		stock;

	i = 1;
	tmp = stack_a;
	stock = stack_a->nbr;
	while (stack_a)
	{
		if (stack_a->nbr < stock)
		{
			stock = stack_a->nbr;
		}
		stack_a = stack_a->next;
	}
	while (tmp->nbr != stock)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

/**
 * @brief Va mettre le plus petit elements de la liste en haut de la pile.
 * 
 * @param stack_a 
 * @return t_stack 
 */
t_stack	*min_up_list(t_stack *stack_a)
{
	int	min;
	int	len;

	len = len_list(stack_a);
	min = min_pos(stack_a);
	if (min <= len / 2)
	{
		while (min && min != 1)
		{
			stack_a = rotate_a(stack_a);
			min--;
		}
	}
	else if (min != 1)
	{
		while (min <= len)
		{
			stack_a = rrotate_a(stack_a);
			min++;
		}
	}
	return (stack_a);
}

/**
 * @brief Regarde la taille de la liste, cherche le plus grand element
 * Si il n'y a que 2 element et 
 * que l'element le plus grand se trouve en haut de la pile alors on swap
 * Sinon on fait rrotate jusqu(a arrivé a l'element le plus grand
 * 
 * @param stack_a 
 * @return t_stack 
 */
t_stack	*max_up_list(t_stack *stack_a)
{
	int	max;
	int	len;

	len = len_list(stack_a);
	max = max_pos(stack_a);
	if (max <= len / 2)
	{
		if (max == 2)
			stack_a = swap_a(stack_a);
	}
	else if (max != 1)
	{
		while (max <= len)
		{
			stack_a = rrotate_a(stack_a);
			max++;
		}
	}
	return (stack_a);
}
