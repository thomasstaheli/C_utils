/**
 * @file    fifo_poo_example.c
 * @author  Thomas Stäheli
 * @date    10.10.2025
 * @version 1.0
 *
 * @brief   This is an example for the fifo.c library
 */

#include <stdio.h>
#include "fifo_poo.h"

#define FIFO_SIZE 50

int main(void) {

  Char_Fifo fifo;
  fifo_init_functions(&fifo);

  fifo.init((struct Char_Fifo *) &fifo, FIFO_SIZE);

  // Filling the Fifo
  for(uint8_t j = 0; j < 20; ++j) {
    char* string = "hello, world!\n";
    fifo.put_string((struct Char_Fifo *) &fifo, string);

    // Reading the fifo
    char* another_string[FIFO_SIZE];
    fifo.get_string((struct Char_Fifo *) &fifo, (char *) another_string);
    printf("String inside FIFO : %s", (char *) another_string);
    printf("\n");
  }

  fifo.mem_free((struct Char_Fifo *) &fifo);
}
