/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:44:05 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/23 16:51:59 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_doc_validate(t_app *app);

void	ft_doc_clear(t_app *app)
{
	(void) app;
	if (ft_isfile(app->doc.tempname) && (unlink(app->doc.tempname) != 0
			|| ft_isfile(app->doc.tempname)))
		ft_output_failure("Cannot delete temp file");
}

void	ft_doc_initialize(t_app *app, char **argv)
{
	char	buffer[200000];
	char	*line;

	if (app->offset == 0)
		return ;
	ft_bzero(&buffer, 200000);
	while (1)
	{
		ft_output("here_doc > ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (!ft_strncmp(line, argv[2], ft_strlen(argv[2]))
			&& (ft_strlen(argv[2]) == ft_strlen(line) - 1))
			break ;
		ft_strlcat(buffer, line, 200000);
		free(line);
	}
	free(line);
	ft_bzero(&buffer[ft_strlen(buffer) - 1], 1);
	app->input_fd = open(app->doc.tempname, O_CREAT | O_RDWR | O_TRUNC, 0775);
	ft_output(buffer, app->input_fd);
	close(app->input_fd);
	app->input_fd = open(app->doc.tempname, O_RDONLY);
	ft_doc_validate(app);
}

static void	ft_doc_validate(t_app *app)
{
	if (!ft_isfile(app->doc.tempname))
		ft_exit_failure(app,
			"Permission denied : Cannot create temporary file");
	if (app->input_fd == -1)
		ft_exit_failure(app, "Permission denied : Cannot open temporary file");
}
