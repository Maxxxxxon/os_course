#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv){
    int nfiles = argc - 1;
    int append = 0;
    if (strcmp(argv[1], "-a") == 0){
        append = 1;
        nfiles -= 1;
    }
    int fds[nfiles];
    for (int i = 1 + append; i < argc; i++){
        if (append)
            fds[i] = open(argv[i], O_WRONLY | O_APPEND);
        else
            fds[i] = open(argv[i], O_WRONLY);
    }
    char ch;
    while (read(0, &ch, 1) > 0){
        write(1, &ch, 1);
        for (int i = 0; i < nfiles; i++){
            // write works both for rewrite and append depending on the given permissions
            write(fds[i], &ch, 1);
        }
    }
    for (int i = 0; i < nfiles; i++){
        close(fds[i]);
    }    
}