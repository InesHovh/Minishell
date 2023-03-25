/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihovhann <ihovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:19:27 by ihovhann          #+#    #+#             */
/*   Updated: 2022/07/22 13:26:45 by ihovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	operators(t_token *tokens)
{
	while (tokens != 0)
	{
		if (tokens->type == 'o')
		{
			if (ft_strncmp(tokens->value, ">", 2) == 0 || \
					ft_strncmp(tokens->value, ">>", 3) == 0 || \
					ft_strncmp(tokens->value, "<", 2) == 0 || \
					ft_strncmp(tokens->value, "<<", 3) == 0)
				tokens->type = 'r';
			else if (ft_strncmp(tokens->value, "|", 2) == 0)
				tokens->type = 'p';
			else
			{
				ft_putstr_fd("Minishell: Syntax error: unexpected token '", 2);
				ft_putstr_fd(tokens->value, 2);
				ft_putstr_fd("'\n", 2);
				return (-1);
			}
		}
		tokens = tokens->next;
	}
	return (0);
}
