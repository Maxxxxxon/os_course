#include <stdio.h>

void bubblesort(int array[], int n){
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; j < n - 1; j++){
			if (array[j] > array[j + 1]){
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

int main(){
	int a[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
	bubblesort(a, 9);
	for (int i = 0; i < 9; i++){
		printf("%d ", a[i]);
	}
	return 0;
}