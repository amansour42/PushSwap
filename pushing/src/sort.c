#include "pushswap.h"

static int     min(t_int *a)
{
    int min;
    t_int *tmp;

    tmp = a;
    min = tmp->nbr;
    while (tmp)
    {
        if (tmp->nbr < min)
            min = tmp->nbr;
        tmp = tmp->next;
    }
    return (min);
}

static int     max(t_int *a)
{
    int max;
    t_int *tmp;

    tmp = a;
    max = tmp->nbr;
    while (tmp)
    {
        if (tmp->nbr >max)
            max = tmp->nbr;
        tmp = tmp->next;
    }
    return (max);
}

void    sort(t_int **a)
{
    t_int   *b;
    int     p;
    char    *str;
    int     i;

    b = NULL;
    i = 0;

    while (i < 15 && length(*a) > 2 && !check_order(*a))
    {

        str = ft_strdup("");
        /*if (min(*a) == (*a)->nbr || (*a)->nbr == max(*a))
        {
            //printf("OK");
            pile_swap(a);
            ft_putstr("sa\n");
        } */
        /*if (min(*a) != last(*a))
        {
            if (last(*a) == max(*a))
            {
                rotate(a);
                ft_putstr("ra\n");
                p = last(*a);
            }       
        
            p = last(*a);
        //printf("le pivot %d\n", p);
            treat_a(a, &b, p, &str);
            ft_putstr(str);
        }*/
        if (min(*a) == (*a)->nbr)
        {
            ft_putstr(push(&b, a, 'b'));
        }
        else if (min(*a) == last(*a))
        {
            reverse_rotate(a);
            ft_putstr("rra\n");
            ft_putstr(push(&b, a, 'b'));
        }
        else
        {
            if (last(*a) == max(*a))
            {
                rotate(a);
                ft_putstr("ra\n");
                p = last(*a);
            }      
        
            p = last(*a);
        //printf("le pivot %d\n", p);
            treat_a(a, &b, p, &str);
            ft_putstr(str);
        } 
        /*printf("A after treat\n");
        affiche(*a); 
        printf("B\n");
        affiche(b); */
        free(str);        
        if (length(b) > 1)
        {
            while (!(check_invorder(b)) && length(b) > 2)
            {
                str = ft_strdup("");
                p = last(b);
                //printf("pivot_B = %d\n", p);
                treat_b(&b, a, p, &str);
                //printf("B avant le push\n");
                //affiche(b);
                ft_putstr(str);
                if (!(check_invorder(b)))
                ft_putstr(push(a, &b, 'a')); 
                free(str);
            }
            if (length(b) == 2 && !check_invorder(b))
            {
                pile_swap(&b);
                ft_putstr("sb\n");
            }
        }
        ++i;
        //printf("A End\n");
        //affiche(*a);  
    }
    if (length(*a) == 2 && !check_order(*a))
    {
            pile_swap(a);
            ft_putstr("sa\n");
    }    
    while (b)
        ft_putstr(push(a, &b, 'a'));
    return ;
}
