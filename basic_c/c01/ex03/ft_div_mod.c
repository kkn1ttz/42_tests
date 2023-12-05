void    ft_div_mod(int a, int b, int *div, int *mod)
{
    int div_int;
    int mod_int;

    div_int = a / b;
    mod_int = a % b;

    div = &div_int;
    mod = &mod_int;
}