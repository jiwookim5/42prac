#ifndef GETNEXTLINE_H
#define GETNEXTLINE_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *getnextline(int fd);
#ifndef BUFFSIZE
#define BUFFSIZE 42
#endif
#endif
