#include "pipex.h"
int main(int argc, char **argv, char **envp) {
/*	int fd;
	FILE *file;
	if((file = fopen("hola.txt", "r")) == NULL)
		perror("Error");
	//	printf("%s", strerror(errno));
	else
		printf("%i", fd);
*/
/*	for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
*/
    for (char **env = envp; *env != 0; env++) {
        char *thisEnv = *env;
        printf("%s\n", thisEnv);
    }

/*	char *argv1 = argv[1];
	char *temp = ft_strnstr(argv1, ".", ft_strlen(argv1));
*/
	/*if (temp)
	{
		printf("%s", "si");
		argv1 = ft_strjoin(ft_substr(argv1, 0, temp - argv1), ft_substr(temp, 1, ft_strlen(temp)));
	}
	printf("%s", argv1);
*/
/*	int i = access(argv1, F_OK);
	printf("%i", i);
*/	return 0;
}

/*	temp = ft_strnstr(argv, "\"", ft_strlen(argv));
	if (temp)
		argv = ft_strjoin(ft_substr(argv, 0, temp - argv), ft_substr(temp, 0, ft_strlen(temp)));*/
