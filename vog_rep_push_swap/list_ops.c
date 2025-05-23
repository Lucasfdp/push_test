/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 06:14:13 by luferna3          #+#    #+#             */
/*   Updated: 2025/05/20 04:58:04 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew_ps(int content)
{
	t_stack	*result;

	result = (t_stack *)malloc(sizeof(*result));
	if (!result)
		return (NULL);
	result->value = content;
	result->next = NULL;
	return (result);
}

void	ft_lstadd_front_ps(t_stack **lst, t_stack *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back_ps(t_stack **lst, t_stack *new)
{
	t_stack	*lstnode;

	if (!new || !lst)
		return ;
	lstnode = ft_lstlast_ps(*lst);
	if (!lstnode)
		*lst = new;
	else
		lstnode->next = new;
}

int	ft_lstsize_ps(t_stack *lst)
{
	int		count;
	t_stack	*temp;

	count = 0;
	temp = lst;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

t_stack	*ft_lstlast_ps(t_stack *lst)
{
	t_stack	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}
