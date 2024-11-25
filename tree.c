#include "tree.h"

t_move* remove_move(t_move* moves, int len, int idx){
    t_move* new_moves = (t_move*) malloc((len-1)*sizeof(t_move));
    int j = 0;
    for (int i = 0; i < len-1; i++){
        if (i == idx) j++;
        new_moves[i] = moves[j];
        j++;
    }
    return new_moves;
}

p_node createNode(int nbChildren, int depth, t_move movement, t_localisation loc, t_map map, p_node node) {
    p_node newNode = (t_node *)malloc(sizeof(t_node));
    if (newNode != NULL) {
        newNode->value = map.costs[loc.pos.y][loc.pos.x];
        newNode->depth = depth;
        newNode->movement = movement;
        newNode->parent = node;
        newNode->soil_type = map.soils[loc.pos.y][loc.pos.x];
        newNode->children = (t_node **) malloc(nbChildren*sizeof(t_node *));
        if (newNode->children != NULL) {
            for (int i = 0; i < nbChildren; i++) {
                newNode->children[i] = NULL;
            }
        }
        else {
            free(newNode);
            newNode = NULL;
        }
    }
    return newNode;
}

void freeNode(p_node node) {
    if (node != NULL) {
        for (int i = 0; i < node->nbChildren; i++) {
            freeNode(node->children[i]);
        }
        free(node->children);
        free(node);
    }
}

p_node createEveryNode(int nbPossibilities, int depth, t_move movement, t_move* possibilities, t_localisation robot, t_map map, p_node parentNode){
    if (depth > NB_CHOICES) {
        return NULL;
    }
    else if (depth == NB_CHOICES || map.costs[robot.pos.y][robot.pos.x] >= 10000) {
        nbPossibilities = 0;
    }
    p_node node = createNode(nbPossibilities, depth, movement, robot, map, parentNode);
    for (int i = 0; i < nbPossibilities; i++) {
        t_localisation new_loc = robot;
        updateLocalisation(&new_loc, possibilities[i]);

        if (isValidLocalisation(new_loc.pos, map.x_max, map.y_max)) {
            t_move* newPossibilities = remove_move(possibilities, nbPossibilities, i);
            node -> children[i] = createEveryNode(nbPossibilities> - 1, depth+1, possibilities[i], newPossibilities, new_loc, map, node);
            free(newPossibilities);
        }
        else {
            node -> children[i] = NULL;
        }
    }
    return node;
}

t_tree createTree(int nbPossibilities, int depth, t_move movement, t_move* possibilities, t_localisation robot, t_map map){
    t_tree t;
    t.root = createEveryNode(nbPossibilities, depth, movement, possibilities, robot, map, NULL);
    return t;
}

int searchMinNode(p_node node) {
    if (node->nbChildren == 0) {
        return node->value;
    }
    else {
        int min = node->value;
        for (int i = 0; i < node->nbChildren; i++) {
            if (node->children[i] == NULL) {
                int val = searchMinNode(node->children[i]);
                if (val < min) {
                    min = val;
                }
            }
        }
        return min;
    }
}

int searchMin(t_tree tree) {
    return searchMinNode(tree.root);
}

int nbOfMinNode(p_node node, int min) {
    if (node->nbChildren == 0) {
        if (node->value == min) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        int nb = 0;
        for (int i = 0; i < node->nbChildren; i++) {
            if (node->children[i] != NULL) {
                nb += nbOfMinNode(node->children[i], min);
            }
        }
        return nb;
    }
}

void printTree(t_node *root) {
    if (root != NULL) {
        printf("Node value: %d\n", root->value);
        printf("Node depth: %d\n", root->depth);
        printf("Node soil type: %d\n", root->soil_type);
        for (int i = 0; i < root->nbChildren; i++) {
            printf("Child %d: ", i);
            printTree(root->children[i]);
        }
    }
}
