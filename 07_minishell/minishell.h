
#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct			s_env_lst {
	char				*key;
	char 				*value;
	struct s_env_lst	*next;
}						t_env_lst;

char				**ft_split(const char *s, char c);
int					ft_strcmp(const char *s1, const char *s2);

#endif