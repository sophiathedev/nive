#ifndef CONST_H
#define CONST_H

#if defined(__GNUC__) && !defined(__cplusplus)
#define INLINE __always_inline
#elif defined(__clang__) || defined(_MSC_VER)
#define INLINE inline
#else
#define INLINE
#endif

// Defining the version of Nive
#define NIVE_MAJOR_VERSION    0
#define NIVE_MINOR_VERSION    1
#define NIVE_REVISION_VERSION 0

// Defining the exit codes
#define NIVE_EXIT_SUCCESS 0
#define NIVE_EXIT_FAILURE -1

// ANSI color codes
#define ANSI_COLOR_GREEN  "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_RED    "\x1b[31m"
#define ANSI_COLOR_BLUE   "\x1b[34m"
#define ANSI_COLOR_PURPLE "\x1b[35m"
#define ANSI_COLOR_RESET  "\x1b[0m"

#endif
