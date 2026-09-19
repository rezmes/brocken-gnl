#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

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

char *trim_stash(char *stash)
{
		char *result;
		int i = 0;
		int j = 0;
		if (!stash || !*stash)
				return NULL;
		while (stash[i] && stash[i] != '\n')
				i++;
		if (stash[i] == '\0')
			   return NULL;
		if (stash[i] == '\n')
		{
			i++;
			if (stash[i] == '\0')
					return NULL;
		}
		while (stash[i+j])
				j++;
		result = (char *)malloc(sizeof(char) * (j + 1));
		if (!result)
				return NULL;
		j = 0;
		while (stash[i + j])
		{
				result[j] = stash[i + j];
				j++;
		}
		result[j] = '\0';
		return (result);
}

char	*read_once(int fd)
{
		char *buff;
		int result;
		int i = 0;

		fd = open("./file", O_RDONLY);
		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
				return NULL;

		while (i <= BUFFER_SIZE)
		{
				buff[i] = ;
				i++;
		}


		result = read(fd, buff, BUFFER_SIZE);
		if (result == -1)
				return NULL;
		buff[i] = '\0';
		return (buff);
}

#include <unistd.h>
#include <stdlib.h>

char    *read_once(int fd)
{
        char *buff;
        int result;

        buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!buff)
                return NULL;
        result = read(fd, buff, BUFFER_SIZE);
        if (result == -1)
        {
                free(buff);
                return NULL;
        }
        buff[result] = '\0';
        return (buff);
}

#include <fcntl.h>
#include <stdio.h>

int main()
{
        int fd = open("./file", O_RDONLY);
        char *result = read_once(fd);

        printf(":%s:\n", result);
        free(result);
        close(fd);

        return (0);
}
/*
#include <stdio.h>
int main()
{
		char *result;

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

		result = trim_stash("ab\ncd"); 
		printf(":%s:\n", result);
		free(result);
		result = trim_stash("ab\n");
		printf(":%s:\n", result);
		free(result);
		result = trim_stash("abcd");
		printf(":%s:\n", result);
		free(result);
		result = trim_stash("\nabc");
		printf(":%s:\n", result);
		free(result);
		result = trim_stash("");
		printf(":%s:\n", result);
		free(result);
		result = trim_stash(NULL);
		printf(":%s:\n", result);
		free(result);

	
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


		printf(":%s:\n",ft_strchr("abcd", '\n'));
		printf(":%s:\n", ft_strchr("ab\ncd", '\n'));
		printf(":%s:\n", ft_strchr(NULL, '\n'));

		return (0);
}
*/
