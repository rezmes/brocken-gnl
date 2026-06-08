/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:39:44 by mmesgari          #+#    #+#             */
/*   Updated: 2026/06/08 13:40:21 by mmesgari         ###   ########.fr       */
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

#include <stdio.h>
int main(void)
{
    char *str;
    int len;

    str = "Hello";
    ft_putstr("42\n");
    len = ft_strlen(str);
    printf("%d\n", len);

    return (0);
}
