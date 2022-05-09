#include <stdio.h>
#include "linkedlist.h"

int main(void){
    No* my_list = NULL;

    ll_insert_sorted(&my_list, 3);
    ll_insert_sorted(&my_list, 1);
    ll_insert_sorted(&my_list, 5);

    ll_print(my_list, "my_list: \n");
    //ll_remove(&my_list, 3);

    printf("Tamanho: %d\n", ll_size(my_list));
    printf("Tamanho: %d\n", ll_size(my_list));
    
    ll_print(my_list, "lista nova: \n");
    
    ll_clear(&my_list);
    
    ll_insert_last(&my_list, -1);
    ll_insert_last(&my_list, -2);
    ll_insert_last(&my_list, 0);
    ll_insert_last(&my_list, 3);
    ll_insert_last(&my_list, 2);
    ll_insert_first(&my_list, 9);
    ll_insert_last(&my_list, -15);
    
    ll_print(my_list, "Lista sem ordenação:");
    
return 0;

}