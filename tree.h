//
// Created by victo on 14/11/2024.
//

#ifndef UNTITLED1_TREE_H
#define UNTITLED1_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"
#include "map.h"
#include "moves.h"

typedef struct s_node
{
    int value;
    int depth;
    t_soil soil_type;
    struct s_node **sons;
    int nbSons;
} t_node;


#endif //UNTITLED1_TREE_H
