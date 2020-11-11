#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define N 100
int main() {
    FILE *in = fopen("./input_dl.txt", "r");
    FILE *out = fopen("output_dl.txt", "w");
    char ch;
    int num;
    int n = 0, m = 0;
    while(1){
        fscanf(in, "%d", &num);
        fscanf(in, "%c", &ch);
        m++;
        if (ch == '\n')
            break;
    } 
    int a[m];
    for (int i = 0; i < m; i++) {
        fscanf(in, "%d", &a[i]);
    }
    int allocm[N][m], requestm[N][m];

    while(1) {
        for (int i = 0; i < m; i++) {
            fscanf(in, "%d", &allocm[n][i]);
        }
        n++;
        fscanf(in, "%c", &ch);
        fscanf(in, "%c", &ch);
        if (ch != '\n')
            fseek(in, -1, SEEK_CUR);
        else{
            break;
        }
    };
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            fscanf(in, "%d", &requestm[i][j]);
        }
    }
    int checked[n];
    memset(checked, 0, n * sizeof(int));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (checked[j] == 0){
                int lesseq = 1;
                for (int k = 0; k < m; k++){
                    if (requestm[j][k] > a[k]){
                        lesseq = 0;
                    }
                }
                if (lesseq){
                    for (int k = 0; k < m; k++){
                        a[k] += allocm[j][k];
                    }
                    checked[j] = 1;
                    break;
                }
            }
        }
    }
    int deadlock = 0;
    for (int i = 0; i < n; i++){
        if (checked[i] == 0)
            deadlock = 1;
    }

    if (deadlock){
        fprintf(out, "Deadlocked process:\n");
        for (int j = 0; j < n; j++){
            if (!checked[j]){
                fprintf(out, "%d ", (j + 1));
            }
        }
        return 0;
    }
    fprintf(out, "No deadlocks");
    return 0;

}