/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:31:31 by hakobaya          #+#    #+#             */
/*   Updated: 2024/02/04 17:58:01 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	if (NULL == s1 || NULL == s2)
		error_handle (INPUT_ERROR);
	if (n == 0)
		return (0);
	c1 = (unsigned char)*s1;
	c2 = (unsigned char)*s2;
	while (c1 == c2 && i < n && c1 != '\0' && c2 != '\0')
	{
		c1 = (unsigned char)*s1++;
		c2 = (unsigned char)*s2++;
		i++;
	}
	return (c1 - c2);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
}

void	check_zero(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (str[i] == '0' && '\0' != str[j])
	{
		i++;
		if (str[i] != '.')
			error_handle(ATOF_ERROR);
	}
}
