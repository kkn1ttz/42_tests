#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void ft_puctchar(char c)
{
    write(1, &c, 1);
}

void ft_writearr(char *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        ft_puctchar(arr[i] + 48);
    }
    ft_puctchar(',');
    ft_puctchar(' ');
}

void ft_print_combn(int n)
{
    if (n < 1 || n > 9)
    {
        return;
    }

    char *arr = malloc(n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }

    ft_writearr(arr, n);

    int i = 8;
    while (arr[i] < 9)
    {
        printf("\n");
        arr[i]++;
        ft_writearr(arr, n);
    }
    i--;
    
    for(int y=i+1;y<n;i++){
        arr[y]=arr[y-1]++;
    }

    while (arr[i] < arr[i + 1])
    {

    }

    // int i = 0;
    // while (arr[0] < 10 - n)
    // {
    //     while (arr[i] < arr[i - 1] && arr[i] < 9)
    //     {
    //     }
    // }
}

int main(void)
{
    ft_print_combn(9);

    return 0;
}