//
// Created by danial on 1/13/16.
//

#include "user.h"

int main()
{
    int first_fork = fork();
    printf(2, "executing new Proc: %d\n", first_fork);
    if (first_fork == 0) //child
    {
        char *name = "counter";
        char argv[1][1] = {{""}};
        exec(name, (char **) argv);
    }
    else
    {
        saveProc();
        wait();


        int fork_pid = loadProc();
        printf(2, "loading new Proc: %d\n", fork_pid);
        if (fork_pid != 0)//parent
            wait();
    }
    exit();
}

