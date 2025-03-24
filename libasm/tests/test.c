#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "libasm.h"

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

	printf("\n------------------write error (fd = -1)------------------\n");
	const char *msg_err = "Erreur volontaire\n";
	errno = 0;
	ssize_t ft_write_err = ft_write(-1, msg_err, strlen(msg_err));
	int ft_write_errno = errno;
	errno = 0;
	ssize_t sys_write_err = write(-1, msg_err, strlen(msg_err));
	int sys_write_errno = errno;
	printf("ft_write retour: %zd, errno: %d\n", ft_write_err, ft_write_errno);
	printf("write retour: %zd, errno: %d\n", sys_write_err, sys_write_errno);
	if (ft_write_err == -1 && ft_write_errno == sys_write_errno)
		printf("✅ Gestion d'erreur correcte pour ft_write\n");
	else
		printf("❌ Mauvaise gestion d'erreur pour ft_write\n");

		printf("\n------------------read------------------\n");
	char buffer[100];
	printf("Tape quelque chose (max 100 caractères) : ");
	ssize_t bytes_read_ft = ft_read(0, buffer, sizeof(buffer) - 1);
	buffer[bytes_read_ft > 0 ? bytes_read_ft : 0] = '\0';
	printf("ft_read a lu %zd octets: %s\n", bytes_read_ft, buffer);

	printf("\n------------------read error (fd = -1)------------------\n");
	errno = 0;
	ssize_t ft_read_err = ft_read(-1, buffer, 10);
	int ft_errno = errno;
	errno = 0;
	ssize_t sys_read_err = read(-1, buffer, 10);
	int sys_errno = errno;
	printf("ft_read retour: %zd, errno: %d\n", ft_read_err, ft_errno);
	printf("read retour: %zd, errno: %d\n", sys_read_err, sys_errno);
	if (ft_read_err == -1 && ft_errno == sys_errno)
		printf("✅ Gestion d'erreur correcte pour ft_read\n");
	else
		printf("❌ Mauvaise gestion d'erreur pour ft_read\n");

	return 0;
}