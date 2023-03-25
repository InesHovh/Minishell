/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihovhann <ihovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:19:00 by ihovhann          #+#    #+#             */
/*   Updated: 2022/07/22 13:19:01 by ihovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lst_add_back(t_var **lst, t_var *new_node)
{
	t_var	*tmp;

	if (lst)
	{
		if (*lst == 0)
			*lst = new_node;
		else
		{
			tmp = lst_last(*lst);
			tmp->next = new_node;
		}
	}
}

void	lst_add_back_token(t_token **lst, t_token *new_node)
{
	t_token	*tmp;

	if (lst)
	{
		if (*lst == 0)
			*lst = new_node;
		else
		{
			tmp = lst_last_token(*lst);
			tmp->next = new_node;
		}
	}
}
