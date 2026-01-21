# ifndef GETNEXTLINE_H
# define GETNEXTLINE_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

# ifndef BUFFSIZE
# define BUFFSIZE 42
char *getnextline(int fd);
#endif
#endif