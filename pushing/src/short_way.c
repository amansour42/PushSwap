#include "pushswap.h"

void    short_way(t_int **a, int pos)
{
    int len;
    //int d;

    //d = (length(*a) % 2) ? 1 : 0;
    len = length(*a) / 2 + length(*a) % 2;
    if (pos >len)
    {
        pos = length(*a) - pos + 1;
        while (pos--)
        {
            reverse_rotate(a);
            ft_putstr("rra\n");
        }
    }
    else if (pos == 2)
    {
        pile_swap(a);
        ft_putstr("sa\n");
    }
    else
    {
        while (pos--)
        {
            rotate(a);
            ft_putstr("ra\n"); 
        }

    }
    return ;
}
