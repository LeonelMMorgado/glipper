#ifndef _FILE_UTIL_H
#define _FILE_UTIL_H

#include <stdio.h>

FILE * open_file(const char * path);
const char * file_to_char(FILE * file);
const char * read_file(const char * path);

#endif