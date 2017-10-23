#include "pushswap.h"

void    treat_a(t_int **a, t_int **b, int p, char **str)
{

    *str = ft_strdup("");
    while ((*a) && (*a)->nbr != p)
    {
        if ((*a)->nbr < p)
        {
            
            *str = ft_strjoin(*str, push(b, a, 'b'));
        }
        else if ((*a)->nbr > p)
        {
            rotate(a);
            *str = ft_strjoin(*str, "ra\n");
        }
    }
    return ;
}

void    treat_b(t_int **b, t_int **a, int p, char **str)
{
    t_int *tmp;

    tmp = *b;
    while ((*b) && (*b)->nbr != p)
    {
        if ((*b)->nbr > p)
        {
            //printf("PUSH\n");
            *str = ft_strjoin(*str, push(a, b, 'a'));
        }
        else if ((*b)->nbr < p)
        {
            //printf("ROTATE\n");
            rotate(b);
            *str = ft_strjoin(*str, "rb\n");
        }
    }
    return ;
}
              
int     pivot(t_int **pile, char c, char **str)
{
    if (c == 'a')
    {
        if (last(*pile) < (*pile)->nbr)
        {
            (*str) = ft_strdup("ra\n");
            reverse_rotate(pile);
            return (last(*pile));
        }
        *str = ft_strdup("");
        return ((*pile)->nbr);
    }
    if (last(*pile) > (*pile)->nbr)
        {
            (*str) = ft_strdup("rb\n");
            rotate(pile);
            return (last(*pile));
        }
        return ((*pile)->nbr); 
}

