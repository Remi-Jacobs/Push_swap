/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_b_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:13:15 by ojacobs           #+#    #+#             */
/*   Updated: 2024/05/30 12:03:37 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	find_a_target(t_stack *a, t_stack *b)
{
	t_stack	*cursor;
	t_stack	*a_target;
	long	closest_biggest;

	while (b)
	{
		closest_biggest = LONG_MAX;
		cursor = a;
		while (cursor)
		{
			if (cursor->data > b->data && cursor->data < closest_biggest)
			{
				closest_biggest = cursor->data;
				a_target = cursor;
			}
			cursor = cursor->next;
		}
		if (closest_biggest == LONG_MAX)
			b->swap_target = find_min(a);
		else
			b->swap_target = a_target;
		b = b->next;
	}
}

void	setup_b(t_stack *a, t_stack *b)
{
	index_assignement(a);
	index_assignement(b);
	find_a_target(a, b);
}
