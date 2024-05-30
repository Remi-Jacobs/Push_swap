/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:28:20 by ojacobs           #+#    #+#             */
/*   Updated: 2024/05/30 12:03:31 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rotate(t_stack **head)
{
	t_stack	*top;
	t_stack	*bottom;

	if (!head || !*head || !(*head)->next)
		return ;
	top = *head;
	bottom = *head;
	while (bottom->next != NULL)
		bottom = bottom->next;
	top->next->prev = NULL;
	*head = top->next;
	bottom->next = top;
	top->prev = bottom;
	top->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	if (!a || !b || !cheapest_node || !*a || !*b)
	{
		write(2, "Error\n", 6);
		return ;
	}
	while (*b != cheapest_node->swap_target && *a != cheapest_node)
		rr(a, b);
	index_assignement(*a);
	index_assignement(*b);
}
