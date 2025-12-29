#ifndef LOGGER_H
#define LOGGER_H

#include "const.h"

static char *verbose_label[] = {"MESSAGE", "INFO", "DEBUG", "TRACE"};
static char *verbose_color[] = {ANSI_COLOR_RESET, ANSI_COLOR_BLUE, ANSI_COLOR_GREEN, ANSI_COLOR_PURPLE};

void verbose_message(int verbose_level, const char *format, ...);

void fatal(const int exit_code, const char *format, ...);
void warn(const char *format, ...);

#define message(...)   verbose_message(0, __VA_ARGS__)
#define log_info(...)  verbose_message(1, __VA_ARGS__)
#define log_debug(...) verbose_message(2, __VA_ARGS__)
#define log_trace(...) verbose_message(3, __VA_ARGS__)

#endif
