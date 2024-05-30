/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:27:38 by ojacobs           #+#    #+#             */
/*   Updated: 2024/05/30 12:03:25 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*top_src;

	if (*src == NULL)
		return ;
	top_src = *src;
	*src = top_src->next;
	if (*src != NULL)
		(*src)->prev = NULL;
	top_src->next = *dest;
	if (*dest != NULL)
		(*dest)->prev = top_src;
	*dest = top_src;
}

void	pa(t_stack **b, t_stack **a)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf("pb\n");
}
