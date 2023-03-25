/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihovhann <ihovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:17:46 by ihovhann          #+#    #+#             */
/*   Updated: 2022/07/22 13:17:47 by ihovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*new_s;

	new_s = (char *)s;
	while (*new_s != '\0')
	{
		if (*new_s == c)
			return (new_s);
		new_s++;
	}
	if (*new_s == '\0' && c == '\0')
		return (new_s);
	return (0);
}
