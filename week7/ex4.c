#include <stdio.h>
#include <stdlib.h>

void* realloc__(void* ptr, size_t size) {
  if (ptr == NULL) {
    return malloc(size);
  }
  if (size == 0) {
    free(ptr);
    return ptr;
  }
  
  void* ptr2 = malloc(size);
  int oldsize = malloc_usable_size(ptr);
  if (size > oldsize)
      size = oldsize;
  for (int i = 0; i < size; i++) {
    ((char*)ptr2)[i] = (((char*)ptr2)[i]);
  }
  free(ptr);
  
  return ptr2;
} 
