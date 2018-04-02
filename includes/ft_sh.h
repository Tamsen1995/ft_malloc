/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:54:59 by tbui              #+#    #+#             */
/*   Updated: 2017/12/08 19:23:05 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H

# include <unistd.h>
# include <stdlib.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/param.h>
# include <signal.h>
# include <fcntl.h>
# include <stdio.h>
# include "../includes/libft.h"
# include "../includes/ft_ls.h"

# define BUFF_SIZE 8
# define BIN "/bin/"
# define T_BOOL int
# define TRUE 1
# define FALSE 0

enum				e_pwd
{
	OLD,
	CUR
};

typedef struct		s_env
{
	struct s_env	*next;
	struct s_env	*prev;
	char			*name;
	char			*value;
}					t_env;

/*
** a  linked list of commands here
** each command is a 2d array
** storing the command itself as well as its
** parameters
*/

typedef struct		s_cmds
{
	struct s_cmds	*next;
	struct s_cmds	*prev;
	char			**args;
}					t_cmds;

typedef struct		s_shell
{
	int				argc;
	char			**args;
	struct s_env	*env;
	struct s_cmds	*cmds;
	char			*path_var;
	char			*home_path;
	char			*bin_dir;
}					t_shell;

char				*get_env_var(t_shell *shell, char *name);
void				free_cmds(t_cmds *cmds);
t_cmds				*store_commands(char *commands);
char				*builtin_cmd_from_path(t_shell *shell);
T_BOOL				check_builtin_path(t_shell *shell);
int					exec_builtin(t_shell *shell);
T_BOOL				check_builtins(char *cmd);
void				change_env_var(char *name, char *value, t_shell *shell);
T_BOOL				check_bin_path(t_shell *shell);
T_BOOL				check_directory(char *dir_path, char *file);
void				get_path_var(t_shell *shell);
void				free_shell(t_shell *shell);
int					sh_unsetenv(char **args, t_shell *shell);
void				ft_putenv(t_env **begin_list, char *name, char *value);
T_BOOL				check_bin_cmd(t_shell *shell);
int					sh_env(t_shell *shell);
int					sh_setenv(char **args, t_shell *shell);
t_env				*init_env(char **envv);
int					get_next_line(int const fd, char **line);
int					sh_execute(char **envv, t_shell *shell);
int					sh_launch(char **envv, t_shell *shell);
int					sh_cd(char **args, t_shell *shell);
int					sh_exit(void);
int					sh_echo(char **args);
t_shell				*init_shell(int ac, char **av, char **envv);

#endif
