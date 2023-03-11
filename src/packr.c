/* packr - package manager for GNU/Linux
 *
 * if you don't know where to start with reading the source code, start by read the main function.
 */

// include libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.c"
#include "main.h"

#ifndef VERSION
#define VERSION "unknown"
#endif

// declare functions
static void help(int exitcode);
static void readargs(int argcount, char *arg[]);

void help(int exitcode) {
    fputs("packr [-i pkg] [-r pkg] [-u] [-v]\n"
    , exitcode ? stderr : stdout);
    exit(exitcode);
}

void readargs(int argcount, char *arg[]) {
    for (int i = 1; i < argcount; i++) {
        if (!strcmp(arg[i], "-h") || !strcmp(arg[i], "--help")) { // --help or -h
            help(0);
        } else if (!strcmp(arg[i], "-v") || !strcmp(arg[i], "--version")) { // --version or -v
            fprintf(stdout, "packr %s\n", VERSION);
            exit(0);
        } else {
            fprintf(stderr, "Unknown argument: %s\n", arg[i]);
            exit(1);
        }
    }

    return;
}

void main(int argc, char *argv[]) {
    // start by reading args
    if (argc < 2) {
        help(1);
    } else {
        readargs(argc, argv);
    }

    return;
}
