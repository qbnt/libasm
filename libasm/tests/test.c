#include <stdio.h>
#include <string.h>
#include <unistd.h>

size_t	ft_strlen(const char *s);
char*	ft_strcpy(char* dst, const char* src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t count);

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
	printf("strcpy(\"dest\", \"%s\") = %s\n", str, strcpy(dest, str));
	strcpy(dest, "");
	ft_strcpy(dest, str);
	printf("\n");
	if (strcmp(dest, str) == 0)
		printf("✅ ft_strcpy fonctionne comme strcpy\n");
	else
		printf("❌ ft_strcpy ne copie pas correctement\n");

	printf("\n------------------strcmp------------------\n");
	const char *s1 = "42";
	const char *s2 = "42";
	const char *s3 = "42Network";
	const char *s4 = "41";

	printf("ft_strcmp(\"%s\", \"%s\") = %d\n", s1, s2, ft_strcmp(s1, s2));
	printf("strcmp(\"%s\", \"%s\") = %d\n", s1, s2, strcmp(s1, s2));
	printf("\n");
	printf("ft_strcmp(\"%s\", \"%s\") = %d\n", s1, s3, ft_strcmp(s1, s3));
	printf("strcmp(\"%s\", \"%s\") = %d\n", s1, s3, strcmp(s1, s3));
	printf("\n");
	printf("ft_strcmp(\"%s\", \"%s\") = %d\n", s1, s4, ft_strcmp(s1, s4));
	printf("strcmp(\"%s\", \"%s\") = %d\n", s1, s4, strcmp(s1, s4));

	printf("\n------------------write------------------\n");
	const char *msg = "Hello from ft_write!\n";
	ssize_t bytes_written_ft = ft_write(1, msg, strlen(msg));
	ssize_t bytes_written_sys = write(1, msg, strlen(msg));
	printf("\n");
	printf("ft_write a écrit %zd octets\n", bytes_written_ft);
	printf("write a écrit %zd octets\n", bytes_written_sys);
	printf("\n");
	if (bytes_written_ft == bytes_written_sys)
		printf("✅ ft_write fonctionne comme write\n");
	else
		printf("❌ ft_write diffère de write\n");

    return 0;
}