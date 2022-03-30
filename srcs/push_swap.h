/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:45:08 by mabid             #+#    #+#             */
/*   Updated: 2022/03/15 16:56:27 by mabid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

/*------------------------- STRUCTURE DE MA LISTE ----------------------*/

typedef struct s_stack
{
	long			nbr;
	struct s_stack	*next;
}					t_stack;

/*----------------------------------------------------------------------*/

/*---------------------- FONCTION UTILS DE LA LIBFT --------------------*/

void		ft_putstr(char *s);
void		ft_swap(long *a, long *b);
int			len_list(t_stack *stack_a);
long		ft_atol(const char *str);
char		**ft_split(char	const *s, char c);

/*----------------------------------------------------------------------*/

/*---------------------- FONCTION UTILS DES ACTION ---------------------*/

t_stack		*new_element(int nbr);
t_stack		*ft_stack_front(t_stack *start, int data);
t_stack		*ft_stack_back(t_stack *stack_a, int nbr);
t_stack		*del_nbr_head(t_stack *stack_a);
t_stack		*ft_lstlast(t_stack *lst);
t_stack		*free_stack(t_stack *stack_a);

/*----------------------------------------------------------------------*/

/*--------------------------- FONCTION ACTION --------------------------*/

t_stack		*swap_a(t_stack *stack_a);
t_stack		*push_a(t_stack *stack_a, t_stack *stack_b);
t_stack		*rotate_a(t_stack *stack_a);
t_stack		*rrotate_a(t_stack *stack_a);
t_stack		*swap_b(t_stack *stack_b);
t_stack		*push_b(t_stack *stack_b, t_stack *stack_a);
t_stack		*rotate_b(t_stack *stack_b);
t_stack		*rrotate_b(t_stack *stack_b);
t_stack		*swap_a_b(t_stack *stack_a_b);
t_stack		*rotate_a_b(t_stack *stack_a_b);
t_stack		*rrotate_a_b(t_stack *stack_a_b);

/*----------------------------------------------------------------------*/

/*----------------------------- FONCTION TRI ---------------------------*/

int			max_pos(t_stack *stack_a);
int			min_pos(t_stack *stack_a);
t_stack		*tri_for_2(t_stack *stack_a);
t_stack		*tri_for_3(t_stack *stack_a);
t_stack		*tri_3_plus_de_25_lignes(t_stack *stack_a);
t_stack		*tri_for_5(t_stack *stack_a, t_stack *stack_b);
t_stack		*min_up_list(t_stack *stack_a);
t_stack		*max_up_list(t_stack *stack_a);

/*----------------------------------------------------------------------*/

/*---------------------------- FONCTION ERREUR -------------------------*/

int			ft_isdigit(char s);
int			ft_white_space(char c);
void		check_str(char *str);
void		check_doublon(t_stack *stack_a);
int			check_next(t_stack *stack_a);

/*----------------------------------------------------------------------*/

/*----------------------------- FONCTION ALGO --------------------------*/

int			*tab_int(t_stack *stack_a, int size);
void		free_str(char **tab);
int			*value_pos(int *tab, int len);
t_stack		*max_up_list_stack_b(t_stack *stack_b, int posmax, int size);
t_stack		*max_stack_b_push_a(t_stack *stack_a, t_stack *stack_b);
int			get_group(t_stack *stack, int *tab, int size);
t_stack		*push_by_group(t_stack *stack_a, t_stack *stack_b, int size);

/*----------------------------------------------------------------------*/

/*--------------------------- FONCTION PARSING -------------------------*/

t_stack		*new_element_tab(char **av);
t_stack		*init(char **av);

/*----------------------------------------------------------------------*/

#endif
