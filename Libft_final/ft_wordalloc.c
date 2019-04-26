/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btanja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:50:36 by btanja            #+#    #+#             */
/*   Updated: 2019/04/22 18:25:34 by btanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wordalloc(char const *s, char c)
{
	char	*word;
	int		l;
	int		i;

	i = 0;
	l = 0;
	while (s[l] != c && s[l])
		l++;
	if (!(word = (char*)malloc(sizeof(char*) * l)))
		return (NULL);
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}
