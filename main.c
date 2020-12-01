#include "ft_printf.h"
#include <stdio.h>
#include <string.h>

void	ft_test(char *str, char *a1, int a2, char a3, unsigned int a4)
{
	int originalLen;
	int len;

	printf("------- Original PRINTF -------\n");
	originalLen = printf(str, a1, a2, a3, a4);
	printf("LEN : %d\n", originalLen);
	printf("------- FT_PRINTF -------\n");
	len = ft_printf(str, a1, a2, a3, a4);
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
	ft_test("Salut les gens %s %d %c %u\n", "(argument stylax mamen)", 42, 'B', (unsigned int)424242424242);
}


