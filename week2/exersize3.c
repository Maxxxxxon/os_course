#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int number;
    sscanf(argv[1], "%d", &number);
    // printf("%d", number);
    for (int i = 0; i < number; i++){
        for (int j = 0; j < number - i - 1; j++){
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}