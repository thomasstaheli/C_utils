/**
 * @file    array.h
 * @author  Thomas Stäheli
 * @date    10.10.2025
 * @version 1.0
 *
 * @brief   array library
 */

#ifndef C_UTILS_ARRAY_H
#define C_UTILS_ARRAY_H

#include <stdint.h>

typedef struct {
  uint8_t *data; // Data Array
  uint16_t size; // Actual size
  uint16_t capacity; // Total capacity
} Array;

void  array_init(Array *array, uint16_t capacity);
int   array_append(Array *array, uint8_t data);
int   array_remove(Array *array, uint16_t index, uint8_t *data);
int   array_put(Array *array, uint16_t index, uint8_t data);
int   array_put_multiples(Array *array, uint16_t index, uint8_t *data, uint16_t data_size);
int   array_get(Array *array, uint16_t index, uint8_t *data);


#endif //C_UTILS_ARRAY_H
