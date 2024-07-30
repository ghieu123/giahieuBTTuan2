#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_SIZE 100

typedef struct {
    int integer;
    int numerator;
    int denominator;
} MixedNumber;

// Hàm tạo hỗn số ngẫu nhiên
MixedNumber generate_random_mixed_number() {
    MixedNumber mn;
    mn.integer = rand() % 100; // Phần nguyên từ 0 đến 99
    mn.numerator = rand() % 100; // Tử số từ 0 đến 99
    mn.denominator = (rand() % 99) + 1; // Mẫu số từ 1 đến 99
    return mn;
}

// Hàm tạo Mang hỗn số ngẫu nhiên
void generate_random_mixed_array(MixedNumber* b, int n) {
    for (int i = 0; i < n; i++) {
        b[i] = generate_random_mixed_number();
    }
}

// Hàm xuất danh sách hỗn số
void print_mixed_array(MixedNumber* b, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %d/%d\n", b[i].integer, b[i].numerator, b[i].denominator);
    }
}
// Hàm so sánh 2 hỗn số
int compare_mixed_numbers(MixedNumber a, MixedNumber b) {
    int left = a.integer * b.denominator * a.denominator + a.numerator * b.denominator;
    int right = b.integer * a.denominator * b.denominator + b.numerator * a.denominator;
    if (left > right) return 1;
    else if (left < right) return -1;
    else return 0;
}

// Hàm chuyển hỗn số sang phân số
void mixed_to_fraction(MixedNumber mn, int* numerator, int* denominator) {
    *numerator = mn.integer * mn.denominator + mn.numerator;
    *denominator = mn.denominator;
}

// Hàm chuyển phân số sang hỗn số
MixedNumber fraction_to_mixed(int numerator, int denominator) {
    MixedNumber mn;
    mn.integer = numerator / denominator;
    mn.numerator = numerator % denominator;
    mn.denominator = denominator;
    return mn;
}
// Hàm tính tổng 2 hỗn số
MixedNumber add_mixed_numbers(MixedNumber a, MixedNumber b) {
    int num1, denom1, num2, denom2;
    mixed_to_fraction(a, &num1, &denom1);
    mixed_to_fraction(b, &num2, &denom2);
    int common_denominator = denom1 * denom2;
    int sum_numerator = num1 * denom2 + num2 * denom1;
    return fraction_to_mixed(sum_numerator, common_denominator);
}

// Hàm tính hiệu 2 hỗn số
MixedNumber subtract_mixed_numbers(MixedNumber a, MixedNumber b) {
    int num1, denom1, num2, denom2;
    mixed_to_fraction(a, &num1, &denom1);
    mixed_to_fraction(b, &num2, &denom2);
    int common_denominator = denom1 * denom2;
    int diff_numerator = num1 * denom2 - num2 * denom1;
    return fraction_to_mixed(diff_numerator, common_denominator);
}

// Hàm tính tích 2 hỗn số
MixedNumber multiply_mixed_numbers(MixedNumber a, MixedNumber b) {
    int num1, denom1, num2, denom2;
    mixed_to_fraction(a, &num1, &denom1);
    mixed_to_fraction(b, &num2, &denom2);
    int product_numerator = num1 * num2;
    int product_denominator = denom1 * denom2;
    return fraction_to_mixed(product_numerator, product_denominator);
}

// Hàm tính thương 2 hỗn số
MixedNumber divide_mixed_numbers(MixedNumber a, MixedNumber b) {
    int num1, denom1, num2, denom2;
    mixed_to_fraction(a, &num1, &denom1);
    mixed_to_fraction(b, &num2, &denom2);
    int quotient_numerator = num1 * denom2;
    int quotient_denominator = denom1 * num2;
    return fraction_to_mixed(quotient_numerator, quotient_denominator);
}

// Hàm sắp xếp Interchange Sort
void interchange_sort(MixedNumber* b, int n, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ascending ? compare_mixed_numbers(b[i], b[j]) > 0 : compare_mixed_numbers(b[i], b[j]) < 0) {
                MixedNumber temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp Selection Sort
void selection_sort(MixedNumber* b, int n, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (ascending ? compare_mixed_numbers(b[j], b[min_idx]) < 0 : compare_mixed_numbers(b[j], b[min_idx]) > 0) {
                min_idx = j;
            }
        }
        MixedNumber temp = b[i];
        b[i] = b[min_idx];
        b[min_idx] = temp;
    }
}

