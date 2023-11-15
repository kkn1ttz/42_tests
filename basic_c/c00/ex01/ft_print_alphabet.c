#include <unistd.h>

void ft_print_alphabet(){
    for(int i=97;i<123;i++){
        write(1,&i,1);
    }
}