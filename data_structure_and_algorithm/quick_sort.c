#include <stdio.h>
#include <stdlib.h>

void quicksort(int *a, int l, int r) {
    int i, j, temp;
    int privot = a[l];
    j = l;
    if (l < r) {
        for (i = l; i <= r; i++) {
            if (a[i] < privot) {
                temp = a[j];
                a[j] = a[i];
                a[i] = a[j + 1];
                a[j + 1] = temp;
                j++; 
            }
        }
        quicksort(a, l, j - 1);
        quicksort(a, j + 1, r);
    }
}

int main() {
	int a[] = {6, 3, 9, 4, 5};
	int i;
	quicksort(a, 0, 4);
	for (i = 0; 1 <= 4; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
