/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:00:30 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/23 20:40:27 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(t_app *app, int code)
{
	ft_app_clear(app);
	ft_env_clear(app);
	ft_cmd_clear(app);
	ft_doc_clear(app);
	exit(code);
}

void	ft_exit_failure(t_app *app, const char *message)
{
	if (message && ft_strlen(message))
		ft_output_failure(message);
	ft_exit(app, EXIT_FAILURE);
}

void	ft_exit_success(t_app *app, const char *message)
{
	if (message && ft_strlen(message))
		ft_output_success(message);
	ft_exit(app, EXIT_SUCCESS);
}
