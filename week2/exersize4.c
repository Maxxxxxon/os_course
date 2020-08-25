#include <stdio.h>
#include <string.h>

void permute(int* var1, int* var2){
    int temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}
int main(int argc, char* argv[]) {
    int var1, var2;
    printf("Input first int:\n");
    scanf("%d", &var1);
    printf("Input second int:\n");
    scanf("%d", &var2);
    permute(&var1, &var2);
    printf("Int 1: %d, int 2: %d\n", var1, var2);
    return 0;
}