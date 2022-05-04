/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 11:16:32 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/09/02 11:42:08 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define INFILE 0
# define OUTFILE 1

void	redir(char *cmd, char **env, int fdin);
void	exec(char *cmd, char **env);
char	*getPath(char *cmd, char **env);
int		openfile(char *filename, int mode);

char	*pathjoin(char *path, char *bin);
int		ft_strncmp(char *str1, char *str2, int n);
int		ft_strchr(char *str, char c);
char	*ft_strndup(char *str, unsigned int n);
char	**ft_split(char *str, char sep);

#endif
