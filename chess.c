#include <stdio.h>
#include <stdlib.h>
#include "chess.h"

int start ( char * pp)    // Расстановка фигур (return 0 - ошибка, 1 - верно)
{
    FILE *fa = fopen ("army.txt", "r");  
    if(!fa){
        printf("\n ERROR!\tНевозможно считать файл army.txt\n\n");
        return 0;
    }
    
    for(int i = 0; i < 64; i++){
        pp[i] = getc(fa);
    }
    
    fclose(fa);
    return 1;
}

int print_game (char * pp)    // Вывод положения фигур на доске (return 0 - ошибка, 1 - верно)
{
    FILE *fd = fopen ("desk.txt", "r");
    if(!fd){
        printf("\n ERROR!\tНевозможно открыть desk.txt\n\n");
        return 0;
    }
 
 // Начало вывода   
    printf("\n");
    int i, d, ar, n = 0, k = 1;    // i, d, ar - счетчик, n и k - начало и конец индесации фигур в строке
    char ch;
    for(i = 0; i < 60; i++){ 
        if(i < 26) {
            ch = getc(fd);
            putchar(ch);
        }
        
        if((i >= 26) && (i < 34)){
            
            for( d = 2; d > 0; d--){
                ch = getc(fd);
                putchar(ch);
            }
           
            for( ar = n*1; ar < 8*k; ar++){
               printf("%c", pp[ar]);
            }
            
            for( d = 3; d > 0; d--){
                ch = getc(fd);
                putchar(ch);
            }
         
            n=ar;
            k++; 
        }
        
       if(i >= 34){
           ch = getc(fd);
           putchar(ch);
       }
    }
    fclose(fd);
    printf("\n");
    return 1;    
}

