/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 05:04:55 by wimam             #+#    #+#             */
/*   Updated: 2025/05/10 14:44:41 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_read(int fd)
{
	int		read_byte;
	char	*buffer;
	char	*tmp;

	tmp = malloc(GNL_BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	tmp[GNL_BUFFER_SIZE] = '\0';
	read_byte = 0;
	buffer = ft_init(NULL);
	read_byte = read(fd, tmp, GNL_BUFFER_SIZE);
	while (read_byte > 0)
	{
		buffer = ft_strljoin(buffer, tmp, read_byte);
		if (ft_new_line_check(tmp))
			break ;
		read_byte = read(fd, tmp, GNL_BUFFER_SIZE);
	}
	free(tmp);
	if (read_byte <= 0 && !buffer)
		return (NULL);
	return (buffer);
}

static char	*ft_get_data(int fd, char *old)
{
	char	*buffer;
	char	*data;

	if (read(fd, 0, 0) == -1)
		return (free(old), NULL);
	if (ft_new_line_check(old))
		return (old);
	if (!old)
		old = ft_init(NULL);
	buffer = ft_read(fd);
	data = ft_strljoin(old, buffer, ft_strlen(buffer));
	free(buffer);
	return (data);
}

static char	*ft_get_line(char	*data)
{
	int		i;
	char	*line;

	if (!data)
		return (NULL);
	if (*data == '\0')
		return (NULL);
	i = 0;
	while (data[i] != '\0' && data[i] != '\n')
		i++;
	line = malloc(i + 1 + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (data[i] != '\0' && data[i] != '\n')
	{
		line[i] = data[i];
		i++;
	}
	line[i] = data[i];
	line[++i] = '\0';
	return (line);
}

static char	*ft_update_data(char *text)
{
	int		trim_len;
	int		text_len;
	char	*new_text;

	if (!text)
		return (NULL);
	text_len = ft_strlen(text);
	trim_len = 0;
	while (text[trim_len] != '\0' && text[trim_len] != '\n')
		trim_len++;
	if (trim_len == text_len)
		return (free(text), NULL);
	trim_len++;
	new_text = ft_strdup(text + trim_len);
	free(text);
	return (new_text);
}

char	*get_next_line(int fd)
{
	static char	*data;
	char		*line;

	if (fd == GNL_FREE)
	{
		free(data);
		data = NULL;
	}
	if (fd < 0 || GNL_BUFFER_SIZE <= 0)
		return (NULL);
	data = ft_get_data(fd, data);
	line = ft_get_line(data);
	data = ft_update_data(data);
	return (line);
}
