/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:59:56 by ojacobs           #+#    #+#             */
/*   Updated: 2024/05/30 12:03:28 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	reverse_rotate(t_stack **head)
{
	t_stack	*top;
	t_stack	*bottom;

	if (!head || !*head || !(*head)->next)
		return ;
	top = *head;
	bottom = *head;
	while (bottom->next != NULL)
		bottom = bottom->next;
	bottom->prev->next = NULL;
	bottom->next = top;
	bottom->prev = NULL;
	top->prev = bottom;
	*head = bottom;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}

void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	if (!a || !b || !cheapest_node || !*a || !*b)
	{
		write(2, "Error\n", 6);
		return ;
	}
	while (*b != cheapest_node->swap_target && *a != cheapest_node)
		rrr(a, b);
	index_assignement(*a);
	index_assignement(*b);
}
