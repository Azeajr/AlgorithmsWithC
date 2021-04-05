/**
 * @file list.c
 * @author Antonio Zea
 * @brief 
 * @version 0.1
 * @date 2021-04-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdlib.h>
#include <string.h>

#include "list.h"
/**
 * @brief list_init
 * 
 * @param list 
 * @param destroy 
 */
void list_init(List *list, void (*destroy)(void *data)){
    /**
     * @brief Initialize the list.
     * 
     */
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;

    return;
}
/**
 * @brief list_destroy
 * 
 * @param list 
 */
void list_destroy(List *list){
    void *data;
    /**
     * @brief Remove each element.
     * 
     */
    while(list_size(list) > 0){
        if(list_rem_next(list, NULL, (void **)&data) == 0 && list->destroy != NULL){
            list->destroy(data);
        }
    }
}