// Hàm sắp xếp Quick Sort
void quick_sort(MixedNumber* b, int left, int right, int ascending) {
    if (left >= right) {
        return;
    }
    MixedNumber pivot = b[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (ascending ? compare_mixed_numbers(b[i], pivot) < 0 : compare_mixed_numbers(b[i], pivot) > 0) i++;
        while (ascending ? compare_mixed_numbers(b[j], pivot) > 0 : compare_mixed_numbers(b[j], pivot) < 0) j--;
        if (i <= j) {
            MixedNumber temp = b[i];
            b[i] = b[j];
            b[j] = temp;
            i++;
            j--;
        }
    }
    quick_sort(b, left, j, ascending);
    quick_sort(b, i, right, ascending);
}

 //Hàm hiển thị menu
void display_menu() {
    printf("=== MENU ===\n");
    printf("1. Tao mang hon so ngau nhien\n");
    printf("2. Xuat danh sach hon so\n");
    printf("3. So sanh 2 hon so\n");
    printf("4. Chuyen hon so sang phan so\n");
    printf("5. Chuyen phan so sang hon so\n");
    printf("6. Tinh tong 2 hon so\n");
    printf("7. Tinh hieu 2 hon so\n");
    printf("8. Tinh tich 2 hon so\n");
    printf("9. Tinh thuong 2 hon so\n");
    printf("10. Sap xep tang dan bang Interchange Sort\n");
    printf("11. Sap xep giam dan bang Interchange Sort\n");
    printf("12. Sap xep tang dan bang Selection Sort\n");
    printf("13. Sap xep giam dan bang Selection Sort\n");
    printf("14. Sap xep tang dan bang Quick Sort\n");
    printf("15. Sap xep giam dan bang Quick Sort\n");
    printf("0. Thoat\n");
    printf("==============\n");
}

