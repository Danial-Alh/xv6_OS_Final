//
// Created by danial on 1/13/16.
//

#include "user.h"
#include "fcntl.h"

int main()
{
    int page_fd, flag_fd, context_fd, tf_fd, proc_fd;
    printf(2, "pid user mode: %d\n", getpid());

    char argv[1][1] = {{""}};
    int first_fork_pid;

    first_fork_pid = fork();
    printf(1, "I GOT FORK PID: %d", first_fork_pid);
    if (first_fork_pid == 0) //child
    {
        static char *name = "counter";
        exec(name, (char **) argv);
    }
    else
    {

        page_fd = open("page_backup", O_CREATE | O_RDWR);
        flag_fd = open("flag_backup", O_CREATE | O_RDWR);
        context_fd = open("context_backup", O_CREATE | O_RDWR);
        tf_fd = open("tf_backup", O_CREATE | O_RDWR);
        proc_fd = open("proc_backup", O_CREATE | O_RDWR);

        saveProc(page_fd, flag_fd, context_fd, tf_fd, proc_fd);
        close(page_fd);
        close(flag_fd);
        close(context_fd);
        close(tf_fd);
        close(proc_fd);
        wait();


        printf(1, "*************\n*************\n*************\n*************\n*************\n");

        page_fd = open("page_backup", O_RDONLY);
        flag_fd = open("flag_backup", O_RDONLY);
        context_fd = open("context_backup", O_RDONLY);
        tf_fd = open("tf_backup", O_RDONLY);
        proc_fd = open("proc_backup", O_RDONLY);

        if(loadProc(page_fd, flag_fd, context_fd, tf_fd, proc_fd) != 0)
        {
            close(page_fd);
            close(flag_fd);
            close(context_fd);
            close(tf_fd);
            close(proc_fd);
            wait();
        }
    }
    exit();
}

