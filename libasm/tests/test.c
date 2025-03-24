#include <stdio.h>
#include <string.h>

size_t ft_strlen(const char *s); // déclaration de ta fonction

int main() {
    const char *str = "Hello 42!";
    printf("ft_strlen(\"%s\") = %zu\n", str, ft_strlen(str));
	printf("strlen(\"%s\") = %zu\n", str, strlen(str));
    return 0;
}