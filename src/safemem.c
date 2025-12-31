#include "safemem.h"
#include "const.h"
#include "logger.h"

INLINE
void *safe_malloc(const size_t size) {
  void *block = malloc(size);
  if (block == NULL) {
    fatal(EXIT_FAILURE, "memory allocation failed for size %zu bytes, address: %p", size, &block);
  }

  return block;
}

INLINE
void *safe_realloc(void *ptr, const size_t size) {
  void *block = realloc(ptr, size);
  if (block == NULL) {
    fatal(EXIT_FAILURE, "memory reallocation failed for size %zu bytes, address: %p", size, &block);
  }

  return block;
}
