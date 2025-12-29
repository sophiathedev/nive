#include "logger.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "option.h"

void verbose_message(int verbose_level, const char *format, ...) {
  if (option->verbose < verbose_level)
    return;

  verbose_level = verbose_level <= option->verbose ? verbose_level : option->verbose;

  const time_t     time_now   = time(NULL);
  const struct tm *local_time = localtime(&time_now);

  char time_buf[80];
  strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S", local_time);

  printf("%s[%s] %s\t", verbose_color[verbose_level], time_buf, verbose_label[verbose_level]);

  va_list args;
  va_start(args, format);
  vprintf(format, args);
  va_end(args);

  printf("%s\n", ANSI_COLOR_RESET);
}

void fatal(const int exit_code, const char *format, ...) {
  const time_t time_now = time(NULL);
  const struct tm *local_time = localtime(&time_now);

  char time_buf[80];
  strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S", local_time);

  fprintf(stderr, "%s[%s] FATAL\t", ANSI_COLOR_RED, time_buf);

  va_list args;
  va_start(args, format);
  vfprintf(stderr, format, args);
  va_end(args);

  fprintf(stderr, "%s\n", ANSI_COLOR_RESET);
  exit(exit_code);
}

void warn(const char *format, ...) {
  const time_t time_now = time(NULL);
  const struct tm *local_time = localtime(&time_now);

  char time_buf[80];
  strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S", local_time);

  fprintf(stdout, "%s[%s] WARNING\t", ANSI_COLOR_YELLOW, time_buf);

  va_list args;
  va_start(args, format);
  vfprintf(stdout, format, args);
  va_end(args);

  fprintf(stdout, "%s\n", ANSI_COLOR_RESET);
}
