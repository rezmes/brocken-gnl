#include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2)
{
		char *start1;
		int i = 0;
		int j = 0;

		if (s1 == NULL)
				s1 = "";
		while (s1[i])
				i++;
		while (s2[j])
				j++;
		start1 = (char *)malloc(sizeof(char) * (i + j + 1));
		if (!start1)
				return NULL;
		i = 0;	
		while (*s1)
				start1[i++] = *s1++;
		while (*s2)
				start1[i++] = *s2++;
		start1[i] = '\0';
		return (start1);
}


#include <stdio.h>
#include <string.h>
int main()
{
		char s1[] = "abc";
		char s2[] = "def";
 		char *s3 = NULL;
		char s4[] = "XYZ";
		char s5[] = "";
		char s6[] = "abc";

		char *result1 = ft_strjoin(s1, s2);
		printf(":%s:\n", result1);
		free (result1);
		char *result2 = ft_strjoin(s3, s4);
		printf(":%s:\n", result2);
		free (result2);
		char *result3 = ft_strjoin(s5, s6);
		printf(":%s:\n", result3);
		free (result3);
		return (0);
}
