#include <unistd.h>
#include <stdlib.h>
//#include <fctl.h>

int	ft_strlen(char *str)
{
		int len = 0;

		while (str && str[len]) //I'd forgotten to check `str` too.
				len++;
		return (len);
}

char *ft_strjoin(char *s1, char *s2)
{
		char *result;
		int i = 0;
		int len = 0;

		len = ft_strlen(s1) + ft_strlen(s2);
		result = (char *)malloc(sizeof(char) * (len + 1));
		if (!result)
				return NULL;
		while (s1 && *s1)
				result[i++] = *s1++;
		while (*s2)
				result[i++] = *s2++;
		result[i] = '\0';
		return (result);
}

// I had forgotten what functions we had before ft_extract. I mean I'd forgotten even the existance of `ft_trimstash`.
// Now I checked the name and understood that the correct name is `trim_stash`. even if it is not important and could be any name but the point is that I've forgotten it in a day.

char *extract_line(char *str)
{
		char *result;
		int i = 0;

		if (!str || !*str)
				return NULL;
		while (str[i] && str[i] != '\n')
				i++;
		if (str[i] == '\n')
				i++;
		result = (char *)malloc(sizeof(char) * (i + 1));
		if (!result)
				return NULL;
//		if (!str)
//				return NULL;
//		while (str && *str && *str !='\n')
		i = 0;
		while (*str && *str !='\n')
				result[i++] = *str++;
		if (*str == '\n')
		{
				result[i] = *str;
				i++;
		}
		result[i] = '\0';
		return (result);
}

//char *ft_extract(char *str) again I forgot the name of function :))
char *trim_stash(char *str)
{
		char *result;
		int i = 0;
		int j = 0;

		if (!str)
				return NULL;
		while (str[i] && str[i] != '\n')
				i++;
		if (!str[i])
				return NULL;
		if (str[i] == '\n')
				i++;
		while (str[i + j])
				j++;
		if ( j == 0)
				return NULL;
		result = (char *)malloc(sizeof(char) * (j + 1));
		if (!result)
				return NULL;
		j = 0;
		while (str[i + j])
		{
				result[j] = str[i + j];
				j++;
		}
		result[j] = '\0';
		return (result);
}

char	*read_once(int fd)
{
		int bytes;
		char *buf;
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
				return NULL;
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
				free(buf);
				return 	NULL;
		}

		buf[bytes] = '\0';

		return (buf);
}

char *ft_strchr(char *str, char c)
{
		while (str && *str && *str != c)
				str++;
		if (!str || !*str)
				return NULL;
		return (str);
}


char *read_to_stash(int fd, char *stash)
{
		char	*newstash;
		char	*buf;
		if (!(buf = read_once(fd)))
		{
				free(buf);
				free(stash);
				return NULL;
		}
		if (!*buf)
		{
				free(buf);
				return (stash);
		}
		newstash = ft_strjoin(stash, buf);
		if (!newstash)
		{
				free(stash);
				free(buf);
				return NULL;
		}
		free(stash);
		stash = newstash;
		free(buf);
		if  (*stash && !ft_strchr(stash,'\n'))
				return (read_to_stash(fd, stash));
		return (stash);
}


char  *gnl(int fd)
{
		static char *stash;

		while (*stash)
		{
				stash = read_to_stash(fd, stash);
				if(!stash)
				{
						free(stash);
						return NULL;
				}
				free(stash);
		}
		return (line);
}

#include <fcntl.h>
#include <stdio.h>

int main()
{
        int fd = open("./file", O_RDONLY);
        char *result = read_to_stash(fd, NULL);

        printf(":%s:\n", result);
        free(result);
        close(fd);

   		fd = open("./f1", O_RDONLY);
        char *resultf1 = read_to_stash(fd, NULL);

        printf(":%s:\n", resultf1);
        free(resultf1);
        close(fd);

       fd = open("./f2", O_RDONLY);
       char *resultf2 = read_to_stash(fd, NULL);

        printf(":%s:\n", resultf2);
        free(resultf2);
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

		return (0);
}


        result = extract_line("ab\ncd"); // ->  :ab\n:      (ﯽﻌﻨﯾ ab ﻭ ﺐﻋﺩ ﺦﻃ ﺥﺎﻠﯾ)
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

