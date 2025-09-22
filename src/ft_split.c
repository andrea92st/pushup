/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fio <fio@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:06:38 by fio               #+#    #+#             */
/*   Updated: 2025/09/22 14:02:38 by fio              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  space(char c)
{
    if (c == ' ' || c == '\v' || c == '\r' || c == '\n' || c == '\t' || c == '\f')
        return (1);
    return (0);
}

static int  county(char *s)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (s[i])
    {
        while (s[i] && space(s[i]) == 1)
            i++;
        if (s[i] && space(s[i]) == 0)
            j++;
        while (s[i] && space(s[i]) == 0)
            i++;
    }
    return (j);
}

static void malok(char **tab, int start, int end, char *s, int x)
{
    int i;

    i = 0;
    tab[x] = malloc (sizeof (char) * (end - start + 1));
    if (tab[x] == NULL)
        return;
    while (start < end)
    {
        tab[x][i] = s[start]; 
        i++;
        start++;
    }
    tab[x][i] = '\0';
}

char    **ft_split(char *str)
{
    int     end;
    int     start;
    int     count;
    char    **tab;
    
    count = county(str);
    end = 0;
    start = 0;
    tab =  malloc (sizeof (char*) * (count + 1));
    if(tab == NULL)
        return(NULL);
    ft_split_2(str, start, end, tab);
    tab[count] = NULL;
    return(tab);
}

void ft_split_2(char *str, int start, int end, char **tab)
{
    int i;
    int x;

    i = 0;
    x = 0;
    while (str[i])
    {
        while(str[i] && space(str[i]))
            i++;
        if (str[i])
        {
            start = i;
            while (str[i] && !space(str[i]))
                i++;
            end = i;
            malok(tab, start, end, str, x);
            x++;
        }
    }
}
