#ifndef UNTITLED1_DRAW_H
#define UNTITLED1_DRAW_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PROB_TEN 22 // code 0
#define PROB_TWENTY 15 // code 1
#define PROB_THIRTY 7 // code 2
#define PROB_REVERSE 7 // code 3
#define PROB_NINETY_LEFT 21 // code 4
#define PROB_NINETY_RIGHT 21 // code 5
#define PROB_U_TURN 7 // code 6
#define TOTAL_PROB 100 // total probability



void selectNineRandom(int* possibilities);
void printPossibilities(const int* possibilities);

#endif //UNTITLED1_DRAW_H
