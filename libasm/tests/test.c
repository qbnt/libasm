#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s);
char*	ft_strcpy(char* dst, const char* src);

int main() {
    const char *str = "Hello 42!";
	char dest[200] = "";
	printf("\n------------------strlen------------------\n");
    printf("ft_strlen(\"%s\") = %zu\n", str, ft_strlen(str));
	printf("strlen(\"%s\") = %zu\n", str, strlen(str));
	printf("\n------------------strcpy------------------\n");
	printf("dest avant: %s\n", dest);
	ft_strcpy(dest, str);
	printf("dest apres: %s\n", dest);

    return 0;
}