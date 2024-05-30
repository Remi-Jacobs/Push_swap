/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_a_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:30:13 by ojacobs           #+#    #+#             */
/*   Updated: 2024/05/30 12:03:34 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
//Try to re-evaluate pushcost on median position(if both are alligned)  
void	index_assignement(t_stack	*head)
{
	int		i;
	int		median;
	t_stack	*cursor;

	if (!head)
		return ;
	i = 0;
	cursor = head;
	median = stack_len(head) / 2;
	while (cursor)
	{
		cursor->index = i;
		if (i <= median)
			cursor->above_median = 1;
		else
			cursor->above_median = 0;
		i++;
		cursor = cursor->next;
	}
}

void	find_b_target(t_stack	*a, t_stack	*b)
{
	t_stack	*cursor;
	t_stack	*b_target;
	long	closest_smallest;

	while (a)
	{
		closest_smallest = LONG_MIN;
		b_target = NULL;
		cursor = b;
		while (cursor)
		{
			if (cursor->data < a->data && closest_smallest < cursor->data)
			{
				closest_smallest = cursor->data;
				b_target = cursor;
			}
			cursor = cursor->next;
		}
		if (closest_smallest == LONG_MIN)
			a->swap_target = find_max(b);
		else
			a->swap_target = b_target;
		a = a->next;
	}
}

static void	find_cost_a(t_stack	*a, t_stack	*b)
{
	int	s_len_a;
	int	s_len_b;

	s_len_a = stack_len(a);
	s_len_b = stack_len(b);
	if (!a || !b)
		return ;
	while (a)
	{
		if (a->above_median == 0)
			a->push_cost = s_len_a - (a->index);
		else
			a->push_cost = a->index;
		if (!a->swap_target)
		{
			ft_printf("Null occured idk why");
			exit(1);
		}
		if (a->swap_target->above_median == 0)
			a->push_cost += (s_len_b - a->swap_target->index);
		else
			a->push_cost += (a->swap_target->index);
		a = a-> next;
	}
}

static void	set_cheapest(t_stack *head)
{
	t_stack	*cursor;
	t_stack	*temp;
	long	result;

	if (!head)
		return ;
	cursor = head;
	temp = NULL;
	result = LONG_MAX;
	while (cursor)
	{
		cursor->cheapest = 0;
		if (cursor->push_cost < result)
		{
			result = cursor->push_cost;
			temp = cursor;
		}
		cursor = cursor->next;
	}
	if (temp)
		temp->cheapest = 1;
}

void	setup_a(t_stack *a, t_stack	*b)
{
	if (!a || !b)
		return ;
	index_assignement(a);
	index_assignement(b);
	find_b_target(a, b);
	find_cost_a(a, b);
	set_cheapest(a);
}
