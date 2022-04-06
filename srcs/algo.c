/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:46:24 by mabid             #+#    #+#             */
/*   Updated: 2022/03/15 15:51:31 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * 	Etape 1 : Recupere un tableau d'INT avec la taille de la liste 
 * et ces elements dedans. (tab_int)
 * 	Etape 2 : Place la position de chaque elements dans le tableau.(value_sort)
 * 	Etape 3 : Si nous avons plus de 150 elements nous coupons l'index 
 * en 15 parties pour trié en 15 temps. Sinon ça ne se fera qu'en 7 ou 5 partie.
 * 	Etape 4 : On place l'index dans de le tableau qui sera couper 
 * en 5 ou 7 parties selon le nombre d'arguments. 
 * Et l'initialisera a la variable group.
 * 	Etape 5 : On free tab, car on utilise malloc dans tab_int.
 * 	Etape 6 : On retourne group soit la ou on agira en premier.
 *
 * @param stack 
 * @param tab 
 * @param size 
 * @return int 
 */
int	get_group(t_stack *stack, int *tab, int size)
{
	int	index;
	int	group;

	tab = tab_int(stack, size);
	tab = value_pos(tab, size);
	if (size >= 150)
		index = size / 15;
	else if (size <= 150 && size >= 50)
		index = size / 7;
	else
		index = size / 5;
	group = tab[index];
	free(tab);
	return (group);
}

/**
 * @brief 
 * 	Etape 1 : Tab initialisé a nul car pointeur inutilisé au debut.
 * 	Etape 2 : On créer une varaible tmp pour que tout soit fait la dessus 
 * sans impacté la stack_a.
 * 	Etape 3 : Puis on utilise la variable mediane pour agir sur les index donné,
 * groupe par groupe.
 * 	Etape 4 : On diminue la variable size pour que lorsque elle arrive a 0 
 * nous avons tout trier dans la stack b.
 *  Puisque nous avons un calcul de median qui se fait 
 * a chaque passage dans la boucle .
 * 	Etape 5 : Il calcule la taille de la liste pour savoir ce qu'il reste.
 * 	Etape 6 : A la fin Tout ce qu'il y a dans stack_b est remis dans la stack_a 
 * par la fonction  max_stack_b_push_a.
 * Le tri est terminer
 * 
 * get_group a ete deplacer dans le while 
 * pour plus de precisions lors du clacul de la mediane.
 * @param stack_a 
 * @param stack_b 
 * @param size 
 * @return t_stack* 
 */
t_stack	*push_by_group(t_stack *stack_a, t_stack *stack_b, int size)
{
	int		median;
	int		*tab;
	t_stack	*tmp;

	tab = NULL;
	while (stack_a)
	{
		tmp = stack_a;
		while (size)
		{
			median = get_group(tmp, tab, size);
			if (tmp->nbr <= median)
			{
				stack_b = push_b(tmp, stack_b);
				tmp = del_nbr_head(tmp);
			}
			else
				tmp = rotate_a(tmp);
			size--;
		}
		stack_a = tmp;
		size = len_list(stack_a);
	}
	stack_a = max_stack_b_push_a(stack_a, stack_b);
	return (stack_a);
}
