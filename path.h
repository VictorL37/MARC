#ifndef UNTITLED1_PATH_H
#define UNTITLED1_PATH_H

#include <stdio.h>
#include <stdlib.h>
#include "loc.h"
#include "moves.h"
#include "map.h"
#include "tree.h"
#include "queue_node.h"

p_node *tab_of_min(p_node, int *);

p_node leafMin(t_tree);

p_node leafMinNode(p_node);

t_move *getBestPath(t_tree, int *);

#endif //UNTITLED1_PATH_H
