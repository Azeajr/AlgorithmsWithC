#include <stdio.h>

#include "list.h"

static void print_list(const List *list){
    ListElmt *element;
    int *data, i;

    fprintf(stdout, "List size is %d\n", list_size(list));

    i=0;
    element = list_head(list);

    while(1){
        data = list_data(element);
        fprintf(stdout, "list[%03d]=%03d\n", i, *data);
        
        i++;

        if(list_is_tail(element)){
            break;
        } else {
            element = list_next(element);
        }
    }

    return;
}

int main(int argc, char const *argv[])
{
    List list;
    ListElmt *element;

    int *data, i;

    /**
     * @brief Initialize the linked list.
     * 
     */
    list_init(&list, free);

    /**
     * @brief Perform some linked list operations.
     * 
     */
    element = list_head(&list);

    for(i = 10; i > 0; i--){
        if((data = (int *)malloc(sizeof(int))) == NULL){
            return 1;
        }

        *data = i;

        if(list_ins_next(&list, NULL, data) != 0){
            return 1;
        }
    }



    return 0;
}
