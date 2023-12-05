void    ft_ultimate_div_mod(int *a, int *b)
{
    int temp1;
    int temp2;
    int div;
    int mod;

    temp1 = *a;
    temp2 = *b;
    div = temp1 / temp2;
    mod = temp1 % temp2;
    *a = div;
    *b = mod;
}