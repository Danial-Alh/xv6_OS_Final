//
// Created by danial on 1/13/16.
//

#include "user.h"
#include "fcntl.h"

int main()
{
    int page_fd, context_fd, tf_fd, proc_fd;
    printf(2, "pid user mode: %d\n", getpid());

    char argv[1][1] = {{""}};
    if (fork() == 0) //child
    {
        static char *name = "counter";
        exec(name, (char **) argv);
    }
    else
    {

        page_fd = open("page_backup", O_CREATE | O_RDWR);
        context_fd = open("context_backup", O_CREATE | O_RDWR);
        tf_fd = open("tf_backup", O_CREATE | O_RDWR);
        proc_fd = open("proc_backup", O_CREATE | O_RDWR);

        saveProc(page_fd, context_fd, tf_fd, proc_fd);
        close(page_fd);
        close(context_fd);
        close(tf_fd);
        close(proc_fd);
        wait();
//    fd = open("backup", O_CREATE | O_RDWR);
//    close(page_fd);
//    close(context_fd);
//    close(tf_fd);
//    fd = open("backup", O_RDONLY);

//    loadProc(fd, );

    }
    exit();
}

