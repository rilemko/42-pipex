/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:47:00 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/23 17:07:09 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_process(t_app *app, char **envp);
static void	ft_fork(t_app *app, char **envp, int index);
static void	ft_dup2(int input, int output);
static void	ft_isleep(size_t iteration);

int	main(int argc, char **argv, char **envp)
{
	t_app	app;

	ft_app_initialize(&app, argc, argv);
	ft_env_initialize(&app, envp);
	ft_cmd_initialize(&app, argc, argv);
	ft_doc_initialize(&app, argv);
	ft_process(&app, envp);
	ft_exit_success(&app, NULL);
}

static void	ft_process(t_app *app, char **envp)
{
	int	index;

	index = -1;
	while (++index < (int) app->cmd.count)
		if (pipe(app->pipe + 2 * index) == -1)
			ft_exit_failure(app, strerror(errno));
	index = -1;
	while (++index < (int) app->cmd.count)
		ft_fork(app, envp, index);
}

static void	ft_fork(t_app *app, char **envp, int index)
{
	int		index1;

	if (fork() == 0)
	{
		if (app->cmd.count == 1)
			ft_dup2(app->input_fd, app->output_fd);
		else if (index == 0)
			ft_dup2(app->input_fd, app->pipe[1]);
		else if (index == ((int) app->cmd.count - 1))
			ft_dup2(app->pipe[2 * index - 2], app->output_fd);
		else
			ft_dup2(app->pipe[2 * index - 2], app->pipe[2 * index + 1]);
		index1 = -1;
		while (++index1 < ((int) app->cmd.count * 2))
			close(app->pipe[index1]);
		if (ft_lstgetpos(app->cmd.cmds, index))
			execve(ft_lstgetpos(app->cmd.cmds, index),
				ft_split(ft_lstgetpos(app->cmd.args, index), ' '), envp);
		exit(EXIT_FAILURE);
	}
	else
		if (ft_strnstr(ft_lstgetpos(app->cmd.args, index), "/dev/random",
				ft_strlen(ft_lstgetpos(app->cmd.args, index))))
			return (ft_isleep(4000000));
}

static void	ft_dup2(int input, int output)
{
	dup2(input, 0);
	dup2(output, 1);
}

static void	ft_isleep(size_t iteration)
{
	int		index;

	index = 0;
	while (index < ((int) iteration * 1000))
		index++;
}
