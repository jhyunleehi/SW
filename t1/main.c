#include <stdio.h>
char buf[512];

void cat(int fd) {
    int n;
    while ((n = read(fd, buf, sizeof(buf))) > 0) {
        if (write(1, buf, n) != n) {
            printf(1, "cat: write error\n");
            exit(0);
        }
    }
    if (n < 0) {
        printf(1, "cat: read error\n");
        exit(0);
    }
}

int get_int(char** a) {
    char* b = *a;
    int rtn = 0;
    while (*(b) != ' ' && *(b) != '\n') {
        rtn += (rtn * 10) + *(b)-'0';
        b++;
    }    
    b++;
    *a = b;
    return rtn;
}

int main(int argc, char* argv[]) {
    int fd, i;
    if (argc <= 1) {
        cat(0);
        exit(0);
    }

    for (i = 1; i < argc; i++) {
        if ((fd = open(argv[i], 0)) < 0) {
            printf(1, "cat: cannot open %s\n", argv[i]);
            exit();
        }
        cat(fd);
        close(fd);
    }
    
    char* str = buf;
    for (i = 1; i < 10; i++) {
        printf("%d\n", get_int(&str));
    }



    exit(0);
}
