#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Định nghĩa kích thước mảng là một hằng số
#define SIZE 15

//3 Ham tim kiem tuyen tinh
int timKiemTuyenTinh(int mang[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (mang[i] == x) {
            return i;
        }
    }
    return -1;
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


    // 3. Tim kiem tuyen tinh
    int x = 4;
    int vi_tri = timKiemTuyenTinh(mang, SIZE, x);
    if (vi_tri != -1) {
        printf("Phan tu %d tim thay tai vi tri %d\n", x, vi_tri);
    }
    else {
        printf("Phan tu %d khong tim thay\n", x);
    }


    return 0;
}