//
// Created by thoma on 07.10.2025.
//

#ifndef C_UTILS_FIFO_H
#define C_UTILS_FIFO_H

#include <stdint.h>

typedef struct {
    char* data;             // Data table
    uint16_t size;          // Fifo Size
    uint16_t capacity;      // Fifo Capacity
    uint16_t write_index;   // Write Index
    uint16_t read_index;    // Read Index
} Char_Fifo;

int fifo_init(Char_Fifo* fifo, uint16_t capacity);
int fifo_free(Char_Fifo* fifo);
int fifo_peek_char(Char_Fifo* fifo, char* data);
int fifo_get_char(Char_Fifo* fifo, char* data);
int fifo_put_char(Char_Fifo* fifo, char data);
int fifo_put_string(Char_Fifo* fifo, char* string);
int fifo_get_string(Char_Fifo* fifo, char* string);

#endif //C_UTILS_FIFO_H
