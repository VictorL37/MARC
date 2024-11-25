#include "draw.h"

void selectNineRandom(int* possibilities) {
    int probTen = PROB_TEN;
    int probTwenty = PROB_TWENTY;
    int probThirty = PROB_THIRTY;
    int probReverse = PROB_REVERSE;
    int probNinetyLeft = PROB_NINETY_LEFT;
    int probNinetyRight = PROB_NINETY_RIGHT;
    int probUTurn = PROB_U_TURN;
    int totalProb = TOTAL_PROB;
    int random;

    srand(time(NULL));
    for (int i = 0; i < 9; i++) {
        random = (rand() %  (TOTAL_PROB - i)) + 1;
        if (random > 0 && random <= probTen) {
            possibilities[i] = 0; // code 0
            probTen--;
        } else if (random > probTen && random <= probTen + probTwenty) {
            possibilities[i] = 1; // code 1
            probTwenty--;
        } else if (random > probTen + probTwenty && random <= probTen + probTwenty + probThirty) {
            possibilities[i] = 2; // code 2
            probThirty--;
        } else if (random > probTen + probTwenty + probThirty && random <= probTen + probTwenty + probThirty + probReverse) {
            possibilities[i] = 3; // code 3
            probReverse--;
        } else if (random > probTen + probTwenty + probThirty + probReverse && random <= probTen + probTwenty + probThirty + probReverse + probNinetyLeft) {
            possibilities[i] = 4; // code 4
            probNinetyLeft--;
        } else if (random > probTen + probTwenty + probThirty + probReverse + probNinetyLeft && random <= probTen + probTwenty + probThirty + probReverse + probNinetyLeft + probNinetyRight) {
            possibilities[i] = 5; // code 5
            probNinetyRight--;
        } else if (random > probTen + probTwenty + probThirty + probReverse + probNinetyLeft + probNinetyRight && random <= probTen + probTwenty + probThirty + probReverse + probNinetyLeft + probNinetyRight + probUTurn) {
            possibilities[i] = 6; // code 6
            probUTurn--;
        }
    }
}
void printPossibilities(const int* possibilities) {
    printf("Possibilities: ");
    for (int i = 0; i < 9; i++) {
        switch (possibilities[i]) {
            case 0:
                printf("F_10 ");
                break;
            case 1:
                printf("F_20 ");
                break;
            case 2:
                printf("F_30 ");
                break;
            case 3:
                printf("B_10 ");
                break;
            case 4:
                printf("L_90 ");
                break;
            case 5:
                printf("R_90 ");
                break;
            case 6:
                printf("U_TURN ");
                break;
            default:
                printf("ERROR ");
                break;
        }
    }
    printf("\n");
}