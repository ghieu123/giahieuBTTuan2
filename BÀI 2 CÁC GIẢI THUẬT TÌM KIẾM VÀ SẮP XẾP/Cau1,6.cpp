#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Định nghĩa kích thước mảng là một hằng số
#define SIZE 15


//6 Ham sap xep tang dan theo giai thuat Selection Sort
void selectionSort(int mang[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (mang[j] < min_idx) {
                min_idx = j;
            }
        }
        int temp = mang[min_idx];
        mang[min_idx] = mang[i];
        mang[i] = temp;
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

    // 6. Sap xep tang dan theo Selection Sort
    selectionSort(mang, SIZE);
    printf("Mang sau khi sap xep tang dan (Selection Sort): ");
    inMang(mang, SIZE);

    return 0;
}