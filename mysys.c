//
// Created by danial on 1/13/16.
//

//#include "user.h"


//void
//load(void)
//{
//    int fd;
//    struct test t;
//
//    fd = open("backup", O_RDONLY);
//    if(fd >= 0) {
//        printf(1, "ok: read backup file succeed\n");
//    } else {
//        printf(1, "error: read backup file failed\n");
//        exit();
//    }
//
//    int size = sizeof(t);
//    if(read(fd, &t, size) != size){
//        printf(1, "error: read from backup file failed\n");
//        exit();
//    }
//    printf(1, "file contents name %c and number %d", t.name, t.number);
//    printf(1, "read ok\n");
//    close(fd);
//}

#include "user.h"

int main()
{
//    char *temp = "backup1.1";
    saveProc();
//    load();

//    struct proc *proc1;
    copyproc(proc1);
    exit();
}

