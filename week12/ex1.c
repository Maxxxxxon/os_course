#include <fcntl.h>
#include <unistd.h> 

int main(){
    int input_fd = open("/dev/random", O_RDONLY);

    int output_fd = open("ex1.txt", O_WRONLY);

    char ch[20];
    read(input_fd, ch, 20);
    write(output_fd, ch, 20);

    close(input_fd);
    close(output_fd);
}