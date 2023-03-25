/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_delone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihovhann <ihovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:19:08 by ihovhann          #+#    #+#             */
/*   Updated: 2022/07/22 13:19:09 by ihovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lst_delone(t_var *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->name);
		del(lst->value);
		free (lst);
	}
}

void	lst_delone_token(t_token *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->value);
		del(lst->quote);
		free (lst);
	}
}
