/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:59:51 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/23 16:54:13 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_cmd_findpath(t_app *app, const char *command);
static void	ft_cmd_validate(t_app *app, char **argv);

void	ft_cmd_clear(t_app *app)
{
	if (app->cmd.initialized)
	{
		ft_lstclear(&app->cmd.args, free);
		ft_lstclear(&app->cmd.cmds, free);
	}
}

void	ft_cmd_initialize(t_app *app, int argc, char **argv)
{
	size_t	index;
	char	**command;

	index = 1;
	if (app->offset != 0)
		index++;
	while (++index < ((size_t) argc - 1))
	{
		command = ft_split(argv[index], ' ');
		ft_lstadd_back(&app->cmd.cmds, ft_lstnew(
				ft_cmd_findpath(app, command[0]))
			);
		ft_lstadd_back(&app->cmd.args, ft_lstnew(ft_strdup(argv[index])));
		ft_free_deep((void **) command);
		app->cmd.count++;
	}
	app->cmd.initialized = 1;
	ft_cmd_validate(app, argv);
}

static char	*ft_cmd_findpath(t_app *app, const char *command)
{
	int		index;
	char	*filename;

	if (ft_isreadable(command))
		return (ft_strdup(command));
	index = -1;
	filename = NULL;
	while (app->env.paths[++index])
	{
		filename = ft_strjoin(app->env.paths[index], "/");
		filename = ft_strmjoin(filename, command);
		if (ft_isreadable(filename))
			return (filename);
		ft_free(filename);
	}
	return (NULL);
}

static void	ft_cmd_validate(t_app *app, char **argv)
{
	size_t	index;
	t_lst	*next;

	index = 2;
	next = app->cmd.cmds;
	while (next)
	{
		if (next->content == NULL)
		{
			ft_output("\033[0;33m[Warning] > Command not found : ",
				STDOUT_FILENO);
			ft_output(argv[app->offset + index], STDOUT_FILENO);
			ft_output("\033[0;0m\n", STDOUT_FILENO);
		}
		next = next->next;
		index++;
	}
}
