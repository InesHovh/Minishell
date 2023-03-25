/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihovhann <ihovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:18:16 by ihovhann          #+#    #+#             */
/*   Updated: 2022/07/22 13:26:45 by ihovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	arg_del_next(t_token **tokens, t_token **tmp1, t_token **tmp2)
{
	if (*tokens == *tmp1)
	{
		*tokens = (*tmp1)->next;
		lst_delone_token(*tmp1, &free);
		*tmp1 = *tokens;
	}
	else
	{
		(*tmp2)->next = (*tmp1)->next;
		lst_delone_token(*tmp1, &free);
		*tmp1 = (*tmp2)->next;
	}
}

static void	arg_to_array(t_token **tokens, t_command *command)
{
	int		i;
	t_token	*tmp1;
	t_token	*tmp2;

	i = -1;
	tmp2 = *tokens;
	tmp1 = *tokens;
	while (tmp1 != 0 && tmp1->type != 'p')
	{
		if (tmp1->type == 'w')
		{
			command->args[++i] = ft_strdup(tmp1->value);
			arg_del_next(tokens, &tmp1, &tmp2);
		}
		else
		{
			tmp2 = tmp1;
			tmp1 = tmp1->next;
		}
	}
}

int	arg_count(t_token **tokens, t_command *command)
{
	int		count;
	t_token	*tmp;

	tmp = *tokens;
	count = 0;
	while (tmp != 0 && tmp->type != 'p')
	{
		if (tmp->type == 'r')
		{
			tmp = tmp->next;
			if (tmp != 0 && tmp->type == 'w')
				tmp->type = 'v';
		}
		else
			count++;
		if (tmp != 0)
			tmp = tmp->next;
	}
	command->args = (char **)malloc(sizeof(char *) * (count + 1));
	if (command->args == 0)
		return (-1);
	command->args[count] = 0;
	arg_to_array(tokens, command);
	return (0);
}
