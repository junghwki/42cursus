#include <stdio.h>
#include <unistd.h>
#include <string.h>

size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char * dst, const char * src);
ssize_t	ft_read(int fildex, void *buf, size_t nbyte);
ssize_t	ft_write(int fildex, void *buf, size_t nbyte);

int	main(void)
{
	char a[15];

	printf("\n-======<<< strlen >>>======-\n");
	printf("lib = %zu\n", strlen("Hello "));
	printf("own = %zu\n", ft_strlen("Hello "));
	printf("lib = %zu\n", strlen("World!"));
	printf("own = %zu\n", ft_strlen("World!"));
	printf("lib = %zu\n", strlen("Hello World!"));
	printf("own = %zu\n", ft_strlen("Hello World!"));
	printf("-======<<< strlen >>>======-\n");

	printf("\n-======<<< strcmp >>>======-\n");
	printf("lib = %d\n", strcmp("Hello ", "World!"));
	printf("own = %d\n", ft_strcmp("Hello ", "World!"));
	printf("lib = %d\n", strcmp("Hello World!", "Hello World!"));
	printf("own = %d\n", ft_strcmp("Hello World!", "Hello World!"));
	printf("lib = %d\n", strcmp("World!", "Hello "));
	printf("own = %d\n", ft_strcmp("World!", "Hello "));
	printf("-======<<< strcmp >>>======-\n");

	printf("\n-======<<< strdup >>>======-\n");
	printf("lib = %s\n", strdup("Hello "));
	printf("own = %s\n", ft_strdup("Hello "));
	printf("lib = %s\n", strdup("World!"));
	printf("own = %s\n", ft_strdup("World!"));
	printf("-======<<< strdup >>>======-\n");

	printf("\n-======<<< strcpy >>>======-\n");
	printf("lib = %s\n", strcpy(a, "Hello "));
	printf("lib = %s\n", ft_strcpy(a, "Hello "));
	printf("lib = %s\n", strcpy(a, "World!"));
	printf("lib = %s\n", ft_strcpy(a, "World!"));
	printf("-======<<< strcpy >>>======-\n");
	
	printf("\n-======<<< write >>>======-\n");
	write(1, "lib = Hello world!", 18);
	ft_write(1, "\nown = Hello world!", 19);
	printf("\nlib return = %zd\n", write(-1,"Hello \n",7));
	printf("own return = %zd\n", ft_write(-1,"Hello \n",7));
	printf("-======<<< write >>>======-\n");
	return (0);
}
