#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main () {
	int fd1 = open("ex1.txt", O_RDWR);
    int fd2 = open("ex1.memcpy.txt", O_RDWR);
	struct stat stat_;
	fstat(fd1, &stat_);
	ftruncate(fd2, stat_.st_size);
	void* pa1 = mmap(NULL, stat_.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd1, 0);
	void* pa2 = mmap(NULL, stat_.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd2, 0);
	memcpy(pa2, pa1, stat_.st_size);
	munmap(pa1, stat_.st_size);
	munmap(pa2, stat_.st_size);
	close(fd1);
	close(fd2);
	return 0;
}