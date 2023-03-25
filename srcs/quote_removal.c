/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_removal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihovhann <ihovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:19:45 by ihovhann          #+#    #+#             */
/*   Updated: 2022/07/22 13:19:46 by ihovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	quote_removal(t_token *tokens)
{
	int		i;
	char	*new_value;
	char	*new_quote;

	i = -1;
	while (tokens->value[++i] != '\0')
	{
		if ((tokens->value[i] == '\'' || tokens->value[i] == '\"') && \
				tokens->quote[i] == '1')
		{
			tokens->value[i] = '\0';
			new_value = ft_strjoin(tokens->value, tokens->value + i + 1);
			free(tokens->value);
			tokens->value = new_value;
			tokens->quote[i] = '\0';
			new_quote = ft_strjoin(tokens->quote, tokens->quote + i + 1);
			free(tokens->quote);
			tokens->quote = new_quote;
			--i;
			if (tokens->type == 'h')
				tokens->type = 'H';
		}
	}
}
