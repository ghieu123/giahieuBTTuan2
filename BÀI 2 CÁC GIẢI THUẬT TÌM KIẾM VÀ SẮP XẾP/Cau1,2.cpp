#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Định nghĩa kích thước mảng là một hằng số
#define SIZE 15

//2 Ham tao mang chua toan so chan
void taoMangSoChan(int mang[], int n) {
    for (int i = 0; i < n; i++) {
        mang[i] = 2 * (rand() % 50); // Tao so chan ngau nhien tu 0 den 98
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

    // 2. Tao mang chua toan so chan
    taoMangSoChan(mang, SIZE);
    printf("Mang chua toan so chan: ");
    inMang(mang, SIZE);

    return 0;
}