int main() {
    srand(time(NULL));

    int n = 0;
    MixedNumber b[MAX_SIZE];
    int choice;

    while (1) {
        display_menu();
        printf("Chon chuc nang: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("Nhap so luong phan tu cua Mang: ");
            scanf_s("%d", &n);
            generate_random_mixed_array(b, n);
            printf("Mang hon so ngau nhien da duoc tao.\n");
            break;

        case 2:
            if (n == 0) {
                printf("Hay tao mang hon so truoc!\n");
            }
            else {
                printf("Danh sach hon so:\n");
                print_mixed_array(b, n);
            }
            break;

        case 3: {
            if (n < 2) {
                printf("Hay tao it nhat 2 hon so!\n");
            }
            else {
                int idx1, idx2;
                printf("Nhap vi tri cua hon so thu nhat (0-%d): ", n - 1);
                scanf_s("%d", &idx1);
                printf("Nhap vi tri cua hon so thu hai (0-%d): ", n - 1);
                scanf_s("%d", &idx2);
                int result = compare_mixed_numbers(b[idx1], b[idx2]);
                if (result > 0) {
                    printf("Hon so thu nhat lon hon hon so thu hai.\n");
                }
                else if (result < 0) {
                    printf("Hon so thu nhat nho hon hon so thu hai.\n");
                }
                else {
                    printf("Hai hon so bang nhau.\n");
                }
            }
            break;
        }

        case 4: {
            if (n == 0) {
                printf("Hay tao mang hon so truoc!\n");
            }
            else {
                int idx;
                printf("Nhap vi tri cua hon so can chuyen (0-%d): ", n - 1);
                scanf_s("%d", &idx);
                int numerator, denominator;
                mixed_to_fraction(b[idx], &numerator, &denominator);
                printf("Phan so tuong ung la: %d/%d\n", numerator, denominator);
            }
            break;
        }

        case 5: {
            int numerator, denominator;
            printf("Nhap tu so: ");
            scanf_s("%d", &numerator);
            printf("Nhap mau so (khac 0): ");
            scanf_s("%d", &denominator);
            MixedNumber mn = fraction_to_mixed(numerator, denominator);
            printf("Hon so tuong ung la: %d %d/%d\n", mn.integer, mn.numerator, mn.denominator);
            break;
        }

        case 6: {
            if (n < 2) {
                printf("Hay tao it nhat 2 hon so!\n");
            }
            else {
                int idx1, idx2;
                printf("Nhap vi tri cua hon so thu nhat (0-%d): ", n - 1);
                scanf_s("%d", &idx1);
                printf("Nhap vi tri cua hon so thu hai (0-%d): ", n - 1);
                scanf_s("%d", &idx2);
                MixedNumber result = add_mixed_numbers(b[idx1], b[idx2]);
                printf("Tong cua hai hon so la: %d %d/%d\n", result.integer, result.numerator, result.denominator);
            }
            break;
        }

        case 7: {
            if (n < 2) {
                printf("Hay tao it nhat 2 hon so!\n");
            }
            else {
                int idx1, idx2;
                printf("Nhap vi tri cua hon so thu nhat (0-%d): ", n - 1);
                scanf_s("%d", &idx1);
                printf("Nhap vi tri cua hon so thu hai (0-%d): ", n - 1);
                scanf_s("%d", &idx2);
                MixedNumber result = subtract_mixed_numbers(b[idx1], b[idx2]);
                printf("Hieu cua hai hon so la: %d %d/%d\n", result.integer, result.numerator, result.denominator);
            }
            break;
        }

        case 8: {
            if (n < 2) {
                printf("Hay tao it nhat 2 hon so!\n");
            }
            else {
                int idx1, idx2;
                printf("Nhap vi tri cua hon so thu nhat (0-%d): ", n - 1);
                scanf_s("%d", &idx1);
                printf("Nhap vi tri cua hon so thu hai (0-%d): ", n - 1);
                scanf_s("%d", &idx2);
                MixedNumber result = multiply_mixed_numbers(b[idx1], b[idx2]);
                printf("Tich cua hai hon so la: %d %d/%d\n", result.integer, result.numerator, result.denominator);
            }
            break;
        }

        case 9: {
            if (n < 2) {
                printf("Hay tao it nhat 2 hon so!\n");
            }
            else {
                int idx1, idx2;
                printf("Nhap vi tri cua hon so thu nhat (0-%d): ", n - 1);
                scanf_s("%d", &idx1);
                printf("Nhap vi tri cua hon so thu hai (0-%d): ", n - 1);
                scanf_s("%d", &idx2);
                MixedNumber result = divide_mixed_numbers(b[idx1], b[idx2]);
                printf("Thuong cua hai hon so la: %d %d/%d\n", result.integer, result.numerator, result.denominator);
            }
            break;
        }

        case 10:
            if (n == 0) {
                printf("Hay tao mang hon so truoc!\n");
            }
            else {
                interchange_sort(b, n, 1);
                printf("Mang sau khi Sap xep tang dan bang Interchange Sort:\n");
                print_mixed_array(b, n);
            }
            break;

        case 11:
            if (n == 0) {
                printf("Hay tao mang hon so truoc!\n");
            }
            else {
                interchange_sort(b, n, 0);
                printf("Mang sau khi Sap xep giam dan bang Interchange Sort:\n");
                print_mixed_array(b, n);
            }
            break;

        case 12:
            if (n == 0) {
                printf("Hay tao mang hon so truoc!\n");
            }
            else {
                selection_sort(b, n, 1);
                printf("Mang sau khi Sap xep tang dan bang Selection Sort:\n");
                print_mixed_array(b, n);
            }
            break;

        case 13:
            if (n == 0) {
                printf("Hay tao mang hon so truoc!\n");
            }
            else {
                selection_sort(b, n, 0);
                printf("Mang sau khi Sap xep giam dan bang Selection Sort:\n");
                print_mixed_array(b, n);
            }
            break;

        case 14:
            if (n == 0) {
                printf("Hay tao mang hon so truoc!\n");
            }
            else {
                quick_sort(b, 0, n - 1, 1);
                printf("Mang sau khi Sap xep tang dan bang Quick Sort:\n");
                print_mixed_array(b, n);
            }
            break;

        case 15:
            if (n == 0) {
                printf("Hay tao mang hon so truoc!\n");
            }
            else {
                quick_sort(b, 0, n - 1, 0);
                printf("Mang sau khi Sap xep giam dan bang Quick Sort:\n");
                print_mixed_array(b, n);
            }
            break;

        case 0:
            printf("Thoat chuong trinh.\n");
            exit(0);

        default:
            printf("Lua chon khong hop le!\n");
            break;
        }
    }

    return 0;
}