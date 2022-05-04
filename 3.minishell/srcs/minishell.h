/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:47:45 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/01/07 18:21:14 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <signal.h>
# include <fcntl.h>
#include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>

/* 함수의 성공 여부 */
/* `if (!func()) then failed` 를 고려하여 선언 */
# define FUNC_FAIL		0
# define FUNC_SUC		1

# define STDIN			0
# define STDOUT			1
# define STDERR			2

# define BUFFER_SIZE	1024

# define CTRL_D			-3

/* 명령어 토큰 타입*/
# define T_NULL 0
# define T_WORD 1
# define T_PIPE 2
# define T_REDIRECT 3

# define T_DOUBLE_QUOTES 4
# define T_SINGLE_QUOTES 5
# define T_ENVP 6
# define T_ENVP_DQUOTES 7

# define L_PIPE 10			/* 명령어(11)과 파이프(10)의 집합 */
# define L_CMD 11			/* 명령어(12)와 리디렉트(14)의 집합 */
# define L_SIMPLE_CMD 12	/* 명령어(19 + 13)의 집합 */
# define L_ARGV 13			/* execve의 argv[] 인자에 들어갈 명령어(명령어 경로(19) + 명령어 문자열(17)))의 집합 */
# define L_REDIR 14			/* 리디렉트(15)와 리디렉트(14)의 집합 */
# define L_IO_REDIR 15		/* 리디렉트 기호(16)와 리디렉트 대상 파일이름(18)의 모임 */
# define L_REDIR_TK 16		/* 리디렉트 기호 */
# define L_ARGS 17			/* L_ARGV의 명령어 문자열의 집합*/
# define L_RFNAME 18		/* 리디렉트 대상 파일 이름 문자열 */
# define L_FPATH 19			/* 명령어 경로 문자열 */

# define TEMPFILE "assadf87b67s7d6"
/* 구조체 선언 */
/* 전역 변수를 저장하기 위한 연결리스트 */
typedef struct  s_env_node
{
    struct  s_env_node	*next;
    char        		*data;

}               t_env_node;

typedef struct	s_env_list
{
	t_env_node *head;
	t_env_node *tail;
	char *home_path;
	int len;
}				t_env_list;

/* parsing의 토큰 구조체 */
typedef struct	s_token
{
	struct s_token	*prev;
	struct s_token	*next;
	char		*str;
	int			type;
	int			l_type;
}				t_token;


/* 파싱 예외처리 및 따옴표 병합에 사용되는 구조체 */
/* i, j 등은 단순 반복문을 위한 변수 */
typedef struct s_quote
{
	char		*str;
	int			is_redir;
	int			is_pipe;
	int			is_quoting;
	int			checked;
	char		redir;
	char		quot;
	int			i;
	int			j;
	int			n;
}				t_quote;

/* 파싱 도중 환경변수를 적용하기 위한 구조체 */
typedef struct s_token_env
{
	char		*env;
	char		*env_value;
	char		*buff;
	int			is_env;
	int			i;
	int			start;
	int			end;
}				t_token_env;

/* 토큰을 재귀 하향 파싱 형식으로 저장하는 트리의 구조체 */
/* 구현 참고 문서 : https://epicarts.tistory.com/163 */
/* 문법 참고 문서 : https://www.geeksforgeeks.org/developing-linux-based-shell/ */
typedef struct s_tree
{
	struct s_tree	*root;
	struct s_tree	*left;
	struct s_tree	*right;
	int				cmd_type;
	int				done;
	char			*str;
}					t_tree;

typedef struct	s_param
{
	char **argv;
	char **envp;
}				t_param;

/* 쉘의 모든 데이터를 저장하기 위한 구조체 */
typedef struct s_data
{
	int			error_code;		/* 에러 코드 */
    int			exit_code;		/* 종료 코드 */
	int			delete_home;	/* home 경로 유무 체크 */
    char		**env_path;		/* PATH 저장소 */
	t_env_list	*env_list;		/* 전역 변수 저장소 */
	t_tree		*tree;
	t_tree		*head;
	t_tree		*next_cmd;		/* redirection시 실행할 명령어 저장소 */
	t_param		*param;			/* execve를 실행시키기 위한 인자 */
}				t_data;

/* 전역 변수 선언 */
t_data   g_data;

/* /init/init.c */
char	**node_to_str(t_env_node *target);
int init_data(char **envp);
int init_param(char **argv);

