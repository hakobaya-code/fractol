/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:51:36 by hakobaya          #+#    #+#             */
/*   Updated: 2024/01/30 17:32:07 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	decimal_digit(int count)
{
	int	ret;

	ret = 1;
	while (count > 0)
	{
		ret *= 10;
		count--;
	}
	return (ret);
}

double	ft_decimal(char *str)
{
	int		count;
	double	decimal;

	count = 0;
	decimal = 0.0;
	while ((*str >= '0' && *str <= '9') && count < 6)
	{
		decimal = decimal * 10.0 + (*str - '0');
		count++;
		str++;
	}
	decimal /= decimal_digit(count);
	return (decimal);
}

double	ft_minus(char **str)
{
	double	minus;

	minus = 1.0;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			minus *= -1.0;
		(*str)++;
	}
	return (minus);
}

double	ft_atof(char *str)
{
	double	minus;
	double	num;
	double	decimal;

	num = 0.0;
	minus = ft_minus(&str);
	if (!(*str >= '0' && *str <= '9'))
		error_handle(ATOF_ERROR);
	while (*str != '.' && (*str >= '0' && *str <= '9'))
	{
		num = num + (*str - '0');
		if (num > 1.0)
			error_handle(ATOF_ERROR);
		if (num < -1.0)
			error_handle(ATOF_ERROR);
		str++;
	}
	if (*str == '.')
		str++;
	decimal = ft_decimal(str);
	if (*str != '\0' && !(*str >= '0' && *str <= '9'))
		error_handle(ATOF_ERROR);
	num =  (decimal * minus) + (num * minus);
	return (num);
}
