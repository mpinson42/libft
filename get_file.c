/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:05:25 by mpinson           #+#    #+#             */
/*   Updated: 2017/02/06 14:06:59 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*get_file(int fd)
{
	char	*file;
	char	*tmp;
	char	*swp;

	if (fd == -1)
		return (NULL);
	if (!(file = (char *)ft_memalloc(sizeof(char))))
		return (file);
	if (!(tmp = (char *)ft_memalloc(sizeof(char) * 101)))
	{
		free(file);
		return (tmp);
	}
	while (read(fd, tmp, 100))
	{
		swp = ft_strjoin(file, tmp);
		free(file);
		file = ft_strdup(swp);
		free(swp);
		ft_bzero(tmp, 101);
	}
	free(tmp);
	return (file);
}
