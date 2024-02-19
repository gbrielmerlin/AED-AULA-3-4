#include "array_dinamico.h"
#include <stdlib.h>

#define INITIAL_CAPACITY 10

struct ArrayDinamico {
    Element* data;
    int size;
    int capacity;
};

ArrayDinamico* array_dinamico_create() {
    ArrayDinamico* array = malloc(sizeof(ArrayDinamico));
    array->capacity = INITIAL_CAPACITY;
    array->data = malloc(sizeof(Element)*array->capacity);
    array->size = 0;

    return array;
};

void array_dinamico_destroy(ArrayDinamico* array) {
    free(array->data);
    free(array);

};

void array_dinamico_print(ArrayDinamico* array) {
    for (int i = 0; i < array->size; i++) {
    print_element(array->data[i]);
  }
  printf("\n"); 
};

Element array_dinamico_get(ArrayDinamico* array, int index) {
    if (index < 0 || index >= array->size){
        abort();
    };
    return array->data[index];
};

void array_dinamico_set(ArrayDinamico* array, int index, Element value);

int array_dinamico_size(ArrayDinamico* array){
    return array->size;
};

void array_dinamico_resize(ArrayDinamico* array, int new_capacity) {
    int capacity = sizeof(Element) * new_capacity;
    Element* new_array = realocc(array->data, capacity);

    if (new_array != NULL){
        array->data = new_array;
        array->capacity = new_capacity;
    };
};

void array_dinamico_add(ArrayDinamico* array, Element element) {
    if (array->size == array->capacity){
        array_dinamico_resize(array, array->capacity * 2);
    }
    array->data[array->size];
    array->size++;
    
};