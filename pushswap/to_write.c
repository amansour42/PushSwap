#include "pushswap.h"

void    to_write(t_list *l, char *s)
{
    t_list *t;

    t = l;
    if (!l)
    {
        ft_putstr(s);
        return ;
    }
    while (t && !ft_strcmp((char*)t->content, s))
    {
        ft_putstr((char*)t->content);
        t = t->next;
    }
    if (t)
    {
        (*((char*)t->content) ==  'r') ? ft_putstr("rr\n") : ft_putstr("ss\n");
        t = t->next;
    }
    write_b(t);
    return ;
}

void    write_b(t_list *t)
{
    while (t)
    {
        ft_putstr((char*)t->content);
        t = t->next;
    }
    return ;
}
