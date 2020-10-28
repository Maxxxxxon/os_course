#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main () {
	char* str = "Hello";
	char* buf = malloc(41);
	setvbuf(stdout, buf, _IOLBF, 40);
	for (int i = 0; i < 5; ++i) {
		printf("%c", str[i]);
		sleep(1);
	}
	return 0;
}