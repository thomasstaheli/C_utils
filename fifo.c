/*
 * File Name      : fifo.c
 * Author         : Thomas Stäheli
 * Date           : 10.10.2025
 * Version        : 1.0
 *
 * Description    : This is a fifo library for char data type
 */

#include <malloc.h>
#include <string.h>
#include "fifo.h"

#define SUCCESS           0
#define FAILURE           1
#define FIFO_IS_EMPTY     2
#define FIFO_IS_FULL      3
#define STRING_FOUND      4
#define STRING_NOT_FOUND  (-1)

/*
 * Initializes the fifo
 * Allocates memory for the data table
 * @param fifo : Pointer to the fifo structure
 * @param capacity : Capacity of the fifo
 * @return SUCCESS if the fifo was initialized successfully, FAILURE otherwise
 */
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

/*
 * Frees the memory allocated for the data table
 * @param fifo : Pointer to the fifo structure
 * @return SUCCESS if the memory was freed successfully, FAILURE otherwise
 */
int fifo_free(Char_Fifo* fifo) {
  free(fifo->data);
  return SUCCESS;
}

/*
 * See what is inside the fifo, without taking it
 * @param fifo : Pointer to the fifo structure
 * @param data : Pointer to the variable where the data will be stored
 * @return SUCCESS if the data was read successfully, FIFO_IS_EMPTY if the fifo is empty
 */
int fifo_peek_char(Char_Fifo* fifo, char* data) {

  if(fifo->size > 0) {
    *data = fifo->data[fifo->read_index];
    return SUCCESS;
  }
  return FIFO_IS_EMPTY;
}

/*
 * Takes one char from the fifo
 * @param fifo : Pointer to the fifo structure
 * @param data : Pointer to the variable where the data will be stored
 * @return SUCCESS if the data was read successfully, FIFO_IS_EMPTY if the fifo is empty
 */
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

/*
 * Puts one char into the fifo
 * @param fifo : Pointer to the fifo structure
 * @param data : Data to be put into the fifo
 * @return SUCCESS if the data was put successfully, FIFO_IS_FULL if the fifo is full
 */
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

/*
 * Puts a string into the fifo
 * @param fifo : Pointer to the fifo structure
 * @param string : String to be put into the fifo
 * @return SUCCESS if the string was put successfully, FAILURE otherwise
 */
int fifo_put_string(Char_Fifo* fifo, char* string) {

  // TODO : SHOULD CHECK FOR '\0' -> because using strlen

  uint16_t string_size = strlen(string);

  for(uint16_t i = 0; i < string_size; ++i) {
    fifo_put_char(fifo, string[i]);
  }

  if(string[string_size - 1] != '\n') {
    fifo_put_char(fifo, '\n');
  }

  return SUCCESS;
}

/*
 * Checks if there is a string (ending with '\n') in the fifo
 * @param fifo : Pointer to the fifo structure
 * @param index : Pointer to the variable where the index of the '\n' will be stored
 * @return STRING_FOUND if a string was found, STRING_NOT_FOUND otherwise
 */
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

/*
 * Takes a string from the fifo
 * @param fifo : Pointer to the fifo structure
 * @param string : Pointer to the variable where the string will be stored
 * @return SUCCESS if a string was read successfully, FAILURE otherwise
 */
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

  // Remove '\n' from the buffer
  fifo->data[fifo->read_index] = '\0';

  // Take the '\n'
  fifo_get_char(fifo, &data);
  string[string_pos] = '\n';
  // End the string
  ++string_pos;
  string[string_pos] = '\0';

  return SUCCESS;
}

