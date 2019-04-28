#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IntVector.h"


IntVector* int_vector_new(size_t initial_capacity) {
  IntVector* arr = (IntVector*)malloc(sizeof(IntVector));
  if (arr == NULL) {
    return NULL;
  }
    arr->vector = (int*)calloc(initial_capacity, sizeof(int));  //Создаём массив и инициализируем все его биты нулями
  if (arr->vector == NULL) {
    free(arr);
    return NULL;
  }
  arr->size = 0;
  arr->capacity = initial_capacity;
  return arr;
}


IntVector *int_vector_copy(const IntVector *v) {
  IntVector* arr = (IntVector*)malloc(sizeof(IntVector));
  if (arr == NULL) {
    return NULL;
  }
  
  arr->vector = (int*)malloc(v->capacity * sizeof(int));
  if (arr->vector == NULL) {
    free(arr);
    return NULL;
  }
  arr->size = v->size;
  arr->capacity = v->capacity;
  if(memmove(arr->vector, v->vector, v->capacity) == NULL) {    //Если не удалось скопировать блок памяти из исходного массива, возвращаем NULL
    free(arr);
    return NULL;
  }
  return arr;
}


void int_vector_free(IntVector* v) {
  if (v != NULL) {
  free(v->vector);
  free(v);
  v->size = 0;
  v->capacity = 0;
  }
}


int int_vector_get_item(const IntVector *v, size_t index) {
  if (v != NULL || v->vector != NULL) {
  return v->vector[index];
  }
  return 0;
}


void int_vector_set_item(IntVector *v, size_t index, int item) {
  if (v != NULL || v->vector != NULL) {
    v->vector[index] = item;
  }
}


size_t int_vector_get_size(const IntVector *v) {
  if (v != NULL) {
    return v->size;
  }
  return 0;
}


size_t int_vector_get_capacity(const IntVector *v) {
  if (v != NULL) {
    return v->capacity;
  }
  return 0;
}


int int_vector_push_back(IntVector *v, int item) {
  if (v != NULL) {
    if (v->capacity == v->size) {
      if(!int_vector_reserve(v, v->capacity * 2)) {  
        v->vector[v->size] = item;
        v->size++;
        return 0;
      }
    } else {
      v->capacity++;
      v->size++;
      v->vector[v->size] = item;
    }
    }
  return -1;
}


void int_vector_pop_back(IntVector *v) {
  if (v->size != 0) {
    v->vector[v->size - 1] = 0;
    v->size -= 1;
  }
}


int int_vector_shrink_to_fit(IntVector *v) {
  int *arr = NULL;
  if (v != NULL && v->capacity != v->size) {
    arr = (int*)malloc(v->size * sizeof(int));  //Выделяем память для результирующего массива
    int *tmp = v->vector;
    memmove(arr, v->vector, v->size * sizeof(int));  //Копируем ровно то количество байтов из исходного массива, каков является его размер 
    free(tmp);
    v->vector = arr;
    v->capacity = v->size;
    return 0;
  }
  return -1;
}


int int_vector_resize(IntVector *v, size_t new_size) {
  if (v != NULL) {
    if(new_size <= v->size) {
      v->size = new_size;
    } else {
      if (new_size > v->capacity) {
        int_vector_reserve(v, v->capacity * 2);  //Если новый размер массива больше исходной ёмкости, то увеличиваем ёмкость в два раза
      }
      memset(&(v->vector[v->size]), 0, sizeof(int) * (new_size - v->size));  //Функция для заполнения добавленных элементов нулями
      v->size = new_size;
    }
    return 0;
  }
  return -1;
}


int int_vector_reserve(IntVector *v, size_t new_capacity) {
  int *arr = (int*)malloc(v->size * sizeof(int));
  
  if (v == NULL || new_capacity <= v->capacity) {
    return -1;
  }

  if (new_capacity > v->capacity) {
      arr = realloc(v->vector, new_capacity * sizeof(int)); //Функция для изменения величины выделенной памяти
      v->vector = arr;
      v->capacity = new_capacity;
  }
  return 0;
}