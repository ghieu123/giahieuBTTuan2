#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Định nghĩa kích thước mảng là một hằng số
#define SIZE 15


//4 Ham sap xep tang dan theo giai thuat Interchange Sort
void interchangeSortTangDan(int mang[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mang[i] > mang[j]) {
                int temp = mang[i];
                mang[i] = mang[j];
                mang[j] = temp;
            }
        }
    }
}

//4 Ham sap xep giam dan theo giai thuat Interchange Sort
void interchangeSortGiamDan(int mang[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mang[i] < mang[j]) {
                int temp = mang[i];
                mang[i] = mang[j];
                mang[j] = temp;
            }
        }
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

    // 4. Sap xep tang dan theo Interchange Sort
    interchangeSortTangDan(mang, SIZE);
    printf("Mang sau khi sap xep tang dan (Interchange Sort): ");
    inMang(mang, SIZE);

    // Sap xep giam dan theo Interchange Sort
    interchangeSortGiamDan(mang, SIZE);
    printf("Mang sau khi sap xep giam dan (Interchange Sort): ");
    inMang(mang, SIZE);


    return 0;
}