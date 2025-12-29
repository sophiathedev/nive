#ifndef OPTION_H
#define OPTION_H

typedef struct {
  int verbose;
  int version;
} option_t;

extern option_t *option;

void initialize_option(option_t *opt);

#endif
