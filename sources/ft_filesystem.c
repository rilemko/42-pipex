/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filesystem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:08:58 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/23 16:54:01 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_isfile(const char *filename)
{
	int	status;

	status = access(filename, F_OK) == 0;
	return (status);
}

int	ft_isreadable(const char *filename)
{
	int	status;

	status = access(filename, R_OK) == 0;
	return (status);
}

int	ft_iswriteable(const char *filename)
{
	int	status;

	status = access(filename, W_OK) == 0;
	return (status);
}
