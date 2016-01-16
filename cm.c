//
// Created by danial on 1/13/16.
//

#include "user.h"
#include "fcntl.h"

int main()
{
//    char argv[1][1] = {{""}};
//    int first_fork_pid;

//    first_fork_pid = fork();
//    printf(1, "I GOT FORK PID: %d", first_fork_pid);
//    if (first_fork_pid == 0) //child
//    {
//        static char *name = "counter";
//        exec(name, (char **) argv);
//    }
//    else
//    {

//        saveProc();
//        wait();


//        printf(1, "loading saved process\n*************\n"
//                "*************\n*************\n*************\n*************\n");

        int fork_pid = loadProc();
        printf(2, "loading new Proc: %d\n", fork_pid);
        if( fork_pid != 0)
        {
            wait();
        }
//    }
    exit();
}

