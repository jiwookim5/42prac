#include "getnextline.h"

char *getnextline(int fd)
{
    int i = 0;
    char c;
    char *line = malloc(10000);
    int rd = read(fd, &c, BUFFSIZE - BUFFSIZE + 1);

    if (BUFFSIZE == 0)
    {
        free(line);
        return(0);
    }
    while(rd > 0)
    {
        line[i] = c;
        i++;
        if (c == '\n')
            break;
        rd = read(fd, &c, BUFFSIZE - BUFFSIZE + 1); 
    }
    line[i] = '\0';
    if (rd == -1 || i == 0 || (line[i - 1] && rd == 0))
    {
        free(line);
        return(NULL);
    }s
    return(line);
}
kgkjgk

int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        line = getnextline(fd);
        while(line != NULL)
        {
            printf("%s", line);
            free(line);
            line = getnextline(fd);
        }
        close(fd);
    }
    return(0);
}
