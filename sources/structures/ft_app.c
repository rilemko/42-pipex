/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:48:39 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/23 16:51:53 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_app_validate(t_app *app, char **argv);
static void	ft_app_precheck(t_app *app, int argc);

void	ft_app_clear(t_app *app)
{
	int	index;

	index = -1;
	while (++index < ((int) app->cmd.count * 2))
		close(app->pipe[index]);
	close(app->input_fd);
	close(app->output_fd);
	if (ft_isfile(".tmpin") && (unlink(".tmpin") != 0
			|| ft_isfile(".tmpin")))
		ft_output_failure("Cannot delete temp file");
	if (ft_isfile(".tmpout") && (unlink(".tmpout") != 0
			|| ft_isfile(".tmpout")))
		ft_output_failure("Cannot delete temp file");
}

void	ft_app_initialize(t_app *app, int argc, char **argv)
{
	app->offset = 0;
	app->min_arg = 2;
	ft_app_precheck(app, argc);
	if (!ft_strncmp(argv[1], "here_doc", 8))
		app->offset = 2;
	app->input_fd = -1;
	if (app->offset == 0 && ft_isreadable(argv[1]))
		app->input_fd = open(argv[1], O_RDONLY);
	app->name = argv[0];
	app->output_fd = -1;
	app->output_fd = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0775);
	app->cmd.initialized = 0;
	app->cmd.args = NULL;
	app->cmd.cmds = NULL;
	app->cmd.count = 0;
	app->doc.tempname = "here_doc.txt";
	app->env.initialized = 0;
	ft_app_validate(app, argv);
}

static void	ft_app_precheck(t_app *app, int argc)
{
	if (argc == 1)
		ft_exit_failure(app, "Usage: ./pipex [input] [commands...] [output]");
	if ((app->offset == 2 && argc <= (app->min_arg + 3))
		|| argc <= app->min_arg + 2)
		ft_exit_failure(app, "Too few arguments");
}

static void	ft_app_validate(t_app *app, char **argv)
{
	if (app->offset == 0 && !ft_isfile(argv[1]))
		ft_output_warning("No such input file or directory");
	if (app->offset == 0 && (app->input_fd == -1 || !ft_isreadable(argv[1])))
	{
		ft_output_warning("Input file : Permission denied");
		app->input_fd = open(".tmpin", O_CREAT | O_RDWR | O_TRUNC, 0775);
		if (!ft_isfile(".tmpin"))
			ft_exit_failure(app, strerror(errno));
	}
	if (app->output_fd == -1)
	{
		ft_output_warning("Output file : Permission denied");
		app->output_fd = open(".tmpout", O_CREAT | O_RDWR | O_TRUNC, 0775);
		if (!ft_isfile(".tmpout"))
			ft_exit_failure(app, strerror(errno));
	}
}
