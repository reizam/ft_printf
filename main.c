#include "ft_printf.h"
#include <stdio.h>
#include <string.h>

void	ft_test(char *str, char *a1, int a2, char a3, unsigned int a4, unsigned int a5, void* a6)
{
	int		originalLen;
	int		len;

	printf("------- ORIGINAL PRINTF -------\n");
	originalLen = printf(str, a1, a2, a3, a4, a5, a6);
	printf("LEN : %d\n", originalLen);
	printf("------- FT_PRINTF -------\n");
	len = ft_printf(str, a1, a2, a3, a4, a5, a6);
	printf("LEN : %d\n", len);
	if (originalLen == len)
	{
		printf("\033[1;32m");
		printf("SUCCESS - Same len\n");
		printf("\033[0;32m");
	}
	else
	{
		printf("\033[1;31m");
		printf("FAILURE - Not the same len\n");
		printf("\033[0;31m");
	}
}

int main (void)
{
	int len;
	len = printf("%*.*i\n", 0, -2, 8);
	printf("LEN : %d\n", len);
	len = ft_printf("%*.*i\n", 0, -2, 8);
	printf("LEN : %d\n", len);
	// ft_test("Salut les gens %s %d %c %X %x %.20p\n", "(argument stylax mamen)", 42, 'B', 21021, 5120, (void*)"saluutlesgernsrjij");
}


