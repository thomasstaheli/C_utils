/**
 * @file    vector.c
 * @author  Thomas Stäheli
 * @date    10.10.2025
 * @version 1.0
 *
 * @brief   vector library
 */

#include "vector.h"
#include <malloc.h>

#define SUCCESS   0
#define FAILURE   1

int vector_init(Vector *vector, uint16_t capacity) {

  vector->data = (uint8_t *) calloc(capacity, sizeof(uint8_t));
  if(vector->data == NULL) {
    return FAILURE;
  }

  vector->size = 0;
  vector->capacity = capacity;

  return SUCCESS;
}

int vector_resize(Vector *vector, uint16_t size) {

  uint8_t *tmp = (uint8_t *) realloc(vector->data, size * sizeof(uint8_t));
  if(tmp == NULL) {
    return FAILURE;
  } else {
    // TODO : COPY CONTENT BEFORE
    vector->data = tmp;
  }

  return SUCCESS;
}

int vector_reserve(Vector *vector, uint16_t capacity) {
  return SUCCESS;
}

int vector_put(Vector *vector, uint8_t data) {
  return SUCCESS;
}

int vector_get(Vector *vector, uint8_t *data) {
  return SUCCESS;
}

int vector_push_back(Vector *vector, uint8_t data) {
  return SUCCESS;
}

int vector_pop_back(Vector *vector, uint8_t *data) {
  return SUCCESS;
}

int vector_insert(Vector *vector, uint16_t index, uint8_t *data) {
  return SUCCESS;
}

int vector_erase(Vector *vector, uint16_t index) {
  return SUCCESS;
}

int vector_is_empty(Vector *vector) {
  return SUCCESS;
}
