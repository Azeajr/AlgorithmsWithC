/**
 * @file dlistTest.c
 * @author Antonio Zea
 * @brief Illustrates using a doubly-linked list
 * @version 0.1
 * @date 2021-04-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

/**
 * @brief print_list
 * 
 * @param list 
 */
void print_list(const DList *list){
    DListElmt *element;
    int *data, i;

    /**
     * @brief Display the double-linked list
     * 
     */
    fprintf(stdout, "List size is %d\n", dlist_size(list));

    i=0;
    element = dlist_head(list);

    while(1){
        data = dlist_data(element);
        fprintf(stdout, "list[%03d]=%03d\n", i, *data);

        i++;

        if(dlist_is_tail(element)){
            break;
        } else {
            element = dlist_next(element);
        }
    }
    
    return;
}

/**
 * @brief main
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char const *argv[])
{
    DList list;
    DListElmt *element;
    
    int *data, i;

    dlist_init(&list, free);

    element = dlist_head(&list);

    for(i = 10; i > 0; i--){
        if((data = (int *)malloc(sizeof(int))) == NULL){
            return 1;
        }

        *data = i;

        if(dlist_ins_prev(&list, dlist_head(&list), data) != 0){
            return 1;
        }
    }

    print_list(&list);

    return 0;
}