/* /error/error.c */
int ft_strerror_exit(char *errstr);
void	ft_builtin_err(char *str1, char *str2, int errnum);
void ft_custom_err(char *str1, char *str2);
void ft_custom_err2(char *str1, char *str2, char *str3);
void	ft_redirection_err(char *str, int errnum);

/* /utils/utils.c */
void	free_str(char **str);
char	*remade_err_str(char *str1, char *str2, char *str3);
char	*ft_strjoin_token(char *s1, char *s2);
char	*delete_quote(char *str);
char	*get_path(char *str);

/* /utils/env_node_utils.c */
char *get_env_data(char *name);

/* /utils/env_list_utils.c */
int add_env_node(t_env_list *list, char *data);
int search_env_node(t_env_list *list, char *data);
void	delete_env_node(t_env_list *list, char *data);
void	delete_middle_env_node(t_env_list *list, int pos);
void	delete_end_env_node(t_env_list *list, int pos);

/* /utils/token_utils.c */
int	add_token_back(t_token **token, int type, char *str);
int	add_token_front(t_token **token, int type, char *str);
void	del_token_back(t_token **token);
void	del_token_front(t_token **token);

/* /utils/utils_signal.c */
void	set_signal();

/* /utils/tree_utils.c */
t_tree	*make_node(int l_type, char *str);
int	add_root_left_node(t_tree **head, int l_type, char *str);
int	add_root_right_node(t_tree **head, int l_type, char *str);
int	add_child_left_node(t_tree **head, int l_type, char *str);
int	add_child_right_node(t_tree **head, int l_type, char *str);

/* /utils/env_node_utils.c */
char *get_env_data(char *name);
void change_node_data(char *name, char *data);

/* /parsing/parsing_utils.c */
int	is_word(char *str, int i);
void	init_quote(t_quote *quote);
void	set_quote(t_quote *quote, char c, int flag);

/* /parsing/parsing_utils2.c */
int only_has_space(char *str);
int	space_or_end(char *str, int i);
int	is_quot(char c);
int	is_pipe(char c);
int is_redir(char c);

/* /parsing/get_command.c */
int	get_command(char **input);

/* /parsing/check_input.c */
void	check_quote(char c, t_quote *quote);
int	check_input(char *input);

/* /parsing/tokenize_input.c */
int	init_token(char *input, t_token *token);

/* /parsing/tokenize_input2.c */
void	add_token(char **buffer, t_token **token, t_quote *quote);

/* /parsing/treeing_input.c */
void	treeing_input(t_token *token);

/* parsing/treeing_input2.c */
void	add_pipe(int *trigger, t_tree **buff, t_tree **pipe);
void	add_cmd(t_token *tk, int *trigger, t_tree **buff);
void	add_redir(t_token *tk, int *trigger, t_tree **buff);
void	add_redir_p(t_token *tk, int *trigger, t_tree **buff);

/* /execute/tree_traversal.c */
void tree_traversal(t_tree *node);
void exe_node(t_tree *node);
int exe_builtin(t_tree *node);
void exe_redirection(t_tree *node);
int ft_cmd(t_tree *node);

/* /execute/ft_pipe.c */
void ft_pipe(t_tree *node);

/* /builtin/ft_cd.c */
void edit_path_env(char *old_path);
void ft_cd(t_tree *token);

/* /builtin/ft_echo.c */
void ft_echo(t_tree *token);

/* /builtin/ft_env.c */
void get_home_path(void);
int get_all_env(char **envp);
void ft_env(t_tree *n, int option);

/* /builtin/ft_exit.c */
int is_numeric_arg(char *str);
void ft_exit(t_tree *token);

/* /builtin/ft_export.c */
int check_valid_export(char *str);
void export_data(char *data);
void ft_export(t_tree *node);
void export_error_check(char *str);

/* /builtin/ft_pwd.c */
void ft_pwd();

/* /builtin/ft_unset.c */
int check_valid_unset(char *str);
void ft_unset(t_tree *node);

/* /redirection/appending_redirected_output.c */
int appending_redirected_output(t_tree *node);
int do_cmd();

/* /redirection/here_documents.c */
int here_documents(t_tree *node);
void write_file(t_tree *node);
t_tree *make_temp_node();

/* /redirection/redirection_input.c */
int redirecting_input(t_tree *node);

/* /redirection/redirection_output.c */
int redirecting_output(t_tree *node);
void find_next_cmd(t_tree *node);
void set_argv(t_tree *node);

#endif
