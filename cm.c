//
// Created by danial on 1/13/16.
//

#include "user.h"
#include "fcntl.h"

struct test
{
    char name;
    int number;
};

void
save(void)
{
    int fd;
    struct test t;
    t.name = 'd';
    t.number = 25267;

    fd = open("backup", O_CREATE | O_RDWR);
    if (fd >= 0)
    {
        printf(1, "ok: create backup file succeed\n");
    } else
    {
        printf(1, "error: create backup file failed\n");
        exit();
    }

    int size = sizeof(t);
    if (write(fd, &t, size) != size)
    {
        printf(1, "error: write to backup file failed\n");
        exit();
    }
    printf(1, "write ok\n");
    close(fd);
}

void
load(void)
{
    int fd;
    struct test t;

    fd = open("backup", O_RDONLY);
    if (fd >= 0)
    {
        printf(1, "ok: read backup file succeed\n");
    } else
    {
        printf(1, "error: read backup file failed\n");
        exit();
    }

    int size = sizeof(t);
    if (read(fd, &t, size) != size)
    {
        printf(1, "error: read from backup file failed\n");
        exit();
    }
    printf(1, "file contents name %c and number %d", t.name, t.number);
    printf(1, "read ok\n");
    close(fd);
}

int main()
{
    int page_fd, context_fd, tf_fd, proc_fd;
    printf(2, "pid user mode: %d\n", getpid());

    char argv[1][1] = {{""}};
    if (fork() == 0) //child
    {
        exec("counter", (char **) argv);
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

