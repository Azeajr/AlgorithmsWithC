/**
 * @file queue.c
 * @author Antonio Zea
 * @brief 
 * @version 0.1
 * @date 2021-05-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdlib.h>
#include "list.h"
#include "queue.h"

int queue_enqueue(Queue *queue, const void *data){
    return list_ins_next(queue, list_tail(queue), data);
}

int queue_dequeue(Queue *queue, void **data){
    return list_rem_next(queue, NULL, data);
}