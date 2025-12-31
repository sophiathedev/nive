#ifndef SAFEMEM_H
#define SAFEMEM_H

#include <stdlib.h>

void *safe_malloc(const size_t size);
void *safe_realloc(void *ptr, const size_t size);

#endif
