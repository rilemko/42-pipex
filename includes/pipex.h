/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:38:03 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/23 16:49:38 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "_includes.h"
#include "_definitions.h"

void	ft_app_clear(t_app *app);
void	ft_app_initialize(t_app *app, int argc, char **argv);
void	ft_cmd_clear(t_app *app);
void	ft_cmd_initialize(t_app *app, int argc, char **argv);
void	ft_doc_clear(t_app *app);
void	ft_doc_initialize(t_app *app, char **argv);
void	ft_env_clear(t_app *app);
void	ft_env_initialize(t_app *app, char **envp);
void	ft_exit(t_app *app, int code);
void	ft_exit_failure(t_app *app, const char *message);
void	ft_exit_success(t_app *app, const char *message);
int		ft_isfile(const char *filename);
int		ft_isreadable(const char *filename);
int		ft_iswriteable(const char *filename);
void	ft_output(const char *message, int fd);
void	ft_output_failure(const char *message);
void	ft_output_success(const char *message);
void	ft_output_warning(const char *message);
