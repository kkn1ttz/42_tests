#include <unistd.h>

void ft_print_comb()
{
    int a = '0';
    int b = '0';
    int c = '0';
    while (a <= '9')
    {
        b = a + 1;
        while (b <= '9')
        {
            c = b + 1;
            while (c <= '9')
            {
                write(1, &a, 1);
                write(1, &b, 1);
                write(1, &c, 1);
                write(1,", ",2);
                c++;
            }
            b++;
        }
        a++;
    }
}