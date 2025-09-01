/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:34:54 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/23 16:52:03 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_env_validate(t_app *app);

void	ft_env_clear(t_app *app)
{
	if (app->env.initialized == 1)
		ft_free_deep((void **) app->env.paths);
}

void	ft_env_initialize(t_app *app, char **envp)
{
	int	index;

	index = -1;
	while (envp[++index])
	{
		if (!ft_strncmp(envp[index], "PATH=", 5))
		{
			app->env.paths = ft_split(ft_strchr(envp[index], '=') + 1, ':');
			app->env.initialized = 1;
			return ;
		}
	}
	ft_env_validate(app);
}

static void	ft_env_validate(t_app *app)
{
	if (app->env.initialized == 0)
		ft_exit_failure(app, "Cannot find {$PATH}");
}
