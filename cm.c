//
// Created by danial on 1/13/16.
//

#include "user.h"

int main()
{
    int fork_pid = loadProc();
    printf(2, "loading new Proc: %d\n", fork_pid);
    if (fork_pid != 0)
        wait();
    exit();
}

