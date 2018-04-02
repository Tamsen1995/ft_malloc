#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>

int main(int ac, char **argv)
{
	int i;
	int nb;
	char c;
	char *str;

	nb = atoi(argv[2]);
	c = argv[1][0];
	str = (char *)mmap(0, nb + 1, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

	i = 0;
	ac = 0;
	while (i < nb)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	printf("%s\n", str);
	return (0);
}