#include "monster.h"


void signal_handler(int m)
{
        (void)m;
        write(STDERR_FILENO, "\n", 1);
        write(STDERR_FILENO, "$ ", 2);
}

