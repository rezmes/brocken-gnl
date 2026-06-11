/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:39:44 by mmesgari          #+#    #+#             */
/*   Updated: 2026/06/08 16:14:28 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
void    ft_putstr(char *str)
{
        int i;

        i = 0;
        while (str[i])
        { 
                write(1, &str[i], 1);
                i++;
        } 
}

int ft_strlen(char *str)
{
        int (len);

        len = 0;
        while (*str)
        { 
                str++;
                len++;
        } 
        return (len);

}

char	*ft_strcpy(char *dest, char *src)
{
	char *start;

	start = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';

	return (start);
}

int	ft_strcmp(char *str1, char *str2)
{
	int result;
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	result = (int)*str1 - (int)*str2;
	return (result);
}

char *ft_strdup(char *str)
{
    char *dest;
    char *result;
    int len;

    len = ft_strlen(str);
    dest = malloc(sizeof(char) * (len + 1));
    if (!dest)
        return NULL;
    result = dest;
    while (*str)
        *dest++ = *str++;
    *dest = '\0';
    return (result);
}

char *ft_strcat(char *dest, char *src)
{
    int i;

    i = 0;
    while (dest[i])
        i++;
    while (*src)
        dest[i++] = *src++;
    dest[i] = '\0';
    return (dest);
//    char *start;

//    start = dest;
//    while(*dest)
//        *dest++;
//    while(*src)
//        *dest++ = *src++;
//    *dest = '\0';
//    return (start);
}

char *ft_strncat(char *dest, char *src, int n)
{
    int i = 0;
    int j = 0;

    while (dest[i])
        i++;
    while (src[j] && j < n)
        dest[i++] = src[j++];
    dest[i] = '\0';
    return (dest);
}

char *ft_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    while (src[i] && i < n)
    {
        dest[i] = src[i];
        i++;
    }
    while (i < n)
        dest[i++] = '\0';
    dest[i] = '\0';
    return (dest);
}

#include <stdio.h>
int main(void)
{
    char *str1;
    char str2[10];
	char *str3;
    char *str4;
    char str5[10] = "Hello ";
    int len;

    str1 = "Hellllo";
    
	str3 = "Paol";
    str4 = "man baakhtam, bad ham bakhtam, man abrooye shahre mano bordam, man daram be ghahghara miram, fghat bezahrid berammm man";
    ft_putstr("42\n");
    len = ft_strlen(str1);
    printf("%d\n", len);
	printf("%s\n", ft_strcpy(str2, str1));
    printf("%s\n", ft_strncpy(str2, str1, 3));
	printf("%s\n", str2);
	printf("%d\n", ft_strcmp(str1, str3));
	printf("%s\n", ft_strdup(str4));
    printf("%s\n", ft_strcat(str5, str3));
    

    return (0);
}

