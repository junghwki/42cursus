#include "minishell.h"

void	put_face(void)
{
	printf("o-------------------------.--------~--------.-------------------------o\n");
	printf("|                          \\   minishell   /                          |\n");
	printf("|                           \\_____________/                           |\n");
	printf("|      _(@)_                            _.-=-._                       |\n");
	printf("|    /.~'\"'~.\\   .---------------.     /  ///\\ \\   .---------------.  |\n");
	printf("|   |/--- ---\\| <  Hello, Cadet! |    | /-- --\\_| <  Hello, Cadet! |  |\n");
	printf("|  (]  O)_ O) [) | I am junghwki |   (|/ O)_ O) |) |  I am wopark  |  |\n");
	printf("|   (  .___,  )  '---------------'     \\ .___, /   '---------------'  |\n");
	printf("|    \\__  .__/                          \\_   _/                       |\n");
	printf("|                                                                     |\n");
	printf("o----------------------------------~----------------------------------o\n");
}

void		ft_sep_env(char **envv)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (envv[j])
	{
		while (envv[j][i])
		{
			
			i++;
		}
		j++;
	}
}

int			main(int argc, char **argv, char **envv)
{
	int		read_ret;
	char 	*buff;
	char	**array;

	buff = (char *)malloc(1000);
	put_face();
	while (1)
	{
		write(1, "minishell$ ", 11);
		read_ret = read(0, buff, 1000);
		array = ft_split(buff, ' ');
		if (!(ft_strcmp(array[0], "echo")))
			printf("%s",array[1]);
		// else if (!(ft_strcmp(array[0], "cd")))
		// {

		// }
		else if (!(ft_strcmp(array[0], "pwd")))
		{
			printf("%s",);
		}
		// else if (!(ft_strcmp(array[0], "export")))
		// {

		// }
		// else if (!(ft_strcmp(array[0], "unset")))
		// {

		// }
		// else if (!(ft_strcmp(array[0], "env")))
		// {

		// }
		// else if (!(ft_strcmp(array[0], "exit")))
		// {

		// }
		// else
		// {

		// }
	}
	(void)argv;
	(void)argc;
	return (0);
	printf("%s\n",envv[10]);
}
