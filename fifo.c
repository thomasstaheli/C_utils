#include <malloc.h>
#include <string.h>
#include "fifo.h"

#define SUCCESS           0
#define FAILURE           1
#define FIFO_IS_EMPTY     2
#define FIFO_IS_FULL      3
#define STRING_FOUND      4
#define STRING_NOT_FOUND  (-1)

int fifo_init(Char_Fifo* fifo, uint16_t capacity) {

  fifo->capacity = capacity;
  fifo->size = 0;
  fifo->write_index = 0;
  fifo->read_index  = 0;
  fifo->data = (char *) calloc(capacity, sizeof(char));
  if(fifo->data == NULL) {
    return FAILURE;
  }

  return SUCCESS;
}

int fifo_free(Char_Fifo* fifo) {
  free(fifo->data);
  return SUCCESS;
}

// See what is inside the fifo, without taking it
int fifo_peek_char(Char_Fifo* fifo, char* data) {

  if(fifo->size > 0) {
    *data = fifo->data[fifo->read_index];
    return SUCCESS;
  }
  return FIFO_IS_EMPTY;
}

// Take the data and remove it
int fifo_get_char(Char_Fifo* fifo, char* data) {
  // Check if any data is in the fifo
  if(fifo->size > 0) {
    *data = fifo->data[fifo->read_index];
    // Handling circularity
    if(fifo->read_index == fifo->capacity - 1) {
      fifo->read_index = 0;
    } else {
      ++fifo->read_index;
    }
    --fifo->size;
    return SUCCESS;
  }
  return FIFO_IS_EMPTY;
}

int fifo_put_char(Char_Fifo* fifo, char data) {
  // Check if the fifo is full
  if(fifo->size >= fifo->capacity) {
    return FIFO_IS_FULL;
  }

  fifo->data[fifo->write_index] = data;
  // Handling circularity
  if(fifo->write_index == fifo->capacity - 1) {
    fifo->write_index = 0;
  } else {
    ++fifo->write_index;
  }
  ++fifo->size;

  return SUCCESS;
}

int fifo_put_string(Char_Fifo* fifo, char* string) {

  // SHOULD CHECK FOR '\0' -> because using strlen
  // SHOULD CONTAIN '\n' too for fifo_check_for_string
  // TODO

  uint16_t string_size = strlen(string);

  for(uint16_t i = 0; i < string_size; ++i) {
    fifo_put_char(fifo, string[i]);
  }

  if(string[string_size - 1] != '\n') {
    fifo_put_char(fifo, '\n');
  }

  return SUCCESS;
}

//
int fifo_check_for_string(Char_Fifo* fifo, uint16_t* index) {

  uint16_t current_index = fifo->read_index;
  // Start reading from current reading position (Optimisation)
  while(++current_index != fifo->read_index) {
    // Handle circularity
    if(current_index == fifo->capacity) {
      current_index = 0;
    }

    if(fifo->data[current_index] == '\n') {
      *index = current_index;
      return STRING_FOUND;
    }
  }

  *index = -1;
  return STRING_NOT_FOUND;
}

int fifo_get_string(Char_Fifo* fifo, char* string) {

  uint16_t index;
  if(fifo_check_for_string(fifo, &index) == STRING_NOT_FOUND) {
    return FAILURE;
  }

  uint16_t string_pos = 0;
  char data;
  while(fifo->read_index != index) {
    fifo_get_char(fifo, &data);
    string[string_pos] = data;
    ++string_pos;
  }

  return SUCCESS;
}

