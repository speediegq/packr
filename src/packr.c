/* packr - package manager for GNU/Linux
 *
 * Copyright (C) 2023  speedie
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 * if you don't know where to start with reading the source code, start by read the main function.
 */

// include libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "main.h"
#include "main.c"

// define some basic information
#ifndef VERSION
#define VERSION "unknown"
#endif

// declare functions
static void help(int exitcode);
static void readargs(int argcount, char *arg[]);
static void prepareenv(void);

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

void prepareenv(void) {
    const char *basename = "packr.conf";
    const char *dirname = "/etc/packr";

    char config[30];

    if (!sprintf(config, "%s/%s", dirname, basename)) {
        fprintf(stderr, "packr: failed to determine location of configuration file\n");
        exit(1);
    }

    FILE *conf = fopen(config, "r");

    if (conf) { // the file opens successfully which means it exists and has proper permissions
        fclose(conf);
        return;
    }

    if (geteuid() != 0) {
        fprintf(stderr, "Superuser permissions required (to prepare packr environment).\n");
        exit(1);
    }

    if (mkdir(dirname, 0755)) {
        fprintf(stderr, "packr: could not create directory\n");
        exit(1);
    }

    conf = fopen(config, "w"); // write it and immediately fclose it
    fclose(conf);

    return;
}

void main(int argc, char *argv[]) {
    prepareenv();

    // reading arguments
    if (argc < 2) {
        help(1);
    } else {
        readargs(argc, argv);
    }

    return;
}
