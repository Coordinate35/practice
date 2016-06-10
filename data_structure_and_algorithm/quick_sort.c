#include <stdio.h>
#include <stdlib.h>

void quick_sort(int *a, int l, int r) {
    int i, j, temp;
    int pivot = a[l];
    j = l;
    if (l < r) {
        for (i = l; i <= r; i++) {
            if (a[i] < pivot) {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
                j++;
            } 
        }
        quick_sort(a, l, j - 1);
        quick_sort(a, j + 1, r);
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
