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
            /**
             * @brief Call user-defined function to free dynamically allocated 
             * data.
             * 
             */
            list->destroy(data);
        }
    }
    /**
     * @brief No operations are allowed now, but clear the structure as a 
     * precaution.
     * 
     */
    memset(list, 0, sizeof(List));

    return;
}

/**
 * @brief list_ins_next
 * 
 * @param list 
 * @param element 
 * @param data 
 * @return int 
 */
int list_ins_next(List *list, ListElmt *element, const void *data){
    ListElmt *new_element;
    /**
     * @brief Allocate storage for the element.
     * 
     */
    if((new_element = (ListElmt *)malloc(sizeof(ListElmt))) == NULL){
        return -1;
    }
    /**
     * @brief Insert the element into the list.
     * 
     */
    new_element->data = (void *)data;

    if(element == NULL){
        /**
         * @brief Handle insertion at the head of the list.
         * 
         */
        if(list_size(list) == 0){
            list->tail = new_element;
        }
        new_element->next = list->head;
        list->head = new_element;
    } else {
        /**
         * @brief Handle insertion somewhere other than at the head.
         * 
         */
        if(element->next == NULL){
            list->tail =  new_element;
        }
        new_element->next = element->next;
        element->next = new_element;
    }
    /**
     * @brief Adjust the size of the list to account for the inserted elment.
     * 
     */
    list->size++;
    
    return 0;
}
/**
 * @brief list_rem_next
 * 
 * @param list 
 * @param element 
 * @param data 
 * @return int 
 */
int list_rem_next(List *list, ListElmt *element, void **data){
    ListElmt *old_element;
    if(list_size(list) == 0){
        return -1;
    }
    /**
     * @brief Remove the element from the list.
     * 
     */
    if(element == NULL){
        /**
         * @brief Handle removal from the head of the list.
         * 
         */
        *data = list->head->data;
        old_element = list->head;
        list->head = list->head->next;

        if(list_size(list) == 1){
            list->tail = NULL;
        }
    } else {
        /**
         * @brief Handle removal form somewhere other than the head.
         * 
         */
        if(element->next == NULL){
            return -1;
        }

        *data = element->next->data;
        old_element = element->next;
        element->next = element->next->next;

        if(element->next == NULL){
            list->tail = element;
        }
    }

    /**
     * @brief Free the storage allocated by the abstract datatype.
     * 
     */
    free(old_element);

    /**
     * @brief Adjust the size of the list to account for the removed element.
     * 
     */
    list->size--;

    return 0;
}
