/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihovhann <ihovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:18:43 by ihovhann          #+#    #+#             */
/*   Updated: 2022/07/22 13:18:44 by ihovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env(t_var **env_lst)
{
	int		i;
	char	**envp;

	i = -1;
	envp = env_lst_to_arr(*env_lst, 'e', 0);
	while (envp[++i] != 0)
	{
		ft_putstr_fd(envp[i], 1);
		ft_putchar_fd('\n', 1);
	}
	if (envp[i] == 0)
	{
		arr_free(envp);
		change_status(env_lst, 0);
		return (0);
	}
	else
	{
		arr_free(envp);
		change_status(env_lst, 127);
		return (2);
	}
}
