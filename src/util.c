#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *path_append(const char *path, const char *filename)
{
    int needs_separator = 0;
    if ((path[strnlen(path, MAX_PATH_LEN)-1] != '/') && (filename[0] != '/')) {
        needs_separator = 1;
    }

    char *str;
    size_t ul = strnlen(path, MAX_PATH_LEN);
    size_t sl = strnlen(filename, MAX_FILENAME_LEN);
    str = calloc(ul + sl + needs_separator + 1, sizeof(char));
    if (!str) {
        fprintf(stderr, "path_append(): calloc failure!\n");
        exit(EXIT_FAILURE);
    }
    strncpy(str, path, ul);
    if (needs_separator) {
        str[ul] = '/';
    }
    strncat(str, filename, sl);
    return str;
}

int64_t round_div(int64_t a, int64_t b)
{
    return (a + (b / 2)) / b;
}

void PTHREAD_MUTEX_UNLOCK(pthread_mutex_t *x)
{
    int i;
    i = pthread_mutex_unlock(x);
    if (i) {
        fprintf(stderr, "pthread_mutex_unlock failed, %d, %s\n", i,
        strerror(i));
        exit(EXIT_FAILURE);
    }
}

void PTHREAD_MUTEX_LOCK(pthread_mutex_t *x)
{
    int i;
    i = pthread_mutex_lock(x);
    if (i) {
        fprintf(stderr, "pthread_mutex_lock failed, %d, %s\n", i,
        strerror(i));
        exit(EXIT_FAILURE);
    }
}
