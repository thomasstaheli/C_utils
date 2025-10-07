/*
 * Author : Thomas Stäheli
 * Description : Lib FIFO plutôt utiliser dans l'embarqué
 */
#include <stdio.h>
#include <string.h>
#include "fifo.h"

#define FIFO_SIZE 50

int main(void) {

  Char_Fifo fifo;
  fifo_init(&fifo, FIFO_SIZE);

  // Filling the Fifo
  for(uint8_t j = 0; j < 20; ++j) {
    char* string = "hello, world!\n";
    fifo_put_string(&fifo, string);

    // Reading the fifo
    char* another_string[FIFO_SIZE];
    fifo_get_string(&fifo, (char *) another_string);
    printf("String inside FIFO : %s\n", (char *) another_string);
  }

  fifo_free(&fifo);
}
