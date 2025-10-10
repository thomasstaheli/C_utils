/**
 * @file    vector.h
 * @author  Thomas Stäheli
 * @date    10.10.2025
 * @version 1.0
 *
 * @brief   vector library
 */

#ifndef C_UTILS_VECTOR_H
#define C_UTILS_VECTOR_H

#include <stdint.h>

typedef struct {
  uint8_t *data;
  uint16_t size;
  uint16_t capacity;
} Vector;

int vector_init(Vector *vector, uint16_t capacity);
int vector_resize(Vector *vector, uint16_t size);
int vector_reserve(Vector *vector, uint16_t capacity);
int vector_put(Vector *vector, uint8_t data);
int vector_get(Vector *vector, uint8_t *data);
int vector_push_back(Vector *vector, uint8_t data);
int vector_pop_back(Vector *vector, uint8_t *data);
int vector_insert(Vector *vector, uint16_t index, uint8_t *data);
int vector_erase(Vector *vector, uint16_t index);
int vector_is_empty(Vector *vector);


#endif //C_UTILS_VECTOR_H
