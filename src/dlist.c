/**
 * @file dlist.c
 * @author Antonio Zea
 * @brief Implementation of the Doubly-Linked List Abstract Datatype
 * @version 0.1
 * @date 2021-04-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdlib.h>
#include <string.h>
#include "dlist.h"

/**
 * @brief dlist_init
 * 
 */
void dlist_init(DList *list, void (*destroy)(void *data)){
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;

    return;
}

/**
 * @brief dList_destroy
 * 
 */
void dlist_destroy(DList *list){
    void *data;
    /**
     * @brief Remove each element.
     * 
     */
    while(dlist_size(list) > 0){
        if(dlist_remove(list, dlist_tail(list), (void **)&data) == 0 && list->destroy != NULL){
            /**
             * @brief Call a user-defined function to free dynamically 
             * allocated data.
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
    memset(list, 0, sizeof(DList));
    return;
}
/**
 * @brief dlist_ins_next
 * 
 * @param list 
 * @param element 
 * @param data 
 * @return int 
 */
int dlist_ins_next(DList *list, DListElmt *element, const void *data){
    DListElmt *new_element;
    /**
     * @brief Do not allow a NULL element unless the list is empty.
     * 
     */
    if(element == NULL && dlist_size(list) != 0){
        return -1;
    }
    /**
     * @brief Allocate storage for the element.
     * 
     */
    if((new_element = (DListElmt *)malloc(sizeof(DListElmt))) == NULL){
        return -1;
    }
    /**
     * @brief Insert the new element into the list.
     * 
     */
    new_element->data = (void *)data;

    if(dlist_size(list) == 0){
        /**
         * @brief Handle insertion when the list is empty.
         * 
         */
        list->head = new_element;
        list->head->prev = NULL;
        list->head->next = NULL;
        list->tail = new_element;
    } else {
        /**
         * @brief Handle insertion when the list is not empty.
         * 
         */
        new_element->next = element->next;
        new_element->prev = element;

        if(element->next == NULL){
            list->tail = new_element;
        } else {
            element->next->prev = new_element;
        }
        element->next = new_element;
    }
    /**
     * @brief Adjust the size of the list to account for the inserted element.
     * 
     */
    list->size++;
    
    return 0;
}
/**
 * @brief dlist_ins_prev
 * 
 */
int dlist_ins_prev(DList *list, DListElmt *element, const void *data){
    DListElmt *new_element;
    /**
     * @brief Do not allow a NULL element unless the list is empty.
     * 
     */
    if(element == NULL && dlist_size(list) != 0){
        return -1;
    }

    /**
     * @brief Allocate storeage to be managed by the abstract datatype.
     * 
     */
    if((new_element = (DListElmt *)malloc(sizeof(DListElmt))) == NULL){
        return -1;
    }
    /**
     * @brief Insert the new element into the list.
     * 
     */
    new_element->data= (void *)data;

    if(dlist_size(list) == 0){
        /**
         * @brief Handle insertion when the list is empty.
         * 
         */
        list->head = new_element;
        list->head->prev = NULL;
        list->head->next = NULL;
        list->tail = new_element;
    } else {
        /**
         * @brief Handle insertion when the list is not empty.
         * 
         */
        new_element->next = element;
        new_element->prev = element->prev;
        
        if(element->prev == NULL){
            list->head = new_element;
        } else {
            element->prev->next = new_element;
        }
        element->prev = new_element;
    }

    list->size++;

    return 0;
}

/**
 * @brief dlist_remove
 * 
 */
int dlist_remove(DList *list, DListElmt *element, void **data){
    /**
     * @brief Do not allow a NULL element or removal from an empty list.
     * 
     */
    if(element == NULL || dlist_size(list) == 0){
        return -1;
    }
    /**
     * @brief Remove the element from the list.
     * 
     */
    *data = element->data;
    if(element == list->head){
        /**
         * @brief Handle removal from the head of the list.
         * 
         */
        list->head = element->next;
        if(list->head == NULL){
            list->tail = NULL;
        } else {
            element->next->prev = NULL;
        }
    } else {
        /**
         * @brief Handle remove from other than the head of the list.
         * 
         */
        element->prev->next = element->next;
        if(element->next == NULL){
            list->tail = element->prev;
        } else {
            element->next->prev = element->prev;
        }
    }
    /**
     * @brief Free the storage allocated by the abstract datatype.
     * 
     */
    free(element);

    /**
     * @brief Adjust the size of the list to account for the removed element.
     * 
     */
    list->size--;

    return 0;

}