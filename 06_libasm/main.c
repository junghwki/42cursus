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
	char *b = "Hello ";
	char *c = "World !";

	printf("\n<<< strlen >>>\n");
	printf("lib = %zu\n", strlen(b));
	printf("own = %zu\n", ft_strlen(b));
	printf("\n<<< strlen >>>\n");

	printf("\n<<< strcmp >>>\n");
	printf("lib = %d\n", strcmp(b, c));
	printf("own = %d\n", ft_strcmp(b, c));
	printf("lib = %d\n", strcmp(c, b));
	printf("own = %d\n", ft_strcmp(c, b));
	printf("\n<<< strcmp >>>\n");

	printf("\n<<< strdup >>>\n");
	printf("lib = %s\n", strdup(b));
	printf("own = %s\n", ft_strdup(b));
	printf("lib = %s\n", strdup(c));
	printf("own = %s\n", ft_strdup(c));
	printf("\n<<< strdup >>>\n");

	printf("\n<<< strcpy >>>\n");
	printf("lib = %s\n", strcpy(a, b));
	printf("lib = %s\n", ft_strcpy(a, b));
	printf("lib = %s\n", strcpy(a, c));
	printf("lib = %s\n", ft_strcpy(a, c));
	printf("\n<<< strcpy >>>\n");
	
	printf("\n<<< write >>>\n");
	write(1, "lib = Hello world!", 18);
	ft_write(1, "\nown = Hello world!", 19);
	printf("\nlib return = %zd\n", write(-1,"Hello \n",7));
	printf("own return = %zd\n", ft_write(-1,"Hello \n",7));
	printf("\n<<< write >>>\n");
	return (0);
}