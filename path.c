#include "path.h"

p_node* tab_of_min(p_node node, int* len) {
    int min_val = searchMinNode(node);
    p_node* min_leaf = (p_node*) malloc(MAX * sizeof(p_node));
    if (min_leaf == NULL) {
        *len = 0;
        return NULL;
    }
    t_queue_tab q;
    p_node cur;
    q = createEmptyQueue();
    enqueue_node(&q, node);

    while (q.first != q.last) {
        cur = dequeue_node(&q);
        if (cur == NULL) {
            continue;
        }
        if (cur->value == min_val) {
            int depth_of_min = cur->depth;
            while (cur->depth == depth_of_min && q.first != q.last) {
                if (cur->value == min_val) {
                    min_leaf[*len] = cur;
                    (*len)++;
                }
                cur = dequeue_node(&q);
                if (cur == NULL) {
                    break;
                }
            }
            freeQueue(&q);
            return min_leaf;
        } else if (cur->nbChildren != 0) {
            for (int i = 0; i < cur->nbChildren; i++) {
                if (cur->children[i] != NULL) enqueue_node(&q, cur->children[i]);
            }
        }
    }
    freeQueue(&q);
    *len = 0;
    free(min_leaf);
    return NULL;
}

p_node leafMin(t_tree tree) {
    return leafMinNode(tree.root);
}

p_node leafMinNode(p_node node) {
    int len = 0, cost, cheapest = INT_MAX, idx = -1;
    p_node* tab_min = tab_of_min(node, &len);

    if (tab_min == NULL || len == 0) {
        free(tab_min);
        return NULL;
    }

    for (int i = 0; i < len; i++) {
        p_node cur = tab_min[i];
        cost = 0;
        while (cur != NULL) {
            cost += cur->value;
            cur = cur->parent;
        }
        if (cost < cheapest) {
            cheapest = cost;
            idx = i;
        }
    }

    p_node result = NULL;
    if (idx != -1) {
        result = tab_min[idx];
    }
    free(tab_min);
    return result;
}

t_move* getBestPath(t_tree t, int *len){
    p_node leaf = leafMin(t);
    if (leaf == NULL) {
        *len = 0;
        return NULL;
    }
    int depth = leaf->depth;
    *len = depth;
    t_move* path = (t_move*) malloc(depth * sizeof(t_move));
    if (path == NULL) {
        *len = 0;
        return NULL;
    }

    for (int i = depth - 1; i >= 0; i--){
        path[i] = leaf->movement;
        leaf = leaf->parent;
    }
    return path;
}