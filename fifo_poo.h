/**
 * @file    fifo.h
 * @author  Thomas Stäheli
 * @date    10.10.2025
 * @version 1.0
 *
 * @brief   This is a fifo library for char data type
 */

#ifndef C_UTILS_FIFO_H
#define C_UTILS_FIFO_H

#include <stdint.h>

typedef struct {
    char* data;             // Data table
    uint16_t size;          // Fifo Size
    uint16_t capacity;      // Fifo Capacity
    uint16_t write_index;   // Write Index
    uint16_t read_index;    // Read Index

    // Functions pointers
    int  (*init)(struct Char_Fifo *fifo, uint16_t capacity);
    int  (*mem_free)(struct Char_Fifo *fifo);
    int  (*peek_char)(struct Char_Fifo *fifo, char *data);
    int  (*get_char)(struct Char_Fifo *fifo, char *data);
    int  (*put_char)(struct Char_Fifo *fifo, char data);
    int  (*put_string)(struct Char_Fifo *fifo, char *string);
    int  (*get_string)(struct Char_Fifo *fifo, char *string);
} Char_Fifo;

// !! HAS TO BE USED !!
void fifo_init_functions(Char_Fifo *fifo);

int init(Char_Fifo *fifo, uint16_t capacity);
int mem_free(Char_Fifo *fifo);
int peek_char(Char_Fifo *fifo, char *data);
int get_char(Char_Fifo *fifo, char *data);
int put_char(Char_Fifo *fifo, char data);
int put_string(Char_Fifo *fifo, char *string);
int get_string(Char_Fifo *fifo, char *string);

#endif //C_UTILS_FIFO_H

