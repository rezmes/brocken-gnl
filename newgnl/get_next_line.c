#include <unistd.h>
#include <stdlib.h>

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

int ft_strlen(char *s)
{
		int len = 0;

		while (s[len])
				len++;
		return (len);
}

char *ft_strjoin(char *s1, char *s2)
{
		char *result;
		int i;
		
		if (s1 && *s1)
				i = ft_strlen(s1) + ft_strlen(s2);
		else
				i = ft_strlen(s2);
		result = (char *)malloc(sizeof(char) * (i + 1));
		if (!result)
				return NULL;
		i = 0;
		while (s1 && *s1)
		{
				result[i] = *s1++;
				i++;
		}
		while (*s2)
		{
				result[i] = *s2++;
				i++;
		}
		result[i] = '\0';
		return (result);
}

char *extract_line(char *stash)
{
		char *result;
		int	i = 0;

		if (!stash || !stash[i])
			   return NULL;
		while (stash[i] && stash[i] != '\n')
				i++;
		if (stash[i] == '\n')
				i++;
		result = (char *)malloc(sizeof(char) * (i + 1));
		if (!result)
				return NULL;
		i = 0;
		while (stash && stash[i] && stash[i] != '\n')
		{
				result[i] = stash[i];
				i++;
		}
		if (stash[i] == '\n')
		{
				result[i] = stash[i];
				i++;
		}
		result[i] = '\0';

		return (result);
}

#include <stdio.h>
int main()
{
		char *result;
/*
		result = ft_strjoin(NULL, "XYZ");
		printf(":%s:\n", result);
		free(result);
		result = ft_strjoin("", "XYZ");
		printf(":%s:\n", result);
		free(result);
		result = ft_strjoin("XYZ", "");
		printf(":%s:\n", result);
		free(result);
		result = ft_strjoin("", "");
		printf(":%s:\n", result);
		free(result);
		result = ft_strjoin(NULL, "");
		printf(":%s:\n", result);
		free(result);
*/
		result = extract_line("ab\ncd"); // ->  :ab\n:      (یعنی ab و بعد خط خالی)
		printf(":%s:\n", result);
		free(result);
		result = extract_line("abcd");   // ->  :abcd:
		printf(":%s:\n", result);
		free(result);
		result = extract_line("\nabc");  // ->  :\n:
		printf(":%s:\n", result);
		free(result);
		result = extract_line("");       // ->  :(null):
		printf(":%s:\n", result);
		free(result);
		result = extract_line(NULL);     // ->  :(null):
		printf(":%s:\n", result);
		free(result);
/*
		printf(":%s:\n",ft_strchr("abcd", '\n'));
		printf(":%s:\n", ft_strchr("ab\ncd", '\n'));
		printf(":%s:\n", ft_strchr(NULL, '\n'));
*/
		return (0);
}
