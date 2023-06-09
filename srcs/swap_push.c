/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:49:00 by suchua            #+#    #+#             */
/*   Updated: 2022/11/18 00:49:00 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int print)
{
	t_stack	*dup1;
	t_stack	*dup2;
	t_stack	*third;

	if (get_stack_size(*a) < 2)
		return ;
	dup1 = get_dup_stack(*a);
	dup2 = get_dup_stack((*a)->next);
	third = (*a)->next->next;
	dup2->next = dup1;
	dup1->next = third;
	free((*a)->next);
	free(*a);
	*a = dup2;
	if (print)
		ft_putendl_fd("sa", 1);
}

void	sb(t_stack **b, int print)
{
	t_stack	*dup1;
	t_stack	*dup2;
	t_stack	*third;

	if (get_stack_size(*b) < 2)
		return ;
	dup1 = get_dup_stack(*b);
	dup2 = get_dup_stack((*b)->next);
	third = (*b)->next->next;
	dup2->next = dup1;
	dup1->next = third;
	free((*b)->next);
	free(*b);
	*b = dup2;
	if (print)
		ft_putendl_fd("sb", 1);
}

void	ss(t_stack **a, t_stack **b, int print)
{
	sa(a, 0);
	sb(b, 0);
	if (print)
		ft_putendl_fd("ss", 1);
}

void	pa(t_stack **a, t_stack **b, int print)
{
	t_stack	*new;
	t_stack	*tmp;

	if (!b || !*b)
		return ;
	new = get_dup_stack(*b);
	stack_add_front(a, new);
	tmp = (*b)->next;
	free(*b);
	(*b) = tmp;
	if (print)
		ft_putendl_fd("pa", 1);
}

void	pb(t_stack **a, t_stack **b, int print)
{
	t_stack	*new;
	t_stack	*tmp;

	if (!a || !*a)
		return ;
	new = get_dup_stack(*a);
	stack_add_front(b, new);
	tmp = (*a)->next;
	free(*a);
	(*a) = tmp;
	if (print)
		ft_putendl_fd("pb", 1);
}
