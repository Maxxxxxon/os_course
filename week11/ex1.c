#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main () {
	int fd = open("ex1.txt", O_RDWR);
	struct stat stat_;

    char* str = "This is a nice day";
    int len = strlen(str);
    
	ftruncate(fd, len); 
	fstat(fd, &stat_);

	void* pa = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	strcpy(pa, "This is a nice day");
	munmap(pa, len);
	close(fd);
	return 0;
}