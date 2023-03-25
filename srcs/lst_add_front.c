/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihovhann <ihovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:19:03 by ihovhann          #+#    #+#             */
/*   Updated: 2022/07/22 13:19:04 by ihovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lst_add_front(t_var **lst, t_var *new_elem)
{
	if (lst && new_elem)
	{
		new_elem->next = *lst;
		*lst = new_elem;
	}
}
