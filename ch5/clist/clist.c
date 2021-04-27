/**
 * @file clist.c
 * @author Antonio Zea
 * @brief 
 * @version 0.1
 * @date 2021-04-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include <stdlib.h>
#include <string.h>

#include "clist.h"

void clist_init(CList *list, void (*destroy)(void *data)){
    /**
     * @brief Initialize the list.
     * 
     */

    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;

    return;
}
/**
 * @brief clist_destroy
 * 
 * @param list 
 */
void clist_destroy(CList *list){

    void *data;
    /**
     * @brief Remove each element
     * 
     */
    while(clist_size(list) > 0){
        if(clist_rem_next(list, list->head, (void **)&data) == 0 && list->destroy != NULL){
            list->destroy(data);
        }
    }

    memset(list, 0, sizeof(CList));

    return;
}
/**
 * @brief clist_ins_next
 * 
 * @param list 
 * @param element 
 * @param data 
 * @return int 
 */
int clist_ins_next(CList *list, CListElmt *element, const void *data){
    CListElmt *new_element;
    /**
     * @brief Allocate storage for the element.
     * 
     */
    if((new_element = (CListElmt *)malloc(sizeof(CListElmt))) == NULL){
        return -1;
    }

    new_element->data = (void *) data;

    if(clist_size(list) == 0){
        /**
         * @brief Hnadle insertion whe the list is empty.
         * 
         */
        new_element->next = new_element;
        list->head = new_element;
    } else {
        new_element->next  = element->next;
        element->next = new_element;
    }

    list->size++;
    
    return 0;
}

/**
 * @brief clist_rem_next
 * 
 */
int clist_rem_next(CList *list, CListElmt *element, void **data){
    CListElmt *old_element;
    /**
     * @brief Do not allow removal from an empty list.
     * 
     */
    if(clist_size(list) == 0){
        return -1;
    }
    /**
     * @brief Remove the element from the list
     * 
     */
    *data = element->next->data;

    if(element->next == element){
        /**
         * @brief Handle removing the last element.
         * 
         */
        old_element = element->next;
        list->head = NULL;
    } else {
        /**
         * @brief Handle removing other than the last element.
         * 
         */
        old_element = element->next;
        element->next = element->next->next;
        if(old_element == clist_head(list)){
            list->head = old_element->next;
        }
    }

    /**
     * @brief Free the storage allocated by the abstract datatype.
     * 
     */
    free(old_element);
    /**
     * @brief Adjust the size of the list to account for the remove element.
     * 
     */
    list->size--;

    return 0;
}