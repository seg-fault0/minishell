/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:56:01 by zogrir            #+#    #+#             */
/*   Updated: 2025/05/18 15:26:48 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

static char	*extract_var_name(char *str)
{
	char	*start;
	char	*var_name;
	int		len;

	len = 0;
	start = ft_strchr(str, '$');
	if (!start || !start[1])
		return (NULL);
	start += 1;
	while (is_valid_alpha(start[len]))
		len++;
	var_name = malloc(len + 1);
	if (!var_name)
		return (NULL);
	ft_memcpy(var_name, start, len);
	var_name[len] = '\0';
	return (var_name);
}

void	expand_vars(t_ms *ms)
{
	int		i;
	char	*var_name;
	char	*expanded;

	i = -1;
	while (ms->parse.tmp2d[++i])
	{
		if (expand_checker(ms->parse.tmp2d[i]))
		{
			var_name = extract_var_name(ms->parse.tmp2d[i]);
			if (!var_name)
				continue ;
			expanded = get_env_v2(ms->env, var_name);
			free(var_name);
			free(ms->parse.tmp2d[i]);
			if (expanded)
				ms->parse.tmp2d[i] = ft_strdup(expanded);
			else
				ms->parse.tmp2d[i] = ft_strdup("");
		}
	}
}
