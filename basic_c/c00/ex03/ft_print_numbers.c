#include <unistd.h>

void ft_print_numbers(){
    for(int i=48;i<58;i++){
        write(1,&i,1);
    }
}