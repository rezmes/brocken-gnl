#include <unistd.h>
char *ft_strchr(char *s, int c)
{
		if (!s || !*s)
				return NULL;
		while (*s && *s != c)
				s++;
		if (*s == '\0')
				return NULL;
		return (s);
}

#include <stdio.h>
//int main(int argc, char **argv)
int main()
{
		
		printf("%s:\n",ft_strchr("abcd", '\n'));
		printf("%s:\n", ft_strchr("ab\ncd", '\n'));
		printf("%s:\n", ft_strchr(NULL, '\n'));
		return (0);
}

