#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Định nghĩa kích thước mảng là một hằng số
#define SIZE 15


//7 Ham sap xep tang dan theo giai thuat Quick Sort
void quickSort(int mang[], int trai, int phai) {
    int i = trai, j = phai;
    int pivot = mang[(trai + phai) / 2];

    while (i <= j) {
        while (mang[i] < pivot) {
            i++;
        }
        while (mang[j] > pivot) {
            j--;
        }
        if (i <= j) {
            int temp = mang[i];
            mang[i] = mang[j];
            mang[j] = temp;
            i++;
            j--;
        }
    }

    if (trai < j) {
        quickSort(mang, trai, j);
    }
    if (i < phai) {
        quickSort(mang, i, phai);
    }
}

// Ham in mang
void inMang(int mang[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", mang[i]);
    }
    printf("\n");
}

int main() {
    srand((unsigned int)time(0));

    int mang[SIZE];

    // 7. Sap xep tang dan theo Quick Sort
    quickSort(mang, 0, SIZE - 1);
    printf("Mang sau khi sap xep tang dan (Quick Sort): ");
    inMang(mang, SIZE);

    return 0;
}