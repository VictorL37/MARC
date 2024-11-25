#ifndef UNTITLED1_TREE_H
#define UNTITLED1_TREE_H

#define NB_CHOICES 5

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"
#include "map.h"
#include "moves.h"
#include "loc.h"

typedef struct s_node {
    int value;
    int depth;
    t_move movement;
    t_soil soil_type;
    struct s_node *parent;
    struct s_node **children;
    int nbChildren;
} t_node;

typedef struct s_node t_node, *p_node;

typedef struct s_tree {
    p_node root;
} t_tree;

t_move* remove_move(t_move*, int, int);

p_node createNode(int, int, t_move, t_localisation, t_map, p_node);
void freeNode(p_node);

p_node createEveryNode(int, int, t_move, t_move*, t_localisation, t_map, p_node);
t_tree createTree(int, int, t_move, t_move*, t_localisation, t_map);

int searchMinNode(p_node);
int searchMin(t_tree);
int nbOfMinNode(p_node, int);






void printTree(t_node *node);
#endif //UNTITLED1_TREE_H
