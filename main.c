#include <stdio.h>
#include "map.h"
#include "draw.h"
#include "tree.h"
#include "moves.h"
#include "path.h"

int main() {
    t_map map;

    // The following preprocessor directive checks if the code is being compiled on a Windows system.
    // If either _WIN32 or _WIN64 is defined, it means we are on a Windows platform.
    // On Windows, file paths use backslashes (\), hence we use the appropriate file path for Windows.
#if defined(_WIN32) || defined(_WIN64)
    map = createMapFromFile("..\\maps\\example1.map");
#else
    map = createMapFromFile("../maps/example1.map");
#endif

    printf("Map created with dimensions %d x %d\n", map.y_max, map.x_max);
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%d ", map.soils[i][j]);
        }
        printf("\n");
    }
    // printf the costs, aligned left 5 digits
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%-5d ", map.costs[i][j]);
        }
        printf("\n");
    }
    displayMap(map);
    printf("\n");


    t_move *possibilities = generateMoves(9);
    printf("Possible Moves: \n");
    for (int i = 0; i < 9; i++) {
        printf("%s ", getMoveAsString(possibilities[i]));
        if (i < 8) {
            printf("; ");
        }
    }
    printf("\n\n");

    t_localisation loc = loc_init(0, 0, NORTH);
    printf("MARC's Initial Position :\nx: %d, y: %d, direction: NORTH\n\n", loc.pos.x, loc.pos.y);

    t_tree tree;
    tree = createTree(9, 0, INITIAL_POS, possibilities, loc, map);

    int minValue = searchMin(tree);
    printf("Minimum value: %d\n", minValue);


    p_node MinimumLeaf = leafMin(tree);

    int nbMoves;
    t_move* moves = getBestPath(tree, &nbMoves);

    printf("Best moves :\n");
    for (int i = 0; i < nbMoves; i++) {
        printf("%s ", getMoveAsString(moves[i]));
        if (i < nbMoves - 1) {
            printf("; ");
        }
    }

    printTree(tree.root);

    return 0;
}
