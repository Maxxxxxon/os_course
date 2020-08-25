#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int type, number;
    sscanf(argv[1], "%d", &type);
    sscanf(argv[2], "%d", &number);
    if (type == 1){
        for (int i = 0; i < number; i++){
            for (int j = 0; j < number - i - 1; j++){
                printf(" ");
            }
            for (int j = 0; j < 2 * i + 1; j++){
                printf("*");
            }
            printf("\n");
        }
    }
    else if (type == 2){
        for (int i = 0; i < number; i++){
            for (int j = 0; j < number - i - 1; j++){
                printf(" ");
            }
            for (int j = 0; j < 2 * i + 1; j++){
                printf("*");
            }
            printf("\n");
        }
        for (int i = number - 2; i >= 0; i--){
            for (int j = 0; j < number - i - 1; j++){
                printf(" ");
            }
            for (int j = 0; j < 2 * i + 1; j++){
                printf("*");
            }
            printf("\n");
        }
    }
    else if (type == 3){
        for (int i = number - 1; i >= 0; i--){
            for (int j = 0; j < number - i - 1; j++){
                printf(" ");
            }
            for (int j = 0; j < 2 * i + 1; j++){
                printf("*");
            }
            printf("\n");
        }
        for (int i = 1; i < number; i++){
            for (int j = 0; j < number - i - 1; j++){
                printf(" ");
            }
            for (int j = 0; j < 2 * i + 1; j++){
                printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}