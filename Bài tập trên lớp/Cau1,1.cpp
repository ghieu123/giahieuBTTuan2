#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Định nghĩa kích thước mảng là một hằng số
#define SIZE 15

// Ham tao mang mot chieu ngau nhien co so phan tu lon hon hoac bang 15
void taoMangNgauNhien(int mang[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        mang[i] = min + rand() % (max - min + 1);
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

    // 1. Tao mang mot chieu ngau nhien
    taoMangNgauNhien(mang, SIZE, 0, 100);
    printf("Mang ngau nhien: ");
    inMang(mang, SIZE);

    return 0;
}