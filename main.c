#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IntVector.h"


int main()
{
  double choice;
  
  IntVector *v = int_vector_new(15);
  printf("%p, %d, %d\n", v->vector, v->size, v->capacity);
  
  
  printf("Select test function: ");
  scanf("%lf", &choice);
    
    if (choice == 1) {
      int_vector_copy(v);
      printf("%p, %d, %d\n", v->vector, v->size, v->capacity);
    }

    if (choice == 2) {
      int_vector_free(v);
      printf("%p, %d, %d\n", v->vector, v->size, v->capacity);
    }

    if (choice == 3) {
      int index = 13;
      int_vector_get_item(v, index);
      printf("%d\n", v->vector[index]);
    }

    if (choice == 4) {
      int index = 13;
      int item = 72;
      printf("Source value: %d\n", v->vector[index]);
      int_vector_set_item(v, index, item);
      printf("Result value: %d\n", v->vector[index]);
    }

    if (choice == 5) {
      int size;
      size = int_vector_get_size(v);
      printf("Result: %d\n", size);
    }

    if (choice == 6) {
      int capacity;
      capacity = int_vector_get_capacity(v);
      printf("Result: %d\n", capacity);
    }

    if (choice == 7) {
      printf("Source capacity: %d, source size: %d\n", v->capacity, v->size);
      int_vector_push_back(v, 44);
      printf("Result capacity: %d, result size: %d\n", v->capacity, v->size);
    }

    if (choice == 8) {
      printf("Source size: %d\n", v->size);
      int_vector_pop_back(v);
      printf("Result size: %d\n", v->size);
    }

    if (choice == 9) {
      printf("Source capacity: %d, source size: %d\n", v->capacity, v->size);
      int_vector_shrink_to_fit(v);
      printf("Result capacity: %d, result size: %d\n", v->capacity, v->size);
    }

    if (choice == 10) {
      printf("Source size: %d\n", v->size);
      int_vector_resize(v, 20);
      printf("Result size: %d\n", v->size);
    }

    if (choice == 11) {
      printf("Source capacity: %d\n", v->capacity);
      int_vector_reserve(v, 30);
      printf("Result capacity: %d\n", v->capacity);
    }
}