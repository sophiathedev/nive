#include <stdio.h>
#include <stdlib.h>
#include "argparse.h"
#include "const.h"
#include "logger.h"
#include "option.h"
#include "safemem.h"

static const char *const usages[] = {
  "nive [options] [[--] args]",
  "nive [options]",
  NULL,
};

option_t *option;

int main(int argc, const char **argv) {
  option = (option_t *)safe_malloc(sizeof(option_t));
  initialize_option(option);

  struct argparse_option options[] = {
    OPT_HELP(),
    OPT_GROUP("Basic options"),
    OPT_BOOLEAN('v', "version", &option->version, "show version information", NULL, 0, 0),
    OPT_INTEGER(0, "verbose", &option->verbose, "set verbosity level (default: 0)", NULL, 0, 0),
    OPT_END(),
  };

  struct argparse argparse;

  argparse_init(&argparse, options, usages, 0);
  argparse_describe(&argparse, "Nive is a lightweight and powerful software used to sandbox processes in Linux.", "");

  if (argc < 2) {
    argparse_usage(&argparse);
    return NIVE_EXIT_SUCCESS;
  }
  argc = argparse_parse(&argparse, argc, argv);

  log_trace("Verbosity level set to %d", option->verbose);
  if (option->version != 0) {
    printf("nive %d.%d.%d\n", NIVE_MAJOR_VERSION, NIVE_MINOR_VERSION, NIVE_REVISION_VERSION);
    warn("Version option is not yet implemented.");
    return NIVE_EXIT_SUCCESS;
  }
}
