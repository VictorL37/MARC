#include "queue_node.h"

t_queue_tab createEmptyQueue() {
    t_queue_tab q;
    q.first = 0;
    q.last = 0;
    return q;
}

void enqueue_node(t_queue_tab *q, p_node node) {
    q->values[q->last] = node;
    q->last++;
}

p_node dequeue_node(t_queue_tab *q) {
    p_node node = q->values[q->first];
    q->first++;
    return node;
}

void freeQueue(t_queue_tab* q) {
    while (q->first != q->last) {
        dequeue_node(q);
    }
}