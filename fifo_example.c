/*
 * File Name      : fifo_example.c
 * Author         : Thomas Stäheli
 * Date           : 10.10.2025
 * Version        : 1.0
 *
 * Description    : This is an example for the fifo.c library
 */

#include <stdio.h>
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
    printf("String inside FIFO : %s", (char *) another_string);
    printf("\n");
  }

  fifo_free(&fifo);
}