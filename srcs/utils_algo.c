/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:58:58 by mabid             #+#    #+#             */
/*   Updated: 2022/03/15 17:18:47 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Va créer un tableau de int avec malloc 
 * et metre dans le tableeau le nombre d'element de la liste.
 * on malloc size +1 en general pour le \0 ici se sera pour la valeur NULL.
 * 
 * @param stack_a 
 * @param size 
 * @return int* 
 */
int	*tab_int(t_stack *stack_a, int size)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * size + 1);
	if (!tab)
		return (NULL);
	while (i < size)
	{
		tab[i] = stack_a->nbr;
		i++;
		stack_a = stack_a->next;
	}
	return (tab);
}

/**
 * @brief Va free notre tableau pour 0 fuites de mémoire.
 * 
 * @param tab 
 */
void	free_str(char **tab)
{
	int	line;

	line = 0;
	while (tab[line])
	{
		free(tab[line]);
		line++;
	}
	free(tab);
}

/**
 * @brief 
 * Va nous indiquer les positions de chaque element que l'on met dans la liste,
 * dans le tableau.
 * 
 * @param tab 
 * @param len 
 * @return int* 
 */
int	*value_pos(int *tab, int len)
{
	long	tmp;
	int		posnbr;

	tmp = 0;
	posnbr = 0;
	while (posnbr < len - 1)
	{
		if (tab[posnbr] <= tab[posnbr + 1])
			posnbr++;
		else
		{
			tmp = tab[posnbr];
			tab[posnbr] = tab[posnbr + 1];
			tab[posnbr + 1] = tmp;
			posnbr = 0;
		}
	}
	return (tab);
}

/**
 * @brief Ici on va partir a la recherche de la position de
 * l'element le plus grand.
 * Et le placer en tete de liste.
 * 
 * @param stack_b 
 * @param posmax 
 * @param size 
 * @return t_stack* 
 */
t_stack	*max_up_list_stack_b(t_stack *stack_b, int posmax, int size)
{
	if (posmax <= size / 2)
	{
		while (posmax && posmax != 1)
		{
			stack_b = rotate_b(stack_b);
			posmax--;
		}
	}
	else if (posmax != 1)
	{
		while (posmax <= size)
		{
			stack_b = rrotate_b(stack_b);
			posmax++;
		}
	}
	return (stack_b);
}

/**
 * @brief Dernière étape de la stack_b, 
 * soit tout remetre a la stack_a en triant.
 * La plus grande valeur en tete pour 
 * qu'elle arrive en bas de pile dans la stack_a lorsque l'on push.
 * Ce qui fera un tri correct.
 * 
 * @param stack_a 
 * @param stack_b 
 * @return t_stack* 
 */
t_stack	*max_stack_b_push_a(t_stack *stack_a, t_stack *stack_b)
{
	int	posmax;
	int	size;

	while (stack_b)
	{
		size = len_list(stack_b);
		posmax = max_pos(stack_b);
		stack_b = max_up_list_stack_b(stack_b, posmax, size);
		stack_a = push_a(stack_a, stack_b);
		stack_b = del_nbr_head(stack_b);
	}
	return (stack_a);
}
