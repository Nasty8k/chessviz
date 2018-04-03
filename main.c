#include <stdio.h>
#include <stdlib.h>
#include "chess.h"

int main()
{
    char pole[8][8];                          // Игровое поле
    char * pp = &pole[0][0];                  // Указатель на игровое поле
 
    if(!start(pp)) {                            
        printf("Невозможно начать игру\n");
        return 0;
    }

    print_game(pp);
    return 0;
} 

