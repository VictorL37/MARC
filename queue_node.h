//
// Created by victo on 24/11/2024.
//

#ifndef UNTITLED1_QUEUE_NODE_H
#define UNTITLED1_QUEUE_NODE_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "tree.h"

#define MAX 100

typedef struct s_queue_tab
{
    p_node values[MAX];
    int first, last;
} t_queue_tab;

t_queue_tab createEmptyQueue();
void enqueue_node(t_queue_tab *, p_node);
p_node dequeue_node(t_queue_tab *);
void freeQueue(t_queue_tab*);
#endif //UNTITLED1_QUEUE_NODE_H
