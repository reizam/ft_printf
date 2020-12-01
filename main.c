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
	ft_test("Salut les gens %%d %s %d %c %.X %x %p\n", "(argument stylax mamen)", 42, 'B', 42312312, 123123213, (void*)"saluutlesgernsrjij");
}


