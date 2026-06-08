/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:39:44 by mmesgari          #+#    #+#             */
/*   Updated: 2026/06/08 14:32:58 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

#include <stdio.h>
int main(void)
{
    char *str1;
    char str2[10];
	char *str3;
    int len;

    str1 = "Hellllo";
	str3 = "Paol";
    ft_putstr("42\n");
    len = ft_strlen(str1);
    printf("%d\n", len);
	ft_strcpy(str2, str1);
	printf("%s\n", str2);
	printf("%d\n", ft_strcmp(str1, str3));

    return (0);
}